# create symlinks to the new avr-libc 1.7.1
#
cd hardware/tools/avr/lib/avr || exit
mv -i include{,-orig}
mv -i lib{,-orig}
ln -s ../../../../../../avr-libc-1.7.1-overlay/include .
ln -s ../../../../../../avr-libc-1.7.1-overlay/lib .
