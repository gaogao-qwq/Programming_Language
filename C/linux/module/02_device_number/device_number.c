#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("gaogao-qwq");
MODULE_DESCRIPTION("Device number module");

static int driver_open(struct inode *device_file, struct file *instance) {
	printk("device_number: open was called!\n");
	return 0;
}

static int driver_close(struct inode *device_file, struct file *instance) {
	printk("device_number: close was called!\n");
	return 0;
}

static struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = driver_open,
	.release = driver_close
};

#define MYMAJOR 46

static int __init ModuleInit(void) {
	printk("Hello, Kernal!\n");
	// fs/char_dev.c
	int retval = register_chrdev(MYMAJOR, "device_number_module", &fops);
	if (retval != 0) {
		printk("device_number: Could not register device! Errno: %d\n", retval);
		return retval;
	}
	printk("device_number: registered Device number Major: %d, Minor: %d\n", MYMAJOR, 0);
	return 0;
}

static void __exit ModuleExit(void) {
	unregister_chrdev(MYMAJOR, "device_number_module");
	printk("Goodbye, Kernal\n");
}

module_init(ModuleInit);
module_exit(ModuleExit);
