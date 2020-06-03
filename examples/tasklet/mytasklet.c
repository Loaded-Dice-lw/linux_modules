#include <linux/init.h>
#include <linux/module.h>
#include <linux/interrupt.h>


void func_tasklet(unsigned long data)
{
	printk("%s is call !\n", __FUNCTION__);
}

DECLARE_TASKLET(mytasklet, func_tasklet, 0);
static int __init mytasklet_init(void)
{
	tasklet_schedule(&mytasklet);
	return 0;
}       

static void __exit mytasklet_exit(void)
{
	tasklet_kill(&mytasklet);
}       

module_init(mytasklet_init);
module_exit(mytasklet_exit);

MODULE_AUTHOR("lw");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("a simple example");
MODULE_VERSION("0.0.1");
