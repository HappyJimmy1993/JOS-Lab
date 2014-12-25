// hello, world
#include <inc/lib.h>

void
umain(int argc, char **argv)
{
	//orignal hello.c
	cprintf("hello, world\n");
	cprintf("i am environment %08x\n", thisenv->env_id);

	//check sys_pl
	sys_env_set_pl(0, ENV_PL_HIGH);
	envid_t tem1 = fork();
	envid_t tem2 = fork();
	if (tem1 != 0 && tem2 != 0)
	{
		sys_env_set_pl(0, ENV_PL_HIGH);
		int i = 0;
		for(i = 0; i < 5; ++i)
			cprintf("[%08x] High Priority\n", sys_getenvid());
	}
	else if (tem1 == 0 && tem2 == 0)
	{
		sys_env_set_pl(0, ENV_PL_LOW);
		int i = 0;
		for(i = 0; i < 5; ++i)
			cprintf("[%08x] Low Priority\n", sys_getenvid());
	}
	else
	{
		sys_env_set_pl(0, ENV_PL_DFLT);
		int i = 0;
		for(i = 0; i < 5; ++i)
			cprintf("[%08x] Default Priority\n", sys_getenvid());		
	}
}
