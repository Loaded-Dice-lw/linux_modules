#include <linux/init.h>
#include <linux/module.h>
#include <linux/timer.h>

void timer_func(struct timer_list *next);
DEFINE_TIMER(mytimer, &timer_func);
void timer_func(struct timer_list *next)
{
	printk("%s is call \r\n", __FUNCTION__);
	mod_timer(&mytimer, jiffies + 2 * HZ);
}

static int __init mytimer_init(void)
{
	mytimer.expires = jiffies + 5 * HZ;
	add_timer(&mytimer);
	printk("timer has been added! \r\n");
    	return 0;
}       

static void __exit mytimer_exit(void)
{
	del_timer_sync(&mytimer);
	printk("timer has been removed !\r\n");	
}       

module_init(mytimer_init);
module_exit(mytimer_exit);

MODULE_AUTHOR("lw");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("a simple example");
MODULE_VERSION("0.0.1");
