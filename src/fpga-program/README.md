fpga-program - Program FPGA programmable logic using Fpga Region
============

What is this?
-------------

This is a script to program the programmable logic of FPGA by using Fpga Region technique.

It accepts a **little-endian** `.bin` file that is generated by Xilinx vivado.

Usage
-------

Show usage:
```console
$ fpga-program
USAGE: fpga-program little-endian.bin
```

Program FPGA:
```console
$ fpga-program little-endian.bin
```

NOTE: This script automatically convert the given **little-endian** `.bin`
file to **big-endian** format and program FPGA by using the converted `.bin` file.
So, DO NOT give a **big-endian** `.bin` file to this script.

Reference
---------
* [電気回路/zynq/Petalinux2018.3でPLとDevice Treeを動的に変更する - 武内＠筑波大 #gb07ac62](https://dora.bk.tsukuba.ac.jp/~takeuchi/?%E9%9B%BB%E6%B0%97%E5%9B%9E%E8%B7%AF%2Fzynq%2FPetalinux2018.3%E3%81%A7PL%E3%81%A8Device%20Tree%E3%82%92%E5%8B%95%E7%9A%84%E3%81%AB%E5%A4%89%E6%9B%B4%E3%81%99%E3%82%8B#gb07ac62)