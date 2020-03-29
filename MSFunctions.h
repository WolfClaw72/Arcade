#ifndef MSFunctions_H
#define MSFunctions_H
#include "MSTile.h"
#include <random>
#include <iostream>
class MSFunctions{
protected:
	static const int width = 8;
	static const int height = 8;
	MSTile Table[width][height];
	MSTile Visible[width][height];
public:
	MSFunctions();
	bool isValid(int, int);
	void spawnField(int);
	void calculateNums();
	void draw();
	void reveal(int, int);
	void flag(int, int);
	~MSFunctions();
};
#endif;