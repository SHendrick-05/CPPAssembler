using namespace System;
using namespace System::Collections::Generic;
using namespace System::Text;
using namespace System::Threading::Tasks;

#include "CodeAssembler.h"



Assembler::Instruction^ Assembler::CodeAssembler::DecodeInstruction(String^ input)
{
	// Sanitise string
	Instruction^ result = gcnew Instruction();
	List<String^>^ splitInput = gcnew List<String^>(input->Split(' '));
	for (int i = splitInput->Count-1; i > -1; i--)
	{
		if (String::IsNullOrWhiteSpace(splitInput[i])) 
			splitInput->RemoveAt(i);
	}

	//Get opcode of instruction
	String^ opc = splitInput[0]->ToUpper();
	if (Opcodes->ContainsKey(opc))
		result->Opcode = Opcodes[opc];
	else
	{
		result->Opcode = 10;
		result->Label = opc;
	}

	// Get labels if branch
	if (result->Opcode >= 5 && result->Opcode <= 8)
		result->Label = splitInput[1];

	// Get operand(s) of instruction if they exist.
	else if (splitInput->Count != 1)
	{
		splitInput->RemoveAt(0);
		for(int i = 0; i < splitInput->Count; i++)
		{
			splitInput[i] = splitInput[i]->ToUpper();
		}
		result->Operands = splitInput->ToArray();
	}

	// Return the completed instruction
	return result;
}