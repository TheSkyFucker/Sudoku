// test.cpp: �������̨Ӧ�ó������ڵ㡣
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
/* ������                                                                */
/* ְ�ܣ�����ָ��, �������У�麯��                                          */      
/************************************************************************/
int main(int argc, char * argv[])
{
   //config

    //work
    try
    {
        if (argc < 2)
        {
            throw std::exception("��������ָ���ز�����");
        }
        if (strcmp(argv[1], "-c") == 0)
        {
            //checkParam
            std::cout << "����ʼУ�������" << std::endl;
            std::cout << "��У������С�" << std::endl;
            ParamChecker checker;
            checker.CheckCommandC(argc, argv);
            std::cout << "��У�������ϡ�" << std::endl;
            
            //doCommand
            std::cout << "����ʼ���ɡ�" << std::endl;
            CommandWorker worker;
            worker.WorkCommandC(argc, argv);
            std::cout << "��������ϡ�" << std::endl;
        }
        else if (strcmp(argv[1], "-check") == 0)
        {
            //checkParam
            std::cout << "����ʼУ�������" << std::endl;
            std::cout << "��У������С�" << std::endl;
            ParamChecker checker;
            checker.CheckCommandCheck(argc, argv);
            std::cout << "��У�������ϡ�" << std::endl;

            //doCommand
            std::cout << "����ʼ���顿" << std::endl;
            CommandWorker worker;
            worker.WorkCommandCheck(argc, argv);
            std::cout << "������ͨ����" << std::endl;
        }
        else
        {
            throw std::exception("��δָ֪�");
        }
    }
    catch (const std::exception& e)
    {
        puts(e.what());
    }
    
    system("pause");
    return 0;
}

