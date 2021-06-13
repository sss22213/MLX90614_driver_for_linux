PWD := $(shell pwd)
CC := gcc
KVERSION := $(shell uname -r)
KERNEL_DIR := /lib/modules/$(shell uname -r)/build

MODULE_NAME = mlx90614
obj-m := $(MODULE_NAME).o

all:
	make -C $(KERNEL_DIR) M=$(PWD) modules
clean:
	make -C $(KERNEL_DIR) M=$(PWD) clean
	rm -f test
test:
	gcc -o test test.c -g -Wall
