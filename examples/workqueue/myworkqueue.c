#include <linux/init.h>
#include <linux/module.h>
#include <linux/workqueue.h>

struct mydata {
	int x;
	int y;
	int z;
	struct work_struct work;
};

struct mydata g_var;
struct workqueue_struct *mywq;

void mywork_func(struct work_struct *mywork)
{

	struct mydata *p = (struct mydata *)container_of(mywork, struct mydata, work);
	printk("%s is call ! work: %p \r\n", __FUNCTION__, mywork);
	printk("g_var.x: %d, y: %d z:%d\r\n", g_var.x, g_var.y, g_var.z);
	printk("p->x: %d, y: %d z:%d\r\n", p->x, p->y, p->z);
}
static int __init myworkqueue_init(void)
{
	printk("%s is call!\r\n", __FUNCTION__);
	printk("&g_var.work: %p\r\n", &g_var.work);

	g_var.x = 123;
	g_var.y = 456;
	g_var.z = 789;
	mywq = create_workqueue("mywq");
	if(mywq == NULL) {
		printk("create workqueue error \n");
		return -ENOMEM;
	}
	INIT_WORK(&g_var.work, mywork_func);

	schedule_work(&g_var.work);

    	return 0;
}       

static void __exit myworkqueue_exit(void)
{
	destroy_workqueue(mywq);	
}       

module_init(myworkqueue_init);
module_exit(myworkqueue_exit);

MODULE_AUTHOR("lw");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("a simple example");
MODULE_VERSION("0.0.1");
