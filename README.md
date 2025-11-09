# STC15 8个LED扩散汇聚动画效果

本项目为STC15系列单片机（8051内核）提供了8个LED的向外扩散和向内汇聚动画效果。

## 硬件要求

- STC15系列单片机（或兼容的8051内核单片机）
- 8个LED灯
- 8个限流电阻（通常为220Ω-1kΩ）
- 连接导线

## 硬件连接

### LED连接方式
```
单片机引脚    LED    限流电阻    VCC
P1.0 --------|>|-----[220Ω]-----+5V
P1.1 --------|>|-----[220Ω]-----+5V
P1.2 --------|>|-----[220Ω]-----+5V
P1.3 --------|>|-----[220Ω]-----+5V
P1.4 --------|>|-----[220Ω]-----+5V
P1.5 --------|>|-----[220Ω]-----+5V
P1.6 --------|>|-----[220Ω]-----+5V
P1.7 --------|>|-----[220Ω]-----+5V
```

**说明：**
- LED阴极连接单片机引脚，阳极通过限流电阻连接VCC
- 低电平(0)点亮LED，高电平(1)熄灭LED
- 如果使用共阴极LED，可以修改代码中的逻辑

## 文件结构

```
├── stc15_8led.h           # 头文件，包含函数声明和宏定义
├── stc15_8led.c           # 实现文件，包含所有动画函数
├── stc15_8led_animation.c # 简单版本，包含基本动画函数
├── main_demo.c            # 演示程序，展示所有功能
└── README.md              # 本文档
```

## 主要功能

### 1. 向外扩散动画
从中间位置（LED 4和5）开始，逐步向两端（LED 1和8）点亮：
```
步骤1: ●●○○○○○○  (LED4,LED5)
步骤2: ○●●○○●●○○  (LED3,LED4,LED5,LED6)
步骤3: ○○●●●●○○  (LED2-LED7)
步骤4: ●●●●●●●●  (LED1-LED8)
```

### 2. 向内汇聚动画
从两端（LED 1和8）开始，逐步向中间（LED 4和5）点亮：
```
步骤1: ●○○○○○○●  (LED1,LED8)
步骤2: ●●○○○○●●  (LED1,LED2,LED7,LED8)
步骤3: ●●●○○●●●  (LED1-LED3,LED6-LED8)
步骤4: ●●●●●●●●  (LED1-LED8)
```

## API函数说明

### 基础函数

#### `void led_init(void)`
初始化LED端口，将所有LED设置为熄灭状态。

#### `void delay_ms(unsigned int ms)`
简单的毫秒级延迟函数。

#### `void led_set_single(unsigned char led_num, unsigned char state)`
设置单个LED的状态。
- `led_num`: LED编号(1-8)
- `state`: 0=点亮, 1=熄灭

#### `void led_set_pattern(unsigned char pattern)`
设置所有LED的状态。
- `pattern`: 8位模式，bit0对应LED1，bit7对应LED8

### 动画函数

#### `void led_diffuse_outward(void)`
向外扩散动画，使用默认延迟时间(200ms)。

#### `void led_converge_inward(void)`
向内汇聚动画，使用默认延迟时间(200ms)。

#### `void led_diffuse_outward_config(unsigned int delay_time)`
可配置速度的向外扩散动画。
- `delay_time`: 每一步的延迟时间(毫秒)

#### `void led_converge_inward_config(unsigned int delay_time)`
可配置速度的向内汇聚动画。
- `delay_time`: 每一步的延迟时间(毫秒)

## 编译和下载

### 使用Keil C51编译

1. 创建新项目或打开现有项目
2. 将源文件添加到项目中
3. 选择正确的单片机型号（如STC15F2K60S2）
4. 设置晶振频率（默认按12MHz计算）
5. 编译项目
6. 使用STC-ISP工具下载到单片机

### 编译设置建议

```c
// 在stc15_8led.h中可以根据实际晶振频率调整延迟
// 对于12MHz晶振：
#define DELAY_LOOP_COUNT 114  // 约1ms

// 对于其他晶振频率，按比例调整：
// 24MHz: 228次循环 ≈ 1ms
// 11.0592MHz: 105次循环 ≈ 1ms
```

## 使用示例

### 简单示例
```c
#include "stc15_8led.h"

void main(void)
{
    led_init();
    
    while(1) {
        led_diffuse_outward();  // 向外扩散
        delay_ms(500);
        
        led_converge_inward();  // 向内汇聚
        delay_ms(500);
    }
}
```

### 自定义速度示例
```c
#include "stc15_8led.h"

void main(void)
{
    led_init();
    
    while(1) {
        // 快速扩散(100ms)
        led_diffuse_outward_config(100);
        delay_ms(300);
        
        // 慢速汇聚(400ms)
        led_converge_inward_config(400);
        delay_ms(300);
    }
}
```

## 自定义修改

### 修改LED端口
如果LED连接到其他端口，修改`stc15_8led.h`中的宏定义：
```c
#define LED_PORT P0  // 改为P0、P2或P3
```

### 修改LED逻辑
如果使用共阴极LED（高电平点亮），修改相关函数：
```c
// 在led_set_single函数中
if (state == LED_ON) {
    LED_PORT |= mask;   // 设置对应位，点亮LED
} else {
    LED_PORT &= ~mask;  // 清除对应位，熄灭LED
}
```

### 调整动画步骤
可以修改动画函数中的LED模式来创建不同的效果：
```c
// 自定义扩散模式
void custom_diffuse(void)
{
    led_set_pattern(0xFF);  // 全部熄灭
    delay_ms(100);
    
    led_set_pattern(0x18);  // 只点亮中间两个
    delay_ms(200);
    
    led_set_pattern(0x00);  // 全部点亮
    delay_ms(200);
}
```

## 注意事项

1. **限流电阻**: 必须使用合适的限流电阻，避免损坏LED或单片机端口
2. **端口驱动能力**: 确保单片机端口的驱动能力足够驱动所有LED
3. **电源稳定**: 确保电源电压稳定，避免LED闪烁
4. **延迟精度**: 延迟函数的精度取决于晶振频率，可能需要调整
5. **编译器兼容性**: 代码针对Keil C51优化，其他编译器可能需要调整

## 故障排除

### LED不亮
- 检查硬件连接
- 确认限流电阻值合适
- 检查电源电压
- 确认LED极性正确

### 动画效果不正确
- 检查LED连接顺序
- 确认端口定义正确
- 调整延迟时间
- 检查晶振频率设置

### 编译错误
- 确认包含正确的头文件
- 检查单片机型号设置
- 确认编译器路径正确

## 版本信息

- 版本: 1.0
- 日期: 2024年
- 兼容性: STC15系列单片机，Keil C51
- 作者: 自动生成

## 许可证

本项目仅供学习和参考使用。