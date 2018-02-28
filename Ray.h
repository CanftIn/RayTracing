/*
	Copyright (c) 2018 by CanftIn <wwc7033@gmail.com>
	contact me at https://weibo.com/5632002270/profile
	or http://www.canftin.com
	MIT licence
*/

#ifndef RAY_H_
#define RAY_H_

#include "./Math/Vec3.h"

namespace CAN
{
    class Ray
    {
        using vec = Vector3;
    private:
        vec mOrigin, mDirection;

    public:
        Ray() : mOrigin(vec(CAN_ZERO, CAN_ZERO, CAN_ZERO))
              , mDirection(vec(CAN_ONE, CAN_ZERO, CAN_ZERO)) 
        {}

        Ray(vec origin, vec direction) : mOrigin(origin), mDirection(direction) {}

        vec getRayOrigin() { return mOrigin; }

        vec getRayDirection() { return mDirection; }
    };
}


#endif // !RAY_H_
