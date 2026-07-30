SUBDIR=	src

install-cmdinfo:
	mkdir -p ${DESTDIR}${INFODIR}
	for f in cmdinfo/*.about; do \
		install -m 644 $$f ${DESTDIR}${INFODIR}; \
	done
.include <bsd.subdir.mk>
