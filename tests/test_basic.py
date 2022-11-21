import bpy

import HinaPE_py as hn

bpy.ops.mesh.primitive_cube_add(size=1)


def test_main():
    # assert m.__version__ == "0.0.1"
    # assert m.add(1, 2) == 3
    # assert m.subtract(1, 2) == -1
    hn.add(1, 2)
    print("Hello Blender")
