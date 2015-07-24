# kio_afc
libimobiledevice based AFC KIO Protocol for KF5.

based on the greate work from Jonathan Beck.

# Requires:
1, libimobiledevice >= 1.1.5(you should also have usbmuxd an related libraries installed)

2, KF5 KIO

# Installation:
$mkdir build

$cd build

$cmake -DCMAKE_INSTALL_PREFIX=/usr ..

$make

$sudo make install

If your dist. choose install kf5 module to qt plugins dir(for example, fedora), you may use:

$cmake -DCMAKE_INSTALL_PREFIX=/usr -DPLUGIN_INSTALL_DIR=/usr/lib/qt5/plugins ..


# Usage:
To use KF5 KIO, at least you should have dolphin or konqueror of KF5 installed. 
Maybe you need install the git version.

After that:

$dolphin5 afc:/ or dolphin5 afc:

will list all connected devices.

OR:

$idevice_id -l

$dolphin5 afc:/<deviceid>

to view contents of your device directly.

OR:

You can use the "network" in dolphin sidebar, I also put a remote item there named "Apple Devices".


# KF5 solid integration.
KF5 solid currently can not identify AFC device, for iphone, it may identify it as camera with "ptp" protocol and "gphoto" driver support
That's to say, currently AFC KIO can not be associated with a solid action service.

Maybe, I will create a solid backend later to handle "usbmuxd" device.


