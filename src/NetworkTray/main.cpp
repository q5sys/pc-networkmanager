 
#include <err.h>

#include <qtimer.h>
#include <QTranslator>
#include <QDebug>
#include <QFile>
#include <qtextcodec.h>
#include <QApplication>
#include <QLocale>
#include <QTextCodec>

#include <NetworkTray.h>
#include <unistd.h>

#include "../backend/backend-network.h"

#define PREFIX QString("/usr/local")

bool PICOSESSION = false;

int  main(int argc, char *argv[]) {

  PICOSESSION = !QString(getenv("PICO_CLIENT_LOGIN")).isEmpty();

  QString dev;
  if(argc==1){
    //no device specified - automatically figure out which one(s) to use
   QStringList devs = backend::NetDevice::listNetDevices();
   QStringList wifi = devs.filter("wlan");
    qDebug() << "Found Devices:" << devs << wifi;
    wifi.sort();
    //Look for wifi devices first
    for(int i=0; i<wifi.length(); i++){
      devs.removeAll(wifi[i]); //already handled
      if(i==0){ dev = wifi[i]; } //use the first wifi device
      else if(!PICOSESSION){
        //multiple wifi devices - open more tray devices
        QProcess::startDetached("pc-nettray "+devs[i]);
      }
    }
    //Now look for wired devices
    for(int i=0; i<devs.length() && dev.isEmpty(); i++){
      if(devs[i].startsWith("lo")){ continue; } //don't use loopback devices
      dev = devs[i];
    }
    
  }else{
    dev = argv[1];
  }
  qDebug() << "Using device:" << dev;
   QApplication a(argc, argv);

   bool ready = false;
   for(int i=0; i<60 && !ready; i++){
      ready = QSystemTrayIcon::isSystemTrayAvailable();
      if(!ready){
	//Pause for 5 seconds
        sleep(5); //don't worry about stopping event handling - nothing running yet
      }
   }
   if(!ready){
     qDebug() << "Could not find any available system tray after 5 minutes: exiting....";
     return 1;
   }
   
   QTranslator translator;
   QLocale mylocale;
   QString langCode = mylocale.name();
   if ( ! QFile::exists( PREFIX + "/share/trueos/i18n/NetworkTray_" + langCode + ".qm" ) )
     langCode.truncate(langCode.indexOf("_"));
   translator.load( QString("NetworkTray_") + langCode, PREFIX + "/share/trueos/i18n/" );
   a.installTranslator( &translator );
   qDebug() << "Locale:" << langCode;
   QTextCodec::setCodecForLocale( QTextCodec::codecForName("UTF-8") ); //Force Utf-8 compliance
   
   NetworkTray tray;
   QApplication::setQuitOnLastWindowClosed(false);
   tray.programInit(dev);

 

   return  a.exec();
}
