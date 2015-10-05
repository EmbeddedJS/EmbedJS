################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/LwIP/src/core/ipv4/autoip.c \
../Middlewares/Third_Party/LwIP/src/core/ipv4/icmp.c \
../Middlewares/Third_Party/LwIP/src/core/ipv4/igmp.c \
../Middlewares/Third_Party/LwIP/src/core/ipv4/inet.c \
../Middlewares/Third_Party/LwIP/src/core/ipv4/inet_chksum.c \
../Middlewares/Third_Party/LwIP/src/core/ipv4/ip.c \
../Middlewares/Third_Party/LwIP/src/core/ipv4/ip_addr.c \
../Middlewares/Third_Party/LwIP/src/core/ipv4/ip_frag.c 

OBJS += \
./Middlewares/Third_Party/LwIP/src/core/ipv4/autoip.o \
./Middlewares/Third_Party/LwIP/src/core/ipv4/icmp.o \
./Middlewares/Third_Party/LwIP/src/core/ipv4/igmp.o \
./Middlewares/Third_Party/LwIP/src/core/ipv4/inet.o \
./Middlewares/Third_Party/LwIP/src/core/ipv4/inet_chksum.o \
./Middlewares/Third_Party/LwIP/src/core/ipv4/ip.o \
./Middlewares/Third_Party/LwIP/src/core/ipv4/ip_addr.o \
./Middlewares/Third_Party/LwIP/src/core/ipv4/ip_frag.o 

C_DEPS += \
./Middlewares/Third_Party/LwIP/src/core/ipv4/autoip.d \
./Middlewares/Third_Party/LwIP/src/core/ipv4/icmp.d \
./Middlewares/Third_Party/LwIP/src/core/ipv4/igmp.d \
./Middlewares/Third_Party/LwIP/src/core/ipv4/inet.d \
./Middlewares/Third_Party/LwIP/src/core/ipv4/inet_chksum.d \
./Middlewares/Third_Party/LwIP/src/core/ipv4/ip.d \
./Middlewares/Third_Party/LwIP/src/core/ipv4/ip_addr.d \
./Middlewares/Third_Party/LwIP/src/core/ipv4/ip_frag.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/LwIP/src/core/ipv4/%.o: ../Middlewares/Third_Party/LwIP/src/core/ipv4/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DUSE_HAL_DRIVER -DSTM32F207xx -I"/Users/InhoChoi/Documents/workspace/EmbedJS/Drivers/BSP/Components" -I"/Users/InhoChoi/Documents/workspace/EmbedJS/Drivers/BSP/Components/Common" -I"/Users/InhoChoi/Documents/workspace/EmbedJS/Drivers/BSP/Components/stmpe811" -I"/Users/InhoChoi/Documents/workspace/EmbedJS/Drivers/BSP/STM322xG_EVAL" -I"/Users/InhoChoi/Documents/workspace/EmbedJS/Drivers/CMSIS/Device/ST/STM32F2xx/Include" -I"/Users/InhoChoi/Documents/workspace/EmbedJS/Drivers/CMSIS/Include" -I"/Users/InhoChoi/Documents/workspace/EmbedJS/Drivers/STM32F2xx_HAL_Driver/Inc" -I"/Users/InhoChoi/Documents/workspace/EmbedJS/Include" -I"/Users/InhoChoi/Documents/workspace/EmbedJS/Middlewares/Third_Party/FreeRTOS/CMSIS_RTOS" -I"/Users/InhoChoi/Documents/workspace/EmbedJS/Middlewares/Third_Party/FreeRTOS/include" -I"/Users/InhoChoi/Documents/workspace/EmbedJS/Middlewares/Third_Party/FreeRTOS/Source/portable/gcc/ARM_CM3" -I"/Users/InhoChoi/Documents/workspace/EmbedJS/Middlewares/Third_Party/LwIP/src/include" -I"/Users/InhoChoi/Documents/workspace/EmbedJS/Middlewares/Third_Party/LwIP/src/include/ipv4" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


