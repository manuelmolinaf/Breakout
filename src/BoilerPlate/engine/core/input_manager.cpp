#include "input_manager.hpp"

input_manager::input_manager()
{
	W_KEY = false;
	A_KEY = false;
	S_KEY = false;
	D_KEY = false;
	Q_KEY = false;
	E_KEY = false;
	F_KEY = false;
	R_KEY = false;
	Z_KEY = false;
	G_KEY = false;
	T_KEY = false;
	ENTER_KEY = false;
	SPACE_KEY = false;
}

void input_manager::SetW(bool value)
{
	W_KEY = value;
}

void input_manager::SetA(bool value)
{
	A_KEY = value;
}

void input_manager::SetS(bool value)
{
	S_KEY = value;
}

void input_manager::SetD(bool value)
{
	D_KEY = value;
}

void input_manager::SetQ(bool value)
{
	Q_KEY = value;
}

void input_manager::SetE(bool value)
{
	E_KEY = value;
}

void input_manager::SetF(bool value)
{
	F_KEY = value;
}

void input_manager::SetR(bool value)
{
	R_KEY = value;
}

void input_manager::SetZ(bool value)
{
	Z_KEY = value;
}

void input_manager::SetG(bool value)
{
	G_KEY = value;
}

void input_manager::SetENTER(bool value)
{
	ENTER_KEY = value;
}

void input_manager::SetSPACE(bool value)
{
	SPACE_KEY = value;
}

void input_manager::SetT(bool value)
{
	T_KEY = value;
}




bool input_manager::W_IsPressed()
{
	return W_KEY;
}

bool input_manager::A_IsPressed()
{
	return A_KEY;
}

bool input_manager::S_IsPressed()
{
	return S_KEY;
}

bool input_manager::D_IsPressed()
{
	return D_KEY;
}

bool input_manager::Q_IsPressed()
{
	return Q_KEY;
}

bool input_manager::E_IsPressed()
{
	return E_KEY;
}

bool input_manager::F_IsPressed()
{
	return F_KEY;
}

bool input_manager::R_IsPressed()
{
	return R_KEY;
}

bool input_manager::Z_IsPressed()
{
	return Z_KEY;
}

bool input_manager::G_IsPressed()
{
	return G_KEY;
}

bool input_manager::T_IsPressed()
{
	return T_KEY;
}

bool input_manager::ENTER_IsPrerssed()
{
	return ENTER_KEY;
}

bool input_manager::SPACE_IsPressed()
{
	return SPACE_KEY;
}
