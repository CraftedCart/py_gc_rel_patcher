py_gc_rel_patcher
=================

A Python 3 binding for bobjrsenior's GC_Rel_Patcher: https://github.com/bobjrsenior/GC_REL_Patcher

# Cloning
This repo uses a submodule - Make sure you fetch the submoudle when cloning
```shell
git clone --recursive https://github.com/CraftedCart/py_gc_rel_patcher
```
If you've already cloned the repo without fetching the submodule, you can get is like so
```shell
git submodule update --init --recursive
```

**DOWNLOADING A ZIP OR TAR.GZ FROM GITHUB DOES NOT WORK!**  
It doesn't include any submodules in the ZIP or tar.gz

# Building
## Prerequisites
You're going to need Python 3 development headers as well as boost-python installed to compile this

## Compiling
On Unix like systems
```shell
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo ..
make
```

# Sample script
After building, a sample script "sample.py" will exist in the build directory.
Provide "mkb2.main_loop.rel" in the working directory and run the script to perform example modifications on it.
