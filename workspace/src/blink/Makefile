include $(MAKEFILE_COMMON)

EXEC = blink

# source: ./*.c ./src/*.c
SRCS = $(wildcard ./*.c) $(wildcard ./src/*.c)
OBJS = $(patsubst %.c,%.o,$(SRCS)) $(STM32_STARTUP_OBJ)

# header: ./inc/*.h
CFLAGS += -I./inc -I./

# private library directory ./lib/
LDFLAGS += -Wl,-Map=$(EXEC).map -L./lib
# LINK_LIB_FLAGS += -lyour_private_library

all: check $(EXEC)

$(EXEC): $(EXEC).bin $(EXEC).hex
$(EXEC).bin $(EXEC).hex: $(EXEC).elf
$(EXEC).elf: $(OBJS)

flash: $(EXEC)
	stm32flash -w $(EXEC).hex -v -n 40 -b 115200 /dev/ttyUSB0 -g 0x0

clean:
	$(Q) $(RM) -v $(EXEC).elf $(EXEC).bin $(EXEC).hex $(EXEC).map
	$(Q) $(RM) -v $(OBJS) $(STM32_STARTUP_OBJ)

.PHONY: clean distclean download lib all check project

check:
ifeq ($(MAKELEVEL),0)
	make -C ../../ PROJECT=$(EXEC)
endif
