# Mbed OS CTP Server Application

This application implements a responder for [Connection Test Protocol (CTP), aka Loop](https://wiki.wireshark.org/Loop) packets at the Ethernet layer.  CTP packets are used as part of Mbed OS's test suite, and you must have a second Mbed board running this application present on the network for the EMAC test in the Greentea test suite to pass.