################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/FreeRTOS/CMSIS_RTOS/cmsis_os.c 

OBJS += \
./Middlewares/Third_Party/FreeRTOS/CMSIS_RTOS/cmsis_os.o 

C_DEPS += \
./Middlewares/Third_Party/FreeRTOS/CMSIS_RTOS/cmsis_os.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/FreeRTOS/CMSIS_RTOS/%.o: ../Middlewares/Third_Party/FreeRTOS/CMSIS_RTOS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DUSE_HAL_DRIVER -DSTM32F207xx -I"/Users/InhoChoi/Documents/workspace/EmbedJS/Middlewares/Third_Party/LwIP/system" -I"/Users/InhoChoi/Documents/workspace/EmbedJS/Middlewares/JSNative/inc" -I"/Users/InhoChoi/Documents/workspace/EmbedJS/Middlewares/TinyJS/inc" -I"/Users/InhoChoi/Documents/workspace/EmbedJS/Drivers/CMSIS/Device/ST/STM32F2xx/Include" -I"/Users/InhoChoi/Documents/workspace/EmbedJS/Drivers/CMSIS/Include" -I"/Users/InhoChoi/Documents/workspace/EmbedJS/Drivers/STM32F2xx_HAL_Driver/Inc" -I"/Users/InhoChoi/Documents/workspace/EmbedJS/Include" -I"/Users/InhoChoi/Documents/workspace/EmbedJS/Middlewares/Third_Party/FreeRTOS/CMSIS_RTOS" -I"/Users/InhoChoi/Documents/workspace/EmbedJS/Middlewares/Third_Party/FreeRTOS/include" -I"/Users/InhoChoi/Documents/workspace/EmbedJS/Middlewares/Third_Party/FreeRTOS/Source/portable/gcc/ARM_CM3" -I"/Users/InhoChoi/Documents/workspace/EmbedJS/Middlewares/Third_Party/LwIP/src/include" -I"/Users/InhoChoi/Documents/workspace/EmbedJS/Middlewares/Third_Party/LwIP/src/include/ipv4" -std=gnu11 -fexceptions -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


