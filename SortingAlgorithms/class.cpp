#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "class.h"

void Object::configuration()
{
    std::fstream file;
    if (file.good()) std::cout << "Input file is alright" << std::endl;

    file.open("config.txt", std::ios::in);

    for (int i = 0; i < 5; i++)
    {
        std::getline(file, config[i]);
        std::cout << config[i] << std::endl;
    }

    file.close();

    length = stoi(config[4]);
}

void Object::input()
{
    numbers = new int[stoi(config[4])];
    std::fstream in;
    if (in.good()) std::cout << "Output file is alright" << std::endl;

    in.open(config[0], std::ios::in);

    std::string buffer;
    for (int i = 0; i < length; i++)
    {
        in >> buffer;
        buffer.pop_back();
        numbers[i] = std::stoi(buffer);
    }

    in.close();
}

void Object::solve()
{
    //sortowanie malej¹co

    auto start = std::chrono::high_resolution_clock::now();

    int buffer = 0;
    for (int end = 0; end != (length - 1);)
    {
        end = 0;
        for (int i = 0; i < (length - 1); i++)
        {
            if (numbers[i] >= numbers[i + 1])
            {
                end++;
            }
            else
            {
                buffer = numbers[i];
                numbers[i] = numbers[i + 1];
                numbers[i + 1] = buffer;
            }
        }
        std::cout << "Progress " << ((float)end / (length - 1)) * 100 << "%" << std::endl;
    }

    auto finish = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start);
}

void Object::save()
{
    std::fstream out;
    if (out.good()) std::cout << "Save file is alright" << std::endl;

    out.open(config[1], std::ios::out);

    for (int i = 0; i < length; i++)
    {
        out << numbers[i] << ", ";
    }

    out.close();

    std::cout << "Succesfully saved" << std::endl;
}