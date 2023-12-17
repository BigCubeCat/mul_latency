#!/usr/bin/python3

import sys

INPUT_FILE_NAME = "copy.c"
OUTPUT_FILE_NAME = "main.c"

def read_code():
    code = ""
    with open(INPUT_FILE_NAME, "r", encoding="utf-8") as file:
        code = file.read()
    return code


def write_asm_code(code: str):
    with open(OUTPUT_FILE_NAME, "w", encoding="utf-8") as file:
        file.write(code)


if __name__ == "__main__":
    print(sys.argv)
    count = int(sys.argv[1])
    code = read_code()
    code = code.replace("#define N 1", "#define N " + str(count))
    code = code.replace("* b", "* b" * count);
    write_asm_code(code)



