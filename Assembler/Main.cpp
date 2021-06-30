using namespace System;
using namespace System::Windows::Forms;

#include "Main.h"
#include "CodeHandler.h"

[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Assembler::Main form;
	Application::Run(%form);
}

// Draggable //

void Assembler::Main::mouseMove(Object^, MouseEventArgs^ e) {
	if (_dragging)
	{
		Point p = PointToScreen(e->Location);
		Location = *new Point(p.X - _start_point.X, p.Y - _start_point.Y);
	}
}
void Assembler::Main::mouseDown(Object^, MouseEventArgs^ e) {
	_dragging = true;
	_start_point = *new Point(e->X, e->Y);
}
void Assembler::Main::mouseUp(Object^, MouseEventArgs^) {
	_dragging = false;
}



// Buttons //
void Assembler::Main::close_Click(Object^ sender, EventArgs^ e) {
	Application::Exit();
}


void Assembler::Main::enter_Click(Object^ sender, EventArgs^ e) {
	array<String^>^ instr = input->Lines;
	List<Instruction^>^ instrList = gcnew List<Instruction^>();
	for (int i = 0; i < instr->Length; i++)
	{
		String^ decStr = instr[i];
		if (String::IsNullOrWhiteSpace(decStr)) continue;
		Instruction^ decInstr = CodeAssembler::DecodeInstruction(decStr);
		if (decInstr != nullptr)
		{
			instrList->Add(decInstr);
		}
	}
			
	CodeHandler::instrList = instrList;
	CodeHandler::Start(this);
}