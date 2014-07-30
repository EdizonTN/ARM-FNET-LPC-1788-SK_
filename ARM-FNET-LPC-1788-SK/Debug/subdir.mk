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
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D__START=main -D__USE_CMSIS -D__STARTUP_CLEAR_BSS -I"C:\Documents and Settings\peterj\My Documents\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\BSP\Include" -I"C:\Documents and Settings\peterj\My Documents\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Framework" -I"C:\Documents and Settings\peterj\My Documents\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Chip\Include" -I"C:\Documents and Settings\peterj\My Documents\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Chip\Core\Include" -I"C:\Documents and Settings\peterj\My Documents\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Chip\Driver\Include" -I"C:\Documents and Settings\peterj\My Documents\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Include" -I"C:\Documents and Settings\peterj\My Documents\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Framework\FNET" -I"C:\Documents and Settings\peterj\My Documents\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Framework\FNET\compiler" -I"C:\Documents and Settings\peterj\My Documents\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Framework\FNET\cpu" -I"C:\Documents and Settings\peterj\My Documents\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Framework\FNET\cpu\common" -I"C:\Documents and Settings\peterj\My Documents\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Framework\FNET\cpu\lpc17xx" -I"C:\Documents and Settings\peterj\My Documents\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Framework\FNET\os" -I"C:\Documents and Settings\peterj\My Documents\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Framework\FNET\os\ucosII" -I"C:\Documents and Settings\peterj\My Documents\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Framework\FNET\services" -I"C:\Documents and Settings\peterj\My Documents\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Framework\FNET\services\dhcp" -I"C:\Documents and Settings\peterj\My Documents\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Framework\FNET\services\dns" -I"C:\Documents and Settings\peterj\My Documents\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Framework\FNET\services\flash" -I"C:\Documents and Settings\peterj\My Documents\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Framework\FNET\services\fs" -I"C:\Documents and Settings\peterj\My Documents\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Framework\FNET\services\http" -I"C:\Documents and Settings\peterj\My Documents\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Framework\FNET\services\ping" -I"C:\Documents and Settings\peterj\My Documents\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Framework\FNET\services\poll" -I"C:\Documents and Settings\peterj\My Documents\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Framework\FNET\services\serial" -I"C:\Documents and Settings\peterj\My Documents\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Framework\FNET\services\shell" -I"C:\Documents and Settings\peterj\My Documents\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Framework\FNET\services\telnet" -I"C:\Documents and Settings\peterj\My Documents\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Framework\FNET\services\tftp" -I"C:\Documents and Settings\peterj\My Documents\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Framework\FNET\stack" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


