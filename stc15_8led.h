#ifndef __STC15_8LED_H__
#define __STC15_8LED_H__

#include <reg52.h>

/**
 * @file stc15_8led.h
 * @brief STC15单片机8个LED扩散汇聚动画效果头文件
 * @author Generated for STC15 8051 microcontroller
 * @version 1.0
 * @date 2024
 */

// LED端口配置宏定义
#define LED_PORT P1  // 可以根据实际硬件连接修改为P0、P2或P3

// LED状态宏定义 (假设低电平点亮)
#define LED_ON  0
#define LED_OFF 1

// 延迟时间宏定义 (单位：毫秒)
#define DEFAULT_DELAY 200
#define ANIMATION_INTERVAL 500

/**
 * @brief 延迟函数
 * @param ms 延迟毫秒数
 */
void delay_ms(unsigned int ms);

/**
 * @brief LED向外扩散动画（可配置延迟时间）
 * @param delay_time 每一步的延迟时间(毫秒)
 * @note 从中间位置开始，逐步向两端点亮
 */
void led_diffuse_outward_config(unsigned int delay_time);

/**
 * @brief LED向内汇聚动画（可配置延迟时间）
 * @param delay_time 每一步的延迟时间(毫秒)
 * @note 从两端开始，逐步向中间点亮
 */
void led_converge_inward_config(unsigned int delay_time);

/**
 * @brief LED向外扩散动画（使用默认延迟时间）
 */
void led_diffuse_outward(void);

/**
 * @brief LED向内汇聚动画（使用默认延迟时间）
 */
void led_converge_inward(void);

/**
 * @brief 初始化LED端口
 * @note 将所有LED设置为熄灭状态
 */
void led_init(void);

/**
 * @brief 设置指定LED的状态
 * @param led_num LED编号 (1-8)
 * @param state LED状态 (0=点亮, 1=熄灭)
 */
void led_set_single(unsigned char led_num, unsigned char state);

/**
 * @brief 设置所有LED的状态
 * @param pattern 8位模式，每一位对应一个LED的状态
 * @note bit0对应LED1，bit7对应LED8
 */
void led_set_pattern(unsigned char pattern);

#endif /* __STC15_8LED_H__ */