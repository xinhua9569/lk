/*
 * Copyright (c) 2012 Travis Geiselbrecht
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT
 */
#include <lk/err.h>
#include <lk/debug.h>
#include <target.h>
#include <lk/compiler.h>
#include <dev/gpio.h>
#include <platform/gpio.h>
#include <platform/nrf52.h>
#include <target/gpioconfig.h>

void target_early_init(void) {
    gpio_config(GPIO_LED1, GPIO_OUTPUT);
    gpio_config(GPIO_LED2, GPIO_OUTPUT);
    gpio_config(GPIO_LED3, GPIO_OUTPUT);
    gpio_config(GPIO_LED4, GPIO_OUTPUT);

    gpio_set(GPIO_LED1,0);
    gpio_set(GPIO_LED2,0);
    gpio_set(GPIO_LED3,0);
    gpio_set(GPIO_LED4,0);

    nrf52_debug_early_init();
}


void target_init(void) {
    nrf52_debug_init();
    dprintf(SPEW,"Target: PCA10056 DK...\n");
}
