#include "vector_3.hpp"
#include <cmath>

namespace engine
{
	namespace math
	{
		/*Default constructor*/
		vector_3::vector_3()
		{
			m_x = 0.0f;
			m_y = 0.0f;
			m_z = 0.0f;
			m_length = 0.0f;
		}

		/*Parameterized constructor. Sets the x, y and z values to the specified ones*/
		vector_3::vector_3(float pXValue, float pYValue, float pZValue)
		{
			m_x = pXValue;
			m_y = pYValue;
			m_z = pZValue;
			m_length = length();
		}

		/*Parameterized constructor. Sets the x, y and z values to the same specified value*/
		vector_3::vector_3(float pValue)
		{
			m_x = pValue;
			m_y = pValue;
			m_z = pValue;
			m_length = length();
		}

		/*Returns vector's length*/
		float vector_3::length() const
		{
			return sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
		}

		/*Returns length raised to the power of 2*/
		float vector_3::squared_length() const
		{
			return (m_x * m_x + m_y * m_y + m_z * m_z);
		}

		/*Divides x, y and z values by vector's length*/
		float vector_3::normalize()
		{
			float inverseScale = 1.0f / m_length;
			m_x *= inverseScale;
			m_y *= inverseScale;
			m_z *= inverseScale;

			//Calculate new length
			m_length = length();

			return m_length;
		}

		vector_3& vector_3::operator=(const vector_3& pAVector3)
		{
			//Prevent self assignment
			if (this == &pAVector3)
				return *this;

			m_x = pAVector3.m_x;
			m_y = pAVector3.m_y;
			m_z = pAVector3.m_z;

			//Calculate new length
			m_length = length();

			return *this;
		}

		vector_3& vector_3::operator+=(const vector_3& pAVector3)
		{
			m_x = m_x + pAVector3.m_x;
			m_y = m_y + pAVector3.m_y;
			m_z = m_z + pAVector3.m_z;

			//Calculate new length
			m_length = length();

			return *this;
		}

		vector_3& vector_3::operator-=(const vector_3& pAVector3)
		{
			m_x = m_x - pAVector3.m_x;
			m_y = m_y - pAVector3.m_y;
			m_z = m_z - pAVector3.m_z;

			//Calculate new length
			m_length = length();

			return *this;
		}

		vector_3& vector_3::operator*=(const vector_3& pAVector3)
		{
			m_x = m_x * pAVector3.m_x;
			m_y = m_y * pAVector3.m_y;
			m_z = m_z * pAVector3.m_z;

			//Calculate new length
			m_length = length();

			return *this;
		}

		vector_3& vector_3::operator/=(const vector_3& pAVector3)
		{
			if (pAVector3.m_x == 0) throw "Can't divide by zero";
			if (pAVector3.m_y == 0) throw "Can't divide by zero";

			m_x = m_x / pAVector3.m_x;
			m_y = m_y / pAVector3.m_y;
			m_z = m_z / pAVector3.m_z;

			//Calculate new length
			m_length = length();

			return *this;
		}

		/*Calculates resulting coordinates of the addition and returns them as a new vector*/
		vector_3 vector_3::operator+(const vector_3& pAVector3) const
		{
			float xValue = m_x + pAVector3.m_x;
			float yValue = m_y + pAVector3.m_y;
			float zValue = m_z + pAVector3.m_z;

			return vector_3(xValue, yValue, zValue);
		}

		/*Calculates resulting coordinates of the subtraction and returns them as a new vector*/
		vector_3 vector_3::operator-(const vector_3& pAVector3) const
		{
			float xValue = m_x - pAVector3.m_x;
			float yValue = m_y - pAVector3.m_y;
			float zValue = m_z - pAVector3.m_z;

			return vector_3(xValue, yValue, zValue);
		}

		/*Calculates resulting coordinates of the multiplication and returns them as a new vector*/
		vector_3 vector_3::operator*(const vector_3& pAVector3) const
		{
			float xValue = m_x * pAVector3.m_x;
			float yValue = m_y * pAVector3.m_y;
			float zValue = m_z * pAVector3.m_z;

			return vector_3(xValue, yValue, zValue);
		}

		/*Calculates resulting coordinates of the division and returns them as a new vector*/
		vector_3 vector_3::operator/(const vector_3& pAVector3) const
		{
			if (pAVector3.m_x == 0) throw "Can't divide by zero";
			if (pAVector3.m_y == 0) throw "Can't divide by zero";

			float xValue = m_x / pAVector3.m_x;
			float yValue = m_y / pAVector3.m_y;
			float zValue = m_z / pAVector3.m_z;

			return vector_3(xValue, yValue, zValue);
		}

		bool vector_3::operator==(const vector_3& pAVector3)const
		{
			return m_x == pAVector3.m_x && m_y == pAVector3.m_y && m_z == pAVector3.m_z;
		}

		bool vector_3::operator!=(const vector_3& pAVector3)const
		{
			return m_x != pAVector3.m_x || m_y != pAVector3.m_y || m_z != pAVector3.m_z;
		}

		/*Calculates resulting coordinates of the multiplication by a value and returns them as a new vector*/
		vector_3 operator*(float pValue, const vector_3& pAVector3)
		{
			float xValue = pValue * pAVector3.m_x;
			float yValue = pValue * pAVector3.m_y;
			float zValue = pValue * pAVector3.m_z;

			return vector_3(xValue, yValue, zValue);
		}

		/*Calculates resulting coordinates of the multiplication by a value and returns them as a new vector*/
		vector_3 operator*(const vector_3& pAVector3, float pValue)
		{
			float xValue = pValue * pAVector3.m_x;
			float yValue = pValue * pAVector3.m_y;
			float zValue = pValue * pAVector3.m_z;

			return vector_3(xValue, yValue, zValue);
		}
	}
}
