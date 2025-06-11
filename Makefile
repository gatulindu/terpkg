CC := gcc
CFLAGS := -Wall -Wextra -O2

SRCS := src/main.c src/terpkg.c
TARGET := terpkg
INSTALL_PATH := /usr/local/bin

.PHONY: all install clean

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@

install: $(TARGET)
	mv $(TARGET) $(INSTALL_PATH)

clean:
	rm -f $(TARGET)
