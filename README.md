# cuModule "invalid ptx" reproducer

Reproducer for cuModule "invalid ptx" error that arises supplying isResident operand to tex2DGrad.
Reported on OptiX developer forums:
https://forums.developer.nvidia.com/t/migrating-from-optix-7-2-to-7-5-demandloading-problems/240509

Note: this repository contains the [OptiX Toolkit DemandLoading
repository](https://github.com/NVIDIA/otk-demand-loading) as a submodule.  After checking out this
repository, use `git submodule update --init` to initialize the submodule.

The DemandLoading library requires the OptiX SDK, the location of which should be 
specified at configuration time via the `OptiX_INSTALL_DIR` configuration variable, e.g. 
```
cmake -DOptiX_INSTALL_DIR=/usr/local/NVIDIA-OptiX-SDK-7.6 
```
