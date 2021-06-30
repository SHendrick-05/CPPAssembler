using namespace System;
using namespace System::Collections::Generic;
using namespace System::Text;
using namespace System::Threading::Tasks;

namespace Assembler
{
		public ref class Instruction
		{
		public: short Opcode;
		public: array<String^>^ Operands;
		public: String^ Label;
		};

		public ref class CodeAssembler
		{

		public: static Dictionary<String^, Int16>^ Opcodes;

		public: static CodeAssembler()
		{
			Opcodes = gcnew Dictionary<String^, Int16>();
			Opcodes->Add("INP", 0); // Take user input, 0 operands
			Opcodes->Add("MOV", 1); // Move value from A to B, 2 operands
			Opcodes->Add("OUT", 2); // Output value of address to the console, 1 operand
			Opcodes->Add("ADD", 3); // Add value to ACC, 1 operand
			Opcodes->Add("SUB", 4); // Subtract value from ACC, 1 operand
			Opcodes->Add("BRA", 5); // Branch to label, 1 operand
			Opcodes->Add("BEZ", 6); // Branch if ACC is equal to 0, 1 operand
			Opcodes->Add("BGZ", 7); // Branch if ACC is greater than 0, 1 operand
			Opcodes->Add("BLZ", 8); // Branch if ACC is less than 0, 1 operand.
			// 10 = Label
		}		

		public: static Instruction^ DecodeInstruction(String^ input);
		};
}