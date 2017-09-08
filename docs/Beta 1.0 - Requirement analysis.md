﻿# Beta 1.0 - Requirement analysis 

标签（空格分隔）： Sudoku

---

## **文档日志**

| 日期       | 备注       |
| ---------- | ---------- |
| 2017-09-06 | 新增非功能需求 · 60s内响应
| 2017-09-06 | 新增功能需求 · 左上角数为7
| 2017-09-06 | 文档初稿创建


---

## **功能需求**

### Update **`2017-09-06`**

- 左上角的第一个数为：7 **`(4 + 2)% 9 + 1`**

### History

- 生成数独终盘

| 指令          | 功能                     | 示例              |
| ------------- | ------------------------ | ----------------- |
| **`-c`**      |   生成的数独棋盘的数量   | **`sudoku.exe -c 20`**


---

## **非功能需求**

### Update **`2017-09-06`**

- **响应时间需求**：当输入范围在 **`[1, 1000]`**，要求程 60 s 内给出结果

### History

| 指令          | 需求                        | 示例
| ------------- | --------------------------- | ----------------- |
| **`-c`**      | 能就检测非法格式并给出提示  | **`sudoku.exe -c abc`**


- 确保可执行文件的名字命名为 sudoku.exe。
- 确保生成的棋盘文件 sudoku.txt 与可执行文件在同一目录下，生成文件采用相对路径。



