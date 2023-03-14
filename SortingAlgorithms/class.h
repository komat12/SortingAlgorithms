#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#pragma once

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

	void solve();

	void save();

};