#pragma once

#ifndef MATRIX_4_HPP
#define MATRIX_4_HPP

#include "vector_3.hpp"
#include "vector_4.hpp"
#include "math_utilities.hpp"

namespace engine
{

	namespace math
	{
		class matrix_4
		{
		public:

			//constructors
			matrix_4();

			matrix_4(float pFirstPosition, float pSecondPosition, float pThirdPosition, float pFourthPosition, float pFithPosition, float pSixthPosition, float pSeventhPosition,
				float pEigthPosition, float pNinethPosition, float pTenthPosition, float pEleventhPosition, float pTwelvethPosition, float pThirteenthPosition, float pFourteenthPosition,
				float pFithteenthPosition, float pSixteenthPosition);

			matrix_4(float pValues[16]);



			//public members




			//public functions

			float*  get_row(int pRowNumber);
			float*  get_column(int pColumnNumber);
			float* get_matrix();
			matrix_4 get_transpose();
			matrix_4 get_inverse();
			void set_identity();
			vector_3 get_angle();
			void translate(vector_4 pTranslationVector);

			void rotate(float pAngleX, float pAngleY, float pAngleZ);
			void rotateX(float pAngle);
			void rotateY(float pAngle);
			void rotateZ(float pAngle);

			void make_ortho(const float &pMinimumXAxis, const float &pMaximumXAxis, const float &pMinimumYAxis,
				const float &pMaximumYAxis, const float &pMinimumZAxis, const float &pMaximumZAxis);

			void make_perspective(const float &pFieldOfView, const float &pNearClippingPlane, const float &pFarClippingPlane, const float& pScreenAspect);
			void make_look_at(vector_3 pLookingPosition, vector_3 pTargetPosition);
			void assign_matrix(float pMatrix[]);
			void scale(vector_3 pScaleVector);


			matrix_4 operator=(matrix_4& pRightSide);
			matrix_4 operator+(matrix_4& pRightSide);
			matrix_4 operator-(matrix_4& pRightSide);
			matrix_4 operator*(matrix_4& pRightSide);
			matrix_4 operator/(matrix_4& pRightSide);

			friend std::ostream& operator<<(std::ostream& pOstream, matrix_4 pMatrix);
			//float& matrix_4::operator[](const int pRightSide);


		private:

			//private members

			float mMatrix[16];

			//private functions



		};
	}

}

#endif