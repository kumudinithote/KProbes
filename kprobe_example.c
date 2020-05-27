#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kprobes.h>
#include <linux/ktime.h>
#include <linux/limits.h>
#include <linux/sched.h>
#include <linux/memory.h>
#include <linux/memcontrol.h>
#include <linux/proc_fs.h>
#include <asm/uaccess.h>
#include <linux/slab.h>
#include <linux/timekeeping.h>


//to get the pid from command line
static int pid;
module_param(pid, int, 0);


static struct kprobe kp = {
		  .symbol_name  = "handle_mm_fault",
};

//kprobe pre_handler: called just before the probed instruction is executed.
static int handler_pre(struct kprobe *p, struct pt_regs *regs)
{
	//to get the current time of process.

	struct timespec current_time;
	getnstimeofday(&current_time);

	//to check if the pid entered form command line matches with current pid.
	if(pid == current->pid)
	{
		current_time = current_kernel_time();
		pr_info("Page Fault : Process ID = %d Address = %lx  Time = %ld\n", current -> pid, regs->si, current_time.tv_nsec);//time

	}
		return 0;
}
//kprobe post_handler: called after the probed instruction is executed
static void handler_post(struct kprobe *p, struct pt_regs *regs,
				unsigned long flags)
{

}
// fault_handler: this is called if an exception is generated for any instruction within the pre- or post-handler, or when Kprobes single-steps the probed instruction.
static int handler_fault(struct kprobe *p, struct pt_regs *regs, int trapnr)
{
	return 0;
}

//init module
static int __init kprobe_init(void)
{
  int ret;
	kp.pre_handler = handler_pre;
	kp.post_handler = NULL;
	kp.fault_handler = NULL;

	//to register the kprobe module.
  ret = register_kprobe(&kp);
  if (ret < 0)
  {
      printk(KERN_INFO "register_kprobe failed, returned %d\n", ret);
      return -1;
  }
  printk(KERN_INFO "Planted kprobe at %p\n", kp.addr);
  return 0;
}

//exit module
static void __exit kprobe_exit(void)
{
  unregister_kprobe(&kp);
  remove_proc_entry("AProbe",NULL);
  printk(KERN_INFO "kprobe at %p unregistered \n", kp.addr);
}

module_init(kprobe_init)
module_exit(kprobe_exit)
MODULE_LICENSE("GPL");
