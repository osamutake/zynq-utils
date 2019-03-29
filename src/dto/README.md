dto - Device Tree Overlay utility
=====================

What is this?
----------

This small script helps you to modify your device tree without reboot based on the device tree overlay technology.

Usage
----------

Show usage:
```console
$ dto
USAGE: sudo dto folder-name [file-name.dts]
```

Compile device tree source fragment file 'overlay.dtso' and 
load the result onto
`/sys/kernel/config/device-tree/overlays/overlay-path/dtbo`
to overlay the device tree:
```console
$ dto overlay-path overlay.dtso
```

Unapply the overlayed dtbo at 
`/sys/kernel/config/device-tree/overlays/overlay-path/dtbo`:
```console
$ dto overlay-path
```


Example
----------

```console
$ cat << EOT > example.dtso
/dts-v1/;
/plugin/;
/ {
  fragment@0 {
    target-path = "/some-device";
    __overlay__ {
      property1;
      property2 = "value";
      property3 = <1 2 3>;
      some : some@1234 {
        property1;
        property2 = "value";
        property3 = <1 2 3>;
      }
    };
  };
};
EOT

$ ls /sys/kernel/config/device-tree/overlays/example
ls: cannot access '/sys/kernel/config/device-tree/overlays/example': No such file or directory

$ dto example example.dtso  # apply 'example.dtso' to the device tree

$ ls /sys/kernel/config/device-tree/overlays/example
dtbo  path  status

$ cat /sys/kernel/config/device-tree/overlays/gpio1/status
applied

$ dto example   # unapply 'example.dtso'

$ ls /sys/kernel/config/device-tree/overlays/example
ls: cannot access '/sys/kernel/config/device-tree/overlays/example': No such file or directory
```

Reference
---------
* [電気回路/zynq/Petalinux2018.3でPLとDevice Treeを動的に変更する - 武内＠筑波大 #b87fd39f](https://dora.bk.tsukuba.ac.jp/~takeuchi/?%E9%9B%BB%E6%B0%97%E5%9B%9E%E8%B7%AF%2Fzynq%2FPetalinux2018.3%E3%81%A7PL%E3%81%A8Device%20Tree%E3%82%92%E5%8B%95%E7%9A%84%E3%81%AB%E5%A4%89%E6%9B%B4%E3%81%99%E3%82%8B#b87fd39f)
