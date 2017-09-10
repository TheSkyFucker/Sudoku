#include "stdafx.h"
#include "CommandWorker.h"


CommandWorker::CommandWorker()
{
}

std::string CommandWorker::getExePath() const throw()
{
    char path[500];
    strcpy(path, _pgmptr); *(strrchr(path, '\\')) = '\0';
    return std::string(path);
}

void CommandWorker::WorkCommandC(int argc, char * argv[]) const throw(std::exception)
{
    //config && get Params
    int number = atoi(argv[2]);
    SudokuGenerator generator(7);
    const std::string filePath = getExePath() + "/sudoku.txt";

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
    std::cout << "    �������Ƿ��ظ����������㷨��ԭ��Ͳ����ϱ�֤�˲��ظ���" << std::endl;
    std::cout << "    �������Ƿ��ظ����������ṩ���ظ���У��ָ�� -check��������Ϣ��ִ�У� -check" << std::endl;
}

void CommandWorker::WorkCommandCheck(int argc, char * argv[]) const throw(std::exception)
{
    //config
    const std::string filePath = getExePath() + "/sudoku.txt";
    SudokuChecker checker;

    //check
    std::cout << "    ������У�顿" << std::endl;
    freopen(filePath.c_str(), "r", stdin);
    checker.Check();
    freopen("CON", "r", stdin);
    std::cout << "    ��У��ͨ����" << std::endl;
    
    //finish & tops
    //null
}

void CommandWorker::WorkCommandHelp(int argc, char * argv[]) const throw()
{
    //PS: ��黹û���Զ�������������⣬�����ٿ��ǸĽ�

    std::cout << "    ������ָ��������ڡ�2017-09-09" << std::endl;
    std::cout << "    ��������ء�" << std::endl;
    std::cout << "         1. ��Ŀ��Դ��https://github.com/TheSkyFucker/Sudoku, ����鿴 README.md ����ĵ�" << std::endl;
    std::cout << "         2. �汾�ĵ���https://github.com/TheSkyFucker/Sudoku/tree/master/docs" << std::endl;
    std::cout << "    ������ָ���б�" << std::endl;
    std::cout << "         1. -help : ��ʾ�����˵�" << std::endl;
    std::cout << "         2. -c [int number] : ���� number ������" << std::endl;
    std::cout << "         3. -check : ���������Ƿ��ظ�" << std::endl;
    std::cout << "    �����������Bug����" << std::endl;
    std::cout << "         1. ������Ա���䣺359084415@qq.com" << std::endl;
}

CommandWorker::~CommandWorker()
{
}
