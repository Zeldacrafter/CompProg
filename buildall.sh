#!/bin/bash

tmp_dir=$(mktemp -d)
echo $tmp_dir

find . -name '*.cc' | while read line; do
    line=${line/.\//}
    echo "trying to compile $line"
    out="$tmp_dir/${line//\//-}"
    clang++ -c -Wall -Wextra -Wpedantic -std=gnu++17 -o $out $line
done

rm -r $tmp_dir

