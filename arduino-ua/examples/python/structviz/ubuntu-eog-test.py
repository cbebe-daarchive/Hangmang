"""
    Test program for Ubuntu that uses eog image viewer
"""


import subprocess
from structviz import StructViz

v = StructViz()
w = StructViz()

# v.analyze_struct(v)


def update_dot(v, obj, filename, style='compact'):
    dotname = filename + '.dot'
    f = open(dotname, "w", encoding="utf-8")
    v.analyze_struct(obj)
    if style == 'compact':
        rep = v.gen_compact_dot_desc()
    else:
        rep = v.gen_detailed_dot_desc()
    f.write(rep)
    f.close()
    # now generate the image file and it will be refreshed
    subprocess.call(["dot", "-Tpng", dotname, "-O"])


def pause():
    input("continue?")


dump_w = True


class CC:
    def __init__(self):
        self._xxx = {1, 2, 3}
        self._yyy = [33, 44, 55, 66]


cc = CC()

print("Testing ...\n")

tb = 42
tc = tb

# I want a lambda here!
f = lambda x: x
x = [42]
s = {'x'}
h = {'a': 33, 'b': 44, 2: 55}
obj = (cc, [f, h], x, s, 42, (42, 43, 44))
# obj = [ f ]
# obj = tb

update_dot(v, obj, "testo", style='object')
update_dot(v, obj, "testc")
if dump_w:
    update_dot(w, v, "testi", style='object')
if dump_w:
    update_dot(w, v, "testic")
