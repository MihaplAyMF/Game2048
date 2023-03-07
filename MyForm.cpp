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
			grid[i, j]->label = gcnew Label();
			grid[i, j]->label->Location = Point(10 + i * 70, 105 + j * 70);
			grid[i, j]->label->Size = System::Drawing::Size(60, 30);
			grid[i, j]->label->Font = gcnew System::Drawing::Font("Arial", 14);
			grid[i, j]->label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			grid[i, j]->label->BackColor = Color::LightGray;
			grid[i, j]->label->ForeColor = Color::Black;
			grid[i, j]->label->Text = " ";
			Controls->Add(grid[i, j]->label);
			grid[i, j]->pictureBox = gcnew PictureBox();
			grid[i, j]->pictureBox->Location = Point(10 + i * 70, 90 + j * 70);
			grid[i, j]->pictureBox->Size = System::Drawing::Size(60, 60);
			grid[i, j]->pictureBox->BackColor = Color::LightGray;
			Controls->Add(grid[i, j]->pictureBox);
		}
	}
	AddRundomNumber();
}

void Game2048::MyForm::AddRundomNumber(){
	int x, y, i;

	do {
		x = randint(0, 4);
		y = randint(0, 4);

	} while (grid[x, y]->num != 0);

	grid[x, y]->num = randint(1,2)*2;

}

void Game2048::MyForm::ClearState() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			grid[i, j]->state = false;
		}
	}

}

void Game2048::MyForm::Print(){
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (grid[i, j]->num != 0) {
				grid[i, j]->label->Text = grid[i, j]->num.ToString();
			} else {
				grid[i, j]->label->Text = " ";
			}
		}
	}
	label2->Text = score.ToString();
}

void Game2048::MyForm::MoveUp() {

	int stateRandom = 0;

	for (int i = 0; i < SIZE; i++) {
		for (int j = 1; j < SIZE; j++) {
			for (int k = j; k > 0; k--) {

				if (grid[i, k]->num == 0) {
					continue;
				}

				if (grid[i, k]->num != 0 && grid[i, k - 1]->num == 0) {
					grid[i, k - 1]->num = grid[i, k]->num;
					grid[i, k]->num = 0;
					stateRandom = 1;
				} else if (grid[i, k]->num == grid[i, k - 1]->num && grid[i, k - 1]->state == false && grid[i, k]->state == false) {
					grid[i, k - 1]->num += grid[i, k]->num;
					grid[i, k]->num = 0;
					grid[i, k - 1]->state = true;
					score += grid[i, k - 1]->num;
					stateRandom = 1;
				}
			}
		}
	}

	if(stateRandom == 1){
		AddRundomNumber();
	}

	ClearState();
}

void Game2048::MyForm::MoveRight(){
	
	int stateRandom = 0;

	for (int i = 0; i < SIZE; i++) {
		for (int j = SIZE - 1; j >= 0; j--) {
			for (int k = j; k < SIZE - 1; k++) {

				if (grid[k, i]->num == 0) {
					continue;
				}

				if (grid[k, i]->num != 0 && grid[k + 1, i]->num == 0) {
					grid[k + 1, i]->num = grid[k, i]->num;
					grid[k, i]->num = 0;
					stateRandom = 1;
				} else if (grid[k, i]->num == grid[k + 1, i]->num && grid[k + 1, i]->state == false && grid[k, i]->state == false) {
					grid[k + 1, i]->num += grid[k, i]->num;
					grid[k, i]->num = 0;
					grid[k + 1, i]->state = true;
					score += grid[k + 1, i]->num;
					stateRandom = 1;
				}
			}
		}
	}

	if (stateRandom == 1) {
		AddRundomNumber();
	}

	ClearState();
}

void Game2048::MyForm::MoveDown() {

	int stateRandom = 0;
	for (int i = 0; i < SIZE; i++) {
		for (int j = SIZE - 1; j >= 0; j--) {
			for (int k = j; k < SIZE - 1; k++) {

				if (grid[i, k]->num == 0) {
					continue;
				}

				if (grid[i, k]->num != 0 && grid[i, k + 1]->num == 0) {
					grid[i, k + 1]->num = grid[i, k]->num;
					grid[i, k]->num = 0;
					stateRandom = 1;
				} else if (grid[i, k]->num == grid[i, k + 1]->num && grid[i, k + 1]->state == false && grid[i, k]->state == false) {
					grid[i, k + 1]->num += grid[i, k]->num;
					grid[i, k]->num = 0;
					grid[i, k + 1]->state = true;
					score += grid[i, k + 1]->num;
					stateRandom = 1;
				}
			}
		}
	}

	if (stateRandom == 1) {
		AddRundomNumber();
	}

	ClearState();
}

void Game2048::MyForm::MoveLeft() {

	int stateRandom = 0;

	for (int i = 0; i < SIZE; i++) {
		for (int j = 1; j < SIZE; j++) {
			for (int k = j; k > 0; k--) {

				if (grid[k, i]->num == 0) {
					continue;
				}

				if (grid[k, i]->num != 0 && grid[k - 1, i]->num == 0) {
					grid[k - 1, i]->num = grid[k, i]->num;
					grid[k, i]->num = 0;
					stateRandom = 1;
				} else if (grid[k, i]->num == grid[k - 1, i]->num && grid[k - 1, i]->state == false && grid[k, i]->state == false) {
					grid[k - 1, i]->num += grid[k, i]->num;
					grid[k, i]->num = 0;
					grid[k - 1, i]->state = true;
					score += grid[k - 1, i]->num;
					stateRandom = 1;
				}
			}
		}
	}

	if (stateRandom == 1) {
		AddRundomNumber();
	}
	
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
