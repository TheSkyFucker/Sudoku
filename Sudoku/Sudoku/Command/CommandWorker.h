//===============================================================
//Summary:
//          CommandWorker �࣬ 
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
    // Method:    getExePath
    // FullName:  CommandWorker::getExePath
    // Access:    public 
    // Returns:   std::string
    // Qualifier: const throw()
    // Function: ��ȡ��ǰexe�ļ�Ŀ¼
    //************************************
    std::string getExePath() const throw();


    //************************************
    // Method:    WorkCommandC
    // FullName:  CommandWorker::WorkCommandC
    // Access:    public 
    // Returns:   void
    // Qualifier: const throw()
    // Function: ִ�� -c ָ��
    //************************************
    void WorkCommandC(int argc, char * argv[]) const throw(std::exception);


    //************************************
    // Method:    WorkCommandCheck
    // FullName:  CommandWorker::WorkCommandCheck
    // Access:    public 
    // Returns:   void
    // Qualifier: const throw()
    // Parameter: int argc
    // Parameter: char * argv[]
    // Function: ִ��<-check>ָ��
    //************************************
    void WorkCommandCheck(int argc, char * argv[]) const throw();


    //************************************
    // Method:    WorkCommandHelp
    // FullName:  CommandWorker::WorkCommandHelp
    // Access:    public 
    // Returns:   void
    // Qualifier: const throw()
    // Parameter: int argc
    // Parameter: char * argv[]
    // Function: ִ��<-help>ָ��
    //************************************
    void WorkCommandHelp(int argc, char * argv[]) const throw();


    ~CommandWorker();
};

