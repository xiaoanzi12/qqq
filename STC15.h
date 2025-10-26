/*******************************************************************************
 * 文件名：STC15.h
 * 功能：STC15系列单片机寄存器定义头文件
 * 芯片：STC15F2K60S2及其他STC15系列单片机
 * 说明：本文件定义了STC15系列单片机的特殊功能寄存器(SFR)
 ******************************************************************************/

#ifndef __STC15_H__
#define __STC15_H__

// 标准8051寄存器定义
sfr P0   = 0x80;  // P0口数据寄存器
sfr SP   = 0x81;  // 堆栈指针
sfr DPL  = 0x82;  // 数据指针低字节
sfr DPH  = 0x83;  // 数据指针高字节
sfr PCON = 0x87;  // 电源控制寄存器
sfr TCON = 0x88;  // 定时器/计数器控制寄存器
sfr TMOD = 0x89;  // 定时器/计数器模式寄存器
sfr TL0  = 0x8A;  // 定时器0低字节
sfr TL1  = 0x8B;  // 定时器1低字节
sfr TH0  = 0x8C;  // 定时器0高字节
sfr TH1  = 0x8D;  // 定时器1高字节
sfr P1   = 0x90;  // P1口数据寄存器
sfr SCON = 0x98;  // 串行口控制寄存器
sfr SBUF = 0x99;  // 串行口数据缓冲寄存器
sfr P2   = 0xA0;  // P2口数据寄存器
sfr IE   = 0xA8;  // 中断允许寄存器
sfr P3   = 0xB0;  // P3口数据寄存器
sfr IP   = 0xB8;  // 中断优先级寄存器
sfr PSW  = 0xD0;  // 程序状态字
sfr ACC  = 0xE0;  // 累加器
sfr B    = 0xF0;  // B寄存器

// P0口位定义
sbit P0_0 = P0^0;
sbit P0_1 = P0^1;
sbit P0_2 = P0^2;
sbit P0_3 = P0^3;
sbit P0_4 = P0^4;
sbit P0_5 = P0^5;
sbit P0_6 = P0^6;
sbit P0_7 = P0^7;

// P1口位定义
sbit P1_0 = P1^0;
sbit P1_1 = P1^1;
sbit P1_2 = P1^2;
sbit P1_3 = P1^3;
sbit P1_4 = P1^4;
sbit P1_5 = P1^5;
sbit P1_6 = P1^6;
sbit P1_7 = P1^7;

// P2口位定义
sbit P2_0 = P2^0;
sbit P2_1 = P2^1;
sbit P2_2 = P2^2;
sbit P2_3 = P2^3;
sbit P2_4 = P2^4;
sbit P2_5 = P2^5;
sbit P2_6 = P2^6;
sbit P2_7 = P2^7;

// P3口位定义
sbit P3_0 = P3^0;
sbit P3_1 = P3^1;
sbit P3_2 = P3^2;
sbit P3_3 = P3^3;
sbit P3_4 = P3^4;
sbit P3_5 = P3^5;
sbit P3_6 = P3^6;
sbit P3_7 = P3^7;

// STC15特殊功能寄存器
sfr P4   = 0xC0;  // P4口数据寄存器
sfr P5   = 0xC8;  // P5口数据寄存器
sfr P6   = 0xE8;  // P6口数据寄存器
sfr P7   = 0xF8;  // P7口数据寄存器

// 端口模式配置寄存器（STC15特有）
sfr P0M0 = 0x94;  // P0口输出模式配置0
sfr P0M1 = 0x93;  // P0口输出模式配置1
sfr P1M0 = 0x92;  // P1口输出模式配置0
sfr P1M1 = 0x91;  // P1口输出模式配置1
sfr P2M0 = 0x96;  // P2口输出模式配置0
sfr P2M1 = 0x95;  // P2口输出模式配置1
sfr P3M0 = 0xB2;  // P3口输出模式配置0
sfr P3M1 = 0xB1;  // P3口输出模式配置1
sfr P4M0 = 0xB4;  // P4口输出模式配置0
sfr P4M1 = 0xB3;  // P4口输出模式配置1
sfr P5M0 = 0xCA;  // P5口输出模式配置0
sfr P5M1 = 0xC9;  // P5口输出模式配置1
sfr P6M0 = 0xCC;  // P6口输出模式配置0
sfr P6M1 = 0xCB;  // P6口输出模式配置1
sfr P7M0 = 0xE2;  // P7口输出模式配置0
sfr P7M1 = 0xE1;  // P7口输出模式配置1

/*
 * 端口模式配置说明：
 * PxM1  PxM0  模式
 *  0     0    准双向口（弱上拉）- 默认
 *  0     1    推挽输出（强推挽）
 *  1     0    高阻输入（仅输入）
 *  1     1    开漏输出
 */

// 辅助寄存器
sfr AUXR  = 0x8E;  // 辅助寄存器
sfr AUXR1 = 0xA2;  // 辅助寄存器1

// 中断优先级寄存器
sfr IPH   = 0xB7;  // 中断优先级高位
sfr IP2   = 0xB5;  // 中断优先级2
sfr IP2H  = 0xB6;  // 中断优先级2高位

// 电源控制
sfr PCON2 = 0x97;  // 电源控制寄存器2

// 时钟分频寄存器
sfr CLK_DIV = 0x97;  // 时钟分频控制寄存器

// 看门狗控制寄存器
sfr WDT_CONTR = 0xC1;  // 看门狗控制寄存器

// IAP/ISP控制寄存器
sfr IAP_DATA    = 0xC2;  // IAP数据寄存器
sfr IAP_ADDRH   = 0xC3;  // IAP地址高字节
sfr IAP_ADDRL   = 0xC4;  // IAP地址低字节
sfr IAP_CMD     = 0xC5;  // IAP命令寄存器
sfr IAP_TRIG    = 0xC6;  // IAP触发寄存器
sfr IAP_CONTR   = 0xC7;  // IAP控制寄存器

// 定时器2相关寄存器
sfr T2H   = 0xD6;  // 定时器2高字节
sfr T2L   = 0xD7;  // 定时器2低字节
sfr T3H   = 0xD2;  // 定时器3高字节
sfr T3L   = 0xD3;  // 定时器3低字节
sfr T4H   = 0xD4;  // 定时器4高字节
sfr T4L   = 0xD5;  // 定时器4低字节

// TCON位定义
sbit TF1 = TCON^7;  // 定时器1溢出标志
sbit TR1 = TCON^6;  // 定时器1运行控制
sbit TF0 = TCON^5;  // 定时器0溢出标志
sbit TR0 = TCON^4;  // 定时器0运行控制
sbit IE1 = TCON^3;  // 外部中断1请求标志
sbit IT1 = TCON^2;  // 外部中断1触发方式
sbit IE0 = TCON^1;  // 外部中断0请求标志
sbit IT0 = TCON^0;  // 外部中断0触发方式

// IE位定义
sbit EA  = IE^7;  // 总中断允许
sbit ET2 = IE^5;  // 定时器2中断允许
sbit ES  = IE^4;  // 串口中断允许
sbit ET1 = IE^3;  // 定时器1中断允许
sbit EX1 = IE^2;  // 外部中断1允许
sbit ET0 = IE^1;  // 定时器0中断允许
sbit EX0 = IE^0;  // 外部中断0允许

// IP位定义
sbit PT2 = IP^5;  // 定时器2中断优先级
sbit PS  = IP^4;  // 串口中断优先级
sbit PT1 = IP^3;  // 定时器1中断优先级
sbit PX1 = IP^2;  // 外部中断1优先级
sbit PT0 = IP^1;  // 定时器0中断优先级
sbit PX0 = IP^0;  // 外部中断0优先级

// PSW位定义
sbit CY  = PSW^7;  // 进位标志
sbit AC  = PSW^6;  // 辅助进位标志
sbit F0  = PSW^5;  // 用户标志0
sbit RS1 = PSW^4;  // 寄存器组选择位1
sbit RS0 = PSW^3;  // 寄存器组选择位0
sbit OV  = PSW^2;  // 溢出标志
sbit P   = PSW^0;  // 奇偶标志

// SCON位定义
sbit SM0 = SCON^7;  // 串口模式位0
sbit SM1 = SCON^6;  // 串口模式位1
sbit SM2 = SCON^5;  // 多机通信控制
sbit REN = SCON^4;  // 接收使能
sbit TB8 = SCON^3;  // 发送数据位8
sbit RB8 = SCON^2;  // 接收数据位8
sbit TI  = SCON^1;  // 发送中断标志
sbit RI  = SCON^0;  // 接收中断标志

#endif // __STC15_H__
