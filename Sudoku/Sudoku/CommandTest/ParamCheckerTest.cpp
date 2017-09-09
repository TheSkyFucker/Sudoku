#include "stdafx.h"
#include "CppUnitTest.h"
#include <vector>
#include "../Command/ParamChecker.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CommandTest
{		

    char * * newCharArr2(int row, int col)
    {
        char * * result;
        result = new char *[row];
        for (int _row = 0; _row < row; _row++)
        {
            result[_row] = new char[col];
        }
        return result;
    }

    void delCharArr2(char * * arr2, int row)
    {
        for (int _row = 0; _row < row; _row++)
        {
            delete arr2[_row];
        }
        delete arr2;
    }

    void _CheckeCommandC(std::vector<std::string> str, bool expectedResult)
    {
        //config
        int argc = (int)str.size();
        char * * argv = newCharArr2(argc, 100);      
        for (int _argc = 0; _argc < argc; _argc++)
        {
            strcpy_s(argv[_argc], str[_argc].size() + 1, str[_argc].c_str());
        }
        ParamChecker checker;

        //test
        bool result = true;
        try
        {
            checker.CheckeCommandC(argc, argv);
        }
        catch (const std::exception&e)
        {
            result = false;
        }
        Assert::AreEqual(expectedResult, result);

        //delete
        delCharArr2(argv, argc);
    }


	TEST_CLASS(UnitTest1)
	{
	public:
		
        
		TEST_METHOD(IsDigit)
		{
            //
            std::string testString;
            ParamChecker checker;
            //test 1
            testString = "5135adfafafaf135faf1341";
            Assert::IsFalse(checker.IsDigit(testString));
            //test 2
            testString = "111341413";
            Assert::IsTrue(checker.IsDigit(testString));
            //test 3
            testString = "1";
            Assert::IsTrue(checker.IsDigit(testString));
        }

        TEST_METHOD(CheckeCommandC)
        {
            //test
            _CheckeCommandC({ "d:\\", "-c", "afadfda" }, false);
            _CheckeCommandC({ "d:\\", "-c", "41341341341313413" }, false);
            _CheckeCommandC({ "d:\\", "-c", "f4134adf" }, false);
            _CheckeCommandC({ "d:\\", "-c", "a" }, false);
            _CheckeCommandC({ "d:\\", "-c", " " }, false);
            _CheckeCommandC({ "d:\\", "-c", "1" }, true);
            _CheckeCommandC({ "d:\\", "-c", "123" }, true);
            _CheckeCommandC({ "d:\\", "-c", "1000000" }, true);
        }

	};
}