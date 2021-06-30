using namespace System;

#include "Prompt.h"

void Assembler::Prompt::enter_Click(Object^, EventArgs^) {
	this->Close();
}

Decimal^ Assembler::Prompt::ShowPrompt()
{
	Prompt^ prmpt = gcnew Prompt();
	return prmpt->ShowDialog() == System::Windows::Forms::DialogResult::OK ? prmpt->input->Value : 0;
}