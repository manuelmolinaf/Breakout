#pragma once

#ifndef MATRIX_4_HPP
#define MATRIX_4_HPP

namespace engine
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

		float mMatrix[4][4];

		//public functions

		float* get_row(int pRowNumber);
		float* get_column(int pColumnNumber);
		float* get_matrix();
		float* get_transpose();

		void set_identity();





	private:





	};
	
}

#endif