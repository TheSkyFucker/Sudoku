#include "stdafx.h"
#include <vector>
#include "CppUnitTest.h"
#include "../Sudoku/Sudoku.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SudokuTest
{		
	TEST_CLASS(SudokuTest)
	{
	public:
		
		TEST_METHOD(GetAndSetMatrix)
		{
            //config test Point
            vector<pair<pair<int, int>, int> > point;
            point.push_back({ {1, 1}, 1 });
            point.push_back({ {3, 6}, 4 });
            //test
            Sudoku sudo;
            for (int i = 0; i < (int)point.size(); i++)
            {
                pair<int, int> pos = point[i].first;
                Assert::AreEqual(sudo.GetMatrix(pos.first, pos.second), 0);
            }
            for (int i = 0; i < (int)point.size(); i++)
            {
                pair<int, int> pos = point[i].first;
                int digit = point[i].second;
                sudo.SetMatrix(pos.first, pos.second, digit);
                Assert::AreEqual(sudo.GetMatrix(pos.first, pos.second), digit);
            }
		}

        //行非法测试
        TEST_METHOD(IsRowCrash)
        {
            Sudoku sudo;
            const int testRow = 3;
            for (int col = 0; col < 9; col++)
            {
                sudo.SetMatrix(testRow, col, col + 1);
                Assert::AreEqual(sudo.IsCrash(testRow, col), false);
            }
            sudo.SetMatrix(testRow, 3, 3);
            Assert::AreEqual(sudo.IsCrash(testRow, 3), true);
        }

        //列非法测试
        TEST_METHOD(IsColCrash)
        {
            Sudoku sudo;
            const int testCol = 3;
            for (int row = 0; row < 9; row++)
            {
                sudo.SetMatrix(row, testCol, row + 1);
                Assert::AreEqual(sudo.IsCrash(row, testCol), false);
            }
            sudo.SetMatrix(4, testCol, 1);
            Assert::AreEqual(sudo.IsCrash(4, testCol), true);

        }  
        
        //宫非法测试
        TEST_METHOD(isBlockCrash)
        {
            Sudoku sudo;
            const int testBlockRow = 1; //被测试宫的 Row
            const int testBlockCol = 1; //被测试宫的 Col
            for (int _row = 0; _row < 3; _row++) //枚举相对行
            {
                for (int _col = 0; _col < 3; _col++) //枚举相对列
                {
                    int row = testBlockRow * 3 + _row;
                    int col = testBlockCol * 3 + _col;
                    int digit = _row * 3 + _col + 1;
                    sudo.SetMatrix(row, col, digit);
                    Assert::AreEqual(sudo.IsCrash(row, col), false);
                }
            }
            int row = testBlockRow * 3 + 1;
            int col = testBlockCol * 3 + 1;
            sudo.SetMatrix(row, col, 1);
            Assert::AreEqual(sudo.IsCrash(row, col), true);
        }

        //终盘合法测试
        TEST_METHOD(isLegal)
        {
            Sudoku sudo;
            //construct a Legal-Sudoku
            const int tab[] = { 1, 4, 7, 2, 5, 8, 3, 6, 9 };
            for (int row = 0; row < 9; row++)
            {
                for (int col = 0; col < 9; col++)
                {
                    int digit = (tab[row] + col - 1) % 9 + 1;
                    sudo.SetMatrix(row, col, digit);
                }
            }
            Assert::AreEqual(sudo.IsLegal(), true);
            //construct a Illegal-Sudoku
            int row = 5;
            int col = 5;
            int digit = (tab[row] + col - 1) % 9 + 1;
            digit = (digit + 6) % 9 + 1;
            sudo.SetMatrix(row, col, digit);
            Assert::AreEqual(sudo.IsLegal(), false);
        }

        //交换行测试
        TEST_METHOD(SwapRow)
        {
            ///config
            const int testRow1 = 3;
            const int testDigit1 = 4;
            const int testRow2 = 5;
            const int testDigit2 = 6;
            ///test
            Sudoku sudo;
            for (int col = 0; col < 9; col++)
            {
                sudo.SetMatrix(testRow1, col, testDigit1);
                sudo.SetMatrix(testRow2, col, testDigit2);
            }
            sudo.SwapRow(testRow1, testRow2);
            for (int col = 0; col < 9; col++)
            {
                Assert::AreEqual(sudo.GetMatrix(testRow1, col), testDigit2);
                Assert::AreEqual(sudo.GetMatrix(testRow2, col), testDigit1);
            }
        }

        //交换列测试
        TEST_METHOD(SwapCol)
        {
            ///config
            const int testCol1 = 3;
            const int testDigit1 = 4;
            const int testCol2 = 5;
            const int testDigit2 = 6;
            ///test
            Sudoku sudo;
            for (int row = 0; row < 9; row++)
            {
                sudo.SetMatrix(row, testCol1, testDigit1);
                sudo.SetMatrix(row, testCol2, testDigit2);
            }
            sudo.SwapCol(testCol1, testCol2);
            for (int row = 0; row < 9; row++)
            {
                Assert::AreEqual(sudo.GetMatrix(row, testCol1), testDigit2);
                Assert::AreEqual(sudo.GetMatrix(row, testCol2), testDigit1);
            }
        }
    
    };

    TEST_CLASS(UnitTest2)
    {
    public:
        TEST_METHOD(test)
        {

        }
    };

}