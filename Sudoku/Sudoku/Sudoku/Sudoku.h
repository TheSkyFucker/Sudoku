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
using namespace std;

class Sudoku
{

private:

    int m_matrix[9][9];          //数独矩阵
    int m_crashElem;             //冲突格子数
    int m_emptyElem;             //为空格子数
    int usedRow[9][10];          //第 i 行，数字 j 被使用
    int usedCol[9][10];          //第 i 列，数字 j 被使用
    int usedBlock[3][3][10];     //(i, j) 宫中数字 k 被使用


public:

    int GetCrashElem() throw();

    int GetEmptyElem() throw();

    int GetMatrix(int row, int col) throw();
    

    //************************************
    // Method: 初始所有格子都为 0
    //************************************
    Sudoku() throw();


    //************************************
    // Method: 设置row行col列的数字为digit
    //************************************
    void SetMatrix(int row, int col, int digit) throw();


    //************************************
    // Method: 检测 m_matrix[row][col] 是否冲突
    //************************************
    bool IsCrash(int row, int col) throw();


    //************************************
    // Method: 检测是否为合法终盘
    //************************************
    bool IsLegal() throw();


    //************************************
    // Method: 交换两行
    //************************************
    void SwapRow(int rowA, int rowB) throw();


    //************************************
    // Method: 交换两列
    //************************************
    void SwapCol(int colA, int colB) throw();


    //************************************
    // Method: 析构
    //************************************
    ~Sudoku() throw();


};


