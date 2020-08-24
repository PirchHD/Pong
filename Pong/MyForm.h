#pragma once

namespace Pong {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ platformleft;
	private: System::Windows::Forms::PictureBox^ platformright;
	protected:

	protected:

	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::PictureBox^ ball;
	private: System::Windows::Forms::Label^ labelL;
	private: System::Windows::Forms::Label^ labelR;



	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->platformleft = (gcnew System::Windows::Forms::PictureBox());
			this->platformright = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->ball = (gcnew System::Windows::Forms::PictureBox());
			this->labelL = (gcnew System::Windows::Forms::Label());
			this->labelR = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->platformleft))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->platformright))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ball))->BeginInit();
			this->SuspendLayout();
			// 
			// platformleft
			// 
			this->platformleft->BackColor = System::Drawing::Color::Transparent;
			this->platformleft->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"platformleft.Image")));
			this->platformleft->Location = System::Drawing::Point(12, 206);
			this->platformleft->Name = L"platformleft";
			this->platformleft->Size = System::Drawing::Size(28, 133);
			this->platformleft->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->platformleft->TabIndex = 0;
			this->platformleft->TabStop = false;
			// 
			// platformright
			// 
			this->platformright->BackColor = System::Drawing::Color::Transparent;
			this->platformright->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"platformright.Image")));
			this->platformright->Location = System::Drawing::Point(841, 206);
			this->platformright->Name = L"platformright";
			this->platformright->Size = System::Drawing::Size(28, 133);
			this->platformright->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->platformright->TabIndex = 1;
			this->platformright->TabStop = false;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 50;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// ball
			// 
			this->ball->BackColor = System::Drawing::Color::Transparent;
			this->ball->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ball.Image")));
			this->ball->Location = System::Drawing::Point(447, 301);
			this->ball->Name = L"ball";
			this->ball->Size = System::Drawing::Size(25, 25);
			this->ball->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->ball->TabIndex = 2;
			this->ball->TabStop = false;
			// 
			// labelL
			// 
			this->labelL->AutoSize = true;
			this->labelL->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 72, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelL->Location = System::Drawing::Point(207, 9);
			this->labelL->Name = L"labelL";
			this->labelL->Size = System::Drawing::Size(99, 108);
			this->labelL->TabIndex = 3;
			this->labelL->Text = L"0";
			// 
			// labelR
			// 
			this->labelR->AutoSize = true;
			this->labelR->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 72, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelR->Location = System::Drawing::Point(658, 9);
			this->labelR->Name = L"labelR";
			this->labelR->Size = System::Drawing::Size(99, 108);
			this->labelR->TabIndex = 4;
			this->labelR->Text = L"0";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(881, 552);
			this->Controls->Add(this->ball);
			this->Controls->Add(this->labelR);
			this->Controls->Add(this->labelL);
			this->Controls->Add(this->platformright);
			this->Controls->Add(this->platformleft);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MovesPlatform);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->platformleft))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->platformright))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ball))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		int moveX = 0;
		int moveY = 0;

		char DirectionLeft, DirectionRight;

		char Where;

		int PointsL = 0, PointsR = 0;

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		ball->Left += moveX;
		ball->Top += moveY;

		// odbijanie pijki od sciany
		//if (ball->Left >= MyForm::Width - ball->Width - 12) moveX = -moveX;

		if (ball->Top >= MyForm::Height - ball->Height - 35) moveY = -moveY;

		if (ball->Top <= 0) moveY = -moveY;

		//if (ball->Left <= 5 ) moveX = -moveX;

		//lewa platforma
		if ((DirectionLeft == 'W') && platformleft->Top > 0) {
			platformleft->Top -= 20;
		}
		if ((DirectionLeft == 'S') && (platformleft->Bottom < MyForm::Bottom - platformleft->Height - 10)) {
			platformleft->Top += 20;
		}
		// PRAWA PLATFORMA
		if ((DirectionRight == 'U') && platformright->Top > 0 ) {
			platformright->Top -= 20;
		}
		if ((DirectionRight == 'D') && (platformright->Bottom < MyForm::Bottom - platformright->Height - 10)) {
			platformright->Top += 20;
		}

		//ODBIJANIE
		if ((ball->Right > platformright->Left + 2) && (ball->Top  > platformright->Top) && ( ball->Top < platformright->Bottom ) ) {
			moveX = -moveX;
			
		}
		if ((ball->Right < platformleft->Right + 2) && (ball->Top > platformleft->Top) && (ball->Top < platformleft->Bottom)) {
			moveX = -moveX;

		}

		// jezeli przegrasz
		if (ball->Left >= MyForm::Width) {

			Where = 'R';
			ball->Left = MyForm::Width  - 70;
			ball->Top = MyForm::Height / 2;

			platformright->Left = MyForm::Width- 50;
			platformright -> Top = MyForm::Height / 2;
			PointsR += 1;
			moveX = 0; moveY = 0;
			labelR->Text = "" + PointsR;
		}
		if (ball->Right <= 0) {

			Where = 'L';
			ball->Left = 30;
			ball->Top = MyForm::Height / 2;

			platformleft->Left = 10;
			platformleft->Top = MyForm::Height / 2;
			PointsL += 1;
			moveX = 0; moveY = 0;
			labelL->Text = "" + PointsL;
		}

	}

private: System::Void MovesPlatform(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyCode == Keys::Down)DirectionRight = 'D';
	if (e->KeyCode == Keys::Up)DirectionRight = 'U';

	if (e->KeyCode == Keys::W) DirectionLeft = 'W';
	
	if (e->KeyCode == Keys::S) DirectionLeft = 'S';

	if (e->KeyCode == Keys::Space) {
		if (Where == 'R') {
			moveX = -15;
		}
		else
		{
			moveX = 15;
		}
		
		moveY = 15;
	}
}
private: System::Void MyForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	DirectionLeft = '`'; DirectionRight = '`';
}

};
}
