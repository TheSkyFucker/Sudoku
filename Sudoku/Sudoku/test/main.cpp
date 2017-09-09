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
/* ְ�ܣ��������У�麯�������� ����                                         */
/************************************************************************/

//ָ��<-c>
void _c(int argc, char * argv[])
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

//ָ��<-check>
void _check(int argc, char * argv[])
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

//ָ��<-help>
void _help(int argc, char * argv[])
{
    //checkParam
    std::cout << "����ʼУ�������" << std::endl;
    std::cout << "��У������С�" << std::endl;
    ParamChecker checker;
    checker.CheckCommandHelp(argc, argv);
    std::cout << "��У�������ϡ�" << std::endl;

    //doCommand
    std::cout << "��=�����˵�=��" << std::endl;
    CommandWorker worker;
    worker.WorkCommandHelp(argc, argv);
}

//δָ֪��
void _unknow(int argc, char * argb[])
{
    throw std::exception("��δָ֪����� -help ?");
}
/************************************************************************/
/* ������                                                                */
/* ְ�ܣ�����ָ��, ������ظ�����                                            */      
/************************************************************************/
int main(int argc, char * argv[])
{
    //config

    //work
    try
    {
        if (argc < 2)
        {
            throw std::exception("��������ָ���ز��������� -help ?");
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

