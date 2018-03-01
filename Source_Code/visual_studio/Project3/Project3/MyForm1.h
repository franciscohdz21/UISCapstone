#pragma once

namespace Project3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
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
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  resetBTN;
	protected:

	private: System::Windows::Forms::Button^  startBTN;
	private: System::Windows::Forms::NumericUpDown^  levelSelector;
	private: System::Windows::Forms::Label^  levelLBL;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  scoreLBL;
	private: System::Windows::Forms::Label^  actScoreLBL;
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
			this->resetBTN = (gcnew System::Windows::Forms::Button());
			this->startBTN = (gcnew System::Windows::Forms::Button());
			this->levelSelector = (gcnew System::Windows::Forms::NumericUpDown());
			this->levelLBL = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->scoreLBL = (gcnew System::Windows::Forms::Label());
			this->actScoreLBL = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->levelSelector))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// resetBTN
			// 
			this->resetBTN->Location = System::Drawing::Point(513, 501);
			this->resetBTN->Name = L"resetBTN";
			this->resetBTN->Size = System::Drawing::Size(105, 49);
			this->resetBTN->TabIndex = 0;
			this->resetBTN->Text = L"Reset";
			this->resetBTN->UseVisualStyleBackColor = true;
			// 
			// startBTN
			// 
			this->startBTN->Location = System::Drawing::Point(513, 420);
			this->startBTN->Name = L"startBTN";
			this->startBTN->Size = System::Drawing::Size(105, 49);
			this->startBTN->TabIndex = 1;
			this->startBTN->Text = L"Start";
			this->startBTN->UseVisualStyleBackColor = true;
			this->startBTN->Click += gcnew System::EventHandler(this, &MyForm1::button2_Click);
			// 
			// levelSelector
			// 
			this->levelSelector->Location = System::Drawing::Point(513, 351);
			this->levelSelector->Name = L"levelSelector";
			this->levelSelector->Size = System::Drawing::Size(120, 38);
			this->levelSelector->TabIndex = 2;
			// 
			// levelLBL
			// 
			this->levelLBL->AutoSize = true;
			this->levelLBL->Location = System::Drawing::Point(513, 291);
			this->levelLBL->Name = L"levelLBL";
			this->levelLBL->Size = System::Drawing::Size(84, 32);
			this->levelLBL->TabIndex = 3;
			this->levelLBL->Text = L"Level";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(40, 41);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(412, 536);
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			// 
			// scoreLBL
			// 
			this->scoreLBL->AutoSize = true;
			this->scoreLBL->Location = System::Drawing::Point(474, 41);
			this->scoreLBL->Name = L"scoreLBL";
			this->scoreLBL->Size = System::Drawing::Size(89, 32);
			this->scoreLBL->TabIndex = 5;
			this->scoreLBL->Text = L"Score";
			// 
			// actScoreLBL
			// 
			this->actScoreLBL->AutoSize = true;
			this->actScoreLBL->Location = System::Drawing::Point(480, 87);
			this->actScoreLBL->Name = L"actScoreLBL";
			this->actScoreLBL->Size = System::Drawing::Size(127, 32);
			this->actScoreLBL->TabIndex = 6;
			this->actScoreLBL->Text = L"actScore";
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(711, 656);
			this->Controls->Add(this->actScoreLBL);
			this->Controls->Add(this->scoreLBL);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->levelLBL);
			this->Controls->Add(this->levelSelector);
			this->Controls->Add(this->startBTN);
			this->Controls->Add(this->resetBTN);
			this->Name = L"MyForm1";
			this->Text = L"MyForm1";
			this->Load += gcnew System::EventHandler(this, &MyForm1::MyForm1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->levelSelector))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm1_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	};
}
