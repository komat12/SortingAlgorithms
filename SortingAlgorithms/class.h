#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <vector>
#pragma once

void quick_sort(int*, int, int);

class Object
{
private:
	
	int* numbers;
	int time_loop_count = 0;
	std::chrono::nanoseconds time[10];
	std::string config[5];
	int length;

public:

	void configuration();

	void input();

	void solve_bouble();

	void solve_quick();

	void solve_insanity();

	void save();

	int loop_count();

	void save_time();
};