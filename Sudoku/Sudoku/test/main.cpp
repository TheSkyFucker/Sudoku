// test.cpp: �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include "../Sudoku/Sudoku.h"
#include "../Sudoku/SudokuGenerator.h"
#include "../Sudoku//SudokuChecker.h"



/************************************************************************/
/* ������                                                                */
/* ְ�ܣ�����ָ��, �������У�麯��                                          */      
/************************************************************************/
int main(int argc, char * argv[])
{
   
    try
    {
            if (argc < 2)
            {
                throw std::exception("��������ָ���ز�����");
            }
            if (strcmp(argv[1], "-c") == 0)
            {
                std::cout << "����ʼ���ɡ�" << std::endl;
                std::cout << "��������ϡ�" << std::endl;
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

