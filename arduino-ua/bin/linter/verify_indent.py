import sys
import tempfile
import subprocess

'''
Known Issues:
    - Inconsistent use of tabs and spaces
    - '{' and '}' in strings and comments
    - Removing comments
'''


def new_block(line):
    if line and line[-1] == '{':
        return True
    return False


def close_block(line):
    if line and line.lstrip()[0] == '}':
        return True
    return False


def get_indent_level(line):
    return len(line) - len(line.lstrip())


def invalid_indent(curr_indent, indent_level):
    return curr_indent != indent_level


def print_error(file_name, index):
    print("{}:{}:  Potential indentation error, "
          "verify proper indentation.".format(file_name, index))


def iterate_file(file, file_name):
    indent_level = [0]
    block_update = False
    for index, line in enumerate(file):
        line = line.decode().rstrip()
        if not line:
            continue
        curr_indent = get_indent_level(line)
        if block_update:
            if curr_indent <= indent_level[-1]:
                print_error(file_name, index+1)
                return
            indent_level.append(curr_indent)
            block_update = False
        if new_block(line):
            block_update = True
        if close_block(line):
            if curr_indent >= indent_level[-1]:
                print_error(file_name, index+1)
                return
            indent_level.pop()
            continue
        if invalid_indent(curr_indent, indent_level[-1]):
            print_error(file_name, index+1)
            return


def main(fp=None):
    if not fp:
        fp = sys.argv[1]
    with tempfile.TemporaryFile() as f:
        cmd = ["gcc", "-fpreprocessed", "-dD", "-E", "-P", fp]
        proc = subprocess.Popen(cmd, stdout=f)
        proc.wait()
        f.seek(0)
        try:
            iterate_file(f, fp)
        except:
            print("{}:{}:  Indentation verification failed!".format(fp, 0))


if __name__ == "__main__":
    main()
