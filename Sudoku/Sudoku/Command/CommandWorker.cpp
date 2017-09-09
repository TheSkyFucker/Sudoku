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
    std::cout << "    【找不到文件？】如果是采用命令行，文件将生成在命令行所在目录，如：C:\\Users\\asus" << std::endl;
    std::cout << "    【终盘是否重复？】生成算法在原理和测试上保证了不重复。" << std::endl;
    std::cout << "    【测试是否重复？】程序提供了重复性校验指令 -check，更多信息请执行： -check" << std::endl;
}

CommandWorker::~CommandWorker()
{
}
