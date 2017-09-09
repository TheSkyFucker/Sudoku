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

void ParamChecker::CheckeCommandC(int argc, char * argv[]) throw(std::exception)
{
    if (argc < 3)
    {
        throw std::exception("请输入生成数量");
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

ParamChecker::~ParamChecker()
{
}
