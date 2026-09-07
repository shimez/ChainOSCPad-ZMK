# ChainOSCPad ZMK

ZMK firmware configuration for ChainOSCPad using Seeed Studio XIAO nRF52840.

## Features

- USB HID
- Bluetooth HID
- ZMK Studio
- 12-key matrix
- Encoder push
- Rotary encoder
- D10 red status/decorative LED: always on while firmware is running

## D10 LED wiring

```text
D10 -> 330 ohm -> red LED -> GND
```

The LED uses Zephyr's standard `gpio-leds` devicetree binding with
`default-state = "on"`. No ChainOSCPad-specific C source is used for LED control.

## Encoder

The EC12PL configuration uses 24 pulses and 24 triggers per rotation.
