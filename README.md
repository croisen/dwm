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
-   [classic95](https://github.com/quadpixels/classic95)
-   [hackneyed-x11-cursors](https://gitlab.com/Enthymeme/hackneyed-x11-cursors.git)
-   [Windows-3.11](https://github.com/B00merang-Project/Windows-3.11)

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
