# Beta 1.0 - Test Report

标签（空格分隔）： Sudoku

---

## **Sudoku 类测试**

- 测试工程：**SudokuTest**
- 测试脚本：**SudokuTest.h**

| 单元测试列表     | 备注 | 测试代码行数 | 
| ---------------- | ---- | ------------ | 
| **CanSetMatrix** | 检测能否设置元素测试 | 16
| **GetAndSetMatrix** | 设置、访问元素测试 | 18
| **IsRowCrash** | 行非法测试 | 9
| **IsColCrash** | 列非法测试 | 9
| **IsBlockCrash** | 宫非法测试 | 18
| **isLegal** | 终盘合法测试 | 19


---

## **SudokuGenerator 类测试**

- 测试工程：**SudokuTest**
- 测试脚本：**SudokuGeneratorTest.h**

| 单元测试列表     | 备注 | 测试代码行数 | 
| ---------------- | ---- | ------------ | 
| **NextBlockTable** | 测试下一个块组合 | 19
| **NextDigitTable** | 测试下一个数字组合 | 8
| **Search** | 测试深搜生成终盘 | 4


---

## **SudokuChecker 类测试**

- 测试工程：**SudokuTest**
- 测试脚本：**SudokuCheckerTest.h**

| 单元测试列表     | 备注 | 测试代码行数 | 
| ---------------- | ---- | ------------ | 
| **Check** | 测试终盘检测脚本 | 66


---

## **ParamChecker 类测试**

- 测试工程：**CommandTest**
- 测试脚本：**ParamChecker.h**

| 单元测试列表     | 备注 | 测试代码行数 | 
| ---------------- | ---- | ------------ | 
| **IsDigit** | 工具函数测试 | 8
| **CheckCommandC** | 指令-c测试 | 40
| **CheckCommandCheck** | 指令-check测试 | 33
| **CheckCommandHelp**  | 指令-help测试  | 33