//===============================================================
//Summary:
//          ParamChecker 类， 
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
    // Function: 校验指令 -c 的参数
    //************************************
    void CheckCommandC(int argc, char * argv[]) throw(std::exception);


    //************************************
    // Method:    CheckCommandCheck
    // FullName:  ParamChecker::CheckCommandCheck
    // Access:    public 
    // Returns:   void
    // Qualifier: throw(std::exception)
    // Parameter: int argc
    // Parameter: char * argv[]
    // Funciton: 校验指令 -check 的参数
    //************************************
    void CheckCommandCheck(int argc, char * argv[]) throw(std::exception);


    //************************************
    // Method:    CheckCommandHelp
    // FullName:  ParamChecker::CheckCommandHelp
    // Access:    public 
    // Returns:   void
    // Qualifier: throw(std::exception)
    // Parameter: int argc
    // Parameter: char * argv[]
    // Funciton: 校验指令 -help 的参数
    //************************************
    void CheckCommandHelp(int argc, char * argv[]) throw(std::exception);

    ~ParamChecker();
};

