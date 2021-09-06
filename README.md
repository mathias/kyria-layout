
## Instructions

For either, `cd qmk_firmware`

Flash left half:

```
qmk flash -kb splitkb/kyria -km mathias -bl dfu-split-left
```

Flash right half:

```
qmk flash -kb splitkb/kyria -km mathias -bl dfu-split-right
```
