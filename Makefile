CC := gcc
CFLAGS := -Wall -Wextra -O2

SRCS := main.c run.c help.c init.c
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
