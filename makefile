# dwm - dynamic window manager
# See LICENSE file for copyright and license details.

include config.mk

MAIN				= dwm.c

COMP_FILE			= ${wildcard components/*.c}
COMP_OBJS			= ${patsubst %.c,%.o,${COMP_FILE}}

PATCH_FILE			= ${wildcard d_patches/*.c}
PATCH_OBJS			= ${patsubst %.c,%.o,${PATCH_FILE}}

C_FILES 			= ${COMP_FILE} ${PATCH_FILE}
O_FILES 			= ${COMP_OBJS} ${PATCH_OBJS}

all: ${C_FILES} dwm

${C_FILES}:
	${CC} ${CFLAGS} -c $@ -o ${patsubst %.c,%.o,$@}

dwm: ${C_FILES}
	${CC} ${CFLAGS} -o $@ $(MAIN) $? ${INCS} ${LDFLAGS}

clean:
	rm -f dwm
	rm -f *.o
	rm -f component/*.o
	rm -f component/patch_comps/*.o
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
	cp -f dwm ${DESTDIR}${PREFIX}/bin
	chmod 755 ${DESTDIR}${PREFIX}/bin/dwm
	mkdir -p ${DESTDIR}${MANPREFIX}/man1
	sed "s/VERSION/${VERSION}/g" < dwm.1 > ${DESTDIR}${MANPREFIX}/man1/dwm.1
	chmod 644 ${DESTDIR}${MANPREFIX}/man1/dwm.1
	cp -f dwm.desktop /usr/share/xsessions

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/dwm\
		${DESTDIR}${MANPREFIX}/man1/dwm.1

.PHONY: all clean dist install uninstall dwm ${C_FILES}
