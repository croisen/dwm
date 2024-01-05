VERSION						= 6.4
PREFIX						= /usr/local
MANPREFIX					= ${PREFIX}/share/man

CC							= clang

FREETYPEINC					= /usr/include/freetype2
FREETYPELIB					= -lfontconfig -lXft

X11INC						= /usr/X11R6/include
X11LIB						= /usr/X11R6/lib

XINERAMALIBS				= -lXinerama
XINERAMAFLAG				= -DXINERAMA

# OpenBSD
#FREETYPEINC				= ${X11INC}/freetype2
#MANPREFIX					= ${PREFIX}/man

INCS = -I${X11INC} -I${FREETYPEINC}
LIBS = -L${X11LIB} ${FREETYPELIB} ${XINERAMALIBS} -lX11

CPPFLAGS = -D_DEFAULT_SOURCE -D_BSD_SOURCE -D_XOPEN_SOURCE=700L -DVERSION=\"${VERSION}\" ${XINERAMAFLAGS}
CFLAGS   = -std=c99 -Wpedantic -Wall -Wno-deprecated-declarations -O3 ${INCS} ${CPPFLAGS}
LDFLAGS  = ${LIBS}
