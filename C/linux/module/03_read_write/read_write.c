#include <linux/minmax.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("gaogao-qwq");
MODULE_DESCRIPTION("Register a device and implement some callback functions.");

static char buffer[255];
static int buffer_pointer = 0;

static dev_t my_device_nr;
static struct class *my_class;
static struct cdev my_device;

#define DRIVER_NAME "dummydriver"
#define DRIVER_CLASS "MyMododuleClass"

static int driver_open(struct inode *device_file, struct file *instance) {
	printk("device_number: open was called!\n");
	return 0;
}

static int driver_close(struct inode *device_file, struct file *instance) {
	printk("device_number: close was called!\n");
	return 0;
}

static ssize_t driver_read(struct file *File, char *user_buffer, size_t count, loff_t *offs) {
	int to_copy = umin(count, buffer_pointer);
	int not_copied = copy_to_user(user_buffer, buffer, to_copy);
	return to_copy - not_copied;
}

static ssize_t driver_write(struct file *File, const char *user_buffer, size_t count, loff_t *offs) {
	int to_copy = umin(count, sizeof(buffer));
	int not_copied = copy_from_user(buffer, user_buffer, to_copy);
	buffer_pointer = to_copy;
	return to_copy - not_copied;
}

static struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = driver_open,
	.release = driver_close,
	.read = driver_read,
	.write = driver_write
};


static int __init ModuleInit(void) {
	printk("Hello, Kernal!\n");
	// fs/char_dev.c
	if (alloc_chrdev_region(&my_device_nr, 0, 1, DRIVER_NAME) != 0) {
		printk("Device could not be allocated!\n");
		return -1;
	}
	printk("read_write: Device Dr. Major: %d, Minor: %d\n", my_device_nr >> 20, my_device_nr & 0xfffff);

	my_class = class_create(DRIVER_CLASS);
	if (my_class == NULL) {
		printk("Cannot create device class");
		unregister_chrdev_region(my_device_nr, 1);
		return -1;
	}

	if (device_create(my_class, NULL, my_device_nr, NULL, DRIVER_NAME) == NULL) {
		printk("Cannot create device file");
		class_destroy(my_class);
	}

	cdev_init(&my_device, &fops);
	if (cdev_add(&my_device, my_device_nr, 1) != 0) {
		printk("Failed to register device to kernal");
		device_destroy(my_class, my_device_nr);
	}
	return 0;
}

static void __exit ModuleExit(void) {
	cdev_del(&my_device);
	device_destroy(my_class, my_device_nr);
	class_destroy(my_class);
	unregister_chrdev_region(my_device_nr, 1);
	printk("Goodbye, Kernal\n");
}

module_init(ModuleInit);
module_exit(ModuleExit);
