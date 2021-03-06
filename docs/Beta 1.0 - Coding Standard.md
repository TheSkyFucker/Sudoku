﻿# Beta 1.0 - Coding Standard

标签（空格分隔）： Sudoku

---

## **文档日志**

| 日期       | 备注       |
| ---------- | ---------- |
| 2017-09-07 | 代码规范初稿 |


---

## **1. 代码风格规范**

| 备注 | 限制 |
| ---- | ---- |
| **缩进** | **4** 个空格
| **行宽** | **150** 个字符
| **括号** | 复杂表达式用括号凸出优先级
| **断行和空白的{}行** | 左括号放行末，右括号独占一行
| **分行** | 一行一条语句，变量定义分行


---

## **2. 代码命名规范**

| 备注 | 限制 |
| ---- | ---- |
| **下划线** | 分隔变量名中的作用域标注和变量的语义，成员变量 **`m_`**
| **大小写** | 所有的类型/类/函数名都用 **Pascal** 形式，所有的变量都用 **Camel** 形式。


---

## **3. 代码注释规范**

| 备注 | 限制 |
| ---- | ---- |
| 函数头 | 注释 功能、参数、返回值


---

## **4. 代码设计规范**

### **4.1 函数**
- **原则**：只做一件事，并且做好。
- **倾向**：最好有单一的出口

### **4.2 goto**
- 有助于程序逻辑的清晰体现的话可以使用，慎用。

### **4.3 错误处理**
- 在 **Debug** 版本中所有参数都要验证正确性
- 在 **正式版本** 对从外部（外模块、用户）传递的参数，要验证正确性。

### **4.4 虚函数**
- 使用虚函数来实现多态。
- 仅在必要时，才使用虚函数。
- 某类实现多态 -> 基类的析构函数应为虚函数（避免隐患）

### **4.5 构造函数**
- 简单初始化，不要复杂的操作
- 不应该返回错误

### **4.6 析构函数**
- 把所有清理工作放在析构函数中。
- 有些资源提前被释放应置为 NULL 或 0
- 不应该出错

### **4.7 运算符**
- 必要时再重载操作符，否则尽量使用成员函数。

### **4.8 异常处理**
- 不要以异常作为逻辑控制来处理程序的主要流程。

### **4.9 类型继承**
- 必要时才继承
- 用 **`const`** 标注只读的参数
- 用 **`const`** 标注不改变数据的函数。

---

## **End.**







