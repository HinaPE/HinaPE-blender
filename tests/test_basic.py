import bpy

import HinaPE_py as hina

bpy.ops.mesh.primitive_cube_add(size=1)


def test_main():
    print(hina.add(1, 2))
    test = hina.Test(12, 2)
    print(test.add())
    print(test.add())
    print(test.add())
    print(test.add())
    free_fall = hina.FreeFall()
    n = 20
    while n > 0:
        free_fall.step(0.2)
        print(free_fall.get_position().y)
        n = n - 1
