#include <reg52.h>
#include <intrins.h>

// 延迟函数声明
void delay_ms(unsigned int ms);

// LED动画函数声明
void led_diffuse_outward(void);
void led_converge_inward(void);

// 假设8个LED连接到P1端口 (P1.0 - P1.7)
// LED连接方式：
// P1.0 -> LED1 (最左端)
// P1.1 -> LED2
// P1.2 -> LED3
// P1.3 -> LED4 (中间左侧)
// P1.4 -> LED5 (中间右侧)
// P1.5 -> LED6
// P1.6 -> LED7
// P1.7 -> LED8 (最右端)
// 低电平点亮LED，高电平熄灭LED

/**
 * @brief 简单延迟函数
 * @param ms 延迟毫秒数
 * @note 这是一个粗略的延迟，实际时间取决于晶振频率
 */
void delay_ms(unsigned int ms)
{
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 114; j++);  // 调整此值以获得准确的延迟
}

/**
 * @brief LED向外扩散动画
 * 从中间位置(LED4和LED5)开始，逐步向两端(LED1和LED8)点亮
 * 动画序列：
 * 步骤1: LED4,LED5
 * 步骤2: LED3,LED4,LED5,LED6
 * 步骤3: LED2,LED3,LED4,LED5,LED6,LED7
 * 步骤4: LED1,LED2,LED3,LED4,LED5,LED6,LED7,LED8
 */
void led_diffuse_outward(void)
{
    // 步骤1：点亮中间两个LED (LED4和LED5)
    P1 = 0xE7;  // 1110 0111 -> P1.3和P1.4为低电平
    delay_ms(200);
    
    // 步骤2：向外扩展到LED3和LED6
    P1 = 0xC3;  // 1100 0011 -> P1.2,P1.3,P1.4,P1.5为低电平
    delay_ms(200);
    
    // 步骤3：继续向外扩展到LED2和LED7
    P1 = 0x81;  // 1000 0001 -> P1.1-P1.6为低电平
    delay_ms(200);
    
    // 步骤4：扩展到最外端的LED1和LED8
    P1 = 0x00;  // 0000 0000 -> 所有LED点亮
    delay_ms(200);
    
    // 全部熄灭
    P1 = 0xFF;
    delay_ms(100);
}

/**
 * @brief LED向内汇聚动画
 * 从两端(LED1和LED8)开始，逐步向中间(LED4和LED5)点亮
 * 动画序列：
 * 步骤1: LED1,LED8
 * 步骤2: LED1,LED2,LED7,LED8
 * 步骤3: LED1,LED2,LED3,LED6,LED7,LED8
 * 步骤4: LED1,LED2,LED3,LED4,LED5,LED6,LED7,LED8
 */
void led_converge_inward(void)
{
    // 步骤1：点亮最外端两个LED (LED1和LED8)
    P1 = 0x7E;  // 0111 1110 -> P1.0和P1.7为低电平
    delay_ms(200);
    
    // 步骤2：向内汇聚到LED2和LED7
    P1 = 0x3C;  // 0011 1100 -> P1.0,P1.1,P1.6,P1.7为低电平
    delay_ms(200);
    
    // 步骤3：继续向内汇聚到LED3和LED6
    P1 = 0x18;  // 0001 1000 -> P1.0-P1.2,P1.5-P1.7为低电平
    delay_ms(200);
    
    // 步骤4：汇聚到中间的LED4和LED5
    P1 = 0x00;  // 0000 0000 -> 所有LED点亮
    delay_ms(200);
    
    // 全部熄灭
    P1 = 0xFF;
    delay_ms(100);
}

/**
 * @brief 主函数
 * 演示LED扩散和汇聚动画效果
 */
void main(void)
{
    // 初始化P1端口为输出模式，所有LED熄灭
    P1 = 0xFF;
    
    while (1)
    {
        // 执行向外扩散动画
        led_diffuse_outward();
        delay_ms(500);  // 动画间隔
        
        // 执行向内汇聚动画
        led_converge_inward();
        delay_ms(500);  // 动画间隔
        
        // 可以添加更多动画序列或控制逻辑
    }
}