#!/bin/bash
cd "$(dirname "$0")"
cd ../build
CMake ..
make slibro