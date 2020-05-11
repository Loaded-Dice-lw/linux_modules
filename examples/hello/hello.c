#include <linux/init.h>
#include <linux/module.h>

extern int add_func(const int a, const int b);

static int __init hello_init(void)
{       
    int res = add_func(1,4); 
    printk(KERN_DEBUG "helloworld!priority = 7 \n");
    printk(KERN_INFO "helloworld!prio = 6 \n");
    printk(KERN_NOTICE "helloworld!prio = 5 \n");
    printk(KERN_WARNING "helloworld!prio = 4 \n");
    printk(KERN_ERR "helloworld!prio = 3 \n");
    printk(KERN_CRIT "helloworld!prio = 2 \n");
    printk(KERN_ALERT "helloworld!prio = 1 \n");
    printk(KERN_EMERG "helloworld!prio = 0 \n");
    printk("helloworld! res = %d prio = DEFAULT_MESSAGE_LOGLEVEL \n", res);
    return 0;
}       

static void __exit hello_exit(void)
{       
    printk(KERN_ALERT "module has been removed! \n");
    printk(KERN_DEBUG "goodbye!priority = 7 \n");
    printk(KERN_INFO "goodbye!prio = 6 \n");
    printk(KERN_NOTICE "goodbye!prio = 5 \n");
    printk(KERN_WARNING "goodbye!prio = 4 \n");
    printk(KERN_ERR "goodbye!prio = 3 \n");
    printk(KERN_CRIT "goodbye!prio = 2 \n");
    printk(KERN_ALERT "goodbye!prio = 1 \n");
    printk(KERN_EMERG "goodbye!prio = 0 \n");
    printk("goodbye!prio = DEFAULT_MESSAGE_LOGLEVEL \n");
}       

module_init(hello_init);
module_exit(hello_exit);

MODULE_AUTHOR("lw");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("a simple example");
MODULE_VERSION("0.0.1");
