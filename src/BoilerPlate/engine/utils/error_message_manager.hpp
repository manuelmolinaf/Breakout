#pragma once
#include <iostream>

#ifndef ERROR_MESSAGE_MANAGER_HPP
#define ERROR_MESSAGE_MANAGER_HPP

namespace engine
{

	struct error_message_manager
	{
	public:

		int DisplayErrorMessageBox(std::string fileName, std::string fileLine, std::string errorMessage, std::string rawErrorMessage);


	};

}

#endif
