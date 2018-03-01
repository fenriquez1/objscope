CPP = clang++

CFLAGS = -std=c++11 -O3 -g3 -Wall -c -fmessage-length=0

LFLAGS =

RM = rm -rf

CPP_SRCS += \
src/BundleObject.cpp \
src/BundleReceiver.cpp \
src/BundleSender.cpp \
src/main.cpp

OBJS += \
./BundleObject.o \
./BundleReceiver.o \
./BundleSender.o \
./main.o

all: ObjectScope

ObjectScope: $(OBJS)
	$(CPP) $(LFLAGS) -o $@ $(OBJS)

$(OBJS): $(CPP_SRCS)
	$(CPP) $(CFLAGS) -MT"$(@)" $(CPP_SRCS)

clean:
	-$(RM) $(OBJS) ObjectScope

.PHONY: all clean dependents
