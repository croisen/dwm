# dwm - dynamic window manager
# See LICENSE file for copyright and license details.

include config.mk

MAIN				= dwm.c

all: dwm

dwm:
	${CC} ${CFLAGS} -o $@ $(MAIN) $? ${INCS} ${LDFLAGS}

clean:
	rm -f dwm
	rm -f dwm-${VERSION}.tar.gz

dist: clean
	mkdir -p dwm-${VERSION}
	cp -R LICENSE makefile README.md config.h dwm.1 dwm.c dwm.h transient.c\
		wallpapers.h dwm.desktop components/ dwm-${VERSION}
	tar -cf dwm-${VERSION}.tar dwm-${VERSION}
	gzip dwm-${VERSION}.tar
	rm -rf dwm-${VERSION}

install: all
	mkdir -p ${DESTDIR}${PREFIX}/bin
	mkdir -p /usr/share/xsessions
	cp -f dwm ${DESTDIR}${PREFIX}/bin
	chmod 755 ${DESTDIR}${PREFIX}/bin/dwm
	mkdir -p ${DESTDIR}${MANPREFIX}/man1
	sed "s/VERSION/${VERSION}/g" < dwm.1 > ${DESTDIR}${MANPREFIX}/man1/dwm.1
	chmod 644 ${DESTDIR}${MANPREFIX}/man1/dwm.1
	cp -f dwm.desktop /usr/share/xsessions

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/dwm\
		${DESTDIR}${MANPREFIX}/man1/dwm.1

.PHONY: all clean dist install uninstall dwm
