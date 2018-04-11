#include "matrix_4.hpp"
#include "math_utilities.hpp"
#include "vector_3.hpp"

#include <math.h>
#include <iostream>

namespace engine
{

	namespace math
	{
		math_utilities mathTool;


		matrix_4::matrix_4()
		{

			mMatrix[0] = 1.0f;
			mMatrix[1] = 0.0f;
			mMatrix[2] = 0.0f;
			mMatrix[3] = 0.0f;

			mMatrix[4] = 0.0f;
			mMatrix[5] = 1.0f;
			mMatrix[6] = 0.0f;
			mMatrix[7] = 0.0f;

			mMatrix[8] = 0.0f;
			mMatrix[9] = 0.0f;
			mMatrix[10] = 1.0f;
			mMatrix[11] = 0.0f;

			mMatrix[12] = 0.0f;
			mMatrix[13] = 0.0f;
			mMatrix[14] = 0.0f;
			mMatrix[15] = 1.0f;

		}

		matrix_4::matrix_4(float pFirstPosition, float pSecondPosition, float pThirdPosition, float pFourthPosition, float pFithPosition, float pSixthPosition, float pSeventhPosition,
			float pEigthPosition, float pNinethPosition, float pTenthPosition, float pEleventhPosition, float pTwelvethPosition, float pThirteenthPosition, float pFourteenthPosition,
			float pFithteenthPosition, float pSixteenthPosition)
		{


			mMatrix[0] = pFirstPosition;
			mMatrix[1] = pSecondPosition;
			mMatrix[2] = pThirdPosition;
			mMatrix[3] = pFourthPosition;

			mMatrix[4] = pFithPosition;
			mMatrix[5] = pSixthPosition;
			mMatrix[6] = pSeventhPosition;
			mMatrix[7] = pEigthPosition;

			mMatrix[8] = pNinethPosition;
			mMatrix[9] = pTenthPosition;
			mMatrix[10] = pEleventhPosition;
			mMatrix[11] = pTwelvethPosition;

			mMatrix[12] = pThirteenthPosition;
			mMatrix[13] = pFourteenthPosition;
			mMatrix[14] = pFithteenthPosition;
			mMatrix[15] = pSixteenthPosition;

		}

		matrix_4::matrix_4(float pValues[16])
		{

			mMatrix[0] = pValues[0];
			mMatrix[1] = pValues[1];
			mMatrix[2] = pValues[2];
			mMatrix[3] = pValues[3];

			mMatrix[4] = pValues[4];
			mMatrix[5] = pValues[5];
			mMatrix[6] = pValues[6];
			mMatrix[7] = pValues[7];

			mMatrix[8] = pValues[8];
			mMatrix[9] = pValues[9];
			mMatrix[10] = pValues[10];
			mMatrix[11] = pValues[11];

			mMatrix[12] = pValues[12];
			mMatrix[13] = pValues[13];
			mMatrix[14] = pValues[14];
			mMatrix[15] = pValues[15];
		}


		float* matrix_4::get_row(int pRowNumber)
		{
			float row[4] = {};

			row[0] = mMatrix[pRowNumber];
			row[1] = mMatrix[pRowNumber + 4];
			row[2] = mMatrix[pRowNumber + 8];
			row[3] = mMatrix[pRowNumber + 12];


			return row;
		}


		float* matrix_4::get_column(int pColumnNumber)
		{
			float column[4] = {};

			column[0] = mMatrix[pColumnNumber * 4];
			column[1] = mMatrix[(pColumnNumber * 4) + 1];
			column[2] = mMatrix[(pColumnNumber * 4) + 2];
			column[3] = mMatrix[(pColumnNumber * 4) + 3];

			return column;
		}

		float* matrix_4::get_matrix()
		{
			return mMatrix;
		}


		matrix_4  matrix_4::get_transpose()
		{
			matrix_4 transposedMatrix;


			transposedMatrix.get_matrix()[1] = mMatrix[4];
			transposedMatrix.get_matrix()[2] = mMatrix[8];
			transposedMatrix.get_matrix()[3] = mMatrix[12];

			transposedMatrix.get_matrix()[4] = mMatrix[1];
			transposedMatrix.get_matrix()[6] = mMatrix[9];
			transposedMatrix.get_matrix()[7] = mMatrix[13];

			transposedMatrix.get_matrix()[8] = mMatrix[2];
			transposedMatrix.get_matrix()[9] = mMatrix[6];
			transposedMatrix.get_matrix()[11] = mMatrix[14];

			transposedMatrix.get_matrix()[12] = mMatrix[3];
			transposedMatrix.get_matrix()[13] = mMatrix[7];
			transposedMatrix.get_matrix()[14] = mMatrix[11];

			return transposedMatrix;
		}

		void matrix_4::set_identity()
		{
			mMatrix[0] = 1.0f;
			mMatrix[1] = 0.0f;
			mMatrix[2] = 0.0f;
			mMatrix[3] = 0.0f;

			mMatrix[4] = 0.0f;
			mMatrix[5] = 1.0f;
			mMatrix[6] = 0.0f;
			mMatrix[7] = 0.0f;

			mMatrix[8] = 0.0f;
			mMatrix[9] = 0.0f;
			mMatrix[10] = 1.0f;
			mMatrix[11] = 0.0f;

			mMatrix[12] = 0.0f;
			mMatrix[13] = 0.0f;
			mMatrix[14] = 0.0f;
			mMatrix[15] = 1.0f;
		}


		vector_3 matrix_4::get_angle()
		{
			vector_3 angles;

			if (mMatrix[0] == 1.0f || mMatrix[0] == -1.0f)
			{
				angles.mX = 0; //pitch
				angles.mY = atan2f(mMatrix[8], mMatrix[14]); //yaw
				angles.mZ = 0; //roll

			}
			else
			{

				angles.mX = (float)asin(mMatrix[1]); //pitch
				angles.mY = atan2f(-mMatrix[2], mMatrix[0]); //yaw
				angles.mZ = atan2f(-mMatrix[9], mMatrix[5]); //roll
			}

			return angles;
		}

		std::ostream& operator<<(std::ostream& pOstream, matrix_4 pMatrix)
		{
			for (int row = 0; row < 4; row++)
			{
				pOstream << pMatrix.get_matrix()[row] << " ";

				pOstream << pMatrix.get_matrix()[row + 4] << " ";

				pOstream << pMatrix.get_matrix()[row + 8] << " ";

				pOstream << pMatrix.get_matrix()[row + 12] << " ";

				pOstream << "\n";
			}

			return pOstream;
		}
		/*
		float& matrix_4::operator[](const int pRightSide)
		{
		int row = pRightSide % 4;
		int column = pRightSide / 4;

		return mMatrix[row][column];
		}
		*/

		matrix_4 matrix_4::operator=(matrix_4& pRightSide)
		{
			matrix_4 returnMatrix;

			mMatrix[0] = pRightSide.get_matrix()[0];
			mMatrix[1] = pRightSide.get_matrix()[1];
			mMatrix[2] = pRightSide.get_matrix()[2];
			mMatrix[3] = pRightSide.get_matrix()[3];

			mMatrix[4] = pRightSide.get_matrix()[4];
			mMatrix[5] = pRightSide.get_matrix()[5];
			mMatrix[6] = pRightSide.get_matrix()[6];
			mMatrix[7] = pRightSide.get_matrix()[7];

			mMatrix[8] = pRightSide.get_matrix()[8];
			mMatrix[9] = pRightSide.get_matrix()[9];
			mMatrix[10] = pRightSide.get_matrix()[10];
			mMatrix[11] = pRightSide.get_matrix()[11];

			mMatrix[12] = pRightSide.get_matrix()[12];
			mMatrix[13] = pRightSide.get_matrix()[13];
			mMatrix[14] = pRightSide.get_matrix()[14];
			mMatrix[15] = pRightSide.get_matrix()[15];

			return returnMatrix;
		}

		matrix_4 matrix_4::operator+(matrix_4& pRightSide)
		{

			matrix_4 returnMatrix = matrix_4();

			returnMatrix.get_matrix()[0] = mMatrix[0] + pRightSide.get_matrix()[0];
			returnMatrix.get_matrix()[1] = mMatrix[1] + pRightSide.get_matrix()[1];
			returnMatrix.get_matrix()[2] = mMatrix[2] + pRightSide.get_matrix()[2];
			returnMatrix.get_matrix()[3] = mMatrix[3] + pRightSide.get_matrix()[3];

			returnMatrix.get_matrix()[4] = mMatrix[4] + pRightSide.get_matrix()[4];
			returnMatrix.get_matrix()[5] = mMatrix[5] + pRightSide.get_matrix()[5];
			returnMatrix.get_matrix()[6] = mMatrix[6] + pRightSide.get_matrix()[6];
			returnMatrix.get_matrix()[7] = mMatrix[7] + pRightSide.get_matrix()[7];

			returnMatrix.get_matrix()[8] = mMatrix[8] + pRightSide.get_matrix()[8];
			returnMatrix.get_matrix()[9] = mMatrix[9] + pRightSide.get_matrix()[9];
			returnMatrix.get_matrix()[10] = mMatrix[10] + pRightSide.get_matrix()[10];
			returnMatrix.get_matrix()[11] = mMatrix[11] + pRightSide.get_matrix()[11];

			returnMatrix.get_matrix()[12] = mMatrix[12] + pRightSide.get_matrix()[12];
			returnMatrix.get_matrix()[13] = mMatrix[13] + pRightSide.get_matrix()[13];
			returnMatrix.get_matrix()[14] = mMatrix[14] + pRightSide.get_matrix()[14];
			returnMatrix.get_matrix()[15] = mMatrix[15] + pRightSide.get_matrix()[15];


			return returnMatrix;
		}

		matrix_4 matrix_4::operator-(matrix_4& pRightSide)
		{

			matrix_4 returnMatrix;

			returnMatrix.get_matrix()[0] = mMatrix[0] - pRightSide.get_matrix()[0];
			returnMatrix.get_matrix()[1] = mMatrix[1] - pRightSide.get_matrix()[1];
			returnMatrix.get_matrix()[2] = mMatrix[2] - pRightSide.get_matrix()[2];
			returnMatrix.get_matrix()[3] = mMatrix[3] - pRightSide.get_matrix()[3];

			returnMatrix.get_matrix()[4] = mMatrix[4] - pRightSide.get_matrix()[4];
			returnMatrix.get_matrix()[5] = mMatrix[5] - pRightSide.get_matrix()[5];
			returnMatrix.get_matrix()[6] = mMatrix[6] - pRightSide.get_matrix()[6];
			returnMatrix.get_matrix()[7] = mMatrix[7] - pRightSide.get_matrix()[7];

			returnMatrix.get_matrix()[8] = mMatrix[8] - pRightSide.get_matrix()[8];
			returnMatrix.get_matrix()[9] = mMatrix[9] - pRightSide.get_matrix()[9];
			returnMatrix.get_matrix()[10] = mMatrix[10] - pRightSide.get_matrix()[10];
			returnMatrix.get_matrix()[11] = mMatrix[11] - pRightSide.get_matrix()[11];

			returnMatrix.get_matrix()[12] = mMatrix[12] - pRightSide.get_matrix()[12];
			returnMatrix.get_matrix()[13] = mMatrix[13] - pRightSide.get_matrix()[13];
			returnMatrix.get_matrix()[14] = mMatrix[14] - pRightSide.get_matrix()[14];
			returnMatrix.get_matrix()[15] = mMatrix[15] - pRightSide.get_matrix()[15];

			return returnMatrix;
		}

		matrix_4 matrix_4::operator*(matrix_4& pRightSide)
		{

			matrix_4 returnMatrix;

			returnMatrix.get_matrix()[0] = mMatrix[0] * pRightSide.get_matrix()[0] + mMatrix[1] * pRightSide.get_matrix()[4] + mMatrix[2] * pRightSide.get_matrix()[8] + mMatrix[3] * pRightSide.get_matrix()[12];
			returnMatrix.get_matrix()[1] = mMatrix[0] * pRightSide.get_matrix()[1] + mMatrix[1] * pRightSide.get_matrix()[5] + mMatrix[2] * pRightSide.get_matrix()[9] + mMatrix[3] * pRightSide.get_matrix()[13];
			returnMatrix.get_matrix()[2] = mMatrix[0] * pRightSide.get_matrix()[2] + mMatrix[1] * pRightSide.get_matrix()[6] + mMatrix[2] * pRightSide.get_matrix()[10] + mMatrix[3] * pRightSide.get_matrix()[14];
			returnMatrix.get_matrix()[3] = mMatrix[0] * pRightSide.get_matrix()[3] + mMatrix[1] * pRightSide.get_matrix()[7] + mMatrix[2] * pRightSide.get_matrix()[11] + mMatrix[3] * pRightSide.get_matrix()[15];

			returnMatrix.get_matrix()[4] = mMatrix[4] * pRightSide.get_matrix()[0] + mMatrix[5] * pRightSide.get_matrix()[4] + mMatrix[6] * pRightSide.get_matrix()[8] + mMatrix[7] * pRightSide.get_matrix()[12];
			returnMatrix.get_matrix()[5] = mMatrix[4] * pRightSide.get_matrix()[1] + mMatrix[5] * pRightSide.get_matrix()[5] + mMatrix[6] * pRightSide.get_matrix()[9] + mMatrix[7] * pRightSide.get_matrix()[13];
			returnMatrix.get_matrix()[6] = mMatrix[4] * pRightSide.get_matrix()[2] + mMatrix[5] * pRightSide.get_matrix()[6] + mMatrix[6] * pRightSide.get_matrix()[10] + mMatrix[7] * pRightSide.get_matrix()[14];
			returnMatrix.get_matrix()[7] = mMatrix[4] * pRightSide.get_matrix()[3] + mMatrix[5] * pRightSide.get_matrix()[7] + mMatrix[6] * pRightSide.get_matrix()[11] + mMatrix[7] * pRightSide.get_matrix()[15];

			returnMatrix.get_matrix()[8] = mMatrix[8] * pRightSide.get_matrix()[0] + mMatrix[9] * pRightSide.get_matrix()[4] + mMatrix[10] * pRightSide.get_matrix()[8] + mMatrix[11] * pRightSide.get_matrix()[12];
			returnMatrix.get_matrix()[9] = mMatrix[8] * pRightSide.get_matrix()[1] + mMatrix[9] * pRightSide.get_matrix()[5] + mMatrix[10] * pRightSide.get_matrix()[9] + mMatrix[11] * pRightSide.get_matrix()[13];
			returnMatrix.get_matrix()[10] = mMatrix[8] * pRightSide.get_matrix()[2] + mMatrix[9] * pRightSide.get_matrix()[6] + mMatrix[10] * pRightSide.get_matrix()[10] + mMatrix[11] * pRightSide.get_matrix()[14];
			returnMatrix.get_matrix()[11] = mMatrix[8] * pRightSide.get_matrix()[3] + mMatrix[9] * pRightSide.get_matrix()[7] + mMatrix[10] * pRightSide.get_matrix()[11] + mMatrix[11] * pRightSide.get_matrix()[15];

			returnMatrix.get_matrix()[12] = mMatrix[12] * pRightSide.get_matrix()[0] + mMatrix[13] * pRightSide.get_matrix()[4] + mMatrix[14] * pRightSide.get_matrix()[8] + mMatrix[15] * pRightSide.get_matrix()[12];
			returnMatrix.get_matrix()[13] = mMatrix[12] * pRightSide.get_matrix()[1] + mMatrix[13] * pRightSide.get_matrix()[5] + mMatrix[14] * pRightSide.get_matrix()[9] + mMatrix[15] * pRightSide.get_matrix()[13];
			returnMatrix.get_matrix()[14] = mMatrix[12] * pRightSide.get_matrix()[2] + mMatrix[13] * pRightSide.get_matrix()[6] + mMatrix[14] * pRightSide.get_matrix()[10] + mMatrix[15] * pRightSide.get_matrix()[14];
			returnMatrix.get_matrix()[15] = mMatrix[12] * pRightSide.get_matrix()[3] + mMatrix[13] * pRightSide.get_matrix()[7] + mMatrix[14] * pRightSide.get_matrix()[11] + mMatrix[15] * pRightSide.get_matrix()[15];

			return returnMatrix;
		}

		matrix_4 matrix_4::get_inverse()
		{
			matrix_4 matrix, invertedMatrix;

			matrix = *this;

			float determinant;


			invertedMatrix.get_matrix()[0] = matrix.get_matrix()[5] * matrix.get_matrix()[10] * matrix.get_matrix()[15] -
				matrix.get_matrix()[5] * matrix.get_matrix()[11] * matrix.get_matrix()[14] -
				matrix.get_matrix()[9] * matrix.get_matrix()[6] * matrix.get_matrix()[15] +
				matrix.get_matrix()[9] * matrix.get_matrix()[7] * matrix.get_matrix()[14] +
				matrix.get_matrix()[13] * matrix.get_matrix()[6] * matrix.get_matrix()[11] -
				matrix.get_matrix()[13] * matrix.get_matrix()[7] * matrix.get_matrix()[10];

			invertedMatrix.get_matrix()[1] = -matrix.get_matrix()[1] * matrix.get_matrix()[10] * matrix.get_matrix()[15] +
				matrix.get_matrix()[1] * matrix.get_matrix()[11] * matrix.get_matrix()[14] +
				matrix.get_matrix()[9] * matrix.get_matrix()[2] * matrix.get_matrix()[15] -
				matrix.get_matrix()[9] * matrix.get_matrix()[3] * matrix.get_matrix()[14] -
				matrix.get_matrix()[13] * matrix.get_matrix()[2] * matrix.get_matrix()[11] +
				matrix.get_matrix()[13] * matrix.get_matrix()[3] * matrix.get_matrix()[10];

			invertedMatrix.get_matrix()[2] = matrix.get_matrix()[1] * matrix.get_matrix()[6] * matrix.get_matrix()[15] -
				matrix.get_matrix()[1] * matrix.get_matrix()[7] * matrix.get_matrix()[14] -
				matrix.get_matrix()[5] * matrix.get_matrix()[2] * matrix.get_matrix()[15] +
				matrix.get_matrix()[5] * matrix.get_matrix()[3] * matrix.get_matrix()[14] +
				matrix.get_matrix()[13] * matrix.get_matrix()[2] * matrix.get_matrix()[7] -
				matrix.get_matrix()[13] * matrix.get_matrix()[3] * matrix.get_matrix()[6];

			invertedMatrix.get_matrix()[3] = -matrix.get_matrix()[1] * matrix.get_matrix()[6] * matrix.get_matrix()[11] +
				matrix.get_matrix()[1] * matrix.get_matrix()[7] * matrix.get_matrix()[10] +
				matrix.get_matrix()[5] * matrix.get_matrix()[2] * matrix.get_matrix()[11] -
				matrix.get_matrix()[5] * matrix.get_matrix()[3] * matrix.get_matrix()[10] -
				matrix.get_matrix()[9] * matrix.get_matrix()[2] * matrix.get_matrix()[7] +
				matrix.get_matrix()[9] * matrix.get_matrix()[3] * matrix.get_matrix()[6];

			invertedMatrix.get_matrix()[4] = -matrix.get_matrix()[4] * matrix.get_matrix()[10] * matrix.get_matrix()[15] +
				matrix.get_matrix()[4] * matrix.get_matrix()[11] * matrix.get_matrix()[14] +
				matrix.get_matrix()[8] * matrix.get_matrix()[6] * matrix.get_matrix()[15] -
				matrix.get_matrix()[8] * matrix.get_matrix()[7] * matrix.get_matrix()[14] -
				matrix.get_matrix()[12] * matrix.get_matrix()[6] * matrix.get_matrix()[11] +
				matrix.get_matrix()[12] * matrix.get_matrix()[7] * matrix.get_matrix()[10];

			invertedMatrix.get_matrix()[5] = matrix.get_matrix()[0] * matrix.get_matrix()[10] * matrix.get_matrix()[15] -
				matrix.get_matrix()[0] * matrix.get_matrix()[11] * matrix.get_matrix()[14] -
				matrix.get_matrix()[8] * matrix.get_matrix()[2] * matrix.get_matrix()[15] +
				matrix.get_matrix()[8] * matrix.get_matrix()[3] * matrix.get_matrix()[14] +
				matrix.get_matrix()[12] * matrix.get_matrix()[2] * matrix.get_matrix()[11] -
				matrix.get_matrix()[12] * matrix.get_matrix()[3] * matrix.get_matrix()[10];

			invertedMatrix.get_matrix()[6] = -matrix.get_matrix()[0] * matrix.get_matrix()[6] * matrix.get_matrix()[15] +
				matrix.get_matrix()[0] * matrix.get_matrix()[7] * matrix.get_matrix()[14] +
				matrix.get_matrix()[4] * matrix.get_matrix()[2] * matrix.get_matrix()[15] -
				matrix.get_matrix()[4] * matrix.get_matrix()[3] * matrix.get_matrix()[14] -
				matrix.get_matrix()[12] * matrix.get_matrix()[2] * matrix.get_matrix()[7] +
				matrix.get_matrix()[12] * matrix.get_matrix()[3] * matrix.get_matrix()[6];

			invertedMatrix.get_matrix()[7] = matrix.get_matrix()[0] * matrix.get_matrix()[6] * matrix.get_matrix()[11] -
				matrix.get_matrix()[0] * matrix.get_matrix()[7] * matrix.get_matrix()[10] -
				matrix.get_matrix()[4] * matrix.get_matrix()[2] * matrix.get_matrix()[11] +
				matrix.get_matrix()[4] * matrix.get_matrix()[3] * matrix.get_matrix()[10] +
				matrix.get_matrix()[8] * matrix.get_matrix()[2] * matrix.get_matrix()[7] -
				matrix.get_matrix()[8] * matrix.get_matrix()[3] * matrix.get_matrix()[6];

			invertedMatrix.get_matrix()[8] = matrix.get_matrix()[4] * matrix.get_matrix()[9] * matrix.get_matrix()[15] -
				matrix.get_matrix()[4] * matrix.get_matrix()[11] * matrix.get_matrix()[13] -
				matrix.get_matrix()[8] * matrix.get_matrix()[5] * matrix.get_matrix()[15] +
				matrix.get_matrix()[8] * matrix.get_matrix()[7] * matrix.get_matrix()[13] +
				matrix.get_matrix()[12] * matrix.get_matrix()[5] * matrix.get_matrix()[11] -
				matrix.get_matrix()[12] * matrix.get_matrix()[7] * matrix.get_matrix()[9];

			invertedMatrix.get_matrix()[9] = -matrix.get_matrix()[0] * matrix.get_matrix()[9] * matrix.get_matrix()[15] +
				matrix.get_matrix()[0] * matrix.get_matrix()[11] * matrix.get_matrix()[13] +
				matrix.get_matrix()[8] * matrix.get_matrix()[1] * matrix.get_matrix()[15] -
				matrix.get_matrix()[8] * matrix.get_matrix()[3] * matrix.get_matrix()[13] -
				matrix.get_matrix()[12] * matrix.get_matrix()[1] * matrix.get_matrix()[11] +
				matrix.get_matrix()[12] * matrix.get_matrix()[3] * matrix.get_matrix()[9];

			invertedMatrix.get_matrix()[10] = matrix.get_matrix()[0] * matrix.get_matrix()[5] * matrix.get_matrix()[15] -
				matrix.get_matrix()[0] * matrix.get_matrix()[7] * matrix.get_matrix()[13] -
				matrix.get_matrix()[4] * matrix.get_matrix()[1] * matrix.get_matrix()[15] +
				matrix.get_matrix()[4] * matrix.get_matrix()[3] * matrix.get_matrix()[13] +
				matrix.get_matrix()[12] * matrix.get_matrix()[1] * matrix.get_matrix()[7] -
				matrix.get_matrix()[12] * matrix.get_matrix()[3] * matrix.get_matrix()[5];

			invertedMatrix.get_matrix()[11] = -matrix.get_matrix()[0] * matrix.get_matrix()[5] * matrix.get_matrix()[11] +
				matrix.get_matrix()[0] * matrix.get_matrix()[7] * matrix.get_matrix()[9] +
				matrix.get_matrix()[4] * matrix.get_matrix()[1] * matrix.get_matrix()[11] -
				matrix.get_matrix()[4] * matrix.get_matrix()[3] * matrix.get_matrix()[9] -
				matrix.get_matrix()[8] * matrix.get_matrix()[1] * matrix.get_matrix()[7] +
				matrix.get_matrix()[8] * matrix.get_matrix()[3] * matrix.get_matrix()[5];

			invertedMatrix.get_matrix()[12] = -matrix.get_matrix()[4] * matrix.get_matrix()[9] * matrix.get_matrix()[14] +
				matrix.get_matrix()[4] * matrix.get_matrix()[10] * matrix.get_matrix()[13] +
				matrix.get_matrix()[8] * matrix.get_matrix()[5] * matrix.get_matrix()[14] -
				matrix.get_matrix()[8] * matrix.get_matrix()[6] * matrix.get_matrix()[13] -
				matrix.get_matrix()[12] * matrix.get_matrix()[5] * matrix.get_matrix()[10] +
				matrix.get_matrix()[12] * matrix.get_matrix()[6] * matrix.get_matrix()[9];

			invertedMatrix.get_matrix()[13] = matrix.get_matrix()[0] * matrix.get_matrix()[9] * matrix.get_matrix()[14] -
				matrix.get_matrix()[0] * matrix.get_matrix()[10] * matrix.get_matrix()[13] -
				matrix.get_matrix()[8] * matrix.get_matrix()[1] * matrix.get_matrix()[14] +
				matrix.get_matrix()[8] * matrix.get_matrix()[2] * matrix.get_matrix()[13] +
				matrix.get_matrix()[12] * matrix.get_matrix()[1] * matrix.get_matrix()[10] -
				matrix.get_matrix()[12] * matrix.get_matrix()[2] * matrix.get_matrix()[9];

			invertedMatrix.get_matrix()[14] = -matrix.get_matrix()[0] * matrix.get_matrix()[5] * matrix.get_matrix()[14] +
				matrix.get_matrix()[0] * matrix.get_matrix()[6] * matrix.get_matrix()[13] +
				matrix.get_matrix()[4] * matrix.get_matrix()[1] * matrix.get_matrix()[14] -
				matrix.get_matrix()[4] * matrix.get_matrix()[2] * matrix.get_matrix()[13] -
				matrix.get_matrix()[12] * matrix.get_matrix()[1] * matrix.get_matrix()[6] +
				matrix.get_matrix()[12] * matrix.get_matrix()[2] * matrix.get_matrix()[5];

			invertedMatrix.get_matrix()[15] = matrix.get_matrix()[0] * matrix.get_matrix()[5] * matrix.get_matrix()[10] -
				matrix.get_matrix()[0] * matrix.get_matrix()[6] * matrix.get_matrix()[9] -
				matrix.get_matrix()[4] * matrix.get_matrix()[1] * matrix.get_matrix()[10] +
				matrix.get_matrix()[4] * matrix.get_matrix()[2] * matrix.get_matrix()[9] +
				matrix.get_matrix()[8] * matrix.get_matrix()[1] * matrix.get_matrix()[6] -
				matrix.get_matrix()[8] * matrix.get_matrix()[2] * matrix.get_matrix()[5];



			determinant = matrix.get_matrix()[0] * invertedMatrix.get_matrix()[0] + matrix.get_matrix()[1] * invertedMatrix.get_matrix()[4] +
				matrix.get_matrix()[2] * invertedMatrix.get_matrix()[8] + matrix.get_matrix()[3] * invertedMatrix.get_matrix()[12];

			if (determinant == 0)
			{
				std::cout << "Divided by a matrix with a determinant of zero!\n";
				//return NULL;
			}

			determinant = 1.0f / determinant;

			invertedMatrix.get_matrix()[0] *= determinant;
			invertedMatrix.get_matrix()[1] *= determinant;
			invertedMatrix.get_matrix()[2] *= determinant;
			invertedMatrix.get_matrix()[3] *= determinant;
			invertedMatrix.get_matrix()[4] *= determinant;
			invertedMatrix.get_matrix()[5] *= determinant;
			invertedMatrix.get_matrix()[6] *= determinant;
			invertedMatrix.get_matrix()[7] *= determinant;
			invertedMatrix.get_matrix()[8] *= determinant;
			invertedMatrix.get_matrix()[9] *= determinant;
			invertedMatrix.get_matrix()[10] *= determinant;
			invertedMatrix.get_matrix()[11] *= determinant;
			invertedMatrix.get_matrix()[12] *= determinant;
			invertedMatrix.get_matrix()[13] *= determinant;
			invertedMatrix.get_matrix()[14] *= determinant;
			invertedMatrix.get_matrix()[15] *= determinant;


			return invertedMatrix;
		}


		matrix_4 matrix_4::operator/(matrix_4& pRightSide)
		{
			matrix_4 returnMatrix;


			returnMatrix = *this *  pRightSide.get_inverse();

			return returnMatrix;
		}

		void matrix_4::translate(vector_4 pTranslationVector)
		{
			matrix_4 translationMatrix;


			translationMatrix.get_matrix()[12] = pTranslationVector.mX;
			translationMatrix.get_matrix()[13] = pTranslationVector.mY;
			translationMatrix.get_matrix()[14] = pTranslationVector.mZ;

			*this = *this * translationMatrix;

		}

		void matrix_4::rotateX(float pAngle)
		{
			matrix_4 rotationMatrix = matrix_4();

			rotationMatrix.get_matrix()[5] = std::cos(-pAngle);
			rotationMatrix.get_matrix()[9] = -std::sin(-pAngle);
			rotationMatrix.get_matrix()[6] = std::sin(-pAngle);
			rotationMatrix.get_matrix()[10] = std::cos(-pAngle);

			*this = *this * rotationMatrix;

		}


		void matrix_4::rotateY(float pAngle)
		{
			matrix_4 rotationMatrix = matrix_4();

			rotationMatrix.get_matrix()[0] = std::cos(-pAngle);
			rotationMatrix.get_matrix()[8] = std::sin(-pAngle);
			rotationMatrix.get_matrix()[2] = -std::sin(-pAngle);
			rotationMatrix.get_matrix()[10] = std::cos(-pAngle);

			*this = *this * rotationMatrix;
		}


		void matrix_4::rotateZ(float pAngle)
		{
			matrix_4 rotationMatrix = matrix_4();

			rotationMatrix.get_matrix()[0] = std::cos(-pAngle);
			rotationMatrix.get_matrix()[4] = -std::sin(-pAngle);
			rotationMatrix.get_matrix()[1] = std::sin(-pAngle);
			rotationMatrix.get_matrix()[5] = std::cos(-pAngle);

			*this = *this * rotationMatrix;
		}

		void matrix_4::rotate(float pAngleX, float pAngleY, float pAngleZ)
		{
			matrix_4 rotationMatrix = matrix_4();


			//x rotation

			rotationMatrix.get_matrix()[5] = std::cos(-pAngleX);
			rotationMatrix.get_matrix()[9] = -std::sin(-pAngleX);
			rotationMatrix.get_matrix()[6] = std::sin(-pAngleX);
			rotationMatrix.get_matrix()[10] = std::cos(-pAngleX);

			*this = *this * rotationMatrix;

			//y rotation

			rotationMatrix = matrix_4();

			rotationMatrix.get_matrix()[0] = std::cos(-pAngleY);
			rotationMatrix.get_matrix()[8] = std::sin(-pAngleY);
			rotationMatrix.get_matrix()[2] = -std::sin(-pAngleY);
			rotationMatrix.get_matrix()[10] = std::cos(-pAngleY);

			*this = *this * rotationMatrix;


			//z rotation

			rotationMatrix = matrix_4();

			rotationMatrix.get_matrix()[0] = std::cos(-pAngleZ);
			rotationMatrix.get_matrix()[4] = -std::sin(-pAngleZ);
			rotationMatrix.get_matrix()[1] = std::sin(-pAngleZ);
			rotationMatrix.get_matrix()[5] = std::cos(-pAngleZ);

			*this = *this * rotationMatrix;


		}

		void matrix_4::make_ortho(const float &pMinimumXAxis, const float &pMaximumXAxis, const float &pMinimumYAxis,
			const float &pMaximumYAxis, const float &pMinimumZAxis, const float &pMaximumZAxis)
		{
			set_identity();

			float inverseXAxesDifference = 1 / (pMaximumXAxis - pMinimumXAxis);
			float inverseYAxesDifference = 1 / (pMaximumYAxis - pMinimumYAxis);
			float inverseZAxesDifference = 1 / (pMaximumZAxis - pMinimumZAxis);

			mMatrix[0] = 2.0f * inverseXAxesDifference;
			mMatrix[5] = 2.0f * inverseYAxesDifference;
			mMatrix[10] = -2.0f * inverseZAxesDifference;
			mMatrix[12] = -(pMaximumXAxis + pMinimumXAxis) * inverseXAxesDifference;
			mMatrix[13] = -(pMaximumYAxis + pMinimumYAxis) * inverseYAxesDifference;
			mMatrix[14] = -(pMaximumZAxis + pMinimumZAxis) * inverseZAxesDifference;
		}


		void matrix_4::make_perspective(const float &pFieldOfView, const float &pNearClippingPlane, const float &pFarClippingPlane, const float& pScreenAspect)
		{

			float scale = (float)(1.0f / (tan(mathTool.degrees_to_radians(pFieldOfView * 0.5f))));

			float inverseClippingPlaneDifference = 1.0f / (pFarClippingPlane - pNearClippingPlane);

			mMatrix[0] = scale * pScreenAspect;
			mMatrix[5] = scale;
			mMatrix[10] = -pFarClippingPlane * inverseClippingPlaneDifference;
			mMatrix[11] = -1;
			mMatrix[14] = -pFarClippingPlane * pNearClippingPlane * inverseClippingPlaneDifference;
			mMatrix[15] = 0;

		}

		void matrix_4::make_look_at(vector_3 pLookingPosition, vector_3 pTargetPosition)
		{
			vector_3 forward(pLookingPosition - pTargetPosition);
			forward.normalize();

			vector_3 tmp(0.0f, 1.0f, 0.0f);
			tmp.normalize();

			vector_3 right;
			right = tmp.cross_product(tmp, forward);
			vector_3 up;
			up = tmp.cross_product(forward, right);

			mMatrix[0] = right.mX;
			mMatrix[1] = up.mX;
			mMatrix[2] = forward.mX;
			mMatrix[3] = pLookingPosition.mX;
			mMatrix[4] = right.mY;
			mMatrix[5] = up.mY;
			mMatrix[6] = forward.mY;
			mMatrix[7] = pLookingPosition.mY;
			mMatrix[8] = right.mZ;
			mMatrix[9] = up.mZ;
			mMatrix[10] = forward.mZ;
			mMatrix[11] = pLookingPosition.mZ;

		}


		void matrix_4::assign_matrix(float pMatrix[])
		{
			pMatrix[0] = mMatrix[0];
			pMatrix[1] = mMatrix[1];
			pMatrix[2] = mMatrix[2];
			pMatrix[3] = mMatrix[3];
			pMatrix[4] = mMatrix[4];
			pMatrix[5] = mMatrix[5];
			pMatrix[6] = mMatrix[6];
			pMatrix[7] = mMatrix[7];
			pMatrix[8] = mMatrix[8];
			pMatrix[9] = mMatrix[9];
			pMatrix[10] = mMatrix[10];
			pMatrix[11] = mMatrix[11];
			pMatrix[12] = mMatrix[12];
			pMatrix[13] = mMatrix[13];
			pMatrix[14] = mMatrix[14];
			pMatrix[15] = mMatrix[15];
		}
	}

}

