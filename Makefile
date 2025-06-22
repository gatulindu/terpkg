CC := gcc
CFLAGS := -Wall -Wextra -O2

SRCS := src/main.c src/run.c src/help.c src/init.c
TARGET := terp
INSTALL_PATH := /usr/local/bin

.PHONY: all install clean

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@

install: $(TARGET)
	mv $(TARGET) $(INSTALL_PATH)

clean:
	rm -f $(TARGET)
