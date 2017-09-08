#include "stdafx.h"
#include "SudokuChecker.h"


SudokuChecker::SudokuChecker()
{
}


bool SudokuChecker::Check() const throw(std::exception)
{
    //config
    std::set<std::string> table;

    //check
    int row = 0;
    int col = 0;
    char str[82];
    str[81] = '\0';
    for (char ch = getchar(); ch != EOF; ch = getchar())
    {
        if (ch < '0' || ch > '9')
        {
            continue;
        }
        str[row * 9 + col] = ch - '0';
        if (++col == 9)
        {
            col = 0;
            row = (row < 8) * (row + 1);
        }
        if (row == 0 && col == 0)
        {
            if (table.find(str) != table.end())
            {
                return false;
            }
            else 
            {
                table.insert(str);
            }
        }
    }

    //return
    if (row != 0 || col != 0)
    {
        throw std::exception("【SudokuChecker::Check】被测试终盘文件 sudoku.txt 包含不完整的终盘");
    }
    return true;
}

SudokuChecker::~SudokuChecker()
{
}
