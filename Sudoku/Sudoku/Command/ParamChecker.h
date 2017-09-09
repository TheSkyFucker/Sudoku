//===============================================================
//Summary:
//          ParamChecker �࣬ 
//FileName:
//          ParamChecker.h
//Remarks:
//          ...
//Date:
//          2017/9/9
//Author:
//          kino(359084415@qq.com)
//===============================================================
#include <iostream>
#pragma warning (disable:4290)

#pragma once
class ParamChecker
{
public:
    
    //************************************
    // Method:    ParamChecker
    // FullName:  ParamChecker::ParamChecker
    // Access:    public 
    // Returns:   
    // Qualifier:
    //************************************
    ParamChecker();


    //************************************
    // Method:    IsDigit
    // FullName:  ParamChecker::IsDigit
    // Access:    public 
    // Returns:   bool
    // Qualifier:
    //************************************
    bool IsDigit(std::string str) const throw();

    
    //************************************
    // Method:    CheckeCommandC
    // FullName:  ParamChecker::CheckeCommandC
    // Access:    public 
    // Returns:   void
    // Qualifier: const throw(std::exception)
    // Parameter: int argc
    // Parameter: char * argv
    // Function: У��ָ�� -c �Ĳ���
    //************************************
    void CheckeCommandC(int argc, char * argv[]) throw(std::exception);


    ~ParamChecker();
};

