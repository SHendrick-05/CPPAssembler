ref class Main;

namespace Assembler
{
	ref class CodeHandler
	{
		public: static property Control^ stateBox { public: Control^ get(); }
		public: static property TextBox^ output { public:TextBox^ get(); }
		public: static array<int>^ memory = gcnew array<int>(1000);
		public: static Dictionary<String^, int>^ labels = gcnew Dictionary<String^, int>();
		public: static List<Instruction^>^ instrList = gcnew List<Instruction^>();
		public: static int ACC = 0;
		public: static int IAR = 0;
		public: static  bool HLT = false;
		public: static Main^ usedForm;
		public: static void Start(Main^ form);
		public: static void runInstruction();
		public: static int TakeInput();
		public: static int GetValue(String^ operand);
	};
}