// test.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include "../Sudoku/Sudoku.h"
#include "../Sudoku/SudokuGenerator.h"
#include "../Sudoku//SudokuChecker.h"
#include "../Command/ParamChecker.h"
#include "../Command/CommandWorker.h"


/************************************************************************/
/* 副代码                                                                */
/* 职能：调用相关校验函数、运行 函数                                         */
/************************************************************************/

//指令<-c>
void _c(int argc, char * argv[])
{
    //checkParam
    std::cout << "【开始校验参数】" << std::endl;
    std::cout << "【校验参数中】" << std::endl;
    ParamChecker checker;
    checker.CheckCommandC(argc, argv);
    std::cout << "【校验参数完毕】" << std::endl;

    //doCommand
    std::cout << "【开始生成】" << std::endl;
    CommandWorker worker;
    worker.WorkCommandC(argc, argv);
    std::cout << "【生成完毕】" << std::endl;
}

//指令<-check>
void _check(int argc, char * argv[])
{
    //checkParam
    std::cout << "【开始校验参数】" << std::endl;
    std::cout << "【校验参数中】" << std::endl;
    ParamChecker checker;
    checker.CheckCommandCheck(argc, argv);
    std::cout << "【校验参数完毕】" << std::endl;

    //doCommand
    std::cout << "【开始检验】" << std::endl;
    CommandWorker worker;
    worker.WorkCommandCheck(argc, argv);
    std::cout << "【检验通过】" << std::endl;
}

//指令<-help>
void _help(int argc, char * argv[])
{
    //checkParam
    std::cout << "【开始校验参数】" << std::endl;
    std::cout << "【校验参数中】" << std::endl;
    ParamChecker checker;
    checker.CheckCommandHelp(argc, argv);
    std::cout << "【校验参数完毕】" << std::endl;

    //doCommand
    std::cout << "【=帮助菜单=】" << std::endl;
    CommandWorker worker;
    worker.WorkCommandHelp(argc, argv);
}

//未知指令
void _unknow(int argc, char * argb[])
{
    throw std::exception("【未知指令】试试 -help ?");
}
/************************************************************************/
/* 主代码                                                                */
/* 职能：分析指令, 调用相关副代码                                            */      
/************************************************************************/
int main(int argc, char * argv[])
{
    //config

    //work
    try
    {
        if (argc < 2)
        {
            throw std::exception("【请输入指令及相关参数】试试 -help ?");
        }
        else if (strcmp(argv[1], "-c") == 0)
        {
            _c(argc, argv);
        }
        else if (strcmp(argv[1], "-check") == 0)
        {
            _check(argc, argv);
        }
        else if (strcmp(argv[1], "-help") == 0)
        {
            _help(argc, argv);
        }
        else
        {
            _unknow(argc, argv);
        }
    }
    catch (const std::exception& e)
    {
        puts(e.what());
    }
    
    system("pause");
    return 0;
}

