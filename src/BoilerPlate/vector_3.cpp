#include "vector_3.hpp"
#include <cmath>

namespace engine
{
	/*Default constructor*/
	vector_3::vector_3()
	{
		mX = 0.0f;
		mY = 0.0f;
		mZ = 0.0f;
		mLength = 0.0f;
	}

	/*Parameterized constructor. Sets the x, y and z values to the specified ones*/
	vector_3::vector_3(float pXValue, float pYValue, float pZValue)
	{
		mX = pXValue;
		mY = pYValue;
		mZ = pZValue;
		mLength = length();
	}

	/*Parameterized constructor. Sets the x, y and z values to the same specified value*/
	vector_3::vector_3(float pValue)
	{
		mX = pValue;
		mY = pValue;
		mZ = pValue;
		mLength = length();
	}

	/*Returns vector's length*/
	float vector_3::length() const
	{
		return sqrt(mX * mX + mY * mY + mZ * mZ);
	}

	/*Returns length raised to the power of 2*/
	float vector_3::squared_length() const
	{
		return (mX * mX + mY * mY + mZ * mZ);
	}

	/*Divides x, y and z values by vector's length*/
	float vector_3::normalize()
	{
		float inverseScale = 1.0f / mLength;
		mX *= inverseScale;
		mY *= inverseScale;
		mZ *= inverseScale;

		//Calculate new length
		mLength = length();

		return mLength;
	}

	vector_3& vector_3::operator=(const vector_3& pAVector3)
	{
		//Prevent self assignment
		if (this == &pAVector3)
			return *this;

		mX = pAVector3.mX;
		mY = pAVector3.mY;
		mZ = pAVector3.mZ;

		//Calculate new length
		mLength = length();

		return *this;
	}

	vector_3& vector_3::operator+=(const vector_3& pAVector3)
	{
		mX = mX + pAVector3.mX;
		mY = mY + pAVector3.mY;
		mZ = mZ + pAVector3.mZ;

		//Calculate new length
		mLength = length();

		return *this;
	}

	vector_3& vector_3::operator-=(const vector_3& pAVector3)
	{
		mX = mX - pAVector3.mX;
		mY = mY - pAVector3.mY;
		mZ = mZ - pAVector3.mZ;

		//Calculate new length
		mLength = length();

		return *this;
	}

	vector_3& vector_3::operator*=(const vector_3& pAVector3)
	{
		mX = mX * pAVector3.mX;
		mY = mY * pAVector3.mY;
		mZ = mZ * pAVector3.mZ;

		//Calculate new length
		mLength = length();

		return *this;
	}

	vector_3& vector_3::operator/=(const vector_3& pAVector3)
	{
		if (pAVector3.mX == 0) throw "Can't divide by zero";
		if (pAVector3.mY == 0) throw "Can't divide by zero";

		mX = mX / pAVector3.mX;
		mY = mY / pAVector3.mY;
		mZ = mZ / pAVector3.mZ;

		//Calculate new length
		mLength = length();

		return *this;
	}

	/*Calculates resulting coordinates of the addition and returns them as a new vector*/
	vector_3 vector_3::operator+(const vector_3& pAVector3) const
	{
		float xValue = mX + pAVector3.mX;
		float yValue = mY + pAVector3.mY;
		float zValue = mZ + pAVector3.mZ;

		return vector_3(xValue, yValue, zValue);
	}

	/*Calculates resulting coordinates of the subtraction and returns them as a new vector*/
	vector_3 vector_3::operator-(const vector_3& pAVector3) const
	{
		float xValue = mX - pAVector3.mX;
		float yValue = mY - pAVector3.mY;
		float zValue = mZ - pAVector3.mZ;

		return vector_3(xValue, yValue, zValue);
	}

	/*Calculates resulting coordinates of the multiplication and returns them as a new vector*/
	vector_3 vector_3::operator*(const vector_3& pAVector3) const
	{
		float xValue = mX * pAVector3.mX;
		float yValue = mY * pAVector3.mY;
		float zValue = mZ * pAVector3.mZ;

		return vector_3(xValue, yValue, zValue);
	}

	/*Calculates resulting coordinates of the division and returns them as a new vector*/
	vector_3 vector_3::operator/(const vector_3& pAVector3) const
	{
		if (pAVector3.mX == 0) throw "Can't divide by zero";
		if (pAVector3.mY == 0) throw "Can't divide by zero";

		float xValue = mX / pAVector3.mX;
		float yValue = mY / pAVector3.mY;
		float zValue = mZ / pAVector3.mZ;

		return vector_3(xValue, yValue, zValue);
	}

	bool vector_3::operator==(const vector_3& pAVector3)const
	{
		return mX == pAVector3.mX && mY == pAVector3.mY && mZ == pAVector3.mZ;
	}

	bool vector_3::operator!=(const vector_3& pAVector3)const
	{
		return mX != pAVector3.mX || mY != pAVector3.mY || mZ != pAVector3.mZ;
	}

	/*Calculates resulting coordinates of the multiplication by a value and returns them as a new vector*/
	vector_3 operator*(float pValue, const vector_3& pAVector3)
	{
		float xValue = pValue * pAVector3.mX;
		float yValue = pValue * pAVector3.mY;
		float zValue = pValue * pAVector3.mZ;

		return vector_3(xValue, yValue, zValue);
	}

	/*Calculates resulting coordinates of the multiplication by a value and returns them as a new vector*/
	vector_3 operator*(const vector_3& pAVector3, float pValue)
	{
		float xValue = pValue * pAVector3.mX;
		float yValue = pValue * pAVector3.mY;
		float zValue = pValue * pAVector3.mZ;

		return vector_3(xValue, yValue, zValue);
	}

	vector_3 vector_3::cross_product(const vector_3& pLeftSide, const vector_3& pRightSide)
	{
		vector_3 resultVector;
		resultVector.mX = pLeftSide.mY * pRightSide.mZ - pLeftSide.mZ * pRightSide.mY;
		resultVector.mY = pLeftSide.mZ * pRightSide.mX - pLeftSide.mX * pRightSide.mZ;
		resultVector.mZ = pLeftSide.mX * pRightSide.mY - pLeftSide.mY * pRightSide.mX;

		return resultVector;
	}
}
