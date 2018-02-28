/*
	Copyright (c) 2018 by CanftIn <wwc7033@gmail.com>
	contact me at https://weibo.com/5632002270/profile
	or http://www.canftin.com
	MIT licence
*/

#ifndef OBJECT_H_
#define OBJECT_H_

#include "Ray.h"
#include "./Math/Vec3.h"
#include "Color.h"

namespace CAN
{
    class Object
    {
        using vec = Vector3;

    public:
        Object() {}

        // method functions
        virtual Color getColor() { return Color(CAN_ZERO, CAN_ZERO, CAN_ZERO, CAN_ZERO); }

        virtual vec getNormalAt(vec intersection_position)
        {
            return vec(CAN_ZERO, CAN_ZERO, CAN_ZERO);
        }

        virtual double findIntersection(Ray ray)
        {
            return 0;
        }
    };
}

#endif // !OBJECT_H_