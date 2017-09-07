// Sudoku.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Sudoku.h"


int Sudoku::GetCrashElem() throw()
{
    return m_crashElem;
}

int Sudoku::GetEmptyElem() throw()
{
    return m_emptyElem;
}

int Sudoku::GetMatrix(int row, int col) throw()
{
    return m_matrix[row][col];
}

void Sudoku::SetMatrix(int row, int col, int digit) throw()
{
    //undo set
    const int &preDigit = m_matrix[row][col];
    if (IsCrash(row, col))
    {
        m_crashElem--;
    }
    if (preDigit > 0)
    {
        m_emptyElem++;
        usedRow[row][preDigit]--;
        usedCol[col][preDigit]--;
        usedBlock[row / 3][col / 3][preDigit]--;
    }
    ///set
    m_matrix[row][col] = digit;
    if (digit > 0)
    {
        m_emptyElem--;
        usedRow[row][preDigit]++;
        usedCol[col][preDigit]++;
        usedBlock[row / 3][col / 3][preDigit]++;
    }
    if (IsCrash(row, col))
    {
        m_crashElem++;
    }
}

Sudoku::Sudoku() throw()
{
    //init Condition
    m_emptyElem = 81;
    m_crashElem = 0;
    memset(usedRow, 0, sizeof(usedRow));
    memset(usedCol, 0, sizeof(usedCol));
    memset(usedBlock, 0, sizeof(usedBlock));
    //init m_matrix
    memset(m_matrix, 0, sizeof(m_matrix));
}


bool Sudoku::IsCrash(int row, int col) throw()
{
    const int &digit = m_matrix[row][col];
    if (digit == 0) return false;
    if (usedRow[row][digit] > 1) return true;
    if (usedCol[col][digit] > 1) return true;
    if (usedBlock[row / 3][col / 3][digit] > 1) return true;
    return false;
}


bool Sudoku::IsLegal() throw()
{
    if (m_emptyElem != 0 || m_crashElem != 0)
    {
        return false;
    }
    return true;
}

void Sudoku::SwapRow(int rowA, int rowB) throw()
{
    for (int col = 0; col < 9; col++)
    {
        const int digitA = m_matrix[rowA][col];
        const int digitB = m_matrix[rowB][col];
        SetMatrix(rowA, col, digitB);
        SetMatrix(rowB, col, digitA);
    }
}

void Sudoku::SwapCol(int colA, int colB) throw()
{
    for (int row = 0; row < 9; row++)
    {
        const int digitA = m_matrix[row][colA];
        const int digitB = m_matrix[row][colB];
        SetMatrix(row, colA, digitB);
        SetMatrix(row, colB, digitA);
    }
}

Sudoku::~Sudoku() throw()
{
}
