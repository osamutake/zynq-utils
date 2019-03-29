lcd-control - Manipulate character LCD controller ST7032i via i2c
===========

What is this?
-------------

This program allows you to send commands to the popular LCD controller ST7032i via i2c.

Condition
-----------

This program assumes the ST7032i controller is connected to `/dev/i2c-1`.

If it is connected to some other device, you need to change the parameter and recompile the program.

Usage
-------

Show usage:
```console
$ lcd-control
USAGE:
lcd-control "Hello!"
lcd-control -c 0x39 0x14 0x78 ...
```

Send command characters:
```console
$ # initialization
$ lcd-control -c 0x38
$ lcd-control -c 0x39
$ lcd-control -c 0x14 0x7c 0x5d 0x6d 0x0c 0x06 0x01

$ # clear screen
$ lcd-control -c 0x01

$ # move to the top of the second line
$ lcd-control -c 0xc0 
```

Send printable characters:
```console
$ lcd-control "Hello, world!"
```

Reference
----------
* [電気回路/zynq/Petalinux2018.3でキャラクタLCD制御(ST7032i) - 武内＠筑波大](https://dora.bk.tsukuba.ac.jp/~takeuchi/?%E9%9B%BB%E6%B0%97%E5%9B%9E%E8%B7%AF%2Fzynq%2FPetalinux2018.3%E3%81%A7%E3%82%AD%E3%83%A3%E3%83%A9%E3%82%AF%E3%82%BFLCD%E5%88%B6%E5%BE%A1%28ST7032i%29)
