TEMPLATE = subdirs

SUBDIRS+=src

images.path=/usr/local/share/trueos/pc-netmanager/pics/
images.files=pics/*.png

sudo.path=/usr/local/etc/sudoers.d/
sudo.files=sudoers.d/netmanager

INSTALLS+= images sudo
