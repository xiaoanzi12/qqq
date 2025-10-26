#include "stc15_8led.h"
#include <intrins.h>

/**
 * @brief 简单延迟函数
 * @param ms 延迟毫秒数
 * @note 这是一个粗略的延迟，实际时间取决于晶振频率
 *       对于12MHz晶振，114次循环约等于1ms
 */
void delay_ms(unsigned int ms)
{
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 114; j++);  // 根据晶振频率调整此值
}

/**
 * @brief 初始化LED端口
 * @note 将所有LED设置为熄灭状态
 */
void led_init(void)
{
    LED_PORT = 0xFF;  // 所有LED熄灭（高电平）
}

/**
 * @brief 设置指定LED的状态
 * @param led_num LED编号 (1-8)
 * @param state LED状态 (0=点亮, 1=熄灭)
 */
void led_set_single(unsigned char led_num, unsigned char state)
{
    unsigned char mask;
    
    if (led_num < 1 || led_num > 8) return;  // 参数检查
    
    mask = 1 << (led_num - 1);  // 计算对应的位掩码
    
    if (state == LED_ON) {
        LED_PORT &= ~mask;  // 清除对应位，点亮LED
    } else {
        LED_PORT |= mask;   // 设置对应位，熄灭LED
    }
}

/**
 * @brief 设置所有LED的状态
 * @param pattern 8位模式，每一位对应一个LED的状态
 * @note bit0对应LED1，bit7对应LED8
 *       0表示点亮，1表示熄灭
 */
void led_set_pattern(unsigned char pattern)
{
    LED_PORT = pattern;
}

/**
 * @brief LED向外扩散动画（可配置延迟时间）
 * @param delay_time 每一步的延迟时间(毫秒)
 * @note 从中间位置(LED4和LED5)开始，逐步向两端(LED1和LED8)点亮
 * 动画序列：
 * 步骤1: LED4,LED5           -> 1110 0111 -> 0xE7
 * 步骤2: LED3,LED4,LED5,LED6 -> 1100 0011 -> 0xC3
 * 步骤3: LED2-LED7            -> 1000 0001 -> 0x81
 * 步骤4: LED1-LED8            -> 0000 0000 -> 0x00
 */
void led_diffuse_outward_config(unsigned int delay_time)
{
    // 步骤1：点亮中间两个LED (LED4和LED5)
    led_set_pattern(0xE7);
    delay_ms(delay_time);
    
    // 步骤2：向外扩展到LED3和LED6
    led_set_pattern(0xC3);
    delay_ms(delay_time);
    
    // 步骤3：继续向外扩展到LED2和LED7
    led_set_pattern(0x81);
    delay_ms(delay_time);
    
    // 步骤4：扩展到最外端的LED1和LED8
    led_set_pattern(0x00);
    delay_ms(delay_time);
    
    // 全部熄灭
    led_set_pattern(0xFF);
    delay_ms(delay_time / 2);  // 短暂暂停
}

/**
 * @brief LED向内汇聚动画（可配置延迟时间）
 * @param delay_time 每一步的延迟时间(毫秒)
 * @note 从两端(LED1和LED8)开始，逐步向中间(LED4和LED5)点亮
 * 动画序列：
 * 步骤1: LED1,LED8           -> 0111 1110 -> 0x7E
 * 步骤2: LED1,LED2,LED7,LED8 -> 0011 1100 -> 0x3C
 * 步骤3: LED1-LED3,LED6-LED8  -> 0001 1000 -> 0x18
 * 步骤4: LED1-LED8            -> 0000 0000 -> 0x00
 */
void led_converge_inward_config(unsigned int delay_time)
{
    // 步骤1：点亮最外端两个LED (LED1和LED8)
    led_set_pattern(0x7E);
    delay_ms(delay_time);
    
    // 步骤2：向内汇聚到LED2和LED7
    led_set_pattern(0x3C);
    delay_ms(delay_time);
    
    // 步骤3：继续向内汇聚到LED3和LED6
    led_set_pattern(0x18);
    delay_ms(delay_time);
    
    // 步骤4：汇聚到中间的LED4和LED5
    led_set_pattern(0x00);
    delay_ms(delay_time);
    
    // 全部熄灭
    led_set_pattern(0xFF);
    delay_ms(delay_time / 2);  // 短暂暂停
}

/**
 * @brief LED向外扩散动画（使用默认延迟时间）
 */
void led_diffuse_outward(void)
{
    led_diffuse_outward_config(DEFAULT_DELAY);
}

/**
 * @brief LED向内汇聚动画（使用默认延迟时间）
 */
void led_converge_inward(void)
{
    led_converge_inward_config(DEFAULT_DELAY);
}