fpga - A init.d script that initializes and finalizes fpga
==========================================================

What is this?
-------------

This is an init.d script that is  to initialize and to finalize fpga.

It will:
- program FPGA programmable logic with using `/boot/design*.bin`
- setup device tree by overlaying  `/boot/dtso/*.dtso`
- invoke init.d files `/boot/fpga_init.d/*`

Install
-------

Place **little-endian** formatted *.bin* file at `/boot` like `/boot/design_1_wrapper.bin`.
Thie file name must be matched by the wild card `/boot/design*.bin`.

Place device tree source fragmen for device tree overlay as `/boot/dtso/*.dtso*`.
The files will be processed in the alphabetical order at `start` and in the opposite order at `stop`.

Place `init.d` type scripts at `/boot/fpga_init.d/` to be processed.
The files will be processed in the alphabetical order at `start` and in the opposite order at `stop`.

Copy the script `fpga` into `/etc/init.d/` and setup auto start at boot time with creating a symbolic links in `/etc/rc?.d/` by `update-rc.d`.

Reference
---------
* [電気回路/zynq/自動起動の設定 - 武内＠筑波大 #rfb55e43](https://dora.bk.tsukuba.ac.jp/~takeuchi/?%E9%9B%BB%E6%B0%97%E5%9B%9E%E8%B7%AF%2Fzynq%2F%E8%87%AA%E5%8B%95%E8%B5%B7%E5%8B%95%E3%81%AE%E8%A8%AD%E5%AE%9A#rfb55e43)
