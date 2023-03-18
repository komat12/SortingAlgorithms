#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#pragma once

void quick_sort(int*, int, int);

class Object
{
private:
	
	int* numbers;
	std::chrono::nanoseconds time;
	std::string config[5];
	int length;

public:

	void configuration();

	void input();

	void solve_bouble();

	void solve_quick();

	void save();

};