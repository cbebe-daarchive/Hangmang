You need YAML for your perl installation.

So you need to, as root, do
    cpan
taking all the default answers [in brackets] and then when you
finally get a command prompt do
    install YAML

Also, these are connected to the arduino-port-select script that
determines what ports the arduinos are attached to.  We keep that
in bin since you might want to run that before make to set up
ports outside the clutter of running a make.

Note, we installed the new srk500boo_v2_mega2560.hex for the boot
loader that does not have the "hangon on !!!" bug.

We should have a script that checks for !!! in a row in the source,
or 212121 in the hex file.  Not sure what happens if the 212121 spans
two lines in the hex file.
