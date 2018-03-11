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

		matrix_4(float, float, float, float, float, float, float,
			     float, float, float, float, float, float, float, 
			     float, float);

		matrix_4(float[16]);

		//public members

		float matrix[4][4];

		//public functions

		float* get_row();
		float* get_column();
		float* get_matrix();
		float* get_transpose();



	private:





	};
}

#endif