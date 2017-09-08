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
            //test 1
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
                    Assert::IsTrue(checker.Check());
                    fclose(stdin);
                }
                catch (const std::exception&)
                {
                    Assert::IsTrue(false);
                }
            }
            //test 2
            freopen(testFile, "w", stdout);
            putchar('2');
            fclose(stdout);
            bool checkFlag = false;
            try
            {
                SudokuChecker checker;
                freopen(testFile, "r", stdin);
                Assert::IsFalse(checker.Check());
                fclose(stdin);
            }
            catch (const std::exception&)
            {
                checkFlag = true;
            }
            Assert::IsTrue(checkFlag);
        }


    };
}