#include "stc15_8led.h"

/**
 * @file main_demo.c
 * @brief STC15单片机8个LED动画效果演示程序
 * @author Generated for STC15 8051 microcontroller
 * @version 1.0
 * @date 2024
 * 
 * 本程序演示了8个LED的扩散和汇聚动画效果
 * 硬件连接：
 * - 8个LED分别连接到P1端口的P1.0-P1.7
 * - LED阴极连接单片机引脚，阳极通过限流电阻连接VCC
 * - 低电平点亮LED，高电平熄灭LED
 * 
 * 使用说明：
 * 1. 将程序编译后下载到STC15单片机
 * 2. 观察LED动画效果
 * 3. 可根据需要修改延迟时间参数
 */

/**
 * @brief 演示基本扩散和汇聚动画
 */
void demo_basic_animation(void)
{
    // 基本扩散动画
    led_diffuse_outward();
    delay_ms(ANIMATION_INTERVAL);
    
    // 基本汇聚动画
    led_converge_inward();
    delay_ms(ANIMATION_INTERVAL);
}

/**
 * @brief 演示可配置速度的动画
 */
void demo_variable_speed_animation(void)
{
    unsigned char speeds[] = {100, 150, 200, 300};  // 不同的延迟时间
    unsigned char i;
    
    for (i = 0; i < 4; i++) {
        // 使用不同速度的扩散动画
        led_diffuse_outward_config(speeds[i]);
        delay_ms(ANIMATION_INTERVAL / 2);
        
        // 使用不同速度的汇聚动画
        led_converge_inward_config(speeds[i]);
        delay_ms(ANIMATION_INTERVAL / 2);
    }
}

/**
 * @brief 演示单个LED控制
 */
void demo_single_led_control(void)
{
    unsigned char i;
    
    // 逐个点亮LED
    for (i = 1; i <= 8; i++) {
        led_set_single(i, LED_ON);
        delay_ms(100);
    }
    
    delay_ms(500);
    
    // 逐个熄灭LED
    for (i = 1; i <= 8; i++) {
        led_set_single(i, LED_OFF);
        delay_ms(100);
    }
    
    delay_ms(500);
}

/**
 * @brief 演示自定义图案
 */
void demo_custom_patterns(void)
{
    // 图案1：交替闪烁
    led_set_pattern(0xAA);  // 1010 1010
    delay_ms(300);
    led_set_pattern(0x55);  // 0101 0101
    delay_ms(300);
    led_set_pattern(0xAA);
    delay_ms(300);
    led_set_pattern(0x55);
    delay_ms(300);
    led_set_pattern(0xFF);  // 全部熄灭
    delay_ms(300);
    
    // 图案2：流水灯效果
    unsigned char patterns[] = {0xFE, 0xFC, 0xF8, 0xF0, 0xE0, 0xC0, 0x80, 0x00};
    unsigned char i;
    
    for (i = 0; i < 8; i++) {
        led_set_pattern(patterns[i]);
        delay_ms(150);
    }
    
    led_set_pattern(0xFF);
    delay_ms(300);
}

/**
 * @brief 演示组合动画效果
 */
void demo_combined_animation(void)
{
    // 快速扩散 + 慢速汇聚
    led_diffuse_outward_config(100);   // 快速扩散
    delay_ms(200);
    led_converge_inward_config(300);   // 慢速汇聚
    delay_ms(300);
    
    // 慢速扩散 + 快速汇聚
    led_diffuse_outward_config(300);   // 慢速扩散
    delay_ms(200);
    led_converge_inward_config(100);   // 快速汇聚
    delay_ms(300);
}

/**
 * @brief 主函数
 */
void main(void)
{
    // 初始化LED端口
    led_init();
    
    // 启动提示：所有LED闪烁3次
    unsigned char i;
    for (i = 0; i < 3; i++) {
        led_set_pattern(0x00);  // 全部点亮
        delay_ms(200);
        led_set_pattern(0xFF);  // 全部熄灭
        delay_ms(200);
    }
    
    while (1)
    {
        // 演示基本动画效果
        demo_basic_animation();
        
        // 演示可变速度动画
        demo_variable_speed_animation();
        
        // 演示单个LED控制
        demo_single_led_control();
        
        // 演示自定义图案
        demo_custom_patterns();
        
        // 演示组合动画
        demo_combined_animation();
        
        // 长时间暂停，然后重新开始循环
        led_set_pattern(0xFF);  // 全部熄灭
        delay_ms(1000);         // 等待1秒
    }
}