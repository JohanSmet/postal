This directory contains the build files of the port to the original Microsoft XBox.
The port was done using [nxdx](https://github.com/XboxDev/nxdk), the open-source SDK for original XBox. It does not make use of any leaked, offical XDK.

This port will not function on a stock Xbox, you need a modded Xbox as this is not an official, signed, release.


# Dependencies
To avoid unnecessary download, for platform you might not be interested in, no external sdk/library has been included (as submodule or otherwise).
You will need to obtain a copy of the nxdk manually. The easiest way is to clone the github repository.
``` 
git clone --recurse https://github.com:XboxDev/nxdk.git <nxdk_dir>
``` 

# Build instructions

Retrieve the source code
``` bash
git clone https://github.com/JohanSmet/postal.git

``` 

Copy the game binaries to the `xbox_nxdk/bin` directory. At least the following should be available:
 - `POSTAL.INI`
 - The entire  `res` subdirectory.

Build
``` bash
<nxdk_dir>/bin/activate
make -j <number of cores>
``` 

If the build succeeds a `postal.iso` should be available to be used on your Xbox.

# Remarks
A build script for GitHub Actions is included in the repository (see [build_xbox_nxdk.yml](../.github/workflows/build_xbox_nxdk.yml)).
