#ifndef DIALOGWPAENTERPRISE_H
#define DIALOGWPAENTERPRISE_H

#include <QDebug>
#include <QDialog>
#include <QFile>
#include <QMessageBox>
#include <QTranslator>
#include "ui_dialogwpaenterprise.h"

class dialogWPAEnterprise : public QDialog, private Ui::dialogWPAEnterprise
{
        Q_OBJECT

public:
        dialogWPAEnterprise() : QDialog()
        {
          QTranslator translator;
          QLocale mylocale;
          QString langCode = mylocale.name();
          if ( ! QFile::exists( "/usr/local/share/lifePreserver/i18n/libtrueos_" + langCode + ".qm" ) )
            langCode.truncate(langCode.indexOf("_"));
          translator.load( QString("libtrueos_") + langCode, "/usr/local/share/lifePreserver/i18n/" );
          QCoreApplication::installTranslator( &translator );
          qDebug() << "Locale:" << langCode;
          setupUi(this);
	  setWindowModality(Qt::ApplicationModal);
        }

    void setVariables( int type, QString EAPIdent, QString AnonIdent, QString CACert, QString ClientCert, QString PrivKeyFile, QString Password, int keyMgmt, int EAPPhase2 );
    void init();

public slots:

private slots:
    void slotTypeChanged();
    void slotSelectCACert();
    void slotSelectClientCert();
    void slotSelectPrivateKeyFile();
    void on_checkShowKey_clicked(bool checked);
    void on_buttonBox_clicked(QAbstractButton *);
    void saveAndClose();

private:

signals:
  void saved(int, QString, QString, QString, QString, QString, QString, int, int);

} ;
#endif // DIALOGWPAENTERPRISE_H

