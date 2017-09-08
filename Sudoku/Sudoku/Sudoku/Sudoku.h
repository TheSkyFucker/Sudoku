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

class Sudoku
{

private:

    int m_matrix[9][9];             //��������
    int m_crashElem;                //��ͻ������
    int m_emptyElem;                //Ϊ�ո�����
    int m_usedRow[9][10];           //�� i �У����� j ��ʹ��
    int m_usedCol[9][10];           //�� i �У����� j ��ʹ��
    int m_usedBlock[3][3][10];      //(i, j) �������� k ��ʹ��


public:

    //************************************
    // Method:    GetCrashElem
    // FullName:  Sudoku::GetCrashElem
    // Access:    public 
    // Returns:   int
    // Qualifier: throw()
    // Function: ��ȡ��ͻԪ������
    //************************************
    int GetCrashElem() const throw();


    //************************************
    // Method:    GetEmptyElem
    // FullName:  Sudoku::GetEmptyElem
    // Access:    public 
    // Returns:   int
    // Qualifier: throw()
    // Function: ��ȡΪ��Ԫ������
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
    // Function: ��ȡ(row, col)��Ԫ��
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
    // Function: ���(row, col)����digit�Ƿ�������ͻ
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
    // Functuon: ����(row, col)��Ԫ��Ϊdigit
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
    // Function: ����(row, col)��Ԫ���Ƿ��ͻ
    //************************************
    bool IsCrash(int row, int col) const throw();

    
    //************************************
    // Method:    IsLegal
    // FullName:  Sudoku::IsLegal
    // Access:    public 
    // Returns:   bool
    // Qualifier: throw()
    // Funciton: ����Ƿ�Ϊ�Ϸ�����
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


