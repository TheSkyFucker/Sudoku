#include "stdafx.h"
#include "time.h"
#include "SudokuGenerator.h"



SudokuGenerator::SudokuGenerator(int _fixedDigit) throw()
{
    this->m_fixedDigit = _fixedDigit;
}

void SudokuGenerator::OutputSudoku(const int table[9][9]) throw()
{
    char temp[180];
    temp[(9 * 8 + 9) << 1] = '\0';
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            temp[(row * 9 + col) << 1] = '0' + table[row][col];
            temp[(row * 9 + col) << 1 | 1] = col == 8 ? '\n' : ' ';
        }
    }
    puts(temp);
}

void SudokuGenerator::OutputSudoku(const Sudoku sudo) throw()
{
    int table[9][9];
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            table[row][col] = sudo.GetMatrix(row, col);
        }
    }
    OutputSudoku(table);
}

bool SudokuGenerator::NextBlockTable(int * table) throw()
{
    if (std::next_permutation(table + 6, table + 9))
    {
        return true;
    }
    if (std::next_permutation(table + 3, table + 6))
    {
        return true;
    }
    if (std::next_permutation(table + 1, table + 3))
    {
        return true;
    }
    return false;
}

bool SudokuGenerator::NextDigitTable(int * table) throw()
{
    //move m_fixedDigit to the end
    for (int pos = m_fixedDigit - 1; pos < 8; pos++)
    {
        std::swap(table[pos], table[pos + 1]);
    }
    bool ret = std::next_permutation(table, table + 8);
    //move m_fixedDigit back
    for (int pos = 8; pos >= m_fixedDigit; pos--)
    {
        std::swap(table[pos], table[pos - 1]);
    }
    return ret;
}

void SudokuGenerator::FastGenerate(Sudoku seed, int num) throw(std::exception)
{
    //init
    const int MAX_NUMBER = 2000000;
    int digitTable[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int rowTable[9] = { 0, 1, 2, 3, 4, 5, 6 ,7 ,8 };
    int colTable[9] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
    int resultTable[9][9];

    //work
    if (num > MAX_NUMBER)
    {
        throw std::exception("【SudokuGenerator::FastGenerate】Param(num) is bigger than MAX_NUMBER");
    }
    while (num-- > 0)
    {

        //generate
        Sudoku sudo;
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                const int &_row = rowTable[row];
                const int &_col = colTable[col];
                const int &_digit = digitTable[seed.GetMatrix(row, col) - 1];
                resultTable[_row][_col] = _digit;
            }
        }
        OutputSudoku(resultTable);

        //prepare next
        if (NextBlockTable(colTable) || NextBlockTable(rowTable) || NextDigitTable(digitTable))
        {
            continue;
        }

        //Unexpect Logic
        throw std::exception("【SudokuGenerator::FastGenerate】【Unexpected Logic Path】无法生成下一个重编码方案");
    }

    //finish
    return;
}

/*void SudokuGenerator::GetRandomRow(int arr[9]) throw()
{
    vector<int> temp;
    for (int digit = 1; digit <= 9; digit++)
    {
        temp.push_back(digit);
    }
    for (int pos = 0; pos < 9; pos++)
    {
        //get
        int ranPos = rand() % (int)temp.size();
        arr[pos] = temp[ranPos];
        //throw
        swap(temp[ranPos], temp.back());
        temp.pop_back();
    }
}*/

bool SudokuGenerator::Search(Sudoku & sudo, int row, int col) throw()
{
    if (row == 0 && col == 0)
    {
        sudo.SetMatrix(row, col, m_fixedDigit);
        return Search(sudo, row, col + 1);
    }
    if (col == 9)
    {
        if (++row == 9)
        {
            return true;
        }
        col = 0;
    }
    //config
    std::vector<int> temp;
    for (int digit = 1; digit <= 9; digit++)
    {
        if (sudo.CanSetMartrix(row, col, digit))
        {
            temp.push_back(digit);
        }
    }
    //search
    while (!temp.empty())
    {
        //search
        int pos = rand() % (int)temp.size();
        sudo.SetMatrix(row, col, temp[pos]);
        bool ret = Search(sudo, row, col + 1);
        if (ret)
        {
            return true;
        }
        else
        {
            sudo.SetMatrix(row, col, 0);
        }
        //throw
        std::swap(temp[pos], temp.back());
        temp.pop_back();
    }
    return false;
}

void SudokuGenerator::BestGenerate(int num) throw(std::exception)
{
    //config
    srand((unsigned)time(0));
    const int MAX_NUMBER = 2000000;
    //work
    if (num > MAX_NUMBER)
    {
        throw std::exception("【SudokuGenerator::BestGenerate】Param(num) is bigger than MAX_NUMBER");
    }
    while (num-- > 0)
    {
        Sudoku sudo;
        bool ret = Search(sudo);
        if (!ret)
        {
            throw std::exception("【SudokuGenerator::BestGenerate】搜索失败，请确认调用 Search 的 sudoku 为全 0");
        }
        OutputSudoku(sudo);
    }

}

SudokuGenerator::~SudokuGenerator()
{
}
