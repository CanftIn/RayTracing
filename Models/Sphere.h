/*
	Copyright (c) 2018 by CanftIn <wwc7033@gmail.com>
	contact me at https://weibo.com/5632002270/profile
	or http://www.canftin.com
	MIT licence
*/

#ifndef SPHERE_H_
#define SPHERE_H_

#include "Object.h"
#include "../Scene/Color.h"
#include "../Math/Vec3.h"

namespace CAN
{
    class Sphere : public Object
    {
        using vec = Vector3;

    private:
        vec center;
        double radius;
        Color color;

    public:
        Sphere()
        {
            center = vec(0, 0, 0);
            radius = 1.0;
            color = Color(0.5, 0.5, 0.5, 0);
        }

        Sphere(vec centerValue, double radiusValue, Color colorValue)
        {
            center = centerValue;
            radius = radiusValue;
            color = colorValue;
        }

        vec getSphereCenter () { return center; }
        double getSphereRadius () { return radius; }
        virtual Color getColor () { return color; }

        virtual vec getNormalAt(vec point) 
        {
            // normal always points away from the center of a sphere
            vec normal_Vect = (point - center).Normalize();
            return normal_Vect;
	    }

        virtual double findIntersection(Ray ray)
        {
            vec ray_origin = ray.getRayOrigin();
            double ray_origin_x = ray_origin.x;
            double ray_origin_y = ray_origin.y;
            double ray_origin_z = ray_origin.z;

            vec ray_direction = ray.getRayDirection();
            double ray_direction_x = ray_direction.x;
            double ray_direction_y = ray_direction.y;
            double ray_direction_z = ray_direction.z;

            vec sphere_center = center;
            double sphere_center_x = sphere_center.x;
            double sphere_center_y = sphere_center.y;
            double sphere_center_z = sphere_center.z;

            double a = 1; // normalized
            double b = (2 * (ray_origin_x - sphere_center_x) * ray_direction_x)
                     + (2 * (ray_origin_y - sphere_center_y) * ray_direction_y) 
                     + (2 * (ray_origin_z - sphere_center_z) * ray_direction_z);
            double c = pow(ray_origin_x - sphere_center_x, 2) 
                     + pow(ray_origin_y - sphere_center_y, 2) 
                     + pow(ray_origin_z - sphere_center_z, 2) 
                     - (radius * radius);

            double discriminant = b * b - 4 * c;

            if (discriminant > 0)
            {
                /// the ray intersects the sphere

                // the first root
                double root_1 = ((-1 * b - sqrt(discriminant)) / 2) - 0.000001;

                if (root_1 > 0)
                {
                    // the first root is the smallest positive root
                    return root_1;
                }
                else
                {
                    // the second root is the smallest positive root
                    double root_2 = ((sqrt(discriminant) - b) / 2) - 0.000001;
                    return root_2;
                }
            }
            else
            {
                // the ray missed the sphere
                return -1;
            }
        }
    };
}

#endif // !SPHERE_H_

