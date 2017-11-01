//Form1.h : version 0.2.0
//
#include <msclr\marshal_cppstd.h>
#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <regex>
#include <cctype>
namespace std {

	double parseString(char* sub, int f, int t) {
		int subPar = 0;
		vector<char> operations;
		vector<double> nums;
		bool operationLast = true;
		for (int i = f; i < t; i++) {
			if (sub[i] == '(') {
				operationLast = false;
				int braccount = 0;
				for (int j = i; j <= t; j++) {
					if (sub[j] == '(')
						braccount++;
					if (sub[j] == ')') {
						if (--braccount == 0) {
							if (i + 1 != j)
								nums.push_back(parseString(sub, i + 1, j));
							i = j;
							break;
						}
					}
					if (j == t) {
						cout << "Error: A bracket was opened but not closed." << endl;
						system("pause");
						exit(1);
					}
				}
			}
			else if (sub[i] == ')') {
				operationLast = false;
				cout << "Error: A bracket was closed but not opened." << endl;
				system("pause");
				exit(1);
			}
			else if (!operationLast && (sub[i] == '+' || sub[i] == '-' || sub[i] == '*' || sub[i] == '/' || sub[i] == '^')) {
				operationLast = true;
				operations.push_back(sub[i]);
			}
			else if (operationLast && (sub[i] == '+' || sub[i] == '-')) {
				operationLast == false;
				nums.push_back((sub[i] == '+' ? 1 : -1));
				operations.push_back('*');
			}
			else if (isdigit((unsigned char)sub[i]) || sub[i] == '.') {
				operationLast = false;
				ostringstream s;
				if (sub[i] == '.')
					s << '0';
				s << sub[i];
				while (i + 1 < t && (isdigit(sub[i + 1]) || sub[i + 1] == '.'))
					s << sub[++i];
				nums.push_back(stod(s.str()));
				s.clear();
			}
			else {
				cout << "Error: A character could not be interpreted: " << sub[i] << endl;
				system("pause");
				exit(1);
			}
		}
		while (operations.size() > 0 && nums.size() >= 2) {
			int i = 0;
			char c;
			double a, b;
			char ops[] = { '^','*','/','+','-' };
			int j = 0;
			if (operations.size() > 1)
				for (i = 0; i < operations.size(); i++) {
					if (operations.at(i) == ops[j])
						break;
					if (i + 1 >= operations.size() && j < strlen(ops)) {
						j++;
						i = 0;
					}
				}
			c = operations.at(i);
			operations.erase(operations.begin() + i, operations.begin() + i + 1);
			a = nums.at(i);
			b = nums.at(i + 1);
			nums.erase(nums.begin() + i + 1, nums.begin() + i + 2);
			switch (c) {
			case '+':
				nums.at(i) = a + b;
				break;
			case '-':
				nums.at(i) = a - b;
				break;
			case '*':
				nums.at(i) = a * b;
				break;
			case '/':
				nums.at(i) = (double)(a / b);
				break;
			case '^':
				nums.at(i) = pow(a, b);
				break;
			default:
				break;
			}
		}
		if (operations.size() > 0) {
			cout << "Error: There are more operations than numbers." << endl;
			system("pause");
			exit(1);
		}
		return nums.front();
	}
}

namespace CppCLR_WinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  btnEqual;
	protected:


	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  btnAdd;

	private: System::Windows::Forms::Button^  btnSubt;

	private: System::Windows::Forms::Button^  btnMult;

	private: System::Windows::Forms::Button^  btnDiv;

	private: System::Windows::Forms::Button^  btnPow;
	private: System::Windows::Forms::Button^  btn3;
	private: System::Windows::Forms::Button^  btn6;
	private: System::Windows::Forms::Button^  btn9;




	private: System::Windows::Forms::Button^  btnParenthR;
	private: System::Windows::Forms::Button^  btn2;
	private: System::Windows::Forms::Button^  btn5;
	private: System::Windows::Forms::Button^  btn8;
	private: System::Windows::Forms::Button^  btn0;





	private: System::Windows::Forms::Button^  btn1;
	private: System::Windows::Forms::Button^  btn4;
	private: System::Windows::Forms::Button^  btn7;
	private: System::Windows::Forms::Button^  btnBack;
	private: System::Windows::Forms::Button^  btnDec;





	private: System::Windows::Forms::Button^  btnParenthL;



	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->btnEqual = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->btnSubt = (gcnew System::Windows::Forms::Button());
			this->btnMult = (gcnew System::Windows::Forms::Button());
			this->btnDiv = (gcnew System::Windows::Forms::Button());
			this->btnPow = (gcnew System::Windows::Forms::Button());
			this->btn3 = (gcnew System::Windows::Forms::Button());
			this->btn6 = (gcnew System::Windows::Forms::Button());
			this->btn9 = (gcnew System::Windows::Forms::Button());
			this->btnParenthR = (gcnew System::Windows::Forms::Button());
			this->btn2 = (gcnew System::Windows::Forms::Button());
			this->btn5 = (gcnew System::Windows::Forms::Button());
			this->btn8 = (gcnew System::Windows::Forms::Button());
			this->btn0 = (gcnew System::Windows::Forms::Button());
			this->btn1 = (gcnew System::Windows::Forms::Button());
			this->btn4 = (gcnew System::Windows::Forms::Button());
			this->btn7 = (gcnew System::Windows::Forms::Button());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->btnDec = (gcnew System::Windows::Forms::Button());
			this->btnParenthL = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(12, 47);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(485, 37);
			this->textBox1->TabIndex = 0;
			this->textBox1->TabStop = false;
			this->textBox1->Text = L"0";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// btnEqual
			// 
			this->btnEqual->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnEqual->Location = System::Drawing::Point(380, 348);
			this->btnEqual->Name = L"btnEqual";
			this->btnEqual->Size = System::Drawing::Size(117, 58);
			this->btnEqual->TabIndex = 1;
			this->btnEqual->Text = L"=";
			this->btnEqual->UseVisualStyleBackColor = true;
			this->btnEqual->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->richTextBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox1->Location = System::Drawing::Point(12, 13);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(240, 28);
			this->richTextBox1->TabIndex = 3;
			this->richTextBox1->Text = L"My First CS101 CS480 Calculator";
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->ForeColor = System::Drawing::Color::DimGray;
			this->label2->Location = System::Drawing::Point(381, 419);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(196, 20);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Robert Larsen Enterprises";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btnAdd
			// 
			this->btnAdd->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnAdd->Location = System::Drawing::Point(381, 284);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(117, 58);
			this->btnAdd->TabIndex = 5;
			this->btnAdd->Text = L"+";
			this->btnAdd->UseVisualStyleBackColor = true;
			this->btnAdd->Click += gcnew System::EventHandler(this, &Form1::btnAll_Click);
			// 
			// btnSubt
			// 
			this->btnSubt->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnSubt->Location = System::Drawing::Point(381, 220);
			this->btnSubt->Name = L"btnSubt";
			this->btnSubt->Size = System::Drawing::Size(117, 58);
			this->btnSubt->TabIndex = 6;
			this->btnSubt->Text = L"-";
			this->btnSubt->UseVisualStyleBackColor = true;
			this->btnSubt->Click += gcnew System::EventHandler(this, &Form1::btnAll_Click);
			// 
			// btnMult
			// 
			this->btnMult->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnMult->Location = System::Drawing::Point(381, 156);
			this->btnMult->Name = L"btnMult";
			this->btnMult->Size = System::Drawing::Size(117, 58);
			this->btnMult->TabIndex = 7;
			this->btnMult->Text = L"*";
			this->btnMult->UseVisualStyleBackColor = true;
			this->btnMult->Click += gcnew System::EventHandler(this, &Form1::btnAll_Click);
			// 
			// btnDiv
			// 
			this->btnDiv->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnDiv->Location = System::Drawing::Point(381, 92);
			this->btnDiv->Name = L"btnDiv";
			this->btnDiv->Size = System::Drawing::Size(117, 58);
			this->btnDiv->TabIndex = 8;
			this->btnDiv->Text = L"/";
			this->btnDiv->UseVisualStyleBackColor = true;
			this->btnDiv->Click += gcnew System::EventHandler(this, &Form1::btnAll_Click);
			// 
			// btnPow
			// 
			this->btnPow->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnPow->Location = System::Drawing::Point(258, 92);
			this->btnPow->Name = L"btnPow";
			this->btnPow->Size = System::Drawing::Size(117, 58);
			this->btnPow->TabIndex = 9;
			this->btnPow->Text = L"^";
			this->btnPow->UseVisualStyleBackColor = true;
			this->btnPow->Click += gcnew System::EventHandler(this, &Form1::btnAll_Click);
			// 
			// btn3
			// 
			this->btn3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn3->Location = System::Drawing::Point(258, 156);
			this->btn3->Name = L"btn3";
			this->btn3->Size = System::Drawing::Size(117, 58);
			this->btn3->TabIndex = 13;
			this->btn3->Text = L"3";
			this->btn3->UseVisualStyleBackColor = true;
			this->btn3->Click += gcnew System::EventHandler(this, &Form1::btnAll_Click);
			// 
			// btn6
			// 
			this->btn6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn6->Location = System::Drawing::Point(258, 220);
			this->btn6->Name = L"btn6";
			this->btn6->Size = System::Drawing::Size(117, 58);
			this->btn6->TabIndex = 12;
			this->btn6->Text = L"6";
			this->btn6->UseVisualStyleBackColor = true;
			this->btn6->Click += gcnew System::EventHandler(this, &Form1::btnAll_Click);
			// 
			// btn9
			// 
			this->btn9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn9->Location = System::Drawing::Point(258, 284);
			this->btn9->Name = L"btn9";
			this->btn9->Size = System::Drawing::Size(117, 58);
			this->btn9->TabIndex = 11;
			this->btn9->Text = L"9";
			this->btn9->UseVisualStyleBackColor = true;
			this->btn9->Click += gcnew System::EventHandler(this, &Form1::btnAll_Click);
			// 
			// btnParenthR
			// 
			this->btnParenthR->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnParenthR->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnParenthR->Location = System::Drawing::Point(135, 92);
			this->btnParenthR->Name = L"btnParenthR";
			this->btnParenthR->Size = System::Drawing::Size(117, 58);
			this->btnParenthR->TabIndex = 10;
			this->btnParenthR->Text = L")";
			this->btnParenthR->UseVisualStyleBackColor = true;
			this->btnParenthR->Click += gcnew System::EventHandler(this, &Form1::btnAll_Click);
			// 
			// btn2
			// 
			this->btn2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn2->Location = System::Drawing::Point(135, 156);
			this->btn2->Name = L"btn2";
			this->btn2->Size = System::Drawing::Size(117, 58);
			this->btn2->TabIndex = 17;
			this->btn2->Text = L"2";
			this->btn2->UseVisualStyleBackColor = true;
			this->btn2->Click += gcnew System::EventHandler(this, &Form1::btnAll_Click);
			// 
			// btn5
			// 
			this->btn5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn5->Location = System::Drawing::Point(135, 220);
			this->btn5->Name = L"btn5";
			this->btn5->Size = System::Drawing::Size(117, 58);
			this->btn5->TabIndex = 16;
			this->btn5->Text = L"5";
			this->btn5->UseVisualStyleBackColor = true;
			this->btn5->Click += gcnew System::EventHandler(this, &Form1::btnAll_Click);
			// 
			// btn8
			// 
			this->btn8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn8->Location = System::Drawing::Point(135, 284);
			this->btn8->Name = L"btn8";
			this->btn8->Size = System::Drawing::Size(117, 58);
			this->btn8->TabIndex = 15;
			this->btn8->Text = L"8";
			this->btn8->UseVisualStyleBackColor = true;
			this->btn8->Click += gcnew System::EventHandler(this, &Form1::btnAll_Click);
			// 
			// btn0
			// 
			this->btn0->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn0->Location = System::Drawing::Point(135, 348);
			this->btn0->Name = L"btn0";
			this->btn0->Size = System::Drawing::Size(117, 58);
			this->btn0->TabIndex = 14;
			this->btn0->Text = L"0";
			this->btn0->UseVisualStyleBackColor = true;
			this->btn0->Click += gcnew System::EventHandler(this, &Form1::btnAll_Click);
			// 
			// btn1
			// 
			this->btn1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn1->Location = System::Drawing::Point(12, 156);
			this->btn1->Name = L"btn1";
			this->btn1->Size = System::Drawing::Size(117, 58);
			this->btn1->TabIndex = 21;
			this->btn1->Text = L"1";
			this->btn1->UseVisualStyleBackColor = true;
			this->btn1->Click += gcnew System::EventHandler(this, &Form1::btnAll_Click);
			// 
			// btn4
			// 
			this->btn4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn4->Location = System::Drawing::Point(12, 220);
			this->btn4->Name = L"btn4";
			this->btn4->Size = System::Drawing::Size(117, 58);
			this->btn4->TabIndex = 20;
			this->btn4->Text = L"4";
			this->btn4->UseVisualStyleBackColor = true;
			this->btn4->Click += gcnew System::EventHandler(this, &Form1::btnAll_Click);
			// 
			// btn7
			// 
			this->btn7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn7->Location = System::Drawing::Point(12, 284);
			this->btn7->Name = L"btn7";
			this->btn7->Size = System::Drawing::Size(117, 58);
			this->btn7->TabIndex = 19;
			this->btn7->Text = L"7";
			this->btn7->UseVisualStyleBackColor = true;
			this->btn7->Click += gcnew System::EventHandler(this, &Form1::btnAll_Click);
			// 
			// btnBack
			// 
			this->btnBack->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnBack->Location = System::Drawing::Point(12, 348);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(117, 58);
			this->btnBack->TabIndex = 18;
			this->btnBack->Text = L"Backspace";
			this->btnBack->UseVisualStyleBackColor = true;
			this->btnBack->Click += gcnew System::EventHandler(this, &Form1::btnBack_Click);
			// 
			// btnDec
			// 
			this->btnDec->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnDec->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDec->Location = System::Drawing::Point(258, 348);
			this->btnDec->Name = L"btnDec";
			this->btnDec->Size = System::Drawing::Size(117, 58);
			this->btnDec->TabIndex = 22;
			this->btnDec->Text = L".";
			this->btnDec->UseVisualStyleBackColor = true;
			this->btnDec->Click += gcnew System::EventHandler(this, &Form1::btnAll_Click);
			// 
			// btnParenthL
			// 
			this->btnParenthL->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnParenthL->Location = System::Drawing::Point(12, 92);
			this->btnParenthL->Name = L"btnParenthL";
			this->btnParenthL->Size = System::Drawing::Size(117, 58);
			this->btnParenthL->TabIndex = 23;
			this->btnParenthL->Text = L"(";
			this->btnParenthL->UseVisualStyleBackColor = true;
			this->btnParenthL->Click += gcnew System::EventHandler(this, &Form1::btnAll_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(509, 437);
			this->Controls->Add(this->btnParenthL);
			this->Controls->Add(this->btnDec);
			this->Controls->Add(this->btn1);
			this->Controls->Add(this->btn4);
			this->Controls->Add(this->btn7);
			this->Controls->Add(this->btnBack);
			this->Controls->Add(this->btn2);
			this->Controls->Add(this->btn5);
			this->Controls->Add(this->btn8);
			this->Controls->Add(this->btn0);
			this->Controls->Add(this->btn3);
			this->Controls->Add(this->btn6);
			this->Controls->Add(this->btn9);
			this->Controls->Add(this->btnParenthR);
			this->Controls->Add(this->btnPow);
			this->Controls->Add(this->btnDiv);
			this->Controls->Add(this->btnMult);
			this->Controls->Add(this->btnSubt);
			this->Controls->Add(this->btnAdd);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->btnEqual);
			this->Controls->Add(this->textBox1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->KeyPreview = true;
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"Form1";
			this->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->Text = L"Lab 3 Robert Larsen";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::Form1_KeyPress);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			this->label2->Select();
			msclr::interop::marshal_context context;
			std::string c = context.marshal_as<std::string>(this->textBox1->Text);
			c.erase(remove(c.begin(),c.end(),','),c.end());
			double d = std::parseString((char*)c.c_str(), 0, c.length());
			String^ b;
			b = gcnew String(d.ToString("N20"));
			int i;
			for (i = b->Length - 1; i > 0 && b[i] == '0'; i--);
			b = b->Substring(0, i + 1);
			b = b->TrimEnd('.');
			this->textBox1->Text = b;
		}

		private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
			this->richTextBox1->SelectionStart = 9;
			this->richTextBox1->SelectionLength = 5;
			this->richTextBox1->SelectionFont = gcnew System::Drawing::Font(richTextBox1->Font->FontFamily, richTextBox1->Font->Size, FontStyle::Strikeout);
			this->richTextBox1->Enabled = false;
			this->label2->Select();
		}

		private: System::Void btnAll_Click(System::Object^  sender, System::EventArgs^  e) {
			this->label2->Select();
			if (this->textBox1->Text == "0")
				this->textBox1->Text = "";
			this->textBox1->Text = String::Concat(this->textBox1->Text, ((Button^)sender)->Text);
		}
		private: System::Void Form1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			if (e->KeyChar == 13) {
				button1_Click(this->btnEqual, e);
			}
			else if (e->KeyChar == 8) {
				btnBack_Click(this->btnBack,e);
			}
			else if (e->KeyChar != 16) {
				if (this->textBox1->Text == "0" && e->KeyChar != '^' && e->KeyChar != '*' && e->KeyChar != '/' && e->KeyChar != '+' && e->KeyChar != '-' && e->KeyChar != '.')
					this->textBox1->Text = "";
				this->textBox1->Text = String::Concat(this->textBox1->Text, e->KeyChar);
			}
		}

		private: System::Void btnBack_Click(System::Object^  sender, System::EventArgs^  e) {
			this->label2->Select();
			if (this->textBox1->Text->Length == 1)
				this->textBox1->Text = "0";
			else
				this->textBox1->Text = this->textBox1->Text->Substring(0,this->textBox1->Text->Length - 1);
		}
	};
}