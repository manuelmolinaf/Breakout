#include "matrix_4.hpp"

namespace engine
{
	matrix_4::matrix_4()
	{

		for (int row = 0; row < 4; row++)
		{
			for (int column = 0; column < 4; column++)
			{
				if (row == column)
				{
					matrix[row][column] = 1;
				}
				else
				{
					matrix[row][column] = 0;
				}
			}
		}
	}

	matrix_4::matrix_4(float first_position, float second_position, float third_position, float fourth_position, float fith_position, float sixth_position, float seventh_position,
		               float eigth_position, float nineth_position, float tenth_position, float eleventh_position, float twelveth_position, float thirteenth_position, float fourteenth_position,
		               float fithteenth_position, float sixteenth_position)
	{

		matrix[0][0] = first_position;
		matrix[0][1] = second_position;
		matrix[0][2] = third_position;
		matrix[0][3] = fourth_position;
		matrix[1][0] = fith_position;
		matrix[1][1] = sixth_position;
		matrix[1][2] = seventh_position;
		matrix[1][3] = eigth_position;
		matrix[2][0] = nineth_position;
		matrix[2][1] = tenth_position;
		matrix[2][2] = eleventh_position;
		matrix[2][3] = twelveth_position;
		matrix[3][0] = thirteenth_position;
		matrix[3][1] = fourteenth_position;
		matrix[3][2] = fithteenth_position;
		matrix[3][3] = sixteenth_position;

	}

	matrix_4::matrix_4(float values_array[16])
	{
		
		for (int array_position = 0; array_position < 16; array_position++)
		{
			for (int row = 0; row < 4; row++)
			{
				for (int column = 0; column < 4; column++)
				{
					matrix[row][column] = values_array[array_position];
				}
			}
		}

	}



}
