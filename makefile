# dwm - dynamic window manager
# See LICENSE file for copyright and license details.

include config.mk

COMPONENTS			= dwm.c dwm-funcs.c ${wildcard components/*.c}
COMPONENTS_O		= ${patsubst %.c,%.o,${COMPONENTS}}

HEADERS 			= ${wildcard *.h components/*.h other_conf/*.h}

all: dwm

dwm: ${COMPONENTS_O}
	${CC} ${CFLAGS} -o $@ $? ${INCS} ${LDFLAGS}

%.o: %.c ${HEADERS}
	${CC} ${CFLAGS} -o $@ -c $< ${INCS}

clean:
	rm -f dwm
	rm -f *.o
	rm -f components/*.o
	rm -f dwm-${VERSION}.tar.gz

dist: clean
	mkdir -p dwm-${VERSION}
	cp -R LICENSE makefile README.md config.h dwm.1 dwm.desktop \
		dwm.c dwm-funcs.c dwm-funcs.h other_conf components/ \
		transient.c dwm-${VERSION}
	rm -f dwm-${VERSION}/components/*.o dwn-${VERSION}/other_conf/*.o
	tar -cf dwm-${VERSION}.tar dwm-${VERSION}
	gzip dwm-${VERSION}.tar
	rm -rf dwm-${VERSION}

install: all
	mkdir -p ${DESTDIR}${PREFIX}/bin
	mkdir -p ${DESTDIR}${PREFIX}/share
	mkdir -p ${DESTDIR}${PREFIX}/share/xsessions
	cp -f dwm ${DESTDIR}${PREFIX}/bin
	chmod 755 ${DESTDIR}${PREFIX}/bin/dwm
	mkdir -p ${DESTDIR}${MANPREFIX}/man1
	sed "s/VERSION/${VERSION}/g" < dwm.1 > ${DESTDIR}${MANPREFIX}/man1/dwm.1
	chmod 644 ${DESTDIR}${MANPREFIX}/man1/dwm.1
	cp -f dwm.desktop ${DESTDIR}${PREFIX}/share/xsessions

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/dwm\
		${DESTDIR}${MANPREFIX}/man1/dwm.1

.PHONY: all clean dist install uninstall dwm
