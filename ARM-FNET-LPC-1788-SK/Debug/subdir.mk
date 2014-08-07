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
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D__START=main -D__USE_CMSIS -D__STARTUP_CLEAR_BSS -I"C:\embedded\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\BSP\Include" -I"C:\embedded\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\DRV\PHYLAN" -I"C:\embedded\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Framework" -I"C:\embedded\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Chip\Include" -I"C:\embedded\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Chip\Core\Include" -I"C:\embedded\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Chip\Driver\Include" -I"C:\embedded\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Include" -I"C:\embedded\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Framework\FNET" -I"C:\embedded\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Framework\FNET\compiler" -I"C:\embedded\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Framework\FNET\cpu" -I"C:\embedded\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Framework\FNET\cpu\common" -I"C:\embedded\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Framework\FNET\cpu\lpc17xx" -I"C:\embedded\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Framework\FNET\os" -I"C:\embedded\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Framework\FNET\os\ucosII" -I"C:\embedded\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Framework\FNET\services" -I"C:\embedded\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Framework\FNET\services\dhcp" -I"C:\embedded\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Framework\FNET\services\dns" -I"C:\embedded\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Framework\FNET\services\flash" -I"C:\embedded\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Framework\FNET\services\fs" -I"C:\embedded\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Framework\FNET\services\http" -I"C:\embedded\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Framework\FNET\services\ping" -I"C:\embedded\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Framework\FNET\services\poll" -I"C:\embedded\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Framework\FNET\services\serial" -I"C:\embedded\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Framework\FNET\services\shell" -I"C:\embedded\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Framework\FNET\services\telnet" -I"C:\embedded\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Framework\FNET\services\tftp" -I"C:\embedded\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\Framework\FNET\stack" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


