#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "class.h"

void quick_sort(int* tab, int left, int right)
{
    //std::cout << "Sorting" << std::endl;
    if (right <= left) return;

    int i = left - 1, j = right + 1,
        pivot = tab[(left + right) / 2]; //wybieramy punkt odniesienia

    while (1)
    {
        while (pivot > tab[++i]);
        {

            while (pivot < tab[--j]);
            {
                if (i <= j) std::swap(tab[i], tab[j]);
                else
                    break;
            }
        }
    }

    if (j > left)
        quick_sort(tab, left, j);
    if (i < right)
        quick_sort(tab, i, right);
}

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

void Object::solve_bouble()
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

void Object::solve_quick()
{
    quick_sort(numbers, 0, length - 1);
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