# ChainOSCPad ZMK firmware

ChainOSCPad PCB + Seeed Studio XIAO nRF52840 用の ZMK shield / user config です。

## Hardware mapping

| ChainOSCPad | XIAO pin | ZMK role |
|---|---:|---|
| ROW0 | D0 | Matrix row 0 |
| ROW1 | D1 | Matrix row 1 |
| ROW2 | D2 | Matrix row 2 |
| ROW3 | D3 | Matrix row 3 |
| COL0 | D4 | Matrix column 0 |
| COL1 | D5 | Matrix column 1 |
| COL2 | D6 | Matrix column 2 |
| Encoder A | D7 | Encoder A |
| Encoder B | D8 | Encoder B |
| Encoder Push | D9 | Direct key |
| Spare | D10 | Unused |

PCB diode direction is COL ->| ROW, so the ZMK matrix uses `col2row`.

## Default keymap

- SW1..SW12: F13..F24
- Encoder CW: Volume Up
- Encoder CCW: Volume Down
- Encoder Push: Mute

## Recommended first build: GitHub Actions

For the first ZMK test, no local Zephyr/west toolchain is required.

1. Create a new GitHub repository.
2. Push this whole project.
3. Open the repository's Actions tab.
4. Run or wait for `Build ZMK firmware`.
5. Download the firmware artifact from the successful run.
6. Put the XIAO nRF52840 in UF2 bootloader mode and copy the generated `.uf2`.

Build target is already defined in `build.yaml`:

```yaml
include:
  - board: xiao_ble//zmk
    shield: chainoscpad
```

## Flashing XIAO nRF52840

1. Connect the XIAO via USB.
2. Double-reset the board to enter UF2 bootloader mode.
3. A USB mass-storage drive appears.
4. Copy the generated `.uf2` file to it.
5. The board reboots automatically.

## Local build

The first test is intentionally GitHub-Actions-first.
If you later want local builds in VS Code on Windows, set up Python, west,
CMake/Ninja and the Zephyr SDK at that point.

## Notes

This is v0.1 for initial hardware validation.
The encoder `steps` and `triggers-per-rotation` values may need tuning for
the actual encoder used on ChainOSCPad.
