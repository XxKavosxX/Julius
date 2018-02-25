################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../_micro_library/_EEPROM.c \
../_micro_library/_adc_converter.c \
../_micro_library/_timers.c \
../_micro_library/_twi.c \
../_micro_library/_usart.c \
../_micro_library/_watchdog.c 

OBJS += \
./_micro_library/_EEPROM.o \
./_micro_library/_adc_converter.o \
./_micro_library/_timers.o \
./_micro_library/_twi.o \
./_micro_library/_usart.o \
./_micro_library/_watchdog.o 

C_DEPS += \
./_micro_library/_EEPROM.d \
./_micro_library/_adc_converter.d \
./_micro_library/_timers.d \
./_micro_library/_twi.d \
./_micro_library/_usart.d \
./_micro_library/_watchdog.d 


# Each subdirectory must supply rules for building sources it contributes
_micro_library/%.o: ../_micro_library/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O2 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


