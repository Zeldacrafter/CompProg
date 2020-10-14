#!/bin/bash

tmp_dir=$(mktemp -d)
echo $tmp_dir

find . -name '*.cc' | while read line; do
    line=${line/.\//}
    echo "trying to compile $line"
    out="$tmp_dir/${line//\//-}"
    g++ -c -Wall -Wextra -Wshadow -Wpedantic -std=c++17 -o $out $line
done

rm -r $tmp_dir

