//===============================================================
//Summary:
//          CommandWorker ¿‡£¨ 
//FileName:
//          CommandWorker.h
//Remarks:
//          ...
//Date:
//          2017/9/9
//Author:
//          kino(359084415@qq.com)
//===============================================================
#pragma once
#include "../Sudoku/Sudoku.h"
#include "../Sudoku/SudokuChecker.h"
#include "../Sudoku/SudokuGenerator.h"

class CommandWorker
{
public:


    //************************************
    // Method:    CommandWorker
    // FullName:  CommandWorker::CommandWorker
    // Access:    public 
    // Returns:   
    // Qualifier:
    //************************************
    CommandWorker();


    //************************************
    // Method:    WorkCommandC
    // FullName:  CommandWorker::WorkCommandC
    // Access:    public 
    // Returns:   void
    // Qualifier: const throw()
    // Function: ÷¥–– -c ÷∏¡Ó
    //************************************
    void WorkCommandC(int argc, char * argv[]) const throw();


    ~CommandWorker();
};

