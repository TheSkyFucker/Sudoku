//===============================================================
//Summary:
//          SudokuGenerator �࣬ 
//FileName:
//          SudokuGenerator.h
//Remarks:
//          ...
//Date:
//          2017/9/7
//Author:
//          kino(359084415@qq.com)
//===============================================================
#pragma once
#pragma warning (disable:4290)
#include <set>
#include <vector>
#include "Sudoku.h"

class SudokuGenerator
{

private:

    int m_fixedDigit;           //�̶������Ͻǵ�����

public:

    //************************************
    // Method:    SudokuGenerator
    // FullName:  SudokuGenerator::SudokuGenerator
    // Access:    public 
    // Returns:   
    // Qualifier: throw()
    // Parameter: int _fixedDigit
    //************************************
    explicit SudokuGenerator(int _fixedDigit = 1) throw();


    //************************************
    // Method:    OutputSudoku
    // FullName:  SudokuGenerator::OutputSudoku
    // Access:    public 
    // Returns:   void
    // Qualifier: throw()
    // Parameter: int table[9][9]
    //************************************
    void OutputSudoku(const int table[9][9]) throw();


    //************************************
    // Method:    OutputSudoku
    // FullName:  SudokuGenerator::OutputSudoku
    // Access:    public 
    // Returns:   void
    // Qualifier: throw()
    // Parameter: const Sudoku sudo
    //************************************
    void OutputSudoku(const Sudoku sudo) throw();


    //************************************
    // Method:    NextRowTable
    // FullName:  SudokuGenerator::NextRowTable
    // Access:    private 
    // Returns:   bool
    // Qualifier:
    // Parameter: int * table
    // Function: ���ƻ� Sudoku && (0, 0) ����һ�� ��/���ر��
    //************************************
    bool NextBlockTable(int * table) throw();


    //************************************
    // Method:    NextDigitTable
    // FullName:  SudokuGenerator::NextDigitTable
    // Access:    public 
    // Returns:   bool
    // Qualifier: throw()
    // Parameter: int * table
    // Function: ���ƻ� Sudoku && (0, 0) ����һ�� �����ر��
    //************************************
    bool NextDigitTable(int * table) throw();


    //************************************
    // Method:    FastGenerate
    // FullName:  SudokuGenerator::FastGenerate
    // Access:    public 
    // Returns:   void
    // Qualifier: throw(exception), seed �豣֤���Ͻ�Ϊ m_fixedDigit
    // Parameter: Sudoku seed
    // Parameter: int num
    //************************************
    void FastGenerate(Sudoku seed, int num) throw(std::exception);


    //************************************
    // Method:    Search
    // FullName:  SudokuGenerator::Search
    // Access:    public 
    // Returns:   bool
    // Qualifier: throw()����Ҫ��֤�������� Sudoku ȫΪ0
    // Parameter: Sudoku & sudo
    // Parameter: int row
    // Parameter: int timer
    // Function: ��������
    // Mark: ����֤����ǰ�Ĳ��ظ�
    //************************************
    bool Search(Sudoku &sudo, int row = 0, int col = 0) throw();


    //************************************
    // Method:    BestGenerate
    // FullName:  SudokuGenerator::BestGenerate
    // Access:    public 
    // Returns:   void
    // Qualifier: throw(exception)
    // Parameter: int num
    // Function: ���ɵ���������ԡ����ϴ�
    //************************************
    void BestGenerate(int num) throw(std::exception);


    ~SudokuGenerator();

};

