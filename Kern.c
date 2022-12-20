#include <linux/module.h>
#include<linux/kernel.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>

 int my_module_init(void)
{
	int pid = 1;
	struct task_struct *task;
	for_each_process(task){
		if(task->pid ==pid){
			printk(KERN_INFO "PID : %d", task->pid);
			printk(KERN_INFO "Name : %s\n",task->comm);
			printk(KERN_INFO "USER ID : %d\n" , task->cred->uid.val);
			printk(KERN_INFO "Group ID : %d\n" , task->group_leader->pid);
                 }
	}
	return 0;

}

 void  my_module_exit(void)
{
	printk(KERN_INFO "Exiting kernel module\n");
}

module_init(my_module_init);
module_exit(my_module_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");


