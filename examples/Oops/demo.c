#include <linux/init.h>
#include <linux/module.h>


static int __init Oopsdemo_init(void)
{       
	*((int *)0x00) = 0x19760817;
	return 0;
}

static void __exit Oopsdemo_exit(void)
{       
}       

module_init(Oopsdemo_init);
module_exit(Oopsdemo_exit);

MODULE_AUTHOR("lw");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("a simple example");
MODULE_VERSION("0.0.1");
