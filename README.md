# Linux-driver-for-amg8833

## Test Environment:
 - Board: Raspberry pi 4b

## Install guide:
  1. Compile device tree
  ```bash=
    dtc -@ -I dts -O dtb -o mlx90614-i2c.dtbo mlx90614.dti
  ```
  2. Move device tree binary code to /boot/firmware/overlays/
  3. Add line on /boot/firmware/config.txt
  ```text=
  + dtoverlay=mlx90614-i2c  
  ```
  4. reboot
  5. Compile driver
  ```bash=
  make
  ```
  6. Load module
  ```bash=
  sudo insmod mlx90614.ko
  ```
  7. Compile test program
  ```bash=
  make test
  ```
  8. Give permission
  ```bash=
  sudo chmod 666 /dev/mlx90614
  ```
  9. Excute test
  ```bash=
  ./test
  ```

## Spec
[mlx90614 spec](https://mel-prd-cdn.azureedge.net/-/media/files/documents/datasheets/mlx90614-datasheet-melexis.pdf)

## Data format
```text=
0x01 0x02 0x03 0x04 0x05 0x06
```

TA  =>  0x01 | 0x02 << 8 = 0x0201
TOBJ1 =>  0x03 | 0x04 << 8 = 0x0403
TOBJ2 =>  0x05 | 0x06 << 8 = 0x0605

TA => 0x0403 * 0.02 => (K)
TOBJ1 => 0x0201 * 0.02 => (K)
TOBJ2 => 0x0605 * 0.02 => (K)

TA => 0x0403 * 0.02(K) - 273.15 => (C)
TOBJ1 => 0x0403 * 0.02(K) - 273.15 => (C)
TOBJ2 => 0x0605 * 0.02(K) - 273.15 => (C)