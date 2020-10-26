#!/bin/bash

TMP_DIR=$(mktemp -d)
echo ${TMP_DIR}

COPTIONS="-c -Wall -Wextra -Wshadow -Wpedantic -Werror -Wunused-variable -std=c++17"

EXIT="0"
ERRORS=""

for LINE in $(find . -name '*.cc' | sort); do
    LINE=${LINE/.\//}
    echo "trying to compile ${LINE}"
    OUT="${TMP_DIR}/${LINE//\//-}"
    g++ ${COPTIONS} -o ${OUT} ${LINE} 
    if [ "$?" -ne "0" ]; then
        ERRORS="${ERRORS}  - ${LINE}\n"
        EXIT="1"
    fi 
done

rm -r ${TMP_DIR}

if [ -n "${ERRORS}" ]; then
    echo -ne "Failed for:\n${ERRORS}"
fi

exit ${EXIT}

