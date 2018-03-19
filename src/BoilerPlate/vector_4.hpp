#pragma once

#ifndef _VECTOR_4_HPP
#define _VECTOR_4_HPP

namespace engine
{
	struct vector_4
	{
		/*STATIC*/
		static vector_4 Origin;

		/*MEMBERS*/
		float mX;
		float mY;
		float mZ;
		float mW;
		float mLength;

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

#endif // !_VECTOR_4_HPP
