# Mbed OS CTP Server Application

This application implements a responder for [Connection Test Protocol (CTP), aka Loop](https://wiki.wireshark.org/Loop) packets at the Ethernet layer.  CTP packets are used as part of Mbed OS's test suite, and you must have a second Mbed board running this application present on the network for the EMAC test in the Greentea test suite to pass.

## How to set up this project:

1. Clone it to your machine.  Don't forget to use `--recursive` to clone the submodules: `git clone --recursive https://github.com/mbed-ce/mbed-ethernet-ctp-server.git`
2. You may want to update the mbed-os submodule to the latest version, with `cd mbed-ethernet-ctp-server/mbed-os && git fetch origin && git reset --hard origin/master`
3. Set up the GNU ARM toolchain (and other programs) on your machine using [the toolchain setup guide](https://github.com/mbed-ce/mbed-os/wiki/Toolchain-Setup-Guide).
4. Set up the CMake project for editing.  We have three ways to do this:
    - On the [command line](https://github.com/mbed-ce/mbed-os/wiki/Project-Setup:-Command-Line)
    - Using the [CLion IDE](https://github.com/mbed-ce/mbed-os/wiki/Project-Setup:-CLion)
    - Using the [VS Code IDE](https://github.com/mbed-ce/mbed-os/wiki/Project-Setup:-VS-Code)
5. Build the `flash-ctp-server` target to upload the code to a connected device.
