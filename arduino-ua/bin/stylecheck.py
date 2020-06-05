import sys
import os
from linter import pycodestyle, cpplint, verify_indent

py_ext = ".py"
cpp_ext = ".cpp"
extensions = {py_ext, cpp_ext}


class Colour:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'


def print_error(error, bold=False):
    output = Colour.BOLD if bold else ''
    output += Colour.FAIL + error + Colour.ENDC
    print(output)


if __name__ == "__main__":
    files = sys.argv[1:]
    cwd = os.getcwd()
    if len(files) > 0:
        print(Colour.BOLD + Colour.HEADER +
              "Parsing File(s): {}".format(", ".join(files)) + Colour.ENDC)
        for file in files:
            print()
            file_dir = "{}/{}".format(cwd, file)
            file_path, file_extension = os.path.splitext(file_dir)
            if len(file_extension) <= 0:
                print_error("ERROR: '{}' does not have an extension."
                            .format(file), True)
                print_error("Please provide a valid '.py' or '.cpp' extension")
                continue
            if not os.path.exists(file_dir):
                print_error("ERROR: '{}' file could not be found."
                            .format(file), True)
                print_error(file_dir)
                continue
            if file_extension not in extensions:
                print_error("ERROR: '{}' is not a supported "
                            "extension for file '{}'."
                            .format(file_extension, file), True)
                continue
            # Determine if Python or C++ Program.
            if file_extension == py_ext:
                print(Colour.OKBLUE + "Showing error log for '{}'"
                            .format(file) + Colour.ENDC)
                s = pycodestyle.StyleGuide()
                s.input_file(file)
                print(Colour.OKBLUE + "End of error log for '{}'"
                            .format(file) + Colour.ENDC)
            elif file_extension == cpp_ext:
                print(Colour.OKBLUE + "Showing error log for '{}'"
                            .format(file) + Colour.ENDC)
                print(Colour.BOLD, end='')
                verify_indent.main(file)
                print(Colour.ENDC, end='', flush=True)
                cpplint.main(["--filter=-legal/copyright, "
                              "-build/namespaces, "
                              "-build/namespaces_literals, "
                              "-whitespace/tab",
                              "--quiet", file])
                print(Colour.OKBLUE + "End of error log for '{}'"
                            .format(file) + Colour.ENDC)
            else:
                print_error("ERROR: Invalid Extension (This error "
                            "should *not* be possible, please report this)")
                continue

        print(Colour.BOLD + "\r\ndone" + Colour.ENDC)

    else:
        print("ERROR: Please provide file name(s) to check.")
        print("Example Usage: 'style [file1 file2 file3]'")
