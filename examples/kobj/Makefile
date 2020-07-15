KERNELDIR := /lib/modules/`uname -r`/build
obj-m := kobj.o

modules:
	@$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
	@rm -rf *.o *~ core .depend .*.cmd *.mod.c .tmp_versions Module* modules*
clean:
	rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions Module* modules*
