#include <stdio.h>
#include <stdlib.h>

//链栈(基于链表的)
Status initLStack(LinkStack *s){   //初始化
	s->top=(LinkStackPtr)malloc(sizeof(StackNode));  //创建一个结点
	if(!(s->top))  //检查结点是否被创建
		return ERROR;
	s->top->next=NULL;  //栈顶（栈底）的下一个结点为空（空栈）
    s->count=-1;

	return SUCCESS;
}

Status isEmptyLStack(LinkStack *s){  //判断链栈是否为空
    if(s->count==-1)  //检查栈的元素的个数，-1代表零个
		return SUCCESS;

	return ERROR;
}
Status getTopLStack(LinkStack *s,ElemType *e){  //得到栈顶元素
    LinkStackPtr pd;

	if(s->count==-1||s)  //检查是否为空栈以及栈是否存在
	return ERROR;

	pd=s->top;  //pd指向栈顶
	*e=pd->data;  //e接受出栈的数据

	return SUCCESS;
}

Status clearLStack(LinkStack *s){   //清空栈
    LinkStackPtr pc;

	if(s->count==-1||!s)  //检查是否为空栈以及栈是否存在
	return ERROR;

	while((s->top)->next){
    	pc=(s->top)->next;  //找到要释放的结点
		(s->top)->next=pc->next;  //栈顶指向要出栈结点的下一个结点
	    free(pc);  //释放结点
	}
	s->count=-1;

	return SUCCESS;
}

Status destroyLStack(LinkStack *s){   //销毁栈
    LinkStackPtr pc;

	if(!(s))  //检查栈是否存在
	return ERROR;

	while((s->top)->next){
    	pc=(s->top)->next;  //找到要释放的结点
		(s->top)->next=pc->next;  //栈顶指向要出栈结点的下一个结点
	    free(pc);  //释放结点
	}
    free(s->top);  //释放栈顶
    free(s);  // 销毁空栈

	return SUCCESS;
}
Status LStackLength(LinkStack *s,int *length){    //检测栈长度
	if(!s)  //检查是否为空栈以及栈是否存在
	return ERROR;

	*length=s->count+1; //通过count元素获得栈的大小 

	return SUCCESS;
}
Status pushLStack(LinkStack *s,ElemType data){   //入栈
    LinkStackPtr p;

	if(!s)  //检查栈是否存在
		return ERROR;

	if((p=(LinkStackPtr)malloc(sizeof(StackNode)))==NULL)  //检查新结点是否成功创建
		return ERROR;

	p->data=data;  //输入新结点的数据域
	p->next=s->top->next;  //插入新结点
    s->top->next=p;  //改变栈顶位置
	s->count++;

	return SUCCESS;
}

Status popLStack(LinkStack *s,ElemType *data){   //出栈
	LinkStackPtr p;

	if(!s)  //检查栈是否存在
		return ERROR;
	p=s->top->next;
	if(p==NULL)  //检查是否为空栈
		return ERROR;

    s->top->next=p->next;  //栈顶下移一位
	*data=p->data;  //得到出栈数据
	free(p);  //释放结点
	s->count--;

	return SUCCESS;
}
