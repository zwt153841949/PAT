################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/6.Tree\ Traversals.cpp 

OBJS += \
./src/6.Tree\ Traversals.o 

CPP_DEPS += \
./src/6.Tree\ Traversals.d 


# Each subdirectory must supply rules for building sources it contributes
src/6.Tree\ Traversals.o: ../src/6.Tree\ Traversals.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/6.Tree Traversals.d" -MT"src/6.Tree\ Traversals.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


