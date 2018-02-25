################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../_routine/_clock_setup.c \
../_routine/_main_routine.c 

OBJS += \
./_routine/_clock_setup.o \
./_routine/_main_routine.o 

C_DEPS += \
./_routine/_clock_setup.d \
./_routine/_main_routine.d 


# Each subdirectory must supply rules for building sources it contributes
_routine/%.o: ../_routine/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O2 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


