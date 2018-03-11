#include "math_utilities.hpp"

namespace engine
{
	namespace math
	{
		template <class T>

		T math_utilities::get_max(T pA, T pB) {
			T result;
			result = (pA>pB) ? pA : pB;
			return result;
		}

		template <class T>
		T math_utilities::get_max(T pA, T pB, T pC) {
			T result = pA;
			if (pB>result)
				result = pB;
			else if (pC>result)
				result = pC;
			return result;
		}
		template <class T>
		T math_utilities::get_max(T pA, T pB, T pC, T pD) {
			T result = pA;
			if (pB>result)
				result = pB;
			else if (pC > result)
				result = pC;
			else if (pD > result)
				result = pD;
			return result;
		}
		template <class T>
		T math_utilities::get_min(T pA, T pB) {
			T result;
			result = (pA<pB) ? pA : pB;
			return result;
		}
		template <class T>
		T math_utilities::get_min(T pA, T pB, T pC) {
			T result = pA;
			if (pB < result)
				result = pB;
			else if (pC < result)
				result = pC;
			return result;
		}
		template <class T>
		T math_utilities::get_min(T pA, T pB, T pC, T pD) {
			T result = pA;
			if (pB < result)
				result = pB;
			else if (pC < result)
				result = pC;
			else if (pD < result)
				result = pD;
			return result;
		}

		int math_utilities::float_round_to_int(float pX)
		{
			int i = (int)roundf(pX);
			return i;
		}

		int math_utilities::float_round_to_even_int(float pX)
		{
			int i = (int)pX;
			if (i % 2 != 0)
				i++;

			return i;
		}


		float math_utilities::degrees_to_radians(float pAngle)
		{
			return (float)(pAngle * (PI / 180));
		}

		float math_utilities::radians_to_degrees(float pAngle)
		{
			return (float)(pAngle * (180 / PI));
		}


		int math_utilities::angular_distance(int pX, int pX2)
		{
			int result = pX2 - pX;
			if (result < 0)
				result *= -1;
			return result;
		}

		template <class T>
		T math_utilities::clamp(T pX, T pMin, T pMax)
		{
			if (pX < pMin)
				pX = pMin;
			else if (pX > pMax)
				pX = pMax;

			return pX;
		}

		bool math_utilities::is_power_of_two(int pX)
		{
			bool value = false;
			for (int i = 2; i <= pX; i *= 2)
			{
				if (i == pX)
					value = true;
			}
			return value;
		}

		int math_utilities::float_interpolate(float pX, int pMin, int pMax)
		{
			int range = pMax - pMin, result = -1;
			if (pX >= 0 && pX <= 1)
			{
				result = (int)(range * pX);
				result += pMin;
			}
			return result;
		}

		float math_utilities::random_in_range(int pMin, int pMax)
		{

			return (float)(rand() % pMax + pMin);
		}

		float math_utilities::calculate_distance(float pX1, float pY1, float pX2, float pY2)
		{
			return fabs(sqrtf(powf((pX2 - pX1), 2) + powf((pY2 - pY1), 2)));
		}

	}
}