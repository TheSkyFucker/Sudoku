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

    //get seed 以保证每次执行指令得到的结果不同
    std::cout << "    【正在生成种子】" << std::endl;
    Sudoku seed;
    generator.Search(seed);
    std::cout << "    【种子生成成功】" << std::endl;

    //generate to file
    std::cout << "    【正在生成终盘】" << std::endl;
    freopen(filePath.c_str(), "w", stdout);
    generator.FastGenerate(seed, number);
    freopen("CON", "w", stdout);
    std::cout << "    【终盘生成成功】" << std::endl;

    //finish & tips
    std::cout << "    【文件在哪？】内容已保存在当前文件夹下的sudoku.txt文件。" << std::endl;
    std::cout << "    【终盘是否重复？】生成算法在原理和测试上保证了不重复。" << std::endl;
    std::cout << "    【测试是否重复？】程序提供了重复性校验指令 -check，更多信息请执行： -check" << std::endl;
}

void CommandWorker::WorkCommandCheck(int argc, char * argv[]) const throw(std::exception)
{
    //config
    const std::string filePath = getExePath() + "/sudoku.txt";
    SudokuChecker checker;

    //check
    std::cout << "    【正在校验】" << std::endl;
    freopen(filePath.c_str(), "r", stdin);
    checker.Check();
    freopen("CON", "r", stdin);
    std::cout << "    【校验通过】" << std::endl;
    
    //finish & tops
    //null
}

void CommandWorker::WorkCommandHelp(int argc, char * argv[]) const throw()
{
    //PS: 这块还没做自动化，设计有问题，后续再考虑改进

    std::cout << "    【帮助指令更新日期】2017-09-09" << std::endl;
    std::cout << "    【程序相关】" << std::endl;
    std::cout << "         1. 项目开源：https://github.com/TheSkyFucker/Sudoku, 具体查看 README.md 简介文档" << std::endl;
    std::cout << "         2. 版本文档：https://github.com/TheSkyFucker/Sudoku/tree/master/docs" << std::endl;
    std::cout << "    【已有指令列表】" << std::endl;
    std::cout << "         1. -help : 显示帮助菜单" << std::endl;
    std::cout << "         2. -c [int number] : 生成 number 个终盘" << std::endl;
    std::cout << "         3. -check : 检验终盘是否不重复" << std::endl;
    std::cout << "    【程序出现了Bug？】" << std::endl;
    std::cout << "         1. 开发人员邮箱：359084415@qq.com" << std::endl;
}

CommandWorker::~CommandWorker()
{
}
