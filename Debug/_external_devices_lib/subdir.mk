################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../_external_devices_lib/_DS1302.c \
../_external_devices_lib/_I2C_LCD16x2.c \
../_external_devices_lib/_keyboard.c 

OBJS += \
./_external_devices_lib/_DS1302.o \
./_external_devices_lib/_I2C_LCD16x2.o \
./_external_devices_lib/_keyboard.o 

C_DEPS += \
./_external_devices_lib/_DS1302.d \
./_external_devices_lib/_I2C_LCD16x2.d \
./_external_devices_lib/_keyboard.d 


# Each subdirectory must supply rules for building sources it contributes
_external_devices_lib/%.o: ../_external_devices_lib/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O2 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


