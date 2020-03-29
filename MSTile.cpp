#include "MSTile.h"
#include <iostream>

MSTile::MSTile() { State = Hidden; Value = '0'; };

void MSTile::setState(int n) {
	if (n > 2 || n < 0)
		std::cout << "Invalid state";
	else
		State = n;
};

void MSTile::setValue(char n) {
	Value = n;
};

int MSTile::getState() const {
	return State;
};

char MSTile::getValue() const {
	if (State == Revealed)
	return Value;
};

MSTile::~MSTile() {};