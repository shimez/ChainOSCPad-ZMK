# ChainOSCPad ZMK

ZMK firmware configuration for ChainOSCPad using the Seeed Studio XIAO nRF52840.

## Default controls

- SW1-SW12: F13-F24
- Encoder push: Mute
- Encoder rotation: Volume Down / Volume Up
- USB HID and Bluetooth HID enabled

## Current module layout

The shield lives in the repository-root module path:

```text
boards/shields/chainoscpad/
```

and the repository is exposed to Zephyr/ZMK using:

```text
zephyr/module.yml
```

The old `config/boards/...` compatibility path is not used.

## ZMK Studio

Studio support is enabled in `build.yaml` with:

```yaml
snippet: studio-rpc-usb-uart
cmake-args: -DCONFIG_ZMK_STUDIO=y
```

The shield defines a `zmk,physical-layout` with all 13 physical key positions.

Open ZMK Studio at https://zmk.studio/ in Chrome/Edge or use the native app.

This configuration sets:

```text
CONFIG_ZMK_STUDIO_LOCKING=n
```

so no physical key needs to be reserved for `&studio_unlock`.

Two reserved layers (`Extra 1` and `Extra 2`) are included for later activation
inside ZMK Studio.

Important: after Studio stores a runtime keymap, later changes to the stock
`.keymap` do not automatically replace that stored layout. Use **Restore Stock
Settings** in ZMK Studio when you want to return to the firmware's stock keymap.

Encoder sensor bindings remain in `chainoscpad.keymap`; encoder assignment
editing is not currently a normal ZMK Studio capability.

## Build

Push to GitHub and use the included GitHub Actions workflow. Download the
generated artifact, extract the `.uf2`, enter the XIAO nRF52840 UF2 bootloader,
and copy the firmware file to the bootloader drive.
