uio - A program to manipulate uio devices
=========================================

What is this?
-------------

This program allows you to manipulate `/dev/uio?` devices.

Usage
-------

Show usage:
```console
$ uio
USAGE: uio uio_num byte_offset [value]
```

Read a long word at byte ofset of `8` of the `/dev/uio0`.
```console
$ uio 0 8
0x0000001
```

Write a long word value `100` at byte ofset of `8` of the `/dev/uio0`.
```console
$ uio 0 8 100

$ # hexadecimal format is also accepted
$ uio 0 8 0x00000064
```

Reference
----------
* [電気回路/zynq/Petalinux2018.3でaxi_gpio - 武内＠筑波大 #ma01034d](https://dora.bk.tsukuba.ac.jp/~takeuchi/?%E9%9B%BB%E6%B0%97%E5%9B%9E%E8%B7%AF%2Fzynq%2FPetalinux2018.3%E3%81%A7axi_gpio#ma01034d)
