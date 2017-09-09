#include "stdafx.h"
#include "SudokuChecker.h"


SudokuChecker::SudokuChecker()
{
}


void SudokuChecker::Check() const throw(std::exception)
{
    //config
    std::set<std::string> table;

    //check
    int row = 0;
    int col = 0;
    std::string str;
    str.resize(81);
    for (char ch = getchar(); ch != EOF; ch = getchar())
    {
        if (ch < '0' || ch > '9')
        {
            continue;
        }
        str[row * 9 + col] = ch;
        if (++col == 9)
        {
            col = 0;
            row = (row < 8) * (row + 1);
        }
        if (row == 0 && col == 0)
        {
            if (table.find(str) != table.end())
            {
                throw std::exception("��SudokuChecker::Check�������������ļ� sudoku.txt �����ظ�����");
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
        throw std::exception("��SudokuChecker::Check�������������ļ� sudoku.txt ����������������");
    }
}

SudokuChecker::~SudokuChecker()
{
}
