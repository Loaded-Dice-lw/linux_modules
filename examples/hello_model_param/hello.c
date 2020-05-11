#include <linux/init.h>
#include <linux/module.h>

int num = 0;
static char* name = "LW209";
static int age = 24;
static int array[10] = {0};
module_param(age, int, S_IRUGO);
module_param(name, charp, S_IRUGO);
module_param_array(array, int, &num, S_IRUGO);
static int __init hello_init(void)
{  
    int i = 0;	
    printk(KERN_ALERT "age = %d name = %s \n", age ,name);
    for(i = 0; i < 10; i++) {
    	printk(KERN_EMERG "num = %d ", array[i]);
    }
    return 0;
}       

static void __exit hello_exit(void)
{       
    printk(KERN_EMERG "module has been removed ! \n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_AUTHOR("lw");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("a simple example");
MODULE_VERSION("0.0.1");
