//===============================================================
//Summary:
//          SudokuGenerator 类， 
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

    int m_fixedDigit;           //固定在左上角的数字

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
    // Function: 不破坏 Sudoku && (0, 0) 的下一个 行/列重编号
    //************************************
    bool NextBlockTable(int * table) throw();


    //************************************
    // Method:    NextDigitTable
    // FullName:  SudokuGenerator::NextDigitTable
    // Access:    public 
    // Returns:   bool
    // Qualifier: throw()
    // Parameter: int * table
    // Function: 不破坏 Sudoku && (0, 0) 的下一个 数字重编号
    //************************************
    bool NextDigitTable(int * table) throw();


    //************************************
    // Method:    FastGenerate
    // FullName:  SudokuGenerator::FastGenerate
    // Access:    public 
    // Returns:   void
    // Qualifier: throw(exception), seed 需保证左上角为 m_fixedDigit
    // Parameter: Sudoku seed
    // Parameter: int num
    //************************************
    void FastGenerate(Sudoku seed, int num) throw(std::exception);


    //************************************
    // Method:    Search
    // FullName:  SudokuGenerator::Search
    // Access:    public 
    // Returns:   bool
    // Qualifier: throw()，需要保证传进来的 Sudoku 全为0
    // Parameter: Sudoku & sudo
    // Parameter: int row
    // Parameter: int timer
    // Function: 深搜终盘
    // Mark: 不保证跟以前的不重复
    //************************************
    bool Search(Sudoku &sudo, int row = 0, int col = 0) throw();


    //************************************
    // Method:    BestGenerate
    // FullName:  SudokuGenerator::BestGenerate
    // Access:    public 
    // Returns:   void
    // Qualifier: throw(exception)
    // Parameter: int num
    // Function: 生成的数独随机性、差别较大；
    //************************************
    void BestGenerate(int num) throw(std::exception);


    ~SudokuGenerator();

};

