#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/init.h>

#define LED_NODE DT_ALIAS(chainoscpad_led)

static const struct gpio_dt_spec led =
    GPIO_DT_SPEC_GET(LED_NODE, gpios);

static int chainoscpad_led_init(void)
{
    if (!gpio_is_ready_dt(&led)) {
        return -ENODEV;
    }

    return gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
}

SYS_INIT(chainoscpad_led_init, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);