################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Framework/FNET/stack/subdir.mk
-include Framework/FNET/services/tftp/subdir.mk
-include Framework/FNET/services/telnet/subdir.mk
-include Framework/FNET/services/shell/subdir.mk
-include Framework/FNET/services/serial/subdir.mk
-include Framework/FNET/services/poll/subdir.mk
-include Framework/FNET/services/ping/subdir.mk
-include Framework/FNET/services/http/subdir.mk
-include Framework/FNET/services/fs/subdir.mk
-include Framework/FNET/services/flash/subdir.mk
-include Framework/FNET/services/dns/subdir.mk
-include Framework/FNET/services/dhcp/subdir.mk
-include Framework/FNET/os/ucosII/subdir.mk
-include Framework/FNET/os/freertos/subdir.mk
-include Framework/FNET/os/brtos/subdir.mk
-include Framework/FNET/cpu/lpc17xx/subdir.mk
-include Framework/FNET/cpu/common/subdir.mk
-include Framework/FNET/cpu/subdir.mk
-include Framework/FNET/subdir.mk
-include Chip/Driver/Source/subdir.mk
-include Chip/Core/Source/Template/GCC/subdir.mk
-include Chip/Core/Source/Template/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
ARM_FNET_LPC1788-SK.hex \

SECONDARY_LIST += \
ARM_FNET_LPC1788-SK.lst \

SECONDARY_SIZE += \
ARM_FNET_LPC1788-SK.siz \


# All Target
all: ARM_FNET_LPC1788-SK.elf secondary-outputs

# Tool invocations
ARM_FNET_LPC1788-SK.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross ARM C Linker'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -T "C:\embedded\git\ARM-FNET-LPC-1788-SK\ARM-FNET-LPC-1788-SK\gcc_LPC1788.ld" -Wl,-Map,"ARM_FNET_LPC1788-SK.map" -o "ARM_FNET_LPC1788-SK.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

ARM_FNET_LPC1788-SK.hex: ARM_FNET_LPC1788-SK.elf
	@echo 'Invoking: Cross ARM GNU Create Flash Image'
	arm-none-eabi-objcopy -O ihex "ARM_FNET_LPC1788-SK.elf"  "ARM_FNET_LPC1788-SK.hex"
	@echo 'Finished building: $@'
	@echo ' '

ARM_FNET_LPC1788-SK.lst: ARM_FNET_LPC1788-SK.elf
	@echo 'Invoking: Cross ARM GNU Create Listing'
	arm-none-eabi-objdump --source --all-headers --demangle --line-numbers --wide "ARM_FNET_LPC1788-SK.elf" > "ARM_FNET_LPC1788-SK.lst"
	@echo 'Finished building: $@'
	@echo ' '

ARM_FNET_LPC1788-SK.siz: ARM_FNET_LPC1788-SK.elf
	@echo 'Invoking: Cross ARM GNU Print Size'
	arm-none-eabi-size --format=berkeley -x --totals "ARM_FNET_LPC1788-SK.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(SECONDARY_SIZE)$(OBJS)$(C_DEPS)$(ASM_DEPS)$(SECONDARY_FLASH)$(SECONDARY_LIST)$(S_UPPER_DEPS) ARM_FNET_LPC1788-SK.elf
	-@echo ' '

post-build:
	-checksum.cmd "C:/embedded/git/ARM-FNET-LPC-1788-SK/ARM-FNET-LPC-1788-SK" "Debug"  "ARM_FNET_LPC1788-SK" "LPC1788"
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
