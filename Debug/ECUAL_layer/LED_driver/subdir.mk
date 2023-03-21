################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ECUAL_layer/LED_driver/led.c 

OBJS += \
./ECUAL_layer/LED_driver/led.o 

C_DEPS += \
./ECUAL_layer/LED_driver/led.d 


# Each subdirectory must supply rules for building sources it contributes
ECUAL_layer/LED_driver/%.o: ../ECUAL_layer/LED_driver/%.c ECUAL_layer/LED_driver/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


