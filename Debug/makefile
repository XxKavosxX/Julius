################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include _thecodes/_user_interface_apps/subdir.mk
-include _thecodes/_routine/subdir.mk
-include _thecodes/_plataform_drivers/RealTimeClock/subdir.mk
-include _thecodes/_plataform_drivers/MMI/subdir.mk
-include _thecodes/_parallel_routine/subdir.mk
-include _thecodes/_objects/_sensor/subdir.mk
-include _thecodes/_objects/_date/subdir.mk
-include _thecodes/_objects/subdir.mk
-include _thecodes/_micro_library/subdir.mk
-include _thecodes/_devices_drives/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Julius_v2.0.lss \

FLASH_IMAGE += \
Julius_v2.0.hex \

EEPROM_IMAGE += \
Julius_v2.0.eep \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: Julius_v2.0.elf secondary-outputs

# Tool invocations
Julius_v2.0.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Julius_v2.0.map -mmcu=atmega328p -o "Julius_v2.0.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Julius_v2.0.lss: Julius_v2.0.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Julius_v2.0.elf  >"Julius_v2.0.lss"
	@echo 'Finished building: $@'
	@echo ' '

Julius_v2.0.hex: Julius_v2.0.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Julius_v2.0.elf  "Julius_v2.0.hex"
	@echo 'Finished building: $@'
	@echo ' '

Julius_v2.0.eep: Julius_v2.0.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Julius_v2.0.elf  "Julius_v2.0.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Julius_v2.0.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p Julius_v2.0.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: Julius_v2.0.elf
	@echo 'Invoking: AVRDude'
	/usr/bin/avrdude -pm328p -carduino -P/dev/ttyACM0 -b115200 -Uflash:w:Julius_v2.0.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Julius_v2.0.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
