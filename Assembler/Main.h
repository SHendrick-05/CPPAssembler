#pragma once
#pragma comment(lib, "user32")

#include "CodeAssembler.h"

namespace Assembler {


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;



	/// <summary>
	/// Summary for Main
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{
	public:
		Main(void)
		{
			InitializeComponent();
			_dragging = false;
			_start_point = *new Point(0,0);
		}
	public: bool _dragging;
	private: Point _offset;
	internal: System::Windows::Forms::TextBox^  input;
	internal: System::Windows::Forms::TextBox^  outputBox;
	private: 

	internal: System::Windows::Forms::TextBox^  stateBox;

	private: System::Windows::Forms::Button^  enter;
	private: System::Windows::Forms::Label^  stateLab;
	private: System::Windows::Forms::Label^  outputLab;

	internal: 
	private: Point _start_point;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  top;
	private: System::Windows::Forms::Button^  close;
	private: System::Windows::Forms::Label^  title;

	protected: 

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
			this->close = (gcnew System::Windows::Forms::Button());
			this->input = (gcnew System::Windows::Forms::TextBox());
			this->outputBox = (gcnew System::Windows::Forms::TextBox());
			this->stateBox = (gcnew System::Windows::Forms::TextBox());
			this->enter = (gcnew System::Windows::Forms::Button());
			this->stateLab = (gcnew System::Windows::Forms::Label());
			this->outputLab = (gcnew System::Windows::Forms::Label());
			this->top->SuspendLayout();
			this->SuspendLayout();
			// 
			// top
			// 
			this->top->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(34)), 
				static_cast<System::Int32>(static_cast<System::Byte>(41)));
			this->top->Controls->Add(this->title);
			this->top->Controls->Add(this->close);
			this->top->Dock = System::Windows::Forms::DockStyle::Top;
			this->top->Location = System::Drawing::Point(0, 0);
			this->top->Name = L"top";
			this->top->Size = System::Drawing::Size(558, 36);
			this->top->TabIndex = 0;
			// 
			// title
			// 
			this->title->AutoSize = true;
			this->title->Font = (gcnew System::Drawing::Font(L"Century Gothic", 18, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->title->ForeColor = System::Drawing::SystemColors::Control;
			this->title->Location = System::Drawing::Point(3, 6);
			this->title->Name = L"title";
			this->title->Size = System::Drawing::Size(299, 30);
			this->title->TabIndex = 1;
			this->title->Text = L"Assembler made in C++";
			// 
			// close
			// 
			this->close->Dock = System::Windows::Forms::DockStyle::Right;
			this->close->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->close->ForeColor = System::Drawing::Color::Red;
			this->close->Location = System::Drawing::Point(480, 0);
			this->close->Name = L"close";
			this->close->Size = System::Drawing::Size(78, 36);
			this->close->TabIndex = 0;
			this->close->UseVisualStyleBackColor = true;
			this->close->Click += gcnew System::EventHandler(this, &Main::close_Click);
			// 
			// input
			// 
			this->input->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(34)), 
				static_cast<System::Int32>(static_cast<System::Byte>(41)));
			this->input->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->input->Font = (gcnew System::Drawing::Font(L"Courier New", 12));
			this->input->ForeColor = System::Drawing::SystemColors::Control;
			this->input->Location = System::Drawing::Point(17, 54);
			this->input->Multiline = true;
			this->input->Name = L"input";
			this->input->Size = System::Drawing::Size(254, 643);
			this->input->TabIndex = 3;
			// 
			// outputBox
			// 
			this->outputBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(34)), 
				static_cast<System::Int32>(static_cast<System::Byte>(41)));
			this->outputBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->outputBox->Font = (gcnew System::Drawing::Font(L"Courier New", 12));
			this->outputBox->ForeColor = System::Drawing::SystemColors::Control;
			this->outputBox->Location = System::Drawing::Point(281, 225);
			this->outputBox->Multiline = true;
			this->outputBox->Name = L"outputBox";
			this->outputBox->ReadOnly = true;
			this->outputBox->Size = System::Drawing::Size(252, 472);
			this->outputBox->TabIndex = 4;
			// 
			// stateBox
			// 
			this->stateBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(34)), 
				static_cast<System::Int32>(static_cast<System::Byte>(41)));
			this->stateBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->stateBox->Font = (gcnew System::Drawing::Font(L"Courier New", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->stateBox->ForeColor = System::Drawing::SystemColors::Control;
			this->stateBox->Location = System::Drawing::Point(277, 150);
			this->stateBox->Name = L"stateBox";
			this->stateBox->ReadOnly = true;
			this->stateBox->Size = System::Drawing::Size(256, 31);
			this->stateBox->TabIndex = 5;
			// 
			// enter
			// 
			this->enter->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->enter->Font = (gcnew System::Drawing::Font(L"Century Gothic", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->enter->ForeColor = System::Drawing::SystemColors::Control;
			this->enter->Location = System::Drawing::Point(277, 54);
			this->enter->Name = L"enter";
			this->enter->Size = System::Drawing::Size(256, 54);
			this->enter->TabIndex = 6;
			this->enter->Text = L"Run code";
			this->enter->UseVisualStyleBackColor = true;
			this->enter->Click += gcnew System::EventHandler(this, &Main::enter_Click);
			// 
			// stateLab
			// 
			this->stateLab->AutoSize = true;
			this->stateLab->Font = (gcnew System::Drawing::Font(L"Century Gothic", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->stateLab->ForeColor = System::Drawing::SystemColors::Control;
			this->stateLab->Location = System::Drawing::Point(277, 123);
			this->stateLab->Name = L"stateLab";
			this->stateLab->Size = System::Drawing::Size(155, 24);
			this->stateLab->TabIndex = 7;
			this->stateLab->Text = L"Program State";
			// 
			// outputLab
			// 
			this->outputLab->AutoSize = true;
			this->outputLab->Font = (gcnew System::Drawing::Font(L"Century Gothic", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->outputLab->ForeColor = System::Drawing::SystemColors::Control;
			this->outputLab->Location = System::Drawing::Point(277, 198);
			this->outputLab->Name = L"outputLab";
			this->outputLab->Size = System::Drawing::Size(82, 24);
			this->outputLab->TabIndex = 8;
			this->outputLab->Text = L"Output";
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(44)), 
				static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->ClientSize = System::Drawing::Size(558, 731);
			this->Controls->Add(this->outputLab);
			this->Controls->Add(this->stateLab);
			this->Controls->Add(this->enter);
			this->Controls->Add(this->stateBox);
			this->Controls->Add(this->outputBox);
			this->Controls->Add(this->input);
			this->Controls->Add(this->top);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Main";
			this->Text = L"Main";
			this->top->ResumeLayout(false);
			this->top->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

			this->top->MouseDown += gcnew MouseEventHandler(this, &Main::mouseDown);
			this->top->MouseMove += gcnew MouseEventHandler(this, &Main::mouseMove);
			this->top->MouseUp += gcnew MouseEventHandler(this, &Main::mouseUp);

			this->title->MouseDown += gcnew MouseEventHandler(this, &Main::mouseDown);
			this->title->MouseMove += gcnew MouseEventHandler(this, &Main::mouseMove);
			this->title->MouseUp += gcnew MouseEventHandler(this, &Main::mouseUp);

		}
#pragma endregion


		/* Draggable function */
	private: Void mouseMove(Object^, MouseEventArgs^ e);
	private: Void mouseDown(Object^, MouseEventArgs^ e);
	private: Void mouseUp(Object^, MouseEventArgs^);

		/* Buttons */
	private: Void close_Click(Object^, EventArgs^);
	private: Void enter_Click(Object^, EventArgs^ );

};
}

/* 
			this->top->MouseDown += gcnew MouseEventHandler(this, &Main::mouseDown);
			this->top->MouseMove += gcnew MouseEventHandler(this, &Main::mouseMove);
			this->top->MouseUp += gcnew MouseEventHandler(this, &Main::mouseUp);

			this->title->MouseDown += gcnew MouseEventHandler(this, &Main::mouseDown);
			this->title->MouseMove += gcnew MouseEventHandler(this, &Main::mouseMove);
			this->title->MouseUp += gcnew MouseEventHandler(this, &Main::mouseUp);

*/