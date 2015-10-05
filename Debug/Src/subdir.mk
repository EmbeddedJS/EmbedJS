################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/app_ethernet.c \
../Src/ethernetif.c \
../Src/main.c \
../Src/stm32f2xx_it.c \
../Src/system_stm32f2xx.c \
../Src/tcpecho.c \
../Src/udpecho.c 

OBJS += \
./Src/app_ethernet.o \
./Src/ethernetif.o \
./Src/main.o \
./Src/stm32f2xx_it.o \
./Src/system_stm32f2xx.o \
./Src/tcpecho.o \
./Src/udpecho.o 

C_DEPS += \
./Src/app_ethernet.d \
./Src/ethernetif.d \
./Src/main.d \
./Src/stm32f2xx_it.d \
./Src/system_stm32f2xx.d \
./Src/tcpecho.d \
./Src/udpecho.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DUSE_HAL_DRIVER -DSTM32F207xx -I"/Users/InhoChoi/Documents/workspace/EmbedJS/Drivers/BSP/Components" -I"/Users/InhoChoi/Documents/workspace/EmbedJS/Drivers/BSP/Components/Common" -I"/Users/InhoChoi/Documents/workspace/EmbedJS/Drivers/BSP/Components/stmpe811" -I"/Users/InhoChoi/Documents/workspace/EmbedJS/Drivers/BSP/STM322xG_EVAL" -I"/Users/InhoChoi/Documents/workspace/EmbedJS/Drivers/CMSIS/Device/ST/STM32F2xx/Include" -I"/Users/InhoChoi/Documents/workspace/EmbedJS/Drivers/CMSIS/Include" -I"/Users/InhoChoi/Documents/workspace/EmbedJS/Drivers/STM32F2xx_HAL_Driver/Inc" -I"/Users/InhoChoi/Documents/workspace/EmbedJS/Include" -I"/Users/InhoChoi/Documents/workspace/EmbedJS/Middlewares/Third_Party/FreeRTOS/CMSIS_RTOS" -I"/Users/InhoChoi/Documents/workspace/EmbedJS/Middlewares/Third_Party/FreeRTOS/include" -I"/Users/InhoChoi/Documents/workspace/EmbedJS/Middlewares/Third_Party/FreeRTOS/Source/portable/gcc/ARM_CM3" -I"/Users/InhoChoi/Documents/workspace/EmbedJS/Middlewares/Third_Party/LwIP/src/include" -I"/Users/InhoChoi/Documents/workspace/EmbedJS/Middlewares/Third_Party/LwIP/src/include/ipv4" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


