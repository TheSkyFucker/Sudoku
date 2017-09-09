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

    //************************************
    // Method:    _CheckCommandC
    // FullName:  CommandTest::_CheckCommandC
    // Access:    public 
    // Returns:   void
    // Qualifier:
    // Parameter: std::vector<std::string> str
    // Parameter: bool expectedResult
    // Function: 封装对指令 -c 的校验模板
    //************************************
    void _CheckCommandC(std::vector<std::string> str, bool expectedResult)
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
            checker.CheckCommandC(argc, argv);
        }
        catch (const std::exception&e)
        {
            e;
            result = false;
        }
        Assert::AreEqual(expectedResult, result);

        //delete
        delCharArr2(argv, argc);
    }


    //************************************
    // Method:    _CheckCommandCheck
    // FullName:  CommandTest::_CheckCommandCheck
    // Access:    public 
    // Returns:   void
    // Qualifier:
    // Parameter: std::vector<std::string> str
    // Parameter: bool expectedResult
    // Function: 封装对指令 -check 的校验模板
    //************************************
    void _CheckCommandCheck(std::vector<std::string> str, bool expectedResult)
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
            checker.CheckCommandCheck(argc, argv);
        }
        catch (const std::exception&e)
        {
            e;
            result = false;
        }
        Assert::AreEqual(expectedResult, result);

        //delete
        delCharArr2(argv, argc);
    }

	TEST_CLASS(ParamCheckerTest)
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

        TEST_METHOD(CheckCommandC)
        {
            //test 1
            _CheckCommandC({ "d:\\", "-cc", "123" }, false);    //指令错误
            _CheckCommandC({ "d:\\", "-cc", "123", "adfad" }, false);
            //test 2
            _CheckCommandC({ "d:\\", "-c", "afadfda" }, false);
            _CheckCommandC({ "d:\\", "-c", "41341341341313413" }, false);
            _CheckCommandC({ "d:\\", "-c", "f4134adf" }, false);
            _CheckCommandC({ "d:\\", "-c", "a" }, false);
            _CheckCommandC({ "d:\\", "-c", " " }, false);
            _CheckCommandC({ "d:\\", "-c", "1000000", "233"}, false);
            //legal
            _CheckCommandC({ "d:\\", "-c", "1" }, true);
            _CheckCommandC({ "d:\\", "-c", "123" }, true);
            _CheckCommandC({ "d:\\", "-c", "1000000" }, true);
        }

        TEST_METHOD(CheckCommandCheck)
        {
            //test 1
            _CheckCommandCheck({ "d:\\", "-checkadf" }, false);
            _CheckCommandCheck({ "d:\\", "-check", "1" }, false);
            //legal
            _CheckCommandCheck({ "d:\\", "-check" }, true);
        }

	};
}