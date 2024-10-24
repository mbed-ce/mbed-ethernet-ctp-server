/*
 * Copyright (c) 2017, ARM Limited, All Rights Reserved
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "mbed.h"

#include "NetworkInterface.h"
#include "EmacTestMemoryManager.h"
#include "EmacTestNetworkStack.h"
#include "emac_tests.h"
#include "emac_util.h"

int main()
{
    worker_loop_init();

    static NetworkInterface *network_interface = NetworkInterface::get_default_instance();

#define WIFI 2
#if MBED_CONF_TARGET_NETWORK_DEFAULT_INTERFACE_TYPE == WIFI
#if MBED_CONF_APP_WIFI_SCAN
    WiFiAccessPoint ap[30];

    int size = network_interface->wifiInterface()->scan(ap, 30);

    for (int i = 0; i < size; i++) {
        const char *ssid = ap[i].get_ssid();
        nsapi_security_t security = ap[i].get_security();
        int8_t rssi = ap[i].get_rssi();
        char ch = ap[i].get_channel();

        printf("BS %i\r\n", i);
        printf("ssid %s\r\n", ssid);
        printf("security %i\r\n", security);
        printf("rssi %i\r\n", rssi);
        printf("ch %i\r\n\r\n", ch);
    }
#endif
#endif

    // Power up the interface and emac driver
    auto ret = network_interface->connect();
    if(ret != NSAPI_ERROR_OK)
    {
        printf("Failed to connect network interface! Error %d\n", ret);
    }

    emac_if_set_ctp_server_enabled(true);

    worker_loop_link_up_wait();

    printf("echo server started successfully\r\n\r\n");
}

// Override network stack selection to return the EmacTest network stack
OnboardNetworkStack &OnboardNetworkStack::get_default_instance()
{
    return EmacTestNetworkStack::get_instance();
}