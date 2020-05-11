KERNELDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)
obj-m := linux26_auto.o

modules:
	@$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
	@rm -rf *.o *~ core .depend .*.cmd *.mod.c .tmp_versions Module* modules*
	@gcc app.c -g -o app
clean:
	rm -rf app *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions Module* modules*
