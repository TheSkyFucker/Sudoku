#include "stdafx.h"
#include "ParamChecker.h"


ParamChecker::ParamChecker()
{
}


bool ParamChecker::IsDigit(std::string str) const throw()
{
    for (int pos = 0; pos < (int)str.size(); pos++)
    {
        if (str[pos] < '0' || str[pos] > '9')
        {
            return false;
        }
    }
    return true;
}

void ParamChecker::CheckCommandC(int argc, char * argv[]) throw(std::exception)
{
    //config
    const std::string command = "-c";

    //check
    if (argc < 2 || strcmp(argv[1], command.c_str()))
    {
        throw std::exception("指令与调用的参数检验函数不符");
    }
    if (argc < 3)
    {
        throw std::exception("请输入生成数量");
    }
    if (argc > 3)
    {
        throw std::exception("请勿输入多余参数");
    }
    if (IsDigit(argv[2]) == false)
    {
        throw std::exception("生成数量只能是数字");
    }
    if (strlen(argv[2]) > 7 || atoi(argv[2]) > 1000000)
    {
        throw std::exception("生成数量不能超过1000, 000");
    }
}

void ParamChecker::CheckCommandCheck(int argc, char * argv[]) throw(std::exception)
{
    //config
    const std::string command = "-check";

    //check
    if (argc < 2 || strcmp(argv[1], command.c_str()))
    {
        throw std::exception("指令与调用的参数函数不符");
    }
    if (argc != 2)
    {
        throw std::exception("请勿输入多余参数");
    }
}

ParamChecker::~ParamChecker()
{
}
