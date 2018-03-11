#include "vector_2.hpp"
#include <cmath>

namespace engine
{
	namespace math
	{
		/*Default constructor*/
		vector_2::vector_2()
		{
			m_x = 0.0f;
			m_y = 0.0f;
			m_length = 0.0f;
		}

		/*Parameterized constructor. Sets the x and y values to the specified ones*/
		vector_2::vector_2(float pXValue, float pYValue)
		{
			m_x = pXValue;
			m_y = pYValue;
			m_length = length();
		}

		/*Parameterized constructor. Sets the x and y values to the same specified value*/
		vector_2::vector_2(float pValue)
		{
			m_x = pValue;
			m_y = pValue;
			m_length = length();
		}

		/*Returns vector's length*/
		float vector_2::length() const
		{
			return std::fabs(std::sqrtf(m_x * m_x + m_y * m_y));
		}

		/*Returns length raised to the power of 2*/
		float vector_2::squared_length() const
		{
			return (m_x * m_x + m_y * m_y);
		}

		/*Divides x and y values by vector's length*/
		float vector_2::normalize()
		{
			float inverseScale = 1.0f / m_length;
			m_x *= inverseScale;
			m_y *= inverseScale;

			//Calculate new length
			m_length = length();

			return m_length;
		}

		vector_2& vector_2::operator=(const vector_2& pAVector2)
		{
			//Prevent self assignment
			if (this == &pAVector2)
				return *this;

			m_x = pAVector2.m_x;
			m_y = pAVector2.m_y;

			//Calculate new length
			m_length = length();

			return *this;
		}

		vector_2& vector_2::operator+=(const vector_2& pAVector2)
		{
			m_x = m_x + pAVector2.m_x;
			m_y = m_y + pAVector2.m_y;

			//Calculate new length
			m_length = length();

			return *this;
		}

		vector_2& vector_2::operator-=(const vector_2& pAVector2)
		{
			m_x = m_x - pAVector2.m_x;
			m_y = m_y - pAVector2.m_y;

			//Calculate new length
			m_length = length();

			return *this;
		}

		vector_2& vector_2::operator*=(const vector_2& pAVector2)
		{
			m_x = m_x * pAVector2.m_x;
			m_y = m_y * pAVector2.m_y;

			//Calculate new length
			m_length = length();

			return *this;
		}

		vector_2& vector_2::operator/=(const vector_2& pAVector2)
		{
			if (pAVector2.m_x == 0) throw "Can't divide by zero";
			if (pAVector2.m_y == 0) throw "Can't divide by zero";

			m_x = m_x / pAVector2.m_x;
			m_y = m_y / pAVector2.m_y;

			//Calculate new length
			m_length = length();

			return *this;
		}

		/*Calculates resulting coordinates of the addition and returns them as a new vector*/
		vector_2 vector_2::operator+(const vector_2& pAVector2) const
		{
			float xValue = m_x + pAVector2.m_x;
			float yValue = m_y + pAVector2.m_y;

			return vector_2(xValue, yValue);
		}

		/*Calculates resulting coordinates of the subtraction and returns them as a new vector*/
		vector_2 vector_2::operator-(const vector_2& pAVector2) const
		{
			float xValue = m_x - pAVector2.m_x;
			float yValue = m_y - pAVector2.m_y;

			return vector_2(xValue, yValue);
		}

		/*Calculates resulting coordinates of the multiplication and returns them as a new vector*/
		vector_2 vector_2::operator*(const vector_2& pAVector2) const
		{
			float xValue = m_x * pAVector2.m_x;
			float yValue = m_y * pAVector2.m_y;

			return vector_2(xValue, yValue);
		}

		/*Calculates resulting coordinates of the division and returns them as a new vector*/
		vector_2 vector_2::operator/(const vector_2& pAVector2) const
		{
			if (pAVector2.m_x == 0) throw "Can't divide by zero";
			if (pAVector2.m_y == 0) throw "Can't divide by zero";

			float xValue = m_x / pAVector2.m_x;
			float yValue = m_y / pAVector2.m_y;

			return vector_2(xValue, yValue);
		}

		bool vector_2::operator==(const vector_2& pAVector2)const
		{
			return m_x == pAVector2.m_x && m_y == pAVector2.m_y;
		}

		bool vector_2::operator!=(const vector_2& pAVector2)const
		{
			return m_x != pAVector2.m_x || m_y != pAVector2.m_y;
		}

		/*Calculates resulting coordinates of the multiplication by a value and returns them as a new vector*/
		vector_2 operator*(float pValue, const vector_2& pAVector2)
		{
			float xValue = pValue * pAVector2.m_x;
			float yValue = pValue * pAVector2.m_y;

			return vector_2(xValue, yValue);
		}

		/*Calculates resulting coordinates of the multiplication by a value and returns them as a new vector*/
		vector_2 operator*(const vector_2& pAVector2, float pValue)
		{
			float xValue = pValue * pAVector2.m_x;
			float yValue = pValue * pAVector2.m_y;

			return vector_2(xValue, yValue);
		}

	}
}

