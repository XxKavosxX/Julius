################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../_objects/_device.c \
../_objects/_matrix_.c \
../_objects/_task.c 

OBJS += \
./_objects/_device.o \
./_objects/_matrix_.o \
./_objects/_task.o 

C_DEPS += \
./_objects/_device.d \
./_objects/_matrix_.d \
./_objects/_task.d 


# Each subdirectory must supply rules for building sources it contributes
_objects/%.o: ../_objects/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O2 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


