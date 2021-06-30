using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;

#include "Main.h"
#include "Prompt.h"
#include "CodeHandler.h"

Control^ Assembler::CodeHandler::stateBox::get()
{
	return usedForm->Controls->Find("stateBox", true)[0];
}

TextBox^ Assembler::CodeHandler::output::get()
{
	return (TextBox^)usedForm->Controls->Find("outputBox", true)[0];
}

void Assembler::CodeHandler::Start(Main^ form)
{
	usedForm = form;
	output->Clear();
	//Handle labels
	for(int i = 0; i < instrList->Count; i++)
	{
		Instruction^ instr = instrList[i];
		if (instr->Opcode == 10)
		{
			if (!labels->ContainsKey(instr->Label))
				labels->Add(instr->Label, instrList->IndexOf(instr));
			else if (labels[instr->Label] != instrList->IndexOf(instr))
				throw gcnew Exception();
		}
	}

	// Run instructions
	while (!HLT)
	{
		runInstruction();
	}
	stateBox->Text = "EXECUTION FINISHED: PROGRAM HALTED";

	// Reset program
	ACC = 0;
	IAR = 0;
	HLT = false;
	labels->Clear();
	for (int i = 0; i < 1000; i++)
	{
		memory[i] = 0;
	}
}

//Run the next instruction
void Assembler::CodeHandler::runInstruction()
{
	if (IAR >= instrList->Count)
	{
		HLT = true;
		return;
	}
	Instruction^ instr = instrList[IAR];
	switch (instr->Opcode)
	{
		case 0: {// INP
			ACC = TakeInput();
			break;
				}

		case 1: {// MOV
			int val = GetValue(instr->Operands[0]);
			String^ loc = instr->Operands[1];
			if (loc == "ACC") ACC = val;
			else
			{
				if (loc[0] == '%') loc = loc->Substring(1);
				int locI = int::Parse(loc);
				memory[locI] = val;
			}
			break;
				}

		case 2: {// OUT
			List<String^>^ lines = gcnew List<String^> (
				safe_cast <System::Collections::Generic::IEnumerable<String^> ^>
				( output->Lines));
			lines->Add(GetValue(instr->Operands[0]).ToString());
			output->Lines = lines->ToArray();
			break;
				}

		case 3: {// ADD
			ACC += GetValue(instr->Operands[0]);
			break;
				}

		case 4: {// SUB
			ACC -= GetValue(instr->Operands[0]);
			break;
				}

		case 5: {// BRA
			if (labels->ContainsKey(instr->Label))
				IAR = labels[instr->Label];
			else throw gcnew Exception();
			break;
				}

		case 6: { // BEZ 
			if (ACC == 0)
				if (labels->ContainsKey(instr->Label))
					IAR = labels[instr->Label];
				else throw gcnew Exception();
			break;
				}

		case 7: // BGZ
			{
			if (ACC > 0)
				if (labels->ContainsKey(instr->Label))
					IAR = labels[instr->Label];
				else throw gcnew Exception();
			break;
			}

		case 8: // BLZ
			{
			if (ACC < 0)
				if (labels->ContainsKey(instr->Label))
					IAR = labels[instr->Label];
				else throw gcnew Exception();
			break;
			}

		case 9: // HLT
			{
			HLT = true;
			break;
			}
		default: 
			{// Unknown
			break;
			}			
	}
	IAR++;
}

int Assembler::CodeHandler::TakeInput()
{
	stateBox->Text = "AWAITING USER INPUT...";
	return Convert::ToInt32(Prompt::ShowPrompt());
}

int Assembler::CodeHandler::GetValue(String^ operand)
{
	if (operand == "ACC") return ACC;

	if (operand[0] == '%')
	{
		String^ addS = operand->Substring(1);
		int address = int::Parse(addS);
		return memory[address];
	}
	return int::Parse(operand);
}

