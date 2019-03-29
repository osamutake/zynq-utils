flip32 - Flip byte order of 32bit word data
============================

What is this?
--------------

A small utility that flip the byte order of all 32bit values in a file.

Usage
-------

```console
$ flip32 input.file > output.file
```

Whay is this needed?
------------------------

Xilinx fpga region technology allows us to program the FPGA programable logic without reboot.
However, it requires a **big-endian** binary file to be programmed into a FPGA.

On the other hand, Xilinx vivado generates **little-endian** binary file that can not be used by fpga region process.

``flip32`` converts the **little-endian** bin file to a **big-endian** bin file to fill the gap.

```console
$ flip32 little-endian.bin > big-endian.bin
```

Reference
---------
* [電気回路/zynq/Petalinux2018.3でPLとDevice Treeを動的に変更する - 武内＠筑波大 #zb2c4ddb](https://dora.bk.tsukuba.ac.jp/~takeuchi/?%E9%9B%BB%E6%B0%97%E5%9B%9E%E8%B7%AF%2Fzynq%2FPetalinux2018.3%E3%81%A7PL%E3%81%A8Device%20Tree%E3%82%92%E5%8B%95%E7%9A%84%E3%81%AB%E5%A4%89%E6%9B%B4%E3%81%99%E3%82%8B#zb2c4ddb)
