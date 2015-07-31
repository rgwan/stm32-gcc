MAKEFILE_COMMON = $(abspath ./makefile.common)
include $(MAKEFILE_COMMON)

DEVICE ?= STM32F10X_MD
OSC ?= 8000000

WORKSPACE_DIR = $(abspath ./)
STM32_LIB_DIR = $(abspath ../STM32F10x_StdPeriph_Lib_V3.5.0/)

STM32_LIB_SRCS += $(wildcard $(STM32_LIB_DIR)/Libraries/CMSIS/CM3/CoreSupport/*.c)
STM32_LIB_SRCS += $(wildcard $(STM32_LIB_DIR)/Libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x/*.c)
STM32_LIB_SRCS += $(wildcard $(STM32_LIB_DIR)/Libraries/STM32F10x_StdPeriph_Driver/src/*.c)
STM32_LIB_OBJS = $(patsubst %.c,%.o,$(STM32_LIB_SRCS))

STM32_LIB_INCS += $(STM32_LIB_DIR)/Libraries/STM32F10x_StdPeriph_Driver/inc
STM32_LIB_INCS += $(STM32_LIB_DIR)/Libraries/CMSIS/CM3/CoreSupport
STM32_LIB_INCS += $(STM32_LIB_DIR)/Libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x

STM32_LIB_NAME = kstm32
STM32_LIB_FILE = $(WORKSPACE_DIR)/lib/lib$(STM32_LIB_NAME).a

STM32_STARTUP_OBJ = $(patsubst %.S,%.Os,$(wildcard $(WORKSPACE_DIR)/startup/*.S))

CFLAGS += -D$(DEVICE) -DHSE_VALUE=$(OSC)
CFLAGS += $(addprefix -I,$(STM32_LIB_INCS)) -I$(WORKSPACE_DIR)/inc

LDFLAGS += -T"$(WORKSPACE_DIR)/stm32_flash.ld"
LDFLAGS += -L$(WORKSPACE_DIR)/lib

LINK_LIB_FLAGS = -l$(STM32_LIB_NAME)

export

all: project

check:
ifndef PROJECT
	$(error "Usage: make PROJECT=<app>")
endif

project: check lib
	$(Q) $(MAKE) -C "$(WORKSPACE_DIR)/src/$(PROJECT)"

lib: $(STM32_LIB_FILE)

$(STM32_LIB_FILE): $(STM32_LIB_OBJS)
	$(Q) $(AR) $(ARFLAG) $(STM32_LIB_FILE) $(STM32_LIB_OBJS)

distclean:
	$(Q) $(RM) -v $(STM32_LIB_OBJS)
	$(Q) $(RM) -v $(STM32_LIB_FILE)

clean: check
	$(Q) $(MAKE) -C "$(WORKSPACE_DIR)/src/$(PROJECT)" $@

flash: check
	$(Q) $(MAKE) -C "$(WORKSPACE_DIR)/src/$(PROJECT)" $@


.PHONY: clean distclean download lib all check project
