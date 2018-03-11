#include "vector_4.hpp"
#include <cmath>

namespace engine
{
	/*Default constructor*/
	vector_4::vector_4()
	{
		m_x = 0.0f;
		m_y = 0.0f;
		m_z = 0.0f;
		m_w = 0.0f;
		m_length = 0.0f;
	}

	/*Parameterized constructor. Sets the x, y and z values to the specified ones*/
	vector_4::vector_4(float pXValue, float pYValue, float pZValue, float wValue)
	{
		m_x = pXValue;
		m_y = pYValue;
		m_z = pZValue;
		m_w = wValue;
		m_length = length();
	}

	/*Parameterized constructor. Sets the x, y and z values to the same specified value*/
	vector_4::vector_4(float pValue)
	{
		m_x = pValue;
		m_y = pValue;
		m_z = pValue;
		m_w = pValue;
		m_length = length();
	}

	/*Returns vector's length*/
	float vector_4::length() const
	{
		return sqrt(m_x * m_x + m_y * m_y + m_z * m_z + m_w * m_w);
	}

	/*Returns length raised to the power of 2*/
	float vector_4::squared_length() const
	{
		return (m_x * m_x + m_y * m_y + m_z * m_z + m_w * m_w);
	}

	/*Divides x, y and z values by vector's length*/
	float vector_4::normalize()
	{
		float inverseScale = 1.0f / m_length;
		m_x *= inverseScale;
		m_y *= inverseScale;
		m_z *= inverseScale;
		m_w *= inverseScale;
		//Calculate new length
		m_length = length();

		return m_length;
	}

	vector_4& vector_4::operator=(const vector_4& pAVector4)
	{
		//Prevent self assignment
		if (this == &pAVector4)
			return *this;

		m_x = pAVector4.m_x;
		m_y = pAVector4.m_y;
		m_z = pAVector4.m_z;
		m_w = pAVector4.m_w;

		//Calculate new length
		m_length = length();

		return *this;
	}

	vector_4& vector_4::operator+=(const vector_4& pAVector4)
	{
		m_x = m_x + pAVector4.m_x;
		m_y = m_y + pAVector4.m_y;
		m_z = m_z + pAVector4.m_z;
		m_w = m_w + pAVector4.m_w;
		//Calculate new length
		m_length = length();

		return *this;
	}

	vector_4& vector_4::operator-=(const vector_4& pAVector4)
	{
		m_x = m_x - pAVector4.m_x;
		m_y = m_y - pAVector4.m_y;
		m_z = m_z - pAVector4.m_z;
		m_w = m_w - pAVector4.m_w;
		//Calculate new length
		m_length = length();

		return *this;
	}

	vector_4& vector_4::operator*=(const vector_4& pAVector4)
	{
		m_x = m_x * pAVector4.m_x;
		m_y = m_y * pAVector4.m_y;
		m_z = m_z * pAVector4.m_z;
		m_w = m_w * pAVector4.m_w;
		//Calculate new length
		m_length = length();

		return *this;
	}

	vector_4& vector_4::operator/=(const vector_4& pAVector4)
	{
		if (pAVector4.m_x == 0) throw "Can't divide by zero";
		if (pAVector4.m_y == 0) throw "Can't divide by zero";
		if (pAVector4.m_z == 0) throw "Can't divide by zero";
		if (pAVector4.m_w == 0) throw "Can't divide by zero";

		m_x = m_x / pAVector4.m_x;
		m_y = m_y / pAVector4.m_y;
		m_z = m_z / pAVector4.m_z;
		m_w = m_w / pAVector4.m_w;

		//Calculate new length
		m_length = length();

		return *this;
	}

	/*Calculates resulting coordinates of the addition and returns them as a new vector*/
	vector_4 vector_4::operator+(const vector_4& pAVector4) const
	{
		float xValue = m_x + pAVector4.m_x;
		float yValue = m_y + pAVector4.m_y;
		float zValue = m_z + pAVector4.m_z;
		float wValue = m_w + pAVector4.m_w;

		return vector_4(xValue, yValue, zValue, wValue);
	}

	/*Calculates resulting coordinates of the subtraction and returns them as a new vector*/
	vector_4 vector_4::operator-(const vector_4& pAVector4) const
	{
		float xValue = m_x - pAVector4.m_x;
		float yValue = m_y - pAVector4.m_y;
		float zValue = m_z - pAVector4.m_z;
		float wValue = m_w - pAVector4.m_w;

		return vector_4(xValue, yValue, zValue, wValue);
	}

	/*Calculates resulting coordinates of the multiplication and returns them as a new vector*/
	vector_4 vector_4::operator*(const vector_4& pAVector4) const
	{
		float xValue = m_x * pAVector4.m_x;
		float yValue = m_y * pAVector4.m_y;
		float zValue = m_z * pAVector4.m_z;
		float wValue = m_w * pAVector4.m_w;

		return vector_4(xValue, yValue, zValue, wValue);
	}

	/*Calculates resulting coordinates of the division and returns them as a new vector*/
	vector_4 vector_4::operator/(const vector_4& pAVector4) const
	{
		if (pAVector4.m_x == 0) throw "Can't divide by zero";
		if (pAVector4.m_y == 0) throw "Can't divide by zero";
		if (pAVector4.m_z == 0) throw "Can't divide by zero";
		if (pAVector4.m_w == 0) throw "Can't divide by zero";


		float xValue = m_x / pAVector4.m_x;
		float yValue = m_y / pAVector4.m_y;
		float zValue = m_z / pAVector4.m_z;
		float wValue = m_w / pAVector4.m_w;

		return vector_4(xValue, yValue, zValue, wValue);
	}

	bool vector_4::operator==(const vector_4& pAVector4)const
	{
		return m_x == pAVector4.m_x && m_y == pAVector4.m_y && m_z == pAVector4.m_z && m_w == pAVector4.m_w;
	}

	bool vector_4::operator!=(const vector_4& pAVector4)const
	{
		return m_x != pAVector4.m_x || m_y != pAVector4.m_y || m_z != pAVector4.m_z || m_w != pAVector4.m_w;
	}

	/*Calculates resulting coordinates of the multiplication by a value and returns them as a new vector*/
	vector_4 operator*(float value, const vector_4& pAVector4)
	{
		float xValue = value * pAVector4.m_x;
		float yValue = value * pAVector4.m_y;
		float zValue = value * pAVector4.m_z;
		float wValue = value * pAVector4.m_w;

		return vector_4(xValue, yValue, zValue, wValue);
	}

	/*Calculates resulting coordinates of the multiplication by a value and returns them as a new vector*/
	vector_4 operator*(const vector_4& pAVector4, float pValue)
	{
		float xValue = pValue * pAVector4.m_x;
		float yValue = pValue * pAVector4.m_y;
		float zValue = pValue * pAVector4.m_z;
		float wValue = pValue * pAVector4.m_w;

		return vector_4(xValue, yValue, zValue, wValue);
	}
}