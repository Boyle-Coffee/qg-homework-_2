#include <stdio.h>
#include "../head/LinkStack.h"
#include <stdlib.h>
#include "LinkStack.c"
void printdone();
char get_first();
int get_int();
void printLStack(LinkStack *s);
int main()
{
	LinkStack stack;
	char choice;
	int e;
	
	atexit(printdone);  //注册打印函数，表明程序结束
	while(!(initLStack(&stack))){
		puts("fail to Create the stack,continue?(c to continue):");
		if(get_first()!='c')
			return 0;
	}
	puts("the stack has been created");
	while(1){
        printf("please choose how to deal with the stack:\n"
            	 "A.is it empty?    B.get the top\n"
		         "C.clear the stack D.length\n"
		         "E.push the stack  F.pop the stack \n"
		         "G.destroy the stack(quit)\n"
				 "H.print\n"
		         "request:_____\b\b\b\b\b");
        choice=get_first();  //获得第一个输入的字符
		switch(choice){  //通过switch语句进行相应的选项
			case'A':if(isEmptyLStack(&stack))  //检查是否空栈
						puts("\nthe stack is empty");
					else  //栈不存在，报错
						puts("\nthe stack is not empty");
					break;
			case'B':if(getTopLStack(&stack,&e))  //获得栈顶元素
						printf("\nThe data of the stack top is %d\n",e);
				    else  //栈空或不存在，报错  
						printf("\nError!I can not get the data\n");
					break;
			case'C':if(clearLStack(&stack))  //清空栈
						puts("\nthe stack is cleared");
				    else  //栈不存在，报错
						puts("\nError!The stack can not be cleared");
					break;
			case'D':if(LStackLength(&stack,&e))  //获得栈的大小
						printf("\nthe length of stack is %d\n",e);
					else
						puts("\nError!I can't get the length of stack");
					break;
			case'E':printf("please tell me the data: ");
					e=get_int();  //入栈时获得数据
					if(pushLStack(&stack,e))  //入栈
						printf("the %d has been pushed into the stack",e);
					else  //栈不存在，报错
						puts("Error!I can not push the stack");
					break;
			case'F':if(popLStack(&stack,&e))  //出栈
						printf("the data you want is %d",e);
					else  //栈空或不存在，报错
						puts("Error!I can not push the stack");
					break;
			case'G':if(destroyLStack(&stack)){
						printf("the stack has been destroyed\n");  //摧毁栈并结束程序
						getchar();
						return 0;
					}
					else{
						printf("Error!");  //摧毁失败，栈不存在
                        getchar();   
						return 0;
					}
					break;
			case'H':printLStack(&stack);  //打印栈
					break;
			default:printf("The choice you entered is wrong!please try again!\n");  //处理错误的输入
		}
		puts("\nAny key continue\n");
		getchar();
		while(getchar()!='\n')  //舍弃其他字符，避免影响到后面的输入
			continue;
	}

	return 0;
}

void printdone(){
	printf("Done!\n");
}

int get_int(){  //获得整数以及处理错误输入
	int input;
	char ch;

	while(scanf("%d",&input)!=1){
		while((ch=getchar())!='\n')
			putchar(ch);
		printf(" is not an integer. please enter an integer:");
	}

	return input;
}

char get_first(){  //获得第一个输入的字符，舍弃其他字符
	char ch;
	
	ch=getchar();
	while(getchar()!='\n')
		continue;

	return ch;
}

void printLStack(LinkStack *s){  //通过指针遍历打印栈
	LinkStackPtr p;
	
	if(!(s))
		printf("the is not exit!");
	else if((s->top)->next==NULL)
		printf("top->  \n  count=%d\n",s->count+1);
	else{
		printf("top->  ");
		p=s->top->next;
		while(p){
			printf("%d ",p->data);
			p=p->next;
		}
		printf("\n  count=%d\n",s->count+1);
	}
}
