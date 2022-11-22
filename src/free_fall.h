#ifndef HINAPE_PY_FREE_FALL_H
#define HINAPE_PY_FREE_FALL_H

#include "math/vector3.h"

namespace HinaPE
{
class FreeFall
{
public:
    Vector3F get_position();
    void step(float dt);

public:
    FreeFall();

private:
    Vector3F _position;
    Vector3F _velocity;
    Vector3F _acceleration;
    float _floor_level;
};
}

#endif //HINAPE_PY_FREE_FALL_H
