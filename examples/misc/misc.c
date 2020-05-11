#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>

static int mymisc_open(struct inode* pinde, struct file* pfile)
{
	printk("line:%d, %s is call\n", __LINE__, __FUNCTION__);
	return 0;
}

static ssize_t mymisc_read(struct file* pfile, char __user* buf, size_t count, loff_t *poff)
{
	printk("line:%d, %s is call\n", __LINE__, __FUNCTION__);
	return count;
}

static ssize_t mymisc_write(struct file* pfile, const char __user* buf, size_t count, loff_t *poff)
{
	printk("line:%d, %s is call\n", __LINE__, __FUNCTION__);
	return count;
}

static int mymisc_release(struct inode* pinde, struct file* pfile)
{
	printk("line:%d, %s is call\n", __LINE__, __FUNCTION__);
	return 0;
}

static const struct file_operations misc_ops = {
	.open = mymisc_open,
	.read = mymisc_read,
	.write = mymisc_write,
	.release = mymisc_release,
};

static struct miscdevice  mymisc = {
	.minor = 255,
	.name = "mymisc",
	.fops = &misc_ops,
};
static int __init misc_init(void)
{
	int ret;
	ret = misc_register(&mymisc);
	if(ret < 0) {
		printk("mymisc register error\n");
		return ret;
	}
	printk("misc_register ok\n");
	return 0;
}

static void __exit misc_exit(void)
{       
	misc_deregister(&mymisc);
	printk("mymisc deregister ok\n");
}       

module_init(misc_init);
module_exit(misc_exit);

MODULE_AUTHOR("lw");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("a simple example");
MODULE_VERSION("0.0.1");
