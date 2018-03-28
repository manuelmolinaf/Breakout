#pragma once

#ifndef _VECTOR_3_HPP
#define _VECTOR_3_HPP

namespace engine
{
	namespace math
	{
		struct vector_3
		{
			/*STATIC*/
			static vector_3 Origin;

			/*MEMBERS*/
			float mX;
			float mY;
			float mZ;
			float mLength;

			/*CTOR*/
			vector_3();
			vector_3(float, float, float);
			vector_3(float);

			/*PUBLIC FUNCTIONS*/
			float length() const;
			float squared_length() const;
			float normalize();
			vector_3 cross_product(const vector_3&, const vector_3&);

			/*OPERATORS*/
			vector_3& operator= (const vector_3&);
			vector_3& operator+= (const vector_3&);
			vector_3& operator-= (const vector_3&);
			vector_3& operator*= (const vector_3&);
			vector_3& operator/= (const vector_3&);
			vector_3 operator+ (const vector_3&)const;
			vector_3 operator- (const vector_3&)const;
			vector_3 operator* (const vector_3&)const;
			vector_3 operator/ (const vector_3&)const;
			bool operator== (const vector_3&)const;
			bool operator!= (const vector_3&)const;
			friend vector_3 operator*(float, const vector_3&);
			friend vector_3 operator*(const vector_3&, float);
		};

	}

}


#endif // !_VECTOR_3_HPP
