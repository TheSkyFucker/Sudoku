//===============================================================
//Summary:
//          Sudoku 类， 
//FileName:
//          Sudoku.h
//Remarks:
//          ...
//Date:
//          2017/9/7
//Author:
//          kino(359084415@qq.com)
//===============================================================
#pragma once
#include <iostream>
#include <algorithm>

class Sudoku
{

private:

    int m_matrix[9][9];             //数独矩阵
    int m_crashElem;                //冲突格子数
    int m_emptyElem;                //为空格子数
    int m_usedRow[9][10];           //第 i 行，数字 j 被使用
    int m_usedCol[9][10];           //第 i 列，数字 j 被使用
    int m_usedBlock[3][3][10];      //(i, j) 宫中数字 k 被使用


public:

    //************************************
    // Method:    GetCrashElem
    // FullName:  Sudoku::GetCrashElem
    // Access:    public 
    // Returns:   int
    // Qualifier: throw()
    // Function: 获取冲突元素数量
    //************************************
    int GetCrashElem() const throw();


    //************************************
    // Method:    GetEmptyElem
    // FullName:  Sudoku::GetEmptyElem
    // Access:    public 
    // Returns:   int
    // Qualifier: throw()
    // Function: 获取为空元素数量
    //************************************
    int GetEmptyElem() const throw();


    //************************************
    // Method:    GetMatrix
    // FullName:  Sudoku::GetMatrix
    // Access:    public 
    // Returns:   int
    // Qualifier: throw()
    // Parameter: int row
    // Parameter: int col
    // Function: 获取(row, col)的元素
    //************************************
    int GetMatrix(int row, int col) const throw();
    

    //************************************
    // Method:    Sudoku
    // FullName:  Sudoku::Sudoku
    // Access:    public 
    // Returns:   
    // Qualifier: throw()
    //************************************
    Sudoku() throw();


    //************************************
    // Method:    CanSetMatrix
    // FullName:  Sudoku::CanSetMatrix
    // Access:    public 
    // Returns:   bool
    // Qualifier: throw()
    // Parameter: int row
    // Parameter: int col
    // Parameter: int digit
    // Function: 检测(row, col)放置digit是否会引起冲突
    //************************************
    bool CanSetMartrix(int row, int col, int digit) const throw();


    //************************************
    // Method:    SetMatrix
    // FullName:  Sudoku::SetMatrix
    // Access:    public 
    // Returns:   void
    // Qualifier: throw()
    // Parameter: int row
    // Parameter: int col
    // Parameter: int digit
    // Functuon: 设置(row, col)的元素为digit
    //************************************
    void SetMatrix(int row, int col, int digit) throw();


    //************************************
    // Method:    IsCrash
    // FullName:  Sudoku::IsCrash
    // Access:    public 
    // Returns:   bool
    // Qualifier: throw()
    // Parameter: int row
    // Parameter: int col
    // Function: 检验(row, col)的元素是否冲突
    //************************************
    bool IsCrash(int row, int col) const throw();

    
    //************************************
    // Method:    IsLegal
    // FullName:  Sudoku::IsLegal
    // Access:    public 
    // Returns:   bool
    // Qualifier: throw()
    // Funciton: 检测是否为合法终盘
    //************************************
    bool IsLegal() const throw();

    
    //************************************
    // Method:    ~Sudoku
    // FullName:  Sudoku::~Sudoku
    // Access:    public 
    // Returns:   
    // Qualifier: throw()
    //************************************
    ~Sudoku() throw();


};


