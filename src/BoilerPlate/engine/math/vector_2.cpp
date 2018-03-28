#include "vector_2.hpp"
#include <cmath>

namespace engine
{
	namespace math
	{
		/*Default constructor*/
		vector_2::vector_2()
		{
			mX = 0.0f;
			mY = 0.0f;
			mLength = 0.0f;
		}

		/*Parameterized constructor. Sets the x and y values to the specified ones*/
		vector_2::vector_2(float pXValue, float pYValue)
		{
			mX = pXValue;
			mY = pYValue;
			mLength = length();
		}

		/*Parameterized constructor. Sets the x and y values to the same specified value*/
		vector_2::vector_2(float pValue)
		{
			mX = pValue;
			mY = pValue;
			mLength = length();
		}

		/*Returns vector's length*/
		float vector_2::length() const
		{
			return std::fabs(std::sqrtf(mX * mX + mY * mY));
		}

		/*Returns length raised to the power of 2*/
		float vector_2::squared_length() const
		{
			return (mX * mX + mY * mY);
		}

		/*Divides x and y values by vector's length*/
		float vector_2::normalize()
		{
			float inverseScale = 1.0f / mLength;
			mX *= inverseScale;
			mY *= inverseScale;

			//Calculate new length
			mLength = length();

			return mLength;
		}

		vector_2& vector_2::operator=(const vector_2& pAVector2)
		{
			//Prevent self assignment
			if (this == &pAVector2)
				return *this;

			mX = pAVector2.mX;
			mY = pAVector2.mY;

			//Calculate new length
			mLength = length();

			return *this;
		}

		vector_2& vector_2::operator+=(const vector_2& pAVector2)
		{
			mX = mX + pAVector2.mX;
			mY = mY + pAVector2.mY;

			//Calculate new length
			mLength = length();

			return *this;
		}

		vector_2& vector_2::operator-=(const vector_2& pAVector2)
		{
			mX = mX - pAVector2.mX;
			mY = mY - pAVector2.mY;

			//Calculate new length
			mLength = length();

			return *this;
		}

		vector_2& vector_2::operator*=(const vector_2& pAVector2)
		{
			mX = mX * pAVector2.mX;
			mY = mY * pAVector2.mY;

			//Calculate new length
			mLength = length();

			return *this;
		}

		vector_2& vector_2::operator/=(const vector_2& pAVector2)
		{
			if (pAVector2.mX == 0) throw "Can't divide by zero";
			if (pAVector2.mY == 0) throw "Can't divide by zero";

			mX = mX / pAVector2.mX;
			mY = mY / pAVector2.mY;

			//Calculate new length
			mLength = length();

			return *this;
		}

		/*Calculates resulting coordinates of the addition and returns them as a new vector*/
		vector_2 vector_2::operator+(const vector_2& pAVector2) const
		{
			float xValue = mX + pAVector2.mX;
			float yValue = mY + pAVector2.mY;

			return vector_2(xValue, yValue);
		}

		/*Calculates resulting coordinates of the subtraction and returns them as a new vector*/
		vector_2 vector_2::operator-(const vector_2& pAVector2) const
		{
			float xValue = mX - pAVector2.mX;
			float yValue = mY - pAVector2.mY;

			return vector_2(xValue, yValue);
		}

		/*Calculates resulting coordinates of the multiplication and returns them as a new vector*/
		vector_2 vector_2::operator*(const vector_2& pAVector2) const
		{
			float xValue = mX * pAVector2.mX;
			float yValue = mY * pAVector2.mY;

			return vector_2(xValue, yValue);
		}

		/*Calculates resulting coordinates of the division and returns them as a new vector*/
		vector_2 vector_2::operator/(const vector_2& pAVector2) const
		{
			if (pAVector2.mX == 0) throw "Can't divide by zero";
			if (pAVector2.mY == 0) throw "Can't divide by zero";

			float xValue = mX / pAVector2.mX;
			float yValue = mY / pAVector2.mY;

			return vector_2(xValue, yValue);
		}

		bool vector_2::operator==(const vector_2& pAVector2)const
		{
			return mX == pAVector2.mX && mY == pAVector2.mY;
		}

		bool vector_2::operator!=(const vector_2& pAVector2)const
		{
			return mX != pAVector2.mX || mY != pAVector2.mY;
		}

		/*Calculates resulting coordinates of the multiplication by a value and returns them as a new vector*/
		vector_2 operator*(float pValue, const vector_2& pAVector2)
		{
			float xValue = pValue * pAVector2.mX;
			float yValue = pValue * pAVector2.mY;

			return vector_2(xValue, yValue);
		}

		/*Calculates resulting coordinates of the multiplication by a value and returns them as a new vector*/
		vector_2 operator*(const vector_2& pAVector2, float pValue)
		{
			float xValue = pValue * pAVector2.mX;
			float yValue = pValue * pAVector2.mY;

			return vector_2(xValue, yValue);
		}
	}

}

