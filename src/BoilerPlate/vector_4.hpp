#pragma once

#ifndef _VECTOR_4_HPP_
#define _VECTOR_4_HPP_

namespace engine
{
	struct vector_4
	{
		/*STATIC*/
		static vector_4 Origin;

		/*MEMBERS*/
		float m_x;
		float m_y;
		float m_z;
		float m_w;
		float m_length;

		/*CTOR*/
		vector_4();
		vector_4(float, float, float, float);
		vector_4(float);

		/*PUBLIC FUNCTIONS*/
		float length() const;
		float squared_length() const;
		float normalize();

		/*OPERATORS*/
		vector_4& operator= (const vector_4&);
		vector_4& operator+= (const vector_4&);
		vector_4& operator-= (const vector_4&);
		vector_4& operator*= (const vector_4&);
		vector_4& operator/= (const vector_4&);
		vector_4 operator+ (const vector_4&)const;
		vector_4 operator- (const vector_4&)const;
		vector_4 operator* (const vector_4&)const;
		vector_4 operator/ (const vector_4&)const;
		bool operator== (const vector_4&)const;
		bool operator!= (const vector_4&)const;
		friend vector_4 operator*(float, const vector_4&);
		friend vector_4 operator*(const vector_4&, float);
	};

}

#endif // !_VECTOR_4_HPP_
