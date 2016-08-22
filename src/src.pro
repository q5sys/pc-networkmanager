TEMPLATE = subdirs

SUBDIRS+= NetworkManager wificonfig ethernetconfig NetworkTray

#Rules for installing the .desktop registrations
desktop.files=desktop/*.desktop
desktop.path=/usr/local/share/applications

deskauto.files=desktop-autostart/*.desktop
deskauto.path=/usr/local/etc/xdg/autostart

INSTALLS += desktop deskauto
