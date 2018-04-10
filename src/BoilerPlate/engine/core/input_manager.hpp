#pragma once
#pragma once

#ifndef _INPUTMANAGER_HPP
#define _INPUTMANAGER_HPP


class input_manager
{
public:

	input_manager();

	void SetW(bool);
	void SetA(bool);
	void SetS(bool);
	void SetD(bool);
	void SetQ(bool);
	void SetE(bool);
	void SetF(bool);
	void SetR(bool);
	void SetZ(bool);
	void SetG(bool);
	void SetT(bool);
	void SetENTER(bool);
	void SetSPACE(bool);

	bool W_IsPressed();
	bool A_IsPressed();
	bool S_IsPressed();
	bool D_IsPressed();
	bool Q_IsPressed();
	bool E_IsPressed();
	bool F_IsPressed();
	bool R_IsPressed();
	bool Z_IsPressed();
	bool G_IsPressed();
	bool T_IsPressed();
	bool SPACE_IsPressed();
	bool ENTER_IsPrerssed();

private:

	bool W_KEY;
	bool A_KEY;
	bool S_KEY;
	bool D_KEY;
	bool Q_KEY;
	bool E_KEY;
	bool F_KEY;
	bool R_KEY;
	bool Z_KEY;
	bool G_KEY;
	bool T_KEY;
	bool ENTER_KEY;
	bool SPACE_KEY;



};

#endif