#pragma once

namespace Project1 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	Char specialSymbols[10] = { '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*' };
	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		String^ upperAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		String^ lowerAlphabet = "abcdefghijklmnopqrstuvwxyz";
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblId;
	protected:
	private: System::Windows::Forms::TextBox^ txtId;
	private: System::Windows::Forms::Button^ btnGen;
	private: System::Windows::Forms::TextBox^ txtResult;
	private: System::Windows::Forms::Button^ btnClose;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lblId = (gcnew System::Windows::Forms::Label());
			this->txtId = (gcnew System::Windows::Forms::TextBox());
			this->btnGen = (gcnew System::Windows::Forms::Button());
			this->txtResult = (gcnew System::Windows::Forms::TextBox());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblId
			// 
			this->lblId->AutoSize = true;
			this->lblId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblId->Location = System::Drawing::Point(12, 37);
			this->lblId->Name = L"lblId";
			this->lblId->Size = System::Drawing::Size(226, 32);
			this->lblId->TabIndex = 0;
			this->lblId->Text = L"Идентификатор";
			// 
			// txtId
			// 
			this->txtId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtId->Location = System::Drawing::Point(269, 37);
			this->txtId->Name = L"txtId";
			this->txtId->Size = System::Drawing::Size(275, 38);
			this->txtId->TabIndex = 1;
			// 
			// btnGen
			// 
			this->btnGen->Location = System::Drawing::Point(18, 176);
			this->btnGen->Name = L"btnGen";
			this->btnGen->Size = System::Drawing::Size(201, 61);
			this->btnGen->TabIndex = 2;
			this->btnGen->Text = L"Сформировать пароль";
			this->btnGen->UseVisualStyleBackColor = true;
			this->btnGen->Click += gcnew System::EventHandler(this, &MyForm::btnGen_Click);
			// 
			// txtResult
			// 
			this->txtResult->BackColor = System::Drawing::SystemColors::Window;
			this->txtResult->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtResult->Location = System::Drawing::Point(252, 182);
			this->txtResult->Name = L"txtResult";
			this->txtResult->ReadOnly = true;
			this->txtResult->Size = System::Drawing::Size(204, 38);
			this->txtResult->TabIndex = 3;
			// 
			// btnClose
			// 
			this->btnClose->Location = System::Drawing::Point(509, 188);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(90, 36);
			this->btnClose->TabIndex = 4;
			this->btnClose->Text = L"Закрыть";
			this->btnClose->UseVisualStyleBackColor = true;
			this->btnClose->Click += gcnew System::EventHandler(this, &MyForm::btnClose_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(624, 270);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->txtResult);
			this->Controls->Add(this->btnGen);
			this->Controls->Add(this->txtId);
			this->Controls->Add(this->lblId);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Генератор пароля";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: String^ generatePassword(String^ id) {
		Random^ rand = gcnew Random();
		return Convert::ToString(upperAlphabet[rand->Next(0, upperAlphabet->Length)])
			+ upperAlphabet[rand->Next(0, upperAlphabet->Length)]
			+ Convert::ToString((id->Length * id->Length) % 10)
			+ rand->Next(0, 10) + specialSymbols[rand->Next(0, 10)]
			+ Convert::ToString(lowerAlphabet[rand->Next(0, lowerAlphabet->Length)]);
	}
	private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
private: System::Void btnGen_Click(System::Object^ sender, System::EventArgs^ e) {
	txtResult->Text = generatePassword(txtId->Text);
}
};
}
