#!/usr/bin/env sh
set -e

qmk compile -kb cheapino -km manna-harbour_miryoku \
    -e MIRYOKU_ALPHAS=QWERTY \
    -e MIRYOKU_NAV=VI \
    -e MIRYOKU_MOUSE=VI \
    -e MIRYOKU_MEDIA=VI

sudo mount -o umask=0022,gid=1000,uid=1000 /dev/sdg1 /mnt/usb

cp .build/cheapino_manna-harbour_miryoku.uf2 /mnt/usb

sudo umount /mnt/usb

chmod +x util/mybuild.sh
