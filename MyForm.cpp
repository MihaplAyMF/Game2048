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

	Grid();
	Print();
}

void Game2048::MyForm::Grid(){

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			grid[i, j] = gcnew Cell;
			grid[i, j]->X = j;
			grid[i, j]->Y = i;
			grid[i, j]->state = false;
			grid[i, j]->num = 0;

		}
	}
}

void Game2048::MyForm::AddRundomNumber(){
	int x, y, i;

	do {
		x = randint(0, 4);
		y = randint(0, 4);

	} while (grid[x, y]->num != 0);

	grid[x, y]->num = 2; //randint(1,2)*2;

}

void Game2048::MyForm::ClearState() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			grid[i, j]->state = false;
		}
	}

}

void Game2048::MyForm::Print(){
	
	label3->Text = grid[0, 0]->num.ToString();
	label4->Text = grid[1, 0]->num.ToString();
	label5->Text = grid[2, 0]->num.ToString();
	label6->Text = grid[3, 0]->num.ToString();
	label7->Text = grid[0, 1]->num.ToString();
	label8->Text = grid[1, 1]->num.ToString();
	label9->Text = grid[2, 1]->num.ToString();
	label10->Text = grid[3, 1]->num.ToString();
	label11->Text = grid[0, 2]->num.ToString();
	label12->Text = grid[1, 2]->num.ToString();
	label13->Text = grid[2, 2]->num.ToString();
	label14->Text = grid[3, 2]->num.ToString();
	label15->Text = grid[0, 3]->num.ToString();
	label16->Text = grid[1, 3]->num.ToString();
	label17->Text = grid[2, 3]->num.ToString();
	label18->Text = grid[3, 3]->num.ToString();

}

void Game2048::MyForm::MoveUp() {

	for (int i = 0; i < SIZE; i++) {
		for (int j = 1; j < SIZE; j++) {
			for (int k = j; k > 0; k--) {

				if (grid[i, k]->num == 0) {
					continue;
				}

				if (grid[i, k]->num != 0 && grid[i, k - 1]->num == 0) {
					grid[i, k - 1]->num = grid[i, k]->num;
					grid[i, k]->num = 0;
				} else if (grid[i, k]->num == grid[i, k - 1]->num && grid[i, k - 1]->state == false && grid[i, k]->state == false) {
					grid[i, k - 1]->num += grid[i, k]->num;
					grid[i, k]->num = 0;
					grid[i, k - 1]->state = true;
				}
			}
		}
	}


	AddRundomNumber();
	ClearState();
}

void Game2048::MyForm::MoveRight(){
	
	for (int i = 0; i < SIZE; i++) {
		for (int j = SIZE - 1; j >= 0; j--) {
			for (int k = j; k < SIZE - 1; k++) {

				if (grid[k, i]->num == 0) {
					continue;
				}

				if (grid[k, i]->num != 0 && grid[k + 1, i]->num == 0) {
					grid[k + 1, i]->num = grid[k, i]->num;
					grid[k, i]->num = 0;
				} else if (grid[k, i]->num == grid[k + 1, i]->num && grid[k + 1, i]->state == false && grid[k, i]->state == false) {
					grid[k + 1, i]->num += grid[k, i]->num;
					grid[k, i]->num = 0;
					grid[k + 1, i]->state = true;
				}
			}
		}
	}

	AddRundomNumber();
	ClearState();
}

void Game2048::MyForm::MoveDown() {

	for (int i = 0; i < SIZE; i++) {
		for (int j = SIZE - 1; j >= 0; j--) {
			for (int k = j; k < SIZE - 1; k++) {

				if (grid[i, k]->num == 0) {
					continue;
				}

				if (grid[i, k]->num != 0 && grid[i, k + 1]->num == 0) {
					grid[i, k + 1]->num = grid[i, k]->num;
					grid[i, k]->num = 0;
				} else if (grid[i, k]->num == grid[i, k + 1]->num && grid[i, k + 1]->state == false && grid[i, k]->state == false) {
					grid[i, k + 1]->num += grid[i, k]->num;
					grid[i, k]->num = 0;
					grid[i, k + 1]->state = true;
				}
			}
		}
	}

	AddRundomNumber();
	ClearState();
}

void Game2048::MyForm::MoveLeft() {

	for (int i = 0; i < SIZE; i++) {
		for (int j = 1; j < SIZE; j++) {
			for (int k = j; k > 0; k--) {

				if (grid[k, i]->num == 0) {
					continue;
				}

				if (grid[k, i]->num != 0 && grid[k - 1, i]->num == 0) {
					grid[k - 1, i]->num = grid[k, i]->num;
					grid[k, i]->num = 0;
				} else if (grid[k, i]->num == grid[k - 1, i]->num && grid[k - 1, i]->state == false && grid[k, i]->state == false) {
					grid[k - 1, i]->num += grid[k, i]->num;
					grid[k, i]->num = 0;
					grid[k - 1, i]->state = true;
				}
			}
		}
	}

	AddRundomNumber();
	ClearState();
}

System::Void Game2048::MyForm::MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e){
	
	if (e->KeyCode == Keys::D) {
		MoveRight();
		Print();
	}
	if (e->KeyCode == Keys::W) {
		MoveUp();
		Print();
	}
	if (e->KeyCode == Keys::S) {
		MoveDown();
		Print();
	}
	if (e->KeyCode == Keys::A) {
		MoveLeft();
		Print();
	}

	return System::Void();

}


void Game2048::MyForm::Game_Update(Object^ sender, EventArgs^ e) {
	

}