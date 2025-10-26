# Keil C51 项目配置指南

本文档详细说明如何在Keil µVision中创建和配置STC15单片机项目。

## 1. 软件准备

### 1.1 下载和安装

1. **Keil C51**
   - 官网：http://www.keil.com/
   - 下载：Keil µVision 5 (C51 edition)
   - 安装：按提示完成安装

2. **STC-ISP**
   - 官网：http://www.stcmicro.com/
   - 下载页面：http://www.stcmicro.com/rjxz.html
   - 下载：STC-ISP V6.x或更高版本

### 1.2 Keil注册（可选）

Keil C51评估版限制代码大小为2KB，对于本项目已足够使用。
如需去除限制，可购买正式授权或申请教育版。

## 2. 创建Keil项目

### 2.1 新建项目

1. 打开Keil µVision
2. 菜单：`Project` → `New µVision Project...`
3. 选择项目保存位置，输入项目名称（如：`STC15_LED`）
4. 点击"保存"

### 2.2 选择目标芯片

在弹出的器件选择窗口中：

**方法一：选择STC15芯片**（推荐）
```
1. 在搜索框输入"STC"
2. 展开"STC Microelectronics"
3. 选择"STC15F2K60S2"或其他STC15系列芯片
4. 点击"OK"
```

**方法二：选择兼容芯片**（如果找不到STC15）
```
1. 在搜索框输入"89C52"
2. 选择"Atmel" → "AT89C52"
3. 点击"OK"
```

注意：使用89C52作为替代时，需要手动包含STC15.h头文件。

### 2.3 添加源文件

1. 在左侧项目树中，展开"Target 1"
2. 右键点击"Source Group 1"
3. 选择"Add Files to Group 'Source Group 1'..."
4. 浏览并选择`main.c`文件
5. 点击"Add"，然后点击"Close"

### 2.4 添加头文件（可选）

如果需要将STC15.h添加到项目：

1. 右键点击"Source Group 1"
2. 选择"Add Files to Group 'Source Group 1'..."
3. 在文件类型下拉框中选择"All files (*.*)"
4. 选择`STC15.h`文件
5. 点击"Add"，然后点击"Close"

## 3. 项目配置

### 3.1 打开配置窗口

右键点击"Target 1"，选择"Options for Target 'Target 1'..."
（或点击工具栏上的魔棒图标）

### 3.2 Target标签页配置

```
┌─────────────────────────────────────┐
│ Device选项                          │
├─────────────────────────────────────┤
│ ✓ Use on-chip ROM (默认勾选)       │
│   Size: 60 (根据芯片调整)           │
├─────────────────────────────────────┤
│ Xtal (MHz)                          │
│   输入: 11.0592                     │
│   （晶振频率，根据实际调整）         │
└─────────────────────────────────────┘
```

配置说明：
- **Xtal (MHz)**：晶振频率，影响定时器和波特率计算
  - 常用：11.0592MHz、12MHz
  - 本项目默认：11.0592MHz

### 3.3 Output标签页配置

```
┌─────────────────────────────────────┐
│ ✓ Create HEX File                   │
│   (必须勾选，用于生成烧录文件)       │
├─────────────────────────────────────┤
│ Name of Executable: STC15_LED       │
│   (输出文件名)                       │
├─────────────────────────────────────┤
│ Select Folder for Objects:          │
│   Objects\                          │
└─────────────────────────────────────┘
```

重要：必须勾选"Create HEX File"才能生成.hex烧录文件！

### 3.4 Listing标签页配置（可选）

```
┌─────────────────────────────────────┐
│ Select Folder for Listings:         │
│   Listings\                         │
└─────────────────────────────────────┘
```

该目录存放编译生成的列表文件。

### 3.5 C51标签页配置

```
┌─────────────────────────────────────┐
│ Optimization Level: (优化级别)       │
│   ○ Level 0: 不优化                 │
│   ○ Level 1-8: 各级优化             │
│   ● Level 9: 最高优化 (推荐)        │
├─────────────────────────────────────┤
│ Define: (预定义宏，可选)             │
│   (留空)                            │
├─────────────────────────────────────┤
│ Include Paths: (头文件路径)         │
│   .\                                │
│   (添加当前目录)                     │
└─────────────────────────────────────┘
```

优化级别说明：
- Level 0：不优化，代码大，调试方便
- Level 9：最高优化，代码小，适合发布

对于本项目，任何优化级别都可以。

### 3.6 Debug标签页配置（可选）

```
┌─────────────────────────────────────┐
│ Use Simulator:                      │
│   ● Use Simulator                   │
│   ○ Use Hardware Debugger           │
└─────────────────────────────────────┘
```

- 使用仿真器调试选择"Use Simulator"
- 使用硬件调试器选择"Use Hardware Debugger"

### 3.7 Utilities标签页配置（可选）

用于配置第三方烧录工具，本项目使用STC-ISP，无需配置。

## 4. 编译项目

### 4.1 编译操作

方法1：菜单 → `Project` → `Build Target`
方法2：快捷键 `F7`
方法3：点击工具栏"Build"按钮（齿轮图标）

### 4.2 编译输出

编译成功后，在输出窗口会显示：

```
Build target 'Target 1'
compiling main.c...
linking...
Program Size: data=9.0 xdata=0 code=123
creating hex file from "Objects\STC15_LED"...
"Objects\STC15_LED" - 0 Error(s), 0 Warning(s).
Build Time Elapsed:  00:00:01
```

重要信息：
- **Program Size**：程序大小统计
  - data: 内部RAM使用量
  - xdata: 外部RAM使用量
  - code: 程序代码大小
- **0 Error(s), 0 Warning(s)**：无错误和警告

### 4.3 输出文件位置

编译成功后，在项目目录的`Objects`文件夹中会生成：

```
Objects/
├── STC15_LED           (可执行文件)
├── STC15_LED.hex       (HEX烧录文件) ← 重要！
├── STC15_LED.lnp       (链接参数文件)
├── STC15_LED.map       (内存映射文件)
├── main.lst            (汇编列表文件)
├── main.obj            (目标文件)
└── ...
```

**STC15_LED.hex**是最终用于烧录到单片机的文件。

## 5. 常见编译错误及解决方案

### 5.1 找不到头文件

**错误信息**：
```
main.c(7): error C129: missing ';' before 'STC15'
main.c(7): error C202: 'STC15': undefined identifier
```

**原因**：找不到STC15.h头文件

**解决方案**：
1. 确保STC15.h在项目目录中
2. 在C51配置中添加Include Path: `.\`
3. 或将`#include <STC15.h>`改为`#include "STC15.h"`
4. 或使用`#include <reg52.h>`替代

### 5.2 未定义的寄存器

**错误信息**：
```
main.c(45): error C202: 'P1M0': undefined identifier
```

**原因**：使用了STC15特有的寄存器，但头文件不支持

**解决方案**：
1. 使用项目提供的STC15.h头文件
2. 或在代码中手动定义：
```c
sfr P1M0 = 0x92;
sfr P1M1 = 0x91;
```

### 5.3 代码大小超限

**错误信息**：
```
*** ERROR L104: MULTIPLE PUBLIC DEFINITIONS
    SYMBOL:  ?C_STARTUP
```

或

```
Program Size: data=9.0 xdata=0 code=2500
*** WARNING L15: MULTIPLE CALL TO SEGMENT
```

**原因**：评估版Keil限制代码大小为2KB

**解决方案**：
1. 提高优化级别（Level 9）
2. 精简代码
3. 购买正式授权

本项目代码量很小，不会超过2KB限制。

### 5.4 语法错误

**错误信息**：
```
main.c(50): error C141: syntax error near 'for'
```

**原因**：C语言语法错误

**解决方案**：
1. 检查代码语法
2. 确保变量在使用前已声明
3. 检查括号、分号是否匹配

## 6. 仿真调试（可选）

### 6.1 启动仿真

1. 菜单：`Debug` → `Start/Stop Debug Session`（快捷键：Ctrl+F5）
2. 进入调试模式

### 6.2 调试操作

工具栏按钮：
- **Run (F5)**：运行程序
- **Stop**：停止运行
- **Step (F11)**：单步执行（进入函数）
- **Step Over (F10)**：单步执行（不进入函数）
- **Step Out (Ctrl+F11)**：跳出当前函数

### 6.3 观察端口状态

1. 菜单：`Peripherals` → `I/O Ports` → `Port 1`
2. 打开P1口观察窗口
3. 运行程序，观察P1口各位的变化

### 6.4 观察变量

1. 在代码中右键点击变量
2. 选择"Add 'variable_name' to..."
3. 可添加到Watch窗口或Memory窗口

## 7. 项目文件说明

Keil项目会生成以下文件：

```
项目目录/
├── main.c                 (源代码文件)
├── STC15.h                (头文件)
├── STC15_LED.uvproj       (项目文件)
├── STC15_LED.uvopt        (项目选项文件)
├── STC15_LED.uvprojx      (新版项目文件)
├── STC15_LED.uvoptx       (新版选项文件)
├── Objects/               (目标文件目录)
│   ├── *.hex             (HEX文件 - 重要!)
│   ├── *.obj             (目标文件)
│   └── *.map             (映射文件)
├── Listings/              (列表文件目录)
│   └── *.lst             (汇编列表)
└── *.bak                  (备份文件)
```

**.gitignore说明**：
已创建.gitignore文件，以下文件不会提交到Git：
- 编译生成的中间文件和目标文件
- 用户配置文件（*.uvopt, *.uvgui等）
- 备份文件

需要提交到Git的文件：
- 源代码（*.c, *.h）
- 项目文件（*.uvproj, *.uvprojx）
- 文档文件（*.md）

## 8. 快捷键总结

| 功能 | 快捷键 |
|------|--------|
| 编译 | F7 |
| 重新编译所有 | F7 |
| 开始/停止调试 | Ctrl+F5 |
| 运行 | F5 |
| 单步进入 | F11 |
| 单步跳过 | F10 |
| 单步跳出 | Ctrl+F11 |
| 查找 | Ctrl+F |
| 替换 | Ctrl+H |
| 注释/取消注释 | Ctrl+K |
| 保存 | Ctrl+S |
| 保存所有 | Ctrl+Shift+S |

## 9. 技巧和建议

### 9.1 代码编辑技巧

1. **自动补全**：输入代码时按Ctrl+Space
2. **代码折叠**：点击行号左侧的+/-符号
3. **书签**：Ctrl+F2设置书签，F2跳转
4. **快速导航**：Ctrl+G跳转到指定行

### 9.2 项目管理技巧

1. **多文件项目**：
   - 将功能拆分到多个.c文件
   - 使用.h头文件声明函数
   - 在Keil中添加所有.c文件到项目

2. **版本控制**：
   - 使用Git管理代码
   - 提交前检查.gitignore

3. **备份**：
   - 定期备份项目
   - 使用版本控制系统

### 9.3 优化建议

1. **代码优化**：
   - 使用const修饰常量
   - 使用code关键字将数据存储在ROM
   - 合理使用寄存器变量

2. **调试优化**：
   - 调试时使用低优化级别
   - 发布时使用高优化级别

## 10. 进阶配置

### 10.1 自定义内存模型

在C51标签页中可选择内存模型：

- **Small**：变量在内部RAM（默认）
- **Compact**：使用页面寻址
- **Large**：使用外部RAM

本项目使用Small模型即可。

### 10.2 使用汇编混合编程

可在C代码中嵌入汇编：

```c
#pragma asm
    ; 汇编代码
    MOV A, #0xFF
    MOV P1, A
#pragma endasm
```

或使用intrinsic函数：

```c
#include <intrins.h>
_nop_();  // 空操作
```

### 10.3 Startup代码配置

修改startup.a51文件可自定义启动代码：
- 堆栈大小
- 初始化代码
- 中断向量表

一般情况下使用默认配置即可。

## 附录：完整配置检查清单

配置Keil项目时，请检查以下项：

- [ ] 创建新项目
- [ ] 选择目标芯片（STC15F2K60S2或89C52）
- [ ] 添加main.c到项目
- [ ] Target标签页：设置晶振频率（11.0592MHz）
- [ ] Output标签页：勾选"Create HEX File"
- [ ] C51标签页：设置优化级别
- [ ] C51标签页：添加Include Path（.\）
- [ ] 编译项目（F7）
- [ ] 检查编译输出无错误
- [ ] 确认生成.hex文件

---

**配置完成后，就可以编译并下载程序到单片机了！**

下一步请参考README.md中的"下载到单片机"章节。
