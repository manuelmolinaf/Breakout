#pragma once

#ifndef MATH_UTILITIES_HPP_INCLUDED
#define MATH_UTILITIES_HPP_INCLUDED

#include <math.h>
#include <cmath>
#include <cstdlib>
#include "stdarg.h"
#include <vector>
#include <time.h> 
#include <stdlib.h> 
#define PI 3.14159265358979323846

namespace engine
{
	namespace math
	{
			class math_utilities
			{

			public:
				int float_round_to_int(float pX);
				int float_round_to_even_int(float pX);
				template <class T>
				T get_max(T pA, T pB);
				template <class T>
				T get_max(T pA, T pB, T pC);
				template <class T>
				T get_max(T pA, T pB, T pC, T pD);
				template <class T>
				T get_min(T pA, T pB);
				template <class T>
				T get_min(T pA, T pB, T pC);
				template <class T>
				T get_min(T pA, T pB, T pC, T pD);

				float degrees_to_radians(float pAngle);
				float radians_to_degrees(float pAngle);
				int angular_distance(int pX, int pX2);
				template <class T>
				T clamp(T pX, T pMin, T pMax);
				bool is_power_of_two(int pX);
				int float_interpolate(float pX, int pMin, int pMax);
				float random_in_range(int pMin, int pMax);
				float calculate_distance(float pX1, float pY1, float pX2, float pY2);

			};
	}
}

#endif // MATH_UTILITIES_HPP_INCLUDED