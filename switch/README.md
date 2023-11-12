This directory contains the build files of the port to the Nintendo Switch.
The port was done using [devkitA64](https://devkitpro.org/wiki/Getting_Started). It does not make use of any leaked, official, SDK.

This port will not function on a stock Switch, you need a Switch with Custom Firmware as this is not an official, signed, release.

# Dependencies
To avoid unnecessary downloads, for platforms you might not be interested in, no external sdk/library has been included (as a submodule or otherwise).
You will need to obtain and install devkitA64 on your development system. Installation instructions can be found on the devkitA64 homepage.

# Build instructions
Retrieve the source code
```bash
git clone https://github.com/JohanSmet/postal.git
```
Copy the game binaries to the switch/romfs directory. At least the following should be available:
- `POSTAL.INI`
- The entire `res` subdirectory.

Build
```bash
cmake -B _build -DCMAKE_TOOLCHAIN_FILE=<devkitpro-dir>/cmake/Switch.cmake
cmake --build _build --parallel <number of cores>
```
If the build succeeds a `PostalSwitch.nro` should be available in the build directory to be used on your Switch.

# Debugging with GDB
Please refer to the excellent [guide](https://gist.github.com/jam1garner/c9ba6c0cff150f1a2480d0c18ff05e33) by jam1garner.

To summarize:
- Ensure the GDB stub is correctly setup on your Switch console.
- start GDB: `/opt/devkitpro/devkitA64/bin/aarch64-none-elf-gdb`
  - connect to the switch: `target extended-remote <ip address>:22225`
  - find the pid of `hbloader`: `info os processes`
  - attach to `hbloader`: `attach <pid>`
  - continue running hbloader: `c`
  - start postal on your Switch console. GDB should break automatically.
  - find out where the  `postal.elf` module was loaded in memory: `monitor get info`
  - load the symbols: `symbol-file _build/postal.elf -o <address>`
  - you can now start debugging


