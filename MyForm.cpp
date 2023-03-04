#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Game2048::MyForm form;
	Application::Run(% form);
	
}

Game2048::MyForm:: MyForm() {

	InitializeComponent();

}



System::Void Game2048::MyForm::MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e){
	
	/*if (e->KeyCode == Keys::D) {
		label2->Text = "D:";
	}
	if (e->KeyCode == Keys::W) {
		label2->Text = "W:";
	}
	if (e->KeyCode == Keys::S) {
		label2->Text = "S:";
	}
	if (e->KeyCode == Keys::A) {
		label2->Text = "A:";
	}*/

	return System::Void();

}


void Game2048::MyForm::Game_Update(Object^ sender, EventArgs^ e) {
	

}