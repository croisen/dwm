# dwm - dynamic window manager

My own configuration of dwm, it's a mess and that's my fault

## External Packages I Use

-   dmenu
-   dwmblocks
-   feh
-   firefox
-   spotify
-   thunar
-   wireplumber
-   xbacklight

## Patches

-   [dwm-autostart-20210120-cb3f58a.diff](https://dwm.suckless.org/patches/autostart/dwm-autostart-20210120-cb3f58a.diff)
-   [dwm-awesomebar-20230431-6.4.diff](https://dwm.suckless.org/patches/awesomebar/dwm-awesomebar-20230431-6.4.diff)
-   [dwm-clientopacity-6.4.diff](https:/clientopacity/dwm.suckless.org/patches/clientopacity/dwm-clientopacity-6.4.diff)
-   [dwm-gaps-6.0.diff](https://dwm.suckless.org/patches/gaps/dwm-gaps-6.0.diff)
-   [dwm-restartsig-20180523-6.2.diff](https://dwm.suckless.org/patches/restartsig/dwm-restartsig-20180523-6.2.diff)
-   [dwm-rotatestack-20161021-ab9571b.diff](https://dwm.suckless.org/patches/rotatestack/dwm-rotatestack-20161021-ab9571b.diff)
-   [dwm-systray-6.4.diff](https://dwm.suckless.org/patches/systray/dwm-systray-6.4.diff)
-   [dwm-win31theme-20220224-d39e2f3.diff](https://dwm.suckless.org/patches/dwm-win31theme-20220224-d39e2f3.diff)

## Build Requirements

In order to build dwm you need the Xlib header files.

## Installation

Edit config.mk to match your local setup (dwm is installed into
the /usr/local namespace by default).

Afterwards enter the following command to build and install dwm (if
necessary as root):

```bash
make clean install
```

## Running dwm

Add the following line to your .xinitrc to start dwm using startx:

```bash
exec dwm
```

In order to connect dwm to a specific display, make sure that
the DISPLAY environment variable is set correctly, e.g.:

```bash
DISPLAY=foo.bar:1 exec dwm
```

(This will start dwm on display :1 of the host foo.bar.)

In order to display status info in the bar, you can do something
like this in your .xinitrc:

```bash
while xsetroot -name "`date` `uptime | sed 's/.*,//'`"
do
    sleep 1
done &
exec dwm
```

## Configuration

The configuration of dwm is done by creating a custom config.h
and (re)compiling the source code.
Though I have messed with this way more than I should have and now configuration
is done through the various files inside the other_conf directory here...
