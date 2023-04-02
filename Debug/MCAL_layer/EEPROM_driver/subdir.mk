################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL_layer/EEPROM_driver/eeprom.c 

OBJS += \
./MCAL_layer/EEPROM_driver/eeprom.o 

C_DEPS += \
./MCAL_layer/EEPROM_driver/eeprom.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL_layer/EEPROM_driver/%.o: ../MCAL_layer/EEPROM_driver/%.c MCAL_layer/EEPROM_driver/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


