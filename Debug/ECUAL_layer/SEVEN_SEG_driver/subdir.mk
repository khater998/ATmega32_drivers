################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ECUAL_layer/SEVEN_SEG_driver/seven_seg.c 

OBJS += \
./ECUAL_layer/SEVEN_SEG_driver/seven_seg.o 

C_DEPS += \
./ECUAL_layer/SEVEN_SEG_driver/seven_seg.d 


# Each subdirectory must supply rules for building sources it contributes
ECUAL_layer/SEVEN_SEG_driver/%.o: ../ECUAL_layer/SEVEN_SEG_driver/%.c ECUAL_layer/SEVEN_SEG_driver/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


