# KProbes
Tracking page faults for a process using KProbes.

Instructions to compile the programs, run the test programs and insert the module
-----------------------------------------------------------------------------------
1. Compile kprobe_example.c using 
    
    make

2. Insert the kernel module using the following command,
		
	  sudo insmod kprobe_example.ko pid=<PID of the process>
    
3. To see the page fault do
    
     dmesg
     
Now, when page faults occur, the PID and the virtual address, at which the page fault occurred, are printed.

Part A: create a kernel module that takes the process-ID of an active process as an argument and tracks all the virtual addresses on which the target process faults. Print the virtual addresses to the system log using printk(). Show that your code works for any arbitrary target process.

Part B: Plot the virtual addresses you tracked as a scatter-plot graph with X-axis representing the time and Y-axis representing the virtual address. Try at least three different types of target applications, such as kernel compilation (compute and I/O intensive), sysbench (compute intensive), iperf (network I/O intensive), or some other applications.
See if you can observe any interesting trends in memory access patterns of a process. Describe your results in a concise report.
