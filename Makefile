obj-m += hello-kernel.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
