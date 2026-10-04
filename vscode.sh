#!/usr/bin/env bash

set -euo pipefail

repo_dir="/home/ske/work/repos/freertos-esp32-learning"
idf_dir="/opt/esp-idf"

if [[ ! -f "$idf_dir/export.sh" ]]; then
    printf 'ESP-IDF was not found at %s\n' "$idf_dir" >&2
    printf 'Install ESP-IDF first; see README.md.\n' >&2
    exit 1
fi

# Prefer the system CMake over the incompatible Xilinx copy.
export PATH="/usr/local/bin:/usr/bin:/bin:$PATH"
source "$idf_dir/export.sh"
cd "$repo_dir"
exec code .