#include "error_message_manager.hpp"

#include <Windows.h>

namespace engine
{

	int error_message_manager::DisplayErrorMessageBox(std::string fileName, std::string fileLine, std::string errorMessage, std::string rawErrorMessage)
	{

		std::string complete_message = "File name: " + fileName + "\nFile Line: " + fileLine + "\n" + errorMessage + "\nUsing OpenGL 3.30 and GLSL 330 core";
		LPCSTR display_message = complete_message.c_str();

		#ifdef _WIN32
		
		int msgboxID = MessageBoxA(
			NULL,
			display_message,
			rawErrorMessage.c_str(),
			MB_ICONWARNING | MB_OK
		);

		#elif defined _unix_ || defined APPLE

		std::cerr << complete_message;

		#endif
		return msgboxID;
	}

}