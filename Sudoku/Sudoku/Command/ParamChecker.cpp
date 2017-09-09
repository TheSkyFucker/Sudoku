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
        throw std::exception("��������������");
    }
    if (IsDigit(argv[2]) == false)
    {
        throw std::exception("��������ֻ��������");
    }
    if (strlen(argv[2]) > 7 || atoi(argv[2]) > 1000000)
    {
        throw std::exception("�����������ܳ���1000, 000");
    }
}

ParamChecker::~ParamChecker()
{
}
