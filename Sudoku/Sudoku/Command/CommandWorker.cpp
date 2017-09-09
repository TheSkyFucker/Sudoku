#include "stdafx.h"
#include "CommandWorker.h"


CommandWorker::CommandWorker()
{
}

void CommandWorker::WorkCommandC(int argc, char * argv[]) const throw(std::exception)
{
    //config && get Params
    int number = atoi(argv[2]);
    SudokuGenerator generator(7);
    const std::string filePath = "sudoku.txt";

    //get seed �Ա�֤ÿ��ִ��ָ��õ��Ľ����ͬ
    std::cout << "    �������������ӡ�" << std::endl;
    Sudoku seed;
    generator.Search(seed);
    std::cout << "    ���������ɳɹ���" << std::endl;

    //generate to file
    std::cout << "    �������������̡�" << std::endl;
    freopen(filePath.c_str(), "w", stdout);
    generator.FastGenerate(seed, number);
    freopen("CON", "w", stdout);
    std::cout << "    ���������ɳɹ���" << std::endl;

    //finish & tips
    std::cout << "    ���ļ����ģ��������ѱ����ڵ�ǰ�ļ����µ�sudoku.txt�ļ���" << std::endl;
    std::cout << "    ���Ҳ����ļ���������ǲ��������У��ļ�������������������Ŀ¼���磺C:\\Users\\asus" << std::endl;
    std::cout << "    �������Ƿ��ظ����������㷨��ԭ��Ͳ����ϱ�֤�˲��ظ���" << std::endl;
    std::cout << "    �������Ƿ��ظ����������ṩ���ظ���У��ָ�� -check��������Ϣ��ִ�У� -check" << std::endl;
}

CommandWorker::~CommandWorker()
{
}
