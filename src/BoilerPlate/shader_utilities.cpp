#include "shader_utilities.hpp"
#include "error_message_manager.hpp"

#include <string>
#include <vector>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<sstream>

engine::error_message_manager errorManager;

namespace engine
{


	shader_utilities::shader_utilities()
	{

	}

	GLuint shader_utilities::LoadShaders(const char* pVertexFilePath, const char* pFragmentFilePath)
	{
		// Create the shaders
		GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
		GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

		// Read the Vertex Shader code from the file
		std::string VertexShaderCode;
		std::ifstream VertexShaderStream(pVertexFilePath, std::ios::in);
		if (VertexShaderStream.is_open()) {
			std::stringstream sstr;
			sstr << VertexShaderStream.rdbuf();
			VertexShaderCode = sstr.str();
			VertexShaderStream.close();
		}
		else 
		{
			errorManager.DisplayErrorMessageBox(pVertexFilePath, "30", "Impossible to open file. Are you in the right directory ?", " " );
			//printf("Impossible to open %s. Are you in the right directory ? Don't forget to read the FAQ !\n", pVertexFilePath);
			getchar();
			return 0;
		}

		//errorManager.DisplayErrorMessageBox();

		// Read the Fragment Shader code from the file
		std::string FragmentShaderCode;
		std::ifstream FragmentShaderStream(pFragmentFilePath, std::ios::in);
		if (FragmentShaderStream.is_open()) {
			std::stringstream sstr;
			sstr << FragmentShaderStream.rdbuf();
			FragmentShaderCode = sstr.str();
			FragmentShaderStream.close();
		}

		GLint Result = GL_FALSE;
		int InfoLogLength;


		// Compile Vertex Shader
		printf("Compiling shader : %s\n", pVertexFilePath);
		char const * VertexSourcePointer = VertexShaderCode.c_str();
		glShaderSource(VertexShaderID, 1, &VertexSourcePointer, NULL);
		glCompileShader(VertexShaderID);

		// Check Vertex Shader
		glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
		glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
		if (InfoLogLength > 0) {
			std::vector<char> VertexShaderErrorMessage(InfoLogLength + 1);
			glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
			errorManager.DisplayErrorMessageBox(pVertexFilePath, "69", &VertexShaderErrorMessage[0], " ");
			//printf("%s\n", &VertexShaderErrorMessage[0]);
		}



		// Compile Fragment Shader
		printf("Compiling shader : %s\n", pFragmentFilePath);
		char const * FragmentSourcePointer = FragmentShaderCode.c_str();
		glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer, NULL);
		glCompileShader(FragmentShaderID);

		// Check Fragment Shader
		glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
		glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
		if (InfoLogLength > 0) {
			std::vector<char> FragmentShaderErrorMessage(InfoLogLength + 1);
			glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
			errorManager.DisplayErrorMessageBox(pFragmentFilePath, "87", &FragmentShaderErrorMessage[0], " ");
			//printf("%s\n", &FragmentShaderErrorMessage[0]);
		}



		// Link the program
		printf("Linking program\n");
		GLuint ProgramID = glCreateProgram();
		glAttachShader(ProgramID, VertexShaderID);
		glAttachShader(ProgramID, FragmentShaderID);
		glLinkProgram(ProgramID);

		// Check the program
		glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
		glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
		if (InfoLogLength > 0) {
			std::vector<char> ProgramErrorMessage(InfoLogLength + 1);
			glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
			errorManager.DisplayErrorMessageBox(pVertexFilePath, "106", &ProgramErrorMessage[0], " ");
			//printf("%s\n", &ProgramErrorMessage[0]);
		}


		glDetachShader(ProgramID, VertexShaderID);
		glDetachShader(ProgramID, FragmentShaderID);

		glDeleteShader(VertexShaderID);
		glDeleteShader(FragmentShaderID);

		return ProgramID;
	}

}