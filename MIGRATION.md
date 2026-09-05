# Migration from v0.1

## Remove

Delete:

```text
config/boards/shields/chainoscpad/
```

## Add

Add:

```text
boards/shields/chainoscpad/
zephyr/module.yml
```

## Main changes

- Migrates the shield to the recommended ZMK module board-root structure.
- Adds a `zmk,physical-layout` and physical key geometry required by ZMK Studio.
- Removes `zmk,matrix-transform` from `/chosen`.
- Enables `studio-rpc-usb-uart` and `CONFIG_ZMK_STUDIO=y`.
- Adds `studio` to the shield metadata.
- Adds two reserved layers for Studio.
- Keeps the already-tested key matrix and encoder settings.
