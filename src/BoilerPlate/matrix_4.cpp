#include "matrix_4.hpp"

namespace engine
{

	matrix_4::matrix_4()
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

	matrix_4::matrix_4(float pFirstPosition, float pSecondPosition, float pThirdPosition, float pFourthPosition, float pFithPosition, float pSixthPosition, float pSeventhPosition,
		float pEigthPosition, float pNinethPosition, float pTenthPosition, float pEleventhPosition, float pTwelvethPosition, float pThirteenthPosition, float pFourteenthPosition,
		float pFithteenthPosition, float pSixteenthPosition)
	{

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

		for (int array_position = 0; array_position < 16; array_position++)
		{
			for (int row = 0; row < 4; row++)
			{
				for (int column = 0; column < 4; column++)
				{
					mMatrix[row][column] = pValuesArray[array_position];
				}
			}
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

	float* matrix_4::get_matrix()
	{
		return *mMatrix;
	}


	float* matrix_4::get_transpose()
	{
		float transposedMatrix[4][4];

		for (int column = 0; column < 4; column++)
		{
			for (int row = 0; row < 4; row++)
			{
				transposedMatrix[row][column] = mMatrix[column][row];
			}
		}

		return *transposedMatrix;
	}


}
