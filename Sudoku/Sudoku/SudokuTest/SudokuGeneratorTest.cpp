#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Sudoku/SudokuGenerator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SudokuTest
{
    TEST_CLASS(SudokuGeneratorTest)
    {
    public:

        //测试下一个块组合
        TEST_METHOD(NextBlockTable)
        {
            //config
            int testTable[9] = { 3, 1, 2, 6, 5, 4, 9, 8, 7 };
            int finalTable[9] = { 3, 2, 1, 6, 5, 4, 9, 8, 7};
            const int expectTable[9] = { 3, 2, 1, 4, 5, 6, 7, 8, 9 };
            //test
            SudokuGenerator gen;
            Assert::IsTrue(gen.NextBlockTable(testTable));
            Assert::IsFalse(gen.NextBlockTable(finalTable));
            for (int i = 0; i < 9; i++)
            {
                Assert::AreEqual(expectTable[i], testTable[i]);
            }

        }

        //测试下一个数字组合
        TEST_METHOD(NextDigitTable)
        {
            //config
            const int testFixedDigit = 5;
            int testTable[9] = { 1, 9, 8, 7, 5, 6, 4, 3 ,2 };
            const int expectTable[9] = { 2, 1, 3, 4, 5, 6, 7, 8, 9 };
            //test
            SudokuGenerator gen(testFixedDigit);
            Assert::IsTrue(gen.NextDigitTable(testTable));
            for (int i = 0; i < 9; i++)
            {
                Assert::AreEqual(expectTable[i], testTable[i]);
            }
        }

        //测试深搜生成终盘
        TEST_METHOD(Search)
        {
            //config
            SudokuGenerator gen;
            Sudoku sudo;
            Assert::IsTrue(gen.Search(sudo));
            Assert::IsTrue(sudo.IsLegal());
        }

    };
}