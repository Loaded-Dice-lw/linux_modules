#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/slab.h>

#define MY_DEVICE_NAME "linux26"
static unsigned int major;
static struct cdev* pcdev;
static dev_t dev_no;

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

static const struct file_operations linux26_fops = {
	.open = mymisc_open,
	.read = mymisc_read,
	.write = mymisc_write,
	.release = mymisc_release,
};

static int __init linux26_init(void)
{
	int ret = -1;
	pcdev = cdev_alloc();
	if(pcdev == NULL) {
		printk("cdev_alloc error\n");
		ret = -ENOMEM;
		goto err_cdev_alloc;
	}

	ret = alloc_chrdev_region(&dev_no, 0, 2, MY_DEVICE_NAME);
	if(ret < 0) {
		printk("alloc_chrdev_region error\n");
		goto err_alloc_chrdev_region;
	}

	cdev_init(pcdev, &linux26_fops);
	ret = cdev_add(pcdev, dev_no, 2);
	if(ret < 0) {
		printk("cdev_add error\n");
		goto err_cdev_add;
	}

	major = MAJOR(dev_no);
	printk("cdev_add ok\t major = %d\n", major);

	return 0;
err_cdev_add:
	unregister_chrdev_region(dev_no, 2);

err_alloc_chrdev_region:
	kfree(pcdev);

err_cdev_alloc:
	return ret;
}

static void __exit linux26_exit(void)
{       
	cdev_del(pcdev);
	unregister_chrdev_region(dev_no, 2);
	kfree(pcdev);
	printk("cdev_del ok\n");
}       

module_init(linux26_init);
module_exit(linux26_exit);

MODULE_AUTHOR("lw");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("a simple example");
MODULE_VERSION("0.0.1");
