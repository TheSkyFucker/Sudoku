# Beta 1.0 - Design

标签（空格分隔）： Sudoku

---

![此处输入图片的描述][1]

---

## **Sudoku 类**

| 成员列表  | 备注 |
| --------- | ---- |
| **`int m_matrix[9][9]`**              | 数独矩阵
| **`int m_crashElem`**                 | 冲突格子数
| **`int m_emptyElem`**                 | 为空格子数
| **`int m_usedRow[9][10]`**            | **`m_usedRow[i][j]`** ：第 i 行，数字 j 被使用的次数
| **`int m_usedCol[9][10]`**            | **`m_usedCol[i][j]`** ：第 i 列，数字 j 被使用的次数
| **`int m_usedBlock[3][3][10]`**       | **`m_usedBlock[i][j][k]`**：**`(i, j)`** 宫中数字 **`k`** 被使用的次数


| 函数列表   | 备注 |
| ---------- | ---- |
| **`int GetCrashElem()`**                          | 获取 **`m_crashElem`**
| **`int GetEmptyElem()`**                          | 获取 **`m_emptyElem`**
| **`int GetMatrix(int row, int col)`**             | 获取 **`(row, col)`** 的元素
| **`bool CanSetMartrix(int row, int col, int digit)`** |  检测(row, col)放置digit是否会引起冲突
| **`void SetMatrix(int row, int col, int digit)`** | 获取 **`(row, col)`** 的元素为 **`digit`**
| **`bool IsCrash(int row, int col)`**              | 检测 **`(row, col`)** 的元素是否冲突
| **`bool IsLegal()`**                              | 检测是否为合法终盘


---

## **SudokuGenerator 类**
| 成员列表 | 功能 |
| -------- | ---- |
| **`int m_fixedDigit`** | 固定在左上角的数字


| 函数列表 | 功能 |
| -------- | ---- |
| **`void OutputSudoku(const int table[9][9])`** | 输出数组
| **`void OutputSudoku(const Sudoku sudo)`**     | 输出数组
| **`bool NextBlockTable(int * table)`**         | 不破坏 Sudoku && (0, 0) 的下一个 行/列重编号
| **`bool NextDigitTable(int * table)`**         | 不破坏 Sudoku && (0, 0) 的下一个 数字重编号
| **`void FastGenerate(Sudoku seed, int num)`**  | 快速生成
| **`bool Search(Sudoku &sudo, int row = 0, int col = 0)`** | 随机搜索
| **`void void BestGenerate(int num)`**                     | 高质量生成


## **SudokuChecker 类**

| 函数列表 | 功能 |
| -------- | ---- |
| **`bool Check()`**  | 从当前输入流检测读到的终盘是否合法，直至EOF


  [1]: http://od690gqhu.bkt.clouddn.com/201791011320.png