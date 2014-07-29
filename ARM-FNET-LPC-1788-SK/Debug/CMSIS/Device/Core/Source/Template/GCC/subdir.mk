################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
../CMSIS/Device/Core/Source/Template/GCC/startup_LPC177x_8x.S 

OBJS += \
./CMSIS/Device/Core/Source/Template/GCC/startup_LPC177x_8x.o 

S_UPPER_DEPS += \
./CMSIS/Device/Core/Source/Template/GCC/startup_LPC177x_8x.d 


# Each subdirectory must supply rules for building sources it contributes
CMSIS/Device/Core/Source/Template/GCC/%.o: ../CMSIS/Device/Core/Source/Template/GCC/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU Assembler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -x assembler-with-cpp -include"C:\Documents and Settings\peterj\My Documents\workspace\ARM\NXP-LPC\ARM-FNET-LPC-1788-SK\Include\Configuration.h" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


