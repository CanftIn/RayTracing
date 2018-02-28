/*
	Copyright (c) 2018 by CanftIn <wwc7033@gmail.com>
	contact me at https://weibo.com/5632002270/profile
	or http://www.canftin.com
	MIT licence
*/

#ifndef PLANE_H_
#define PLANE_H_

#include "../Scene/Object.h"
#include "../Math/Vec3.h"
#include "../Scene/Color.h"

namespace CAN
{
    class Plane : public Object
    {
        using vec = Vector3;

    private:
        vec normal;
        float distance;
        Color color;

    public:
        Plane()
        {
            normal = vec(1, 0, 0);
            distance = 0;
            color = Color(0.5, 0.5, 0.5, 0);
        }

        Plane(vec normalValue, double distanceValue, Color colorValue)
        {
            normal = normalValue;
            distance = distanceValue;
            color = colorValue;
        }

        // method functions
        vec getPlaneNormal() { return normal; }
        double getPlaneDistance() { return distance; }
        virtual Color getColor() { return color; }

        virtual vec getNormalAt(vec point)
        {
            return normal;
        }

        virtual double findIntersection(Ray ray)
        {
            vec ray_direction = ray.getRayDirection();
            vec ray_dot = ray_direction * normal;
            double a = ray_dot.Sum();

            if (a == 0)
            {
                // ray is parallel to the plane
                return -1;
            }
            else
            {
                vec b_dot = normal * ( ray.getRayOrigin() - (normal * (distance)) );
                double b = b_dot.Sum();
                return -1 * b / a;
            }
        }
    };
}

#endif // !PLANE_H_
