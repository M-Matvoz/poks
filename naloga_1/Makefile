CC      = gcc
CFLAGS  = -std=c11 -Wall -Wextra -g -O0
LDFLAGS =

SRC_DIR   = src
BUILD_DIR = build
TARGET    = $(BUILD_DIR)/main.exe

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))

# mingw32-make uporablja sh, ÄŤe je na voljo, sicer cmd.exe
ifeq ($(shell echo 'x'),x)
    RUN = ./$(TARGET)
    RMDIR = rm -rf $(BUILD_DIR)
else
    RUN = $(subst /,\,$(TARGET))
    RMDIR = rmdir /S /Q $(BUILD_DIR)
endif

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

run: all
	$(RUN)

clean:
	$(if $(wildcard $(BUILD_DIR)),$(RMDIR))
