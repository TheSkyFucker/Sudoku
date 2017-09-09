#include "stdafx.h"
#include "CppUnitTest.h"
#include <iostream>
#include "../Sudoku/Sudoku.h"
#include "../Sudoku/SudokuChecker.h"
#include "../Sudoku/SudokuGenerator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SudokuTest
{
    TEST_CLASS(SudokuCheckTest)
    {

    public:

        TEST_METHOD(Check)
        {
            //config
            const char * testFile = "test.txt";

            //合法测试
            for (int count = 1; count <= 2; count++)
            {
                Sudoku seed;
                
                SudokuGenerator gen;
                gen.Search(seed);
                freopen(testFile, "w", stdout);
                gen.OutputSudoku(seed);
                fclose(stdout);
                try
                {
                    SudokuChecker checker;
                    freopen(testFile, "r", stdin);
                    checker.Check();
                    fclose(stdin);
                }
                catch (const std::exception&)
                {
                    Assert::IsTrue(false);
                }
            }

            //不完整测试
            freopen(testFile, "w", stdout);
            putchar('2');
            fclose(stdout);
            bool checkFlag = false;
            try
            {
                SudokuChecker checker;
                freopen(testFile, "r", stdin);
                checker.Check();
                fclose(stdin);
            }
            catch (const std::exception&)
            {
                checkFlag = true;
            }
            Assert::IsTrue(checkFlag);

            //重复测试
            freopen(testFile, "w", stdout);
            Sudoku seed;
            SudokuGenerator gen;
            gen.Search(seed);
            for (int count = 1; count <= 2; count++)
            {
                gen.OutputSudoku(seed);
            }
            fclose(stdout);
            bool result = true;
            try
            {
                SudokuChecker checker;
                freopen(testFile, "r", stdin);
                checker.Check();
                fclose(stdin);
            }
            catch (const std::exception&)
            {
                result = false;
            }
            Assert::IsFalse(result);
        }


    };
}