# Makefile for STC15 8LED Animation Project
# 适用于SDCC或Keil C51编译器

# 项目名称
PROJECT = stc15_8led_animation

# 源文件
SOURCES = stc15_8led.c main_demo.c
HEADERS = stc15_8led.h

# 编译器设置
# 如果使用SDCC
CC = sdcc
CFLAGS = --model-small --opt-code-size

# 如果使用Keil C51 (需要手动设置)
# CC = C51
# CFLAGS = CODE LARGE OPTIMIZE(9,SIZE)

# 输出文件
TARGET = $(PROJECT).hex

# 默认目标
all: $(TARGET)

# 编译规则
$(TARGET): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(SOURCES)

# 清理生成的文件
clean:
	rm -f *.asm *.lst *.rel *.rst *.sym *.ihx *.hex *.map *.mem *.omf *.bin

# 使用SDCC生成Intel HEX文件
%.hex: %.ihx
	packihx $< > $@

# 演示程序编译
demo: main_demo.c stc15_8led.c stc15_8led.h
	$(CC) $(CFLAGS) main_demo.c stc15_8led.c -o demo.ihx
	packihx demo.ihx > demo.hex

# 简单版本编译
simple: stc15_8led_animation.c
	$(CC) $(CFLAGS) stc15_8led_animation.c -o simple.ihx
	packihx simple.ihx > simple.hex

# 帮助信息
help:
	@echo "可用的编译目标："
	@echo "  all      - 编译所有源文件"
	@echo "  demo     - 编译演示程序"
	@echo "  simple   - 编译简单版本"
	@echo "  clean    - 清理生成的文件"
	@echo "  help     - 显示此帮助信息"
	@echo ""
	@echo "注意："
	@echo "  - 默认使用SDCC编译器"
	@echo "  - 如需使用Keil C51，请手动修改CC和CFLAGS变量"
	@echo "  - 生成的.hex文件可用于单片机下载"

# 声明伪目标
.PHONY: all clean demo simple help