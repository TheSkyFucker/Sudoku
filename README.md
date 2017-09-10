# Sudoku Beta1.5

数独小游戏，目前有 **<-help>、<-c>、<-check>** 指令

---

## **项目相关**

- 维护人员联系方式：359084415@qq.com

## **文档列表**

- **[需求分析 Requirement analysis][1]**
- **[设计文档 Design Spec][2]**      
- **[代码规范 Coding Standard][3]** 
- **[具体设计 Design][4]**
- **[测试报告 Test Report][5]**  
- **[算工作量 Size Measurement][6]**  
- **[总结改进 Postmortem][7]**

## **如何在该项目中快速加入你的指令？**

### **零 · 为你的指令想好名字，以<-help>为例**

### **一 · 为你的指令编写参数校验单元测试**

- 请务必编写！！哪怕没有参数，也写个空测试或检测多余参数也行。
- **命名**：统一前缀（**CheckCommand**） + 指令名（**Help**）
- 例：中间的 **_CheckCommandHelp()**为封装好的测试模板，用于重用代码使得该单元测试写起来更加方便。
![此处输入图片的描述][8]

- 复制一段别的指令内容把红框内的名字改成自己的指令即可。

![此处输入图片的描述][9]

### **二 · 为你的指令编写参数校验**

- 为其在 **Command** 项目中的 **ParamChecker** 类中编写校验函数
- 拷贝其它指令的声明然后修改为当前指令，开始写校验即可。
- **命名**：统一前缀（**CheckParam**） + 指令名（**Help**）
- **声明：**

![此处输入图片的描述][10]

- **定义：**

![此处输入图片的描述][11]

### **三 · 为你的指令编写主函数**

- 为其在 **Command** 项目中的 **CommandWorker** 类中编写主函数
- **命名**：统一前缀（**WorkCommand**） + 指令名（**Help**）
- 拷贝其它指令的声明然后修改为当前指令，开始写主函数即可。
- **声明**

![此处输入图片的描述][12]

- **定义**

![此处输入图片的描述][13]

### **四 · 最后在主函数main中添加对你的指令的识别**

- 主函数在 **Main** 工程里的 **main.cpp**
- 添加一句指令识别：

![此处输入图片的描述][14]

- 最后添加副代码即可
- 副代码逻辑：执行参数校验 -> 执行指令；（基本可以照搬别的指令改下绿框调用的函数后缀指令名）

![此处输入图片的描述][15]

---

## **End.**

  [1]: https://github.com/TheSkyFucker/Sudoku/blob/master/docs/Beta%201.0%20-%20Requirement%20analysis.md
  [2]: https://github.com/TheSkyFucker/Sudoku/blob/master/docs/Beta%201.0%20-%20Design%20Spec.md
  [3]: https://github.com/TheSkyFucker/Sudoku/blob/master/docs/Beta%201.0%20-%20Coding%20Standard.md
  [4]: https://github.com/TheSkyFucker/Sudoku/blob/master/docs/Beta%201.0%20-%20Design.md
  [5]: https://github.com/TheSkyFucker/Sudoku/blob/master/docs/Beta%201.0%20-%20Test%20Report.md
  [6]: https://github.com/TheSkyFucker/Sudoku/blob/master/docs/Beta%201.0%20-%20size%20measurement.md
  [7]: https://github.com/TheSkyFucker/Sudoku/blob/master/docs/Beta%201.0%20-%20Postmortem.md
  [8]: http://od690gqhu.bkt.clouddn.com/201791023537.png
  [9]: http://od690gqhu.bkt.clouddn.com/201791023917.png
  [10]: http://od690gqhu.bkt.clouddn.com/201791024357.png
  [11]: http://od690gqhu.bkt.clouddn.com/20179102458.png
  [12]: http://od690gqhu.bkt.clouddn.com/201791024821.png
  [13]: http://od690gqhu.bkt.clouddn.com/201791025121.png
  [14]: http://od690gqhu.bkt.clouddn.com/201791025427.png
  [15]: http://od690gqhu.bkt.clouddn.com/201791025615.png