################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../_user_interface/_X.c \
../_user_interface/_view_printer.c \
../_user_interface/_views.c \
../_user_interface/_x_viewer.c 

OBJS += \
./_user_interface/_X.o \
./_user_interface/_view_printer.o \
./_user_interface/_views.o \
./_user_interface/_x_viewer.o 

C_DEPS += \
./_user_interface/_X.d \
./_user_interface/_view_printer.d \
./_user_interface/_views.d \
./_user_interface/_x_viewer.d 


# Each subdirectory must supply rules for building sources it contributes
_user_interface/%.o: ../_user_interface/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O2 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


