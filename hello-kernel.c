#include <linux/init.h>
#include <linux/module.h>
#include <linux/version.h>
#include <linux/sched.h>
#include <generated/utsrelease.h>
MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Liam Ryan");
MODULE_DESCRIPTION("First Module");
static char* who = "world";
static int howmany = 1;
module_param(who, charp, S_IRUGO);
module_param(howmany, int, S_IRUGO);

static int __init hello_init(void)
{
	int i = 0;
	printk(KERN_ALERT "Kernel version %s" ,UTS_RELEASE);
	printk(KERN_ALERT "The current process is '%s' (pid %i)\n", 
			current->comm, current->pid);
	for(;i <= howmany; i++)
		printk(KERN_INFO "Hello, %s", who);
	return 0;
}

static void __exit hello_exit(void)
{
	printk(KERN_ALERT "Goodbye, cruel world\n");
}

module_init(hello_init);
module_exit(hello_exit);
