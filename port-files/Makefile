# Created by: Kris Moore <kris@ixsystems.com>
# $FreeBSD$

PORTNAME=	pc-networkmanager
PORTVERSION=	%%CHGVERSION%%
CATEGORIES=	sysutils

MAINTAINER=	kris@ixsystems.com
COMMENT=	TrueOS Qt based network manager

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libtrueos-ui.so:sysutils/trueos-libqt5

MAKE_ARGS=      PREFIX=${STAGEDIR}${PREFIX}

CONFLICTS=      pcbsd-utils*

MAKE_JOBS_UNSAFE=yes
ONLY_FOR_ARCHS= amd64
USE_LDCONFIG=   yes
USES=	qt:5 qmake shebangfix tar:xz
USE_QT=        core gui network svg linguist \
		buildtools x11extras widgets
USE_GL+=	gl

QMAKE_ARGS=     CONFIG+="configure"

USE_GITHUB=	yes
GH_ACCOUNT=	project-trident
GH_PROJECT=	pc-networkmanager
GH_TAGNAME=	%%GHTAG%%

.include <bsd.port.mk>
