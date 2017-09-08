// test.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include "../Sudoku/Sudoku.h"
#include "../Sudoku/SudokuGenerator.h"
#include "../Sudoku//SudokuChecker.h"
using namespace std;

#include<time.h>  

int main()
{
    //config
    clock_t startTime = clock();
    freopen("sudoku.txt", "w", stdout);
    SudokuGenerator gen;
    Sudoku seed;
    const int table[] = { 7, 4, 1, 2 ,5, 8, 3, 6, 9 };
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            int digit = (table[row] + col - 1) % 9 + 1;
            seed.SetMatrix(row, col, digit);
        }
    }
   
    try
    {
        gen.FastGenerate(seed, 1000000);

    }
    catch (const std::exception& e)
    {
        puts(e.what());
        return 0;
    }
    
    fclose(stdout);
    freopen("CON", "w", stdout);
    freopen("sudoku.txt", "r", stdin);
    clock_t middleTime = clock();
    cout << "middle Time : " << (double)(middleTime - startTime) / CLOCKS_PER_SEC << "s" << endl;

    SudokuChecker checker;
    try
    {
        if (checker.Check())
        {
            cout << "测试通过" << std::endl;
        }
        else
        {
            cout << "测试未通过" << std::endl;
        }
    }
    catch (const std::exception&e)
    {
        puts(e.what());
        return 0;
    }

    fclose(stdin);
    clock_t endTime = clock();

    cout << "Totle Time : " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    
    return 0;
}

