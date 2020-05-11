#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>

static unsigned int major = 0;

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

static const struct file_operations early_ops = {
	.open = mymisc_open,
	.read = mymisc_read,
	.write = mymisc_write,
	.release = mymisc_release,
};

static int __init early_init(void)
{
	int ret;
	ret = register_chrdev(0, "early_dev", &early_ops);
	if(ret < 0) {
		printk("early_dev register error\n");
		return ret;
	}

	major = ret;

	printk("misc_register ok \t major = %d\n", ret);
	return 0;
}

static void __exit early_exit(void)
{       
	unregister_chrdev(major, "early_dev");
	printk("early_dev unregister ok\n");
}       

module_init(early_init);
module_exit(early_exit);

MODULE_AUTHOR("lw");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("a simple example");
MODULE_VERSION("0.0.1");
