#include <iostream>
#include "MSFunctions.h"

using namespace std;

int main() {
	int bombs;
	MSFunctions Minesweeper;
	
	cout << "How many bombs would you like (0 for a random amount): ";
	cin >> bombs;

	Minesweeper.spawnField(bombs);




	system("pause");
	return 0;
}