#pragma once

#ifndef _VECTOR_2_HPP
#define _VECTOR_2_HPP

namespace engine
{

	struct vector_2
	{
		/*STATIC*/
		static vector_2 Origin;

		/*MEMBERS*/
		float mX;
		float mY;
		float mLength;

		/*CTOR*/
		vector_2();
		vector_2(float, float);
		vector_2(float);

		/*PUBLIC FUNCTIONS*/
		float length() const;
		float squared_length() const;
		float normalize();

		/*OPERATORS*/
		vector_2& operator= (const vector_2&);
		vector_2& operator+= (const vector_2&);
		vector_2& operator-= (const vector_2&);
		vector_2& operator*= (const vector_2&);
		vector_2& operator/= (const vector_2&);
		vector_2 operator+ (const vector_2&)const;
		vector_2 operator- (const vector_2&)const;
		vector_2 operator* (const vector_2&)const;
		vector_2 operator/ (const vector_2&)const;
		bool operator== (const vector_2&)const;
		bool operator!= (const vector_2&)const;
		friend vector_2 operator*(float, const vector_2&);
		friend vector_2 operator*(const vector_2&, float);
	};

}



#endif // !_VECTOR_2_HPP
