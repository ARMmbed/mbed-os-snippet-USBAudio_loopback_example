/*
 * Copyright (c) 2006-2020 Arm Limited and affiliates.
 * SPDX-License-Identifier: Apache-2.0
 */
#include "mbed.h"
#include "USBAudio.h"

int main()
{
    USBAudio audio(true, 44100, 2, 44100, 2);

    printf("Looping audio\r\n");
    static uint8_t buf[128];
    while (true) {
        if (!audio.read(buf, sizeof(buf))) {
            memset(buf, 0, sizeof(buf));
        }
        audio.write(buf, sizeof(buf));
    }
}
