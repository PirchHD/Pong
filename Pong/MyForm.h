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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->platformleft))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->platformright))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ball))->BeginInit();
			this->SuspendLayout();
			// 
			// platformleft
			// 
			this->platformleft->BackColor = System::Drawing::Color::Transparent;
			this->platformleft->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"platformleft.Image")));
			this->platformleft->Location = System::Drawing::Point(12, 253);
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
			this->platformright->Location = System::Drawing::Point(917, 253);
			this->platformright->Name = L"platformright";
			this->platformright->Size = System::Drawing::Size(28, 133);
			this->platformright->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->platformright->TabIndex = 1;
			this->platformright->TabStop = false;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
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
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(957, 619);
			this->Controls->Add(this->ball);
			this->Controls->Add(this->platformright);
			this->Controls->Add(this->platformleft);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MovesPlatform);
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

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		ball->Left += moveX;
		ball->Top += moveY;

		// odbijanie pijki od sciany
		if (ball->Left >= MyForm::Width - ball->Width - 12) moveX = -moveX;

		if (ball->Top >= MyForm::Height - ball->Height - 35) moveY = -moveY;

		if (ball->Top <= 0) moveY = -moveY;

		if (ball->Left <= 5 ) moveX = -moveX;

		//lewa platforma
		if ((DirectionLeft == 'W') && (platformleft->Left < MyForm::Width - platformleft->Width - 21)) {
			platformleft->Top -= 20;
		}
		if ((DirectionLeft == 'S') && (platformleft->Left > 2)) {
			platformleft->Top += 20;
		}
		// PRAWA PLATFORMA
		if ((DirectionRight == 'U') && (platformright->Left < MyForm::Width - platformright->Width - 21)) {
			platformright->Top -= 20;
		}
		if ((DirectionRight == 'D') && (platformleft->Left > 2)) {
			platformright->Top += 20;
		}

		//ODBIJANIE
		if ((ball->Left + (ball->Width / 2) > platformleft->Left) && (ball->Left < platformleft->Left + platformleft->Width) && (ball->Top + ball->Height > platformleft->Top)) {
			moveX = -moveX;
			
		}
		if ((ball->Left + (ball->Width / 2) > platformright->Left) && (ball->Left < platformright->Left + platformright->Width) && (ball->Top + ball->Height > platformright->Top)) {
			moveX = -moveX;

		}
	}

private: System::Void MovesPlatform(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyCode == Keys::Down)DirectionRight = 'D';
	if (e->KeyCode == Keys::Up)DirectionRight = 'U';

	if (e->KeyCode == Keys::W) DirectionLeft = 'W';
	
	if (e->KeyCode == Keys::S) DirectionLeft = 'S';

	if (e->KeyCode == Keys::Space) {
		moveX = 5;
		moveY = 5;
	}
}
};
}
