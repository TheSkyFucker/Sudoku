// Sudoku.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Sudoku.h"


int Sudoku::GetCrashElem() const throw()
{
    return m_crashElem;
}

int Sudoku::GetEmptyElem() const throw()
{
    return m_emptyElem;
}

int Sudoku::GetMatrix(int row, int col) const throw()
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
        m_usedRow[row][preDigit]--;
        m_usedCol[col][preDigit]--;
        m_usedBlock[row / 3][col / 3][preDigit]--;
    }
    ///set
    m_matrix[row][col] = digit;
    if (digit > 0)
    {
        m_emptyElem--;
        m_usedRow[row][digit]++;
        m_usedCol[col][digit]++;
        m_usedBlock[row / 3][col / 3][digit]++;
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
    memset(m_usedRow, 0, sizeof(m_usedRow));
    memset(m_usedCol, 0, sizeof(m_usedCol));
    memset(m_usedBlock, 0, sizeof(m_usedBlock));
    //init m_matrix
    memset(m_matrix, 0, sizeof(m_matrix));
}

bool Sudoku::CanSetMartrix(int row, int col, int digit) const throw()
{
    int limit = m_matrix[row][col] != digit ? 0 : 1;
    return m_usedRow[row][digit] == limit && m_usedCol[col][digit] == limit && m_usedBlock[row / 3][col / 3][digit] == limit;
}

bool Sudoku::IsCrash(int row, int col) const throw()
{
    const int &digit = m_matrix[row][col];
    if (digit == 0) return false;
    if (m_usedRow[row][digit] > 1) return true;
    if (m_usedCol[col][digit] > 1) return true;
    if (m_usedBlock[row / 3][col / 3][digit] > 1) return true;
    return false;
}

bool Sudoku::IsLegal() const throw()
{
    return !m_emptyElem && !m_crashElem;
}

Sudoku::~Sudoku() throw()
{
}
