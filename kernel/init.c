#include <console.h>
#include <memory.h>
#include <kalloc.h>
#include <monitor.h>

/*
 * Kernel starts executing C code here. Before entring this function, some
 * initialization has been done in the assembly code.
 */
void c_entry(void)
{
	kalloc_init(ALLOCATABLE_MEMORY_START,
		    KERNEL_BASE + INITIAL_MEMORY_SIZE);
	memory_init();
	proc_init();
	console_init();
	kalloc_init(KERNEL_BASE + INITIAL_MEMORY_SIZE,
		    KERNEL_BASE + TOTAL_MEMORY_SIZE);

	/* start the kernel monitor, which should run forever */
	monitor();
}
