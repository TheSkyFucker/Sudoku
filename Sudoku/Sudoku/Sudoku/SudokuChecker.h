//===============================================================
//Summary:
//          SudokuChecker �࣬ 
//FileName:
//          SudokuChecker.h
//Remarks:
//          ...
//Date:
//          2017/9/8
//Author:
//          kino(359084415@qq.com)
//===============================================================
#pragma once
#pragma warning (disable:4290)
#include <set>
#include <iostream>
class SudokuChecker
{
public:

    //************************************
    // Method:    SudokuChecker
    // FullName:  SudokuChecker::SudokuChecker
    // Access:    public 
    // Returns:   
    // Qualifier:
    //************************************
    SudokuChecker();
    

    //************************************
    // Method:    Check
    // FullName:  SudokuChecker::Check
    // Access:    public 
    // Returns:   bool
    // Qualifier: const throw(std::exception)
    // Function: �ӵ�ǰ�������������������Ƿ�Ϸ���ֱ��EOF
    //************************************
    void Check() const throw(std::exception);
    
    ~SudokuChecker();
};

