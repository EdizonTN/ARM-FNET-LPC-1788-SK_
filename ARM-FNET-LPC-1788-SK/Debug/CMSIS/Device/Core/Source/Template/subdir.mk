################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CMSIS/Device/Core/Source/Template/system_LPC177x_8x.c 

OBJS += \
./CMSIS/Device/Core/Source/Template/system_LPC177x_8x.o 

C_DEPS += \
./CMSIS/Device/Core/Source/Template/system_LPC177x_8x.d 


# Each subdirectory must supply rules for building sources it contributes
CMSIS/Device/Core/Source/Template/%.o: ../CMSIS/Device/Core/Source/Template/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D__START=main -D__STARTUP_CLEAR_BSS -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<" @includedirs.txt
	@echo 'Finished building: $<'
	@echo ' '


