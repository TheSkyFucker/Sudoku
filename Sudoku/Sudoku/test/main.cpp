// test.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include "../Sudoku/Sudoku.h"
#include "../Sudoku/SudokuGenerator.h"
#include "../Sudoku//SudokuChecker.h"



/************************************************************************/
/* 主代码                                                                */
/* 职能：分析指令, 调用相关校验函数                                          */      
/************************************************************************/
int main(int argc, char * argv[])
{
   
    try
    {
            if (argc < 2)
            {
                throw std::exception("【请输入指令及相关参数】");
            }
            if (strcmp(argv[1], "-c") == 0)
            {
                std::cout << "【开始生成】" << std::endl;
                std::cout << "【生成完毕】" << std::endl;
            }
            else
            {
                throw std::exception("【未知指令】");
            }
    }
    catch (const std::exception& e)
    {
        puts(e.what());
    }
    
    system("pause");
    return 0;
}

