/*
	Copyright (c) 2018 by CanftIn <wwc7033@gmail.com>
	contact me at https://weibo.com/5632002270/profile
	or http://www.canftin.com
	MIT licence
*/

#ifndef LIGHT_H_
#define LIGHT_H_

#include "Color.h"
#include "./Math/Vec3.h"

namespace CAN
{
	class Source
	{
		using vec = Vector3;

	public:
		Source() {}

		virtual vec getLightPosition() { return vec(CAN_ZERO, CAN_ZERO, CAN_ZERO); }
		virtual Color getLightColor() { return Color(CAN_ONE, CAN_ONE, CAN_ONE, CAN_ZERO); }
	};

	class Light : public Source
	{
		using vec = Vector3;

	private:
		vec position;
		Color color;

	public:
		Light() : position(vec(CAN_ZERO, CAN_ZERO, CAN_ZERO))
				, color(Color(CAN_ONE, CAN_ONE, CAN_ONE, CAN_ZERO)) 
		{}

		Light(vec p, Color c) : position(p), color(c) {}

		// method functions
		virtual vec getLightPosition() { return position; }
		virtual Color getLightColor() { return color; }
	};
}

#endif // !LIGHT_H_