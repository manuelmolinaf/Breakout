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


	float**  matrix_4::get_transpose()
	{
		matrix_4 transposedMatrix;


		for (int row = 0; row < 4; row++)
		{
			for (int column = 0; column < 4; column++)
			{
				transposedMatrix.get_matrix()[row][column] = mMatrix[column][row];
			}
		}

		return transposedMatrix.get_matrix();
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
			angles.m_x = 0; //pitch
			angles.m_y = atan2f(mMatrix[0][2], mMatrix[2][3]); //yaw
			angles.m_z = 0; //roll

		}
		else
		{

			angles.m_x = (float)asin(mMatrix[1][0]); //pitch
			angles.m_y = atan2f(-mMatrix[2][0], mMatrix[0][0]); //yaw
			angles.m_z = atan2f(-mMatrix[1][2], mMatrix[1][1]); //roll
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



}

