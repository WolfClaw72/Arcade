#include "MSFunctions.h"

MSFunctions::MSFunctions() {}

bool MSFunctions::isValid(int j, int i)
{
	return (j > 0) && (j < width - 1) &&
		(i > 0) && (i < height - 1);
}

void MSFunctions::spawnField(int bombs) {
	if (1 > bombs || bombs > width * height) {
		bombs = (rand() % ((width * height) + 1));
		std::cout << "Random number of bombs spawned\n";
	}
	for (int i = 0; i < bombs; ++i) {
		int selection[2] = { (rand() % ((width - 1) + 1)), (rand() % ((height - 1) + 1)) };
		if (Table[selection[0]][selection[1]].getValue() != '*')
			Table[selection[0]][selection[1]].setValue('*');
		else
			i--;
	}

	calculateNums();
	draw();
};

void MSFunctions::calculateNums() {
	int number = 0;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (Table[j][i].getValue() != '*') {
				if (isValid(j - 1, i - 1) == true && Table[j - 1][i - 1].getValue() == '*')
					number++;
				if (isValid(j, i - 1) == true && Table[j][i - 1].getValue() == '*')
					number++;
				if (isValid(j + 1, i - 1) == true && Table[j + 1][i - 1].getValue() == '*')
					number++;
				if (isValid(j + 1, i) == true && Table[j + 1][i].getValue() == '*')
					number++;
				if (isValid(j + 1, i + 1) == true && Table[j + 1][i + 1].getValue() == '*')
					number++;
				if (isValid(j, i + 1) == true && Table[j][i + 1].getValue() == '*')
					number++;
				if (isValid(j - 1, i + 1) == true && Table[j - 1][i + 1].getValue() == '*')
					number++;
				if (isValid(j - 1, i) == true && Table[j - 1][i].getValue() == '*')
					number++;
				Table[j][i].setValue(number);
			}
		}
	}
};

void MSFunctions::draw() {
	for (int i = 0; i < width + 1; i++) {
		std::cout << "|" << i;
	}
	std::cout << "\n";
	
	for (int i = 0; i < height; i++) {
		std::cout << "|" << i + 1;
		for (int j = 0; j < width; j++) {
			std::cout << "|" << Table[j][i].getValue();
		}
		std::cout << "\n";
	}
};

void MSFunctions::reveal(int j,int i) {
	Visible[j][i].setState(2);
	Visible[j][i].setValue(Table[j][i].getValue());
}

void MSFunctions::flag(int j, int i) {
	Visible[j][i].setState(1);
}

MSFunctions::~MSFunctions() {}