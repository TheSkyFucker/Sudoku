//===============================================================
//Summary:
//          Sudoku �࣬ 
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

    int m_matrix[9][9];          //��������
    int m_crashElem;             //��ͻ������
    int m_emptyElem;             //Ϊ�ո�����
    int usedRow[9][10];          //�� i �У����� j ��ʹ��
    int usedCol[9][10];          //�� i �У����� j ��ʹ��
    int usedBlock[3][3][10];     //(i, j) �������� k ��ʹ��


public:

    int GetCrashElem() throw();

    int GetEmptyElem() throw();

    int GetMatrix(int row, int col) throw();
    

    //************************************
    // Method: ��ʼ���и��Ӷ�Ϊ 0
    //************************************
    Sudoku() throw();


    //************************************
    // Method: ����row��col�е�����Ϊdigit
    //************************************
    void SetMatrix(int row, int col, int digit) throw();


    //************************************
    // Method: ��� m_matrix[row][col] �Ƿ��ͻ
    //************************************
    bool IsCrash(int row, int col) throw();


    //************************************
    // Method: ����Ƿ�Ϊ�Ϸ�����
    //************************************
    bool IsLegal() throw();


    //************************************
    // Method: ��������
    //************************************
    void SwapRow(int rowA, int rowB) throw();


    //************************************
    // Method: ��������
    //************************************
    void SwapCol(int colA, int colB) throw();


    //************************************
    // Method: ����
    //************************************
    ~Sudoku() throw();


};


