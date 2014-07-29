################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../main.c 

OBJS += \
./main.o 

C_DEPS += \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D__START=main -D__USE_CMSIS -D__STARTUP_CLEAR_BSS -I"/home/janis/C:\Documents and Settings\peterj\My Documents\git/ARM-NXP-LPC/ARM-FNET-LPC-1788-SK/BSP/Include" -I"/home/janis/C:\Documents and Settings\peterj\My Documents\git/ARM-NXP-LPC/ARM-FNET-LPC-1788-SK/Framework" -I"/home/janis/C:\Documents and Settings\peterj\My Documents\git/ARM-NXP-LPC/ARM-FNET-LPC-1788-SK/Chip/Include" -I"/home/janis/C:\Documents and Settings\peterj\My Documents\git/ARM-NXP-LPC/ARM-FNET-LPC-1788-SK/Chip/Core/Include" -I"/home/janis/C:\Documents and Settings\peterj\My Documents\git/ARM-NXP-LPC/ARM-FNET-LPC-1788-SK/Chip/Driver/Include" -I"/home/janis/C:\Documents and Settings\peterj\My Documents\git/ARM-NXP-LPC/ARM-FNET-LPC-1788-SK/Include" -I"/home/janis/C:\Documents and Settings\peterj\My Documents\git/ARM-NXP-LPC/ARM-FNET-LPC-1788-SK/Framework/FNET" -I"/home/janis/C:\Documents and Settings\peterj\My Documents\git/ARM-NXP-LPC/ARM-FNET-LPC-1788-SK/Framework/FNET/compiler" -I"/home/janis/C:\Documents and Settings\peterj\My Documents\git/ARM-NXP-LPC/ARM-FNET-LPC-1788-SK/Framework/FNET/cpu" -I"/home/janis/C:\Documents and Settings\peterj\My Documents\git/ARM-NXP-LPC/ARM-FNET-LPC-1788-SK/Framework/FNET/cpu/common" -I"/home/janis/C:\Documents and Settings\peterj\My Documents\git/ARM-NXP-LPC/ARM-FNET-LPC-1788-SK/Framework/FNET/cpu/lpc17xx" -I"/home/janis/C:\Documents and Settings\peterj\My Documents\git/ARM-NXP-LPC/ARM-FNET-LPC-1788-SK/Framework/FNET/os" -I"/home/janis/C:\Documents and Settings\peterj\My Documents\git/ARM-NXP-LPC/ARM-FNET-LPC-1788-SK/Framework/FNET/os/ucosII" -I"/home/janis/C:\Documents and Settings\peterj\My Documents\git/ARM-NXP-LPC/ARM-FNET-LPC-1788-SK/Framework/FNET/services" -I"/home/janis/C:\Documents and Settings\peterj\My Documents\git/ARM-NXP-LPC/ARM-FNET-LPC-1788-SK/Framework/FNET/services/dhcp" -I"/home/janis/C:\Documents and Settings\peterj\My Documents\git/ARM-NXP-LPC/ARM-FNET-LPC-1788-SK/Framework/FNET/services/dns" -I"/home/janis/C:\Documents and Settings\peterj\My Documents\git/ARM-NXP-LPC/ARM-FNET-LPC-1788-SK/Framework/FNET/services/flash" -I"/home/janis/C:\Documents and Settings\peterj\My Documents\git/ARM-NXP-LPC/ARM-FNET-LPC-1788-SK/Framework/FNET/services/fs" -I"/home/janis/C:\Documents and Settings\peterj\My Documents\git/ARM-NXP-LPC/ARM-FNET-LPC-1788-SK/Framework/FNET/services/http" -I"/home/janis/C:\Documents and Settings\peterj\My Documents\git/ARM-NXP-LPC/ARM-FNET-LPC-1788-SK/Framework/FNET/services/ping" -I"/home/janis/C:\Documents and Settings\peterj\My Documents\git/ARM-NXP-LPC/ARM-FNET-LPC-1788-SK/Framework/FNET/services/poll" -I"/home/janis/C:\Documents and Settings\peterj\My Documents\git/ARM-NXP-LPC/ARM-FNET-LPC-1788-SK/Framework/FNET/services/serial" -I"/home/janis/C:\Documents and Settings\peterj\My Documents\git/ARM-NXP-LPC/ARM-FNET-LPC-1788-SK/Framework/FNET/services/shell" -I"/home/janis/C:\Documents and Settings\peterj\My Documents\git/ARM-NXP-LPC/ARM-FNET-LPC-1788-SK/Framework/FNET/services/telnet" -I"/home/janis/C:\Documents and Settings\peterj\My Documents\git/ARM-NXP-LPC/ARM-FNET-LPC-1788-SK/Framework/FNET/services/tftp" -I"/home/janis/C:\Documents and Settings\peterj\My Documents\git/ARM-NXP-LPC/ARM-FNET-LPC-1788-SK/Framework/FNET/stack" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


