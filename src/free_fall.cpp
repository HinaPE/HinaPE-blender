#include "free_fall.h"

HinaPE::FreeFall::FreeFall()
{
    _position = Vector3F(0.0f, 0.0f, 0.0f);
    _velocity = Vector3F(0.0f, 0.0f, 0.0f);
    _acceleration = Vector3F(0.0f, -9.8f, 0.0f);
    _floor_level = -5.0f;
}

HinaPE::Vector3F HinaPE::FreeFall::get_position()
{
    return _position;
}
void HinaPE::FreeFall::step(float dt)
{
    _velocity = _velocity + _acceleration * dt;
    _position = _position + _velocity * dt;
    if (_position.y < _floor_level)
    {
        _position.y = _floor_level;
        _velocity.y = std::abs(_velocity.y * 0.999); // 为防止帧率过高导致的穿地现象，这里取绝对值。（因为有可能在两帧很快的时间内，速度反向两次）
    }
}
