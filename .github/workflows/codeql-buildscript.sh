#!/usr/bin/env bash

sudo apt-get install -y build-essential gcc-multilib curl libmpc-dev python
make confload-x86/qemu
make -j$(nproc)
