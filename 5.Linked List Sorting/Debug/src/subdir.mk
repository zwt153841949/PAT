################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/5.Linked\ List\ Sorting.cpp 

OBJS += \
./src/5.Linked\ List\ Sorting.o 

CPP_DEPS += \
./src/5.Linked\ List\ Sorting.d 


# Each subdirectory must supply rules for building sources it contributes
src/5.Linked\ List\ Sorting.o: ../src/5.Linked\ List\ Sorting.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/5.Linked List Sorting.d" -MT"src/5.Linked\ List\ Sorting.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


