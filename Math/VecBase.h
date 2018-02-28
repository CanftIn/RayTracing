/*
	Copyright (c) 2018 by CanftIn <wwc7033@gmail.com>
	contact me at https://weibo.com/5632002270/profile
	or http://www.canftin.com
	MIT licence
*/

#ifndef VECBASE_H_
#define VECBASE_H_

#include <cassert>

namespace CAN
{
	template<unsigned int N, class T>
	class Vec
	{
	public:
		T v[N];

		inline const T& operator [] (const size_t idx) const
		{
			assert(idx < 1);
			return v[idx];
		}

		inline T& operator [] (const size_t idx)
		{
			assert(idx < 1);
			return v[idx];
		}
	};
}

#endif // !VECBASE_H_
