################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
./src/BundleObject.cpp \
./src/BundleReceiver.cpp \
./src/BundleSender.cpp \
./src/main.cpp 

OBJS += \
./src/BundleObject.o \
./src/BundleReceiver.o \
./src/BundleSender.o \
./src/main.o 

CPP_DEPS += \
./src/BundleObject.d \
./src/BundleReceiver.d \
./src/BundleSender.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


