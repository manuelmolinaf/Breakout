#include "matrix_4.hpp"
#include <math.h>
#include <iostream>

namespace engine
{



	matrix_4::matrix_4()
	{

		initialize_matrix();

		for (int column = 0; column < 4; column++)
		{
			for (int row = 0; row < 4; row++)
			{
				if (column == row)
				{
					mMatrix[row][column] = 1.0f;
				}
				else
				{
					mMatrix[row][column] = 0.0f;
				}
			}
		}

	}

	matrix_4::matrix_4(float pFirstPosition, float pSecondPosition, float pThirdPosition, float pFourthPosition,   float pFithPosition,     float pSixthPosition,      float pSeventhPosition,
					   float pEigthPosition, float pNinethPosition, float pTenthPosition, float pEleventhPosition, float pTwelvethPosition, float pThirteenthPosition, float pFourteenthPosition,
					   float pFithteenthPosition, float pSixteenthPosition)
	{

		initialize_matrix();

		mMatrix[0][0] = pFirstPosition;
		mMatrix[1][0] = pSecondPosition;
		mMatrix[2][0] = pThirdPosition;
		mMatrix[3][0] = pFourthPosition;
		mMatrix[0][1] = pFithPosition;
		mMatrix[1][1] = pSixthPosition;
		mMatrix[2][1] = pSeventhPosition;
		mMatrix[3][1] = pEigthPosition;
		mMatrix[0][2] = pNinethPosition;
		mMatrix[1][2] = pTenthPosition;
		mMatrix[2][2] = pEleventhPosition;
		mMatrix[3][2] = pTwelvethPosition;
		mMatrix[0][3] = pThirteenthPosition;
		mMatrix[1][3] = pFourteenthPosition;
		mMatrix[2][3] = pFithteenthPosition;
		mMatrix[3][3] = pSixteenthPosition;

	}

	matrix_4::matrix_4(float pValuesArray[16])
	{
		initialize_matrix();

		int i = 0;

		for (int row = 0; row < 4; row++)
		{
			for (int column = 0; column < 4; column++)
			{
				mMatrix[column][row] = pValuesArray[i];
				i++;
			}
		}

	}


	void matrix_4::initialize_matrix()
	{
		mMatrix = new float*[4];

		for (int i = 0; i < 4; i++)
		{
			mMatrix[i] = new float[4];
		}
	}


	float* matrix_4::get_row(int pRowNumber)
	{
		float row[4];

		for (int i = 0; i < 4; i++)
		{
			row[i] = mMatrix[pRowNumber][i];
		}

		return row;
	}


	float* matrix_4::get_column(int pColumnNumber)
	{
		float column[4];

		for (int i = 0; i < 4; i++)
		{
			column[i] = mMatrix[i][pColumnNumber];
		}

		return column;
	}

	float** matrix_4::get_matrix()
	{
		return mMatrix;
	}


	matrix_4  matrix_4::get_transpose()
	{
		matrix_4 transposedMatrix;


		for (int row = 0; row < 4; row++)
		{
			for (int column = 0; column < 4; column++)
			{
				transposedMatrix.get_matrix()[row][column] = mMatrix[column][row];
			}
		}

		return transposedMatrix;
	}

	void matrix_4::set_identity()
	{
		for (int column = 0; column < 4; column++)
		{
			for (int row = 0; row < 4; row++)
			{
				if (column == row)
				{
					mMatrix[row][column] = 1;
				}
				else
				{
					mMatrix[row][column] = 0;
				}
			}
		}
	}


	vector_3 matrix_4::get_angle()
	{
		vector_3 angles;

		if (mMatrix[0][0] == 1.0f || mMatrix[0][0] == -1.0f)
		{
			angles.mX = 0; //pitch
			angles.mY = atan2f(mMatrix[0][2], mMatrix[2][3]); //yaw
			angles.mZ = 0; //roll

		}
		else
		{

			angles.mX = (float)asin(mMatrix[1][0]); //pitch
			angles.mY = atan2f(-mMatrix[2][0], mMatrix[0][0]); //yaw
			angles.mZ = atan2f(-mMatrix[1][2], mMatrix[1][1]); //roll
		}

		return angles;
	}

	std::ostream& operator<<(std::ostream& pOstream, matrix_4 pMatrix)
	{
		for (int row = 0; row < 4; row++)
		{
			for (int column = 0; column < 4; column++)
			{
				pOstream<<pMatrix.get_matrix()[row][column]<<" ";
			}
			pOstream<<"\n";
		}

		return pOstream;
	}

	float& matrix_4::operator[](const int pRightSide)
	{
		int row = pRightSide % 4;
		int column = pRightSide / 4;

		return mMatrix[row][column];
	}


	matrix_4 matrix_4::operator=(matrix_4& pRightSide)
	{
		matrix_4 returnMatrix;

		for (int column = 0; column < 4; column++)
		{
			for (int row = 0; row < 4; row++)
			{
				mMatrix[row][column] = pRightSide.get_matrix()[row][column];
			}
		}

		return returnMatrix;
	}

	matrix_4 matrix_4::operator+(matrix_4& pRightSide)
	{

		matrix_4 returnMatrix;

		for (int column = 0; column < 4; column++)
		{
			for (int row = 0; row < 4; row++)
			{
				returnMatrix.get_matrix()[row][column] = mMatrix[row][column] + pRightSide.get_matrix()[row][column];
			}
		}

		return returnMatrix;
	}

	matrix_4 matrix_4::operator-(matrix_4& pRightSide)
	{

		matrix_4 returnMatrix;

		for (int column = 0; column < 4; column++)
		{
			for (int row = 0; row < 4; row++)
			{
				returnMatrix.get_matrix()[row][column] = mMatrix[row][column] - pRightSide.get_matrix()[row][column];
			}
		}

		return returnMatrix;
	}

	matrix_4 matrix_4::operator*(matrix_4& pRightSide)
	{

		matrix_4 returnMatrix;
		
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				returnMatrix.get_matrix()[i][j] = 0;
			}
		}
		
		for (int row = 0; row < 4; row++)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					returnMatrix.get_matrix()[row][i] += mMatrix[row][j] * pRightSide.mMatrix[j][i];
				}
			}
		}

		return returnMatrix;
	}
	
	matrix_4 matrix_4::get_inverse()
	{
		matrix_4 matrix, invertedMatrix;

		float determinant;

		for (int row = 0; row < 4; row++)
		{
			for (int column = 0; column < 4; column++)
			{
				matrix.get_matrix()[row][column] = mMatrix[row][column];
			}
		}

		invertedMatrix[0] = matrix[5] * matrix[10] * matrix[15] -
							matrix[5] * matrix[11] * matrix[14] -
							matrix[9] * matrix[6] * matrix[15] +
							matrix[9] * matrix[7] * matrix[14] +
							matrix[13] * matrix[6] * matrix[11] -
							matrix[13] * matrix[7] * matrix[10];

		invertedMatrix[1] = -matrix[1] * matrix[10] * matrix[15] +
							 matrix[1] * matrix[11] * matrix[14] +
							 matrix[9] * matrix[2] * matrix[15] -
							 matrix[9] * matrix[3] * matrix[14] -
							 matrix[13] * matrix[2] * matrix[11] +
							 matrix[13] * matrix[3] * matrix[10];

		invertedMatrix[2] = matrix[1] * matrix[6] * matrix[15] -
							matrix[1] * matrix[7] * matrix[14] -
							matrix[5] * matrix[2] * matrix[15] +
							matrix[5] * matrix[3] * matrix[14] +
							matrix[13] * matrix[2] * matrix[7] -
							matrix[13] * matrix[3] * matrix[6];

		invertedMatrix[3] = -matrix[1] * matrix[6] * matrix[11] +
							 matrix[1] * matrix[7] * matrix[10] +
							 matrix[5] * matrix[2] * matrix[11] -
							 matrix[5] * matrix[3] * matrix[10] -
							 matrix[9] * matrix[2] * matrix[7] +
							 matrix[9] * matrix[3] * matrix[6];

		invertedMatrix[4] = -matrix[4] * matrix[10] * matrix[15] +
							 matrix[4] * matrix[11] * matrix[14] +
							 matrix[8] * matrix[6] * matrix[15] -
							 matrix[8] * matrix[7] * matrix[14] -
							 matrix[12] * matrix[6] * matrix[11] +
							 matrix[12] * matrix[7] * matrix[10];

		invertedMatrix[5] = matrix[0] * matrix[10] * matrix[15] -
							matrix[0] * matrix[11] * matrix[14] -
							matrix[8] * matrix[2] * matrix[15] +
							matrix[8] * matrix[3] * matrix[14] +
							matrix[12] * matrix[2] * matrix[11] -
							matrix[12] * matrix[3] * matrix[10];

		invertedMatrix[6] = -matrix[0] * matrix[6] * matrix[15] +
							 matrix[0] * matrix[7] * matrix[14] +
							 matrix[4] * matrix[2] * matrix[15] -
							 matrix[4] * matrix[3] * matrix[14] -
							 matrix[12] * matrix[2] * matrix[7] +
							 matrix[12] * matrix[3] * matrix[6];
		
		invertedMatrix[7] = matrix[0] * matrix[6] * matrix[11] -
							matrix[0] * matrix[7] * matrix[10] -
							matrix[4] * matrix[2] * matrix[11] +
							matrix[4] * matrix[3] * matrix[10] +
							matrix[8] * matrix[2] * matrix[7] -
							matrix[8] * matrix[3] * matrix[6];

		invertedMatrix[8] = matrix[4] * matrix[9] * matrix[15] -
							matrix[4] * matrix[11] * matrix[13] -
							matrix[8] * matrix[5] * matrix[15] +
							matrix[8] * matrix[7] * matrix[13] +
							matrix[12] * matrix[5] * matrix[11] -
							matrix[12] * matrix[7] * matrix[9];

		invertedMatrix[9] = -matrix[0] * matrix[9] * matrix[15] +
							 matrix[0] * matrix[11] * matrix[13] +
							 matrix[8] * matrix[1] * matrix[15] -
							 matrix[8] * matrix[3] * matrix[13] -
							 matrix[12] * matrix[1] * matrix[11] +
							 matrix[12] * matrix[3] * matrix[9];

		invertedMatrix[10] = matrix[0] * matrix[5] * matrix[15] -
							 matrix[0] * matrix[7] * matrix[13] -
							 matrix[4] * matrix[1] * matrix[15] +
							 matrix[4] * matrix[3] * matrix[13] +
							 matrix[12] * matrix[1] * matrix[7] -
							 matrix[12] * matrix[3] * matrix[5];

		invertedMatrix[11] = -matrix[0] * matrix[5] * matrix[11] +
							  matrix[0] * matrix[7] * matrix[9] +
							  matrix[4] * matrix[1] * matrix[11] -
							  matrix[4] * matrix[3] * matrix[9] -
							  matrix[8] * matrix[1] * matrix[7] +
						  	  matrix[8] * matrix[3] * matrix[5];

		invertedMatrix[12] = -matrix[4] * matrix[9] * matrix[14] +
							  matrix[4] * matrix[10] * matrix[13] +
							  matrix[8] * matrix[5] * matrix[14] -
							  matrix[8] * matrix[6] * matrix[13] -
							  matrix[12] * matrix[5] * matrix[10] +
							  matrix[12] * matrix[6] * matrix[9];

		invertedMatrix[13] = matrix[0] * matrix[9] * matrix[14] -
						  	 matrix[0] * matrix[10] * matrix[13] -
							 matrix[8] * matrix[1] * matrix[14] +
							 matrix[8] * matrix[2] * matrix[13] +
							 matrix[12] * matrix[1] * matrix[10] -
							 matrix[12] * matrix[2] * matrix[9];

		invertedMatrix[14] = -matrix[0] * matrix[5] * matrix[14] +
							  matrix[0] * matrix[6] * matrix[13] +
							  matrix[4] * matrix[1] * matrix[14] -
							  matrix[4] * matrix[2] * matrix[13] -
							  matrix[12] * matrix[1] * matrix[6] +
							  matrix[12] * matrix[2] * matrix[5];

		invertedMatrix[15] = matrix[0] * matrix[5] * matrix[10] -
							 matrix[0] * matrix[6] * matrix[9] -
							 matrix[4] * matrix[1] * matrix[10] +
							 matrix[4] * matrix[2] * matrix[9] +
							 matrix[8] * matrix[1] * matrix[6] -
		  					 matrix[8] * matrix[2] * matrix[5];
		
		

		determinant = matrix[0] * invertedMatrix[0] + matrix[1] * invertedMatrix[4] + matrix[2] * invertedMatrix[8] + matrix[3] * invertedMatrix[12];

		if (determinant == 0)
		{
			for (int row = 0; row < 4; row++)
			{
				for (int column = 0; column < 4; column++)
				{
					invertedMatrix.get_matrix()[row][column] = 0;
				}
			}
			return invertedMatrix;

		}

		determinant = 1.0f / determinant;

		for (int i = 0; i < 16; i++)
		{
			invertedMatrix[i] *= determinant;
		}
			

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
		matrix_4 translationMatrix = matrix_4();
		matrix_4 resultMatrix;

		for (int row = 0; row < 4; row++)
		{
			for (int column = 0; column < 4; column++)
			{
				resultMatrix.get_matrix()[row][column] = mMatrix[row][column];
			}
		}

		translationMatrix[12] = pTranslationVector.mX;
		translationMatrix[13] = pTranslationVector.mY;
		translationMatrix[14] = pTranslationVector.mZ;

		resultMatrix = translationMatrix * resultMatrix;

		for (int row = 0; row < 4; row++)
		{
			for (int column = 0; column < 4; column++)
			{
				mMatrix[row][column]= resultMatrix.get_matrix()[row][column];
			}
		}

	}

	void matrix_4::rotateX(float pAngle)
	{
		matrix_4 rotationMatrix = matrix_4();
		matrix_4 resultMatrix;

		for (int row = 0; row < 4; row++)
		{
			for (int column = 0; column < 4; column++)
			{
				resultMatrix.get_matrix()[row][column] = mMatrix[row][column];
			}
		}

		rotationMatrix[5] = std::cos(-pAngle);
		rotationMatrix[9] = -std::sin(-pAngle);
		rotationMatrix[6] = std::sin(-pAngle);
		rotationMatrix[10] = std::cos(-pAngle);
		
		resultMatrix = rotationMatrix* resultMatrix;

		for (int row = 0; row < 4; row++)
		{
			for (int column = 0; column < 4; column++)
			{
				mMatrix[row][column] = resultMatrix.get_matrix()[row][column];
			}
		}

	}


	void matrix_4::rotateY(float pAngle)
	{
		matrix_4 rotationMatrix = matrix_4();
		matrix_4 resultMatrix;

		for (int row = 0; row < 4; row++)
		{
			for (int column = 0; column < 4; column++)
			{
				resultMatrix.get_matrix()[row][column] = mMatrix[row][column];
			}
		}

		rotationMatrix[0] = std::cos(-pAngle);
		rotationMatrix[8] = std::sin(-pAngle);
		rotationMatrix[2] = -std::sin(-pAngle);
		rotationMatrix[10] = std::cos(-pAngle);

		resultMatrix = rotationMatrix * resultMatrix;

		for (int row = 0; row < 4; row++)
		{
			for (int column = 0; column < 4; column++)
			{
				mMatrix[row][column] = resultMatrix.get_matrix()[row][column];
			}
		}

	}


	void matrix_4::rotateZ(float pAngle)
	{
		matrix_4 rotationMatrix = matrix_4();
		matrix_4 resultMatrix;

		for (int row = 0; row < 4; row++)
		{
			for (int column = 0; column < 4; column++)
			{
				resultMatrix.get_matrix()[row][column] = mMatrix[row][column];
			}
		}

		rotationMatrix[0] = std::cos(-pAngle);
		rotationMatrix[4] = -std::sin(-pAngle);
		rotationMatrix[1] = std::sin(-pAngle);
		rotationMatrix[5] = std::cos(-pAngle);

		resultMatrix = rotationMatrix * resultMatrix;

		for (int row = 0; row < 4; row++)
		{
			for (int column = 0; column < 4; column++)
			{
				mMatrix[row][column] = resultMatrix.get_matrix()[row][column];
			}
		}

	}

	void matrix_4::rotate(float pAngleX, float pAngleY, float pAngleZ)
	{
		matrix_4 rotationMatrix = matrix_4();
		matrix_4 resultMatrix;

		//x rotation
		for (int row = 0; row < 4; row++)
		{
			for (int column = 0; column < 4; column++)
			{
				resultMatrix.get_matrix()[row][column] = mMatrix[row][column];
			}
		}

		rotationMatrix[5] = std::cos(-pAngleX);
		rotationMatrix[9] = -std::sin(-pAngleX);
		rotationMatrix[6] = std::sin(-pAngleX);
		rotationMatrix[10] = std::cos(-pAngleX);

		resultMatrix = rotationMatrix * resultMatrix;

		for (int row = 0; row < 4; row++)
		{
			for (int column = 0; column < 4; column++)
			{
				mMatrix[row][column] = resultMatrix.get_matrix()[row][column];
			}
		}

		//y rotation

		rotationMatrix = matrix_4();

		for (int row = 0; row < 4; row++)
		{
			for (int column = 0; column < 4; column++)
			{
				resultMatrix.get_matrix()[row][column] = mMatrix[row][column];
			}
		}

		rotationMatrix[0] = std::cos(-pAngleY);
		rotationMatrix[8] = std::sin(-pAngleY);
		rotationMatrix[2] = -std::sin(-pAngleY);
		rotationMatrix[10] = std::cos(-pAngleY);

		resultMatrix = rotationMatrix * resultMatrix;

		for (int row = 0; row < 4; row++)
		{
			for (int column = 0; column < 4; column++)
			{
				mMatrix[row][column] = resultMatrix.get_matrix()[row][column];
			}
		}


		//z rotation

		rotationMatrix = matrix_4();

		for (int row = 0; row < 4; row++)
		{
			for (int column = 0; column < 4; column++)
			{
				resultMatrix.get_matrix()[row][column] = mMatrix[row][column];
			}
		}

		rotationMatrix[0] = std::cos(-pAngleZ);
		rotationMatrix[4] = -std::sin(-pAngleZ);
		rotationMatrix[1] = std::sin(-pAngleZ);
		rotationMatrix[5] = std::cos(-pAngleZ);

		resultMatrix = rotationMatrix * resultMatrix;

		for (int row = 0; row < 4; row++)
		{
			for (int column = 0; column < 4; column++)
			{
				mMatrix[row][column] = resultMatrix.get_matrix()[row][column];
			}
		}


	}


	


}

