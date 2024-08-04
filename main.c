#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

#define REGS_FOREACH(_) _(X)  _(Y)
#define RUN_LOGIC  X1 = !X && Y;Y1 = !X&&!Y;
#define DEFINE(X) static int X,X##1;
#define UPDATE(X) X = X##1;
#define PRINT(X)  printf(#X " = %d ",X);


//这里保存每个数字的值
int main(void) {
	REGS_FOREACH(DEFINE);
	while (1) {
		RUN_LOGIC;
		REGS_FOREACH(PRINT);
		REGS_FOREACH(UPDATE);
		putchar('\n');
		sleep(1000);
	}
}






























































