################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../_parallel_routine/_sensor_recognition.c \
../_parallel_routine/_timeout.c \
../_parallel_routine/rotina_principal.c 

OBJS += \
./_parallel_routine/_sensor_recognition.o \
./_parallel_routine/_timeout.o \
./_parallel_routine/rotina_principal.o 

C_DEPS += \
./_parallel_routine/_sensor_recognition.d \
./_parallel_routine/_timeout.d \
./_parallel_routine/rotina_principal.d 


# Each subdirectory must supply rules for building sources it contributes
_parallel_routine/%.o: ../_parallel_routine/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O2 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


