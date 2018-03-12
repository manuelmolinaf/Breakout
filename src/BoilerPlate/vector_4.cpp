#include "vector_4.hpp"
#include <cmath>

namespace engine
{
	/*Default constructor*/
	vector_4::vector_4()
	{
		mX = 0.0f;
		mY = 0.0f;
		mZ = 0.0f;
		mW = 0.0f;
		mLength = 0.0f;
	}

	/*Parameterized constructor. Sets the x, y and z values to the specified ones*/
	vector_4::vector_4(float pXValue, float pYValue, float pZValue, float wValue)
	{
		mX = pXValue;
		mY = pYValue;
		mZ = pZValue;
		mW = wValue;
		mLength = length();
	}

	/*Parameterized constructor. Sets the x, y and z values to the same specified value*/
	vector_4::vector_4(float pValue)
	{
		mX = pValue;
		mY = pValue;
		mZ = pValue;
		mW = pValue;
		mLength = length();
	}

	/*Returns vector's length*/
	float vector_4::length() const
	{
		return sqrt(mX * mX + mY * mY + mZ * mZ + mW * mW);
	}

	/*Returns length raised to the power of 2*/
	float vector_4::squared_length() const
	{
		return (mX * mX + mY * mY + mZ * mZ + mW * mW);
	}

	/*Divides x, y and z values by vector's length*/
	float vector_4::normalize()
	{
		float inverseScale = 1.0f / mLength;
		mX *= inverseScale;
		mY *= inverseScale;
		mZ *= inverseScale;
		mW *= inverseScale;
		//Calculate new length
		mLength = length();

		return mLength;
	}

	vector_4& vector_4::operator=(const vector_4& pAVector4)
	{
		//Prevent self assignment
		if (this == &pAVector4)
			return *this;

		mX = pAVector4.mX;
		mY = pAVector4.mY;
		mZ = pAVector4.mZ;
		mW = pAVector4.mW;

		//Calculate new length
		mLength = length();

		return *this;
	}

	vector_4& vector_4::operator+=(const vector_4& pAVector4)
	{
		mX = mX + pAVector4.mX;
		mY = mY + pAVector4.mY;
		mZ = mZ + pAVector4.mZ;
		mW = mW + pAVector4.mW;
		//Calculate new length
		mLength = length();

		return *this;
	}

	vector_4& vector_4::operator-=(const vector_4& pAVector4)
	{
		mX = mX - pAVector4.mX;
		mY = mY - pAVector4.mY;
		mZ = mZ - pAVector4.mZ;
		mW = mW - pAVector4.mW;
		//Calculate new length
		mLength = length();

		return *this;
	}

	vector_4& vector_4::operator*=(const vector_4& pAVector4)
	{
		mX = mX * pAVector4.mX;
		mY = mY * pAVector4.mY;
		mZ = mZ * pAVector4.mZ;
		mW = mW * pAVector4.mW;
		//Calculate new length
		mLength = length();

		return *this;
	}

	vector_4& vector_4::operator/=(const vector_4& pAVector4)
	{
		if (pAVector4.mX == 0) throw "Can't divide by zero";
		if (pAVector4.mY == 0) throw "Can't divide by zero";
		if (pAVector4.mZ == 0) throw "Can't divide by zero";
		if (pAVector4.mW == 0) throw "Can't divide by zero";

		mX = mX / pAVector4.mX;
		mY = mY / pAVector4.mY;
		mZ = mZ / pAVector4.mZ;
		mW = mW / pAVector4.mW;

		//Calculate new length
		mLength = length();

		return *this;
	}

	/*Calculates resulting coordinates of the addition and returns them as a new vector*/
	vector_4 vector_4::operator+(const vector_4& pAVector4) const
	{
		float xValue = mX + pAVector4.mX;
		float yValue = mY + pAVector4.mY;
		float zValue = mZ + pAVector4.mZ;
		float wValue = mW + pAVector4.mW;

		return vector_4(xValue, yValue, zValue, wValue);
	}

	/*Calculates resulting coordinates of the subtraction and returns them as a new vector*/
	vector_4 vector_4::operator-(const vector_4& pAVector4) const
	{
		float xValue = mX - pAVector4.mX;
		float yValue = mY - pAVector4.mY;
		float zValue = mZ - pAVector4.mZ;
		float wValue = mW - pAVector4.mW;

		return vector_4(xValue, yValue, zValue, wValue);
	}

	/*Calculates resulting coordinates of the multiplication and returns them as a new vector*/
	vector_4 vector_4::operator*(const vector_4& pAVector4) const
	{
		float xValue = mX * pAVector4.mX;
		float yValue = mY * pAVector4.mY;
		float zValue = mZ * pAVector4.mZ;
		float wValue = mW * pAVector4.mW;

		return vector_4(xValue, yValue, zValue, wValue);
	}

	/*Calculates resulting coordinates of the division and returns them as a new vector*/
	vector_4 vector_4::operator/(const vector_4& pAVector4) const
	{
		if (pAVector4.mX == 0) throw "Can't divide by zero";
		if (pAVector4.mY == 0) throw "Can't divide by zero";
		if (pAVector4.mZ == 0) throw "Can't divide by zero";
		if (pAVector4.mW == 0) throw "Can't divide by zero";


		float xValue = mX / pAVector4.mX;
		float yValue = mY / pAVector4.mY;
		float zValue = mZ / pAVector4.mZ;
		float wValue = mW / pAVector4.mW;

		return vector_4(xValue, yValue, zValue, wValue);
	}

	bool vector_4::operator==(const vector_4& pAVector4)const
	{
		return mX == pAVector4.mX && mY == pAVector4.mY && mZ == pAVector4.mZ && mW == pAVector4.mW;
	}

	bool vector_4::operator!=(const vector_4& pAVector4)const
	{
		return mX != pAVector4.mX || mY != pAVector4.mY || mZ != pAVector4.mZ || mW != pAVector4.mW;
	}

	/*Calculates resulting coordinates of the multiplication by a value and returns them as a new vector*/
	vector_4 operator*(float value, const vector_4& pAVector4)
	{
		float xValue = value * pAVector4.mX;
		float yValue = value * pAVector4.mY;
		float zValue = value * pAVector4.mZ;
		float wValue = value * pAVector4.mW;

		return vector_4(xValue, yValue, zValue, wValue);
	}

	/*Calculates resulting coordinates of the multiplication by a value and returns them as a new vector*/
	vector_4 operator*(const vector_4& pAVector4, float pValue)
	{
		float xValue = pValue * pAVector4.mX;
		float yValue = pValue * pAVector4.mY;
		float zValue = pValue * pAVector4.mZ;
		float wValue = pValue * pAVector4.mW;

		return vector_4(xValue, yValue, zValue, wValue);
	}
}