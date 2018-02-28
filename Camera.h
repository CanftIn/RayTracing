/*
	Copyright (c) 2018 by CanftIn <wwc7033@gmail.com>
	contact me at https://weibo.com/5632002270/profile
	or http://www.canftin.com
	MIT licence
*/

#ifndef CAMERA_H_
#define CAMERA_H_

#include "./Math/Vec3.h"

namespace CAN
{
    class Camera
    {
        using vec = Vector3;
    private:
        vec vCampos, vCamdir, vCamright, vCamdown;

    public:
        Camera()
            : vCampos(vec(CAN_ZERO, CAN_ZERO, CAN_ZERO))
            , vCamdir(vec(CAN_ZERO, CAN_ZERO, CAN_ONE))
            , vCamright(vec(CAN_ZERO, CAN_ZERO, CAN_ZERO))
            , vCamdown(vec(CAN_ZERO, CAN_ZERO, CAN_ZERO))
        {}

        Camera(vec pos, vec dir, vec right, vec down)
            : vCampos(pos)
            , vCamdir(dir)
            , vCamright(right)
            , vCamdown(down)
        {}

        vec getCameraPosition() { return vCampos; }
        vec getCameraDirection() { return vCamdir; }
        vec getCameraRight() { return vCamright; }
        vec getCameraDown() { return vCamdown; }
    };
}

#endif // !CAMERA_H_
