#pragma once

namespace Assembler {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Prompt
	/// </summary>
	public ref class Prompt : public System::Windows::Forms::Form
	{
	public:
		Prompt(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Prompt()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  top;
	protected: 
	private: System::Windows::Forms::Label^  title;



	private: System::Windows::Forms::Label^  boxlab;
	private: System::Windows::Forms::Button^  enter;
	private: System::Windows::Forms::NumericUpDown^  input;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->top = (gcnew System::Windows::Forms::Panel());
			this->title = (gcnew System::Windows::Forms::Label());
			this->boxlab = (gcnew System::Windows::Forms::Label());
			this->enter = (gcnew System::Windows::Forms::Button());
			this->input = (gcnew System::Windows::Forms::NumericUpDown());
			this->top->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->input))->BeginInit();
			this->SuspendLayout();
			// 
			// top
			// 
			this->top->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(34)), 
				static_cast<System::Int32>(static_cast<System::Byte>(41)));
			this->top->Controls->Add(this->title);
			this->top->Dock = System::Windows::Forms::DockStyle::Top;
			this->top->Location = System::Drawing::Point(0, 0);
			this->top->Name = L"top";
			this->top->Size = System::Drawing::Size(371, 31);
			this->top->TabIndex = 1;
			// 
			// title
			// 
			this->title->AutoSize = true;
			this->title->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->title->ForeColor = System::Drawing::SystemColors::Control;
			this->title->Location = System::Drawing::Point(3, 3);
			this->title->Name = L"title";
			this->title->Size = System::Drawing::Size(93, 21);
			this->title->TabIndex = 1;
			this->title->Text = L"Dialog box";
			// 
			// boxlab
			// 
			this->boxlab->AutoSize = true;
			this->boxlab->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->boxlab->ForeColor = System::Drawing::SystemColors::Control;
			this->boxlab->Location = System::Drawing::Point(90, 68);
			this->boxlab->Name = L"boxlab";
			this->boxlab->Size = System::Drawing::Size(168, 21);
			this->boxlab->TabIndex = 2;
			this->boxlab->Text = L"Please enter a value";
			// 
			// enter
			// 
			this->enter->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->enter->ForeColor = System::Drawing::SystemColors::Control;
			this->enter->Location = System::Drawing::Point(94, 156);
			this->enter->Name = L"enter";
			this->enter->Size = System::Drawing::Size(164, 31);
			this->enter->TabIndex = 3;
			this->enter->UseVisualStyleBackColor = true;
			this->enter->Click += gcnew System::EventHandler(this, &Prompt::enter_Click);
			// 
			// input
			// 
			this->input->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(34)), 
				static_cast<System::Int32>(static_cast<System::Byte>(41)));
			this->input->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->input->Font = (gcnew System::Drawing::Font(L"Century Gothic", 18));
			this->input->ForeColor = System::Drawing::SystemColors::Control;
			this->input->Location = System::Drawing::Point(94, 104);
			this->input->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100000, 0, 0, 0});
			this->input->Name = L"input";
			this->input->Size = System::Drawing::Size(164, 33);
			this->input->TabIndex = 4;
			// 
			// Prompt
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(44)), 
				static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->ClientSize = System::Drawing::Size(371, 221);
			this->Controls->Add(this->input);
			this->Controls->Add(this->enter);
			this->Controls->Add(this->boxlab);
			this->Controls->Add(this->top);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Prompt";
			this->Text = L"Prompt";
			this->top->ResumeLayout(false);
			this->top->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->input))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void enter_Click(System::Object^, System::EventArgs^);

	public: static Decimal^ ShowPrompt();
};
}
