#include <linux/module.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/kthread.h>
#include <linux/err.h>
//#include <linux/timer.h>

int del_flag;
static struct task_struct *mykthread_task;
void timer_func(struct timer_list *next);
DEFINE_TIMER(mytimer, &timer_func);
void timer_func(struct timer_list *next)
{
        printk("%s is call \r\n", __FUNCTION__);
        mod_timer(&mytimer, jiffies + 2 * HZ);
}  

int mykthread_func(void *data)
{
	int n = 0;
	mytimer.expires = jiffies + 2 * HZ;
	add_timer(&mytimer);
	while(1){
		set_current_state(TASK_UNINTERRUPTIBLE);
        	if(kthread_should_stop()){
                	break;
                }
        	printk("%s: %d\n",__func__,n++);
		if (n == 100) {
			del_timer(&mytimer);
			del_flag = 1;
		}
		schedule_timeout(HZ * 3);
       }

       return 0;	
}

static int __init mykthread_init(void)
{
	int  err;
	mykthread_task = kthread_create(mykthread_func, NULL, "kthread_lw");
	if (IS_ERR(mykthread_task)) {
		printk("unable to start kernel thread.\n");
		err = PTR_ERR(mykthread_task);
		mykthread_task = NULL;
		return err;
	}

	wake_up_process(mykthread_task);
	return 0;
}

static void __exit mykthread_exit(void)
{
	if (mykthread_task) {
		kthread_stop(mykthread_task);
		mykthread_task = NULL;
	}

	if (!del_flag) del_timer(&mytimer);
}

module_init(mykthread_init);                                                                                                                                                                                             
module_exit(mykthread_exit);                                                                                                                                                                                             
                                                                                                                                                                                                                     
MODULE_AUTHOR("lw");                                                                                                                                                                                                 
MODULE_LICENSE("GPL");                                                                                                                                                                                               
MODULE_DESCRIPTION("a simple example");                                                                                                                                                                              
MODULE_VERSION("0.0.1"); 
