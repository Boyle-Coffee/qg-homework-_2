#include <complex.h>
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#define INCREMENTSIZE 10  //栈每次增加大小

typedef enum Status {
	ERROR = 0, SUCCESS = 1
} Status;

//针对double型的栈
typedef complex double ElemType;

typedef struct SqStack {
	ElemType *elem;
	int top;
	int size;
} SqStack;


//顺序栈(基于数组的)
Status initStack(SqStack *s,int sizes);//初始化栈
Status isEmptyStack(SqStack *s);//判断栈是否为空
Status getTopStack(SqStack *s,ElemType *e); //得到栈顶元素
Status clearStack(SqStack *s);//清空栈
Status destroyStack(SqStack *s);//销毁栈
Status stackLength(SqStack *s,int *length);//检测栈长度
Status pushStack(SqStack *s,ElemType data);//入栈
Status popStack(SqStack *s,ElemType *data);//出栈

//针对字符型的栈
typedef char ElemType2;

typedef struct chStack {
	ElemType2 *elem;
	int top;
	int size;
} chStack;


//顺序栈(基于数组的)
Status initChStack(chStack *s,int sizes);//初始化栈
Status isEmptyChStack(chStack *s);//判断栈是否为空
Status getTopChStack(chStack *s,ElemType2 *e); //得到栈顶元素
Status clearChStack(chStack *s);//清空栈
Status destroyChStack(chStack *s);//销毁栈
Status chStackLength(chStack *s,int *length);//检测栈长度
Status pushChStack(chStack *s,ElemType2 data);//入栈
Status popChStack(chStack *s,ElemType2 *data);//出栈


#endif // STACK_H_INCLUDED
