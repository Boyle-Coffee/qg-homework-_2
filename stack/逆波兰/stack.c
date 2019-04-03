#include <stdlib.h>

//针对complex double的顺序栈
Status initStack(SqStack *s,int sizes){  //初始化栈
	s->elem=(ElemType*)malloc(sizes*sizeof(ElemType));
	if(!(s->elem))
		return ERROR;
	s->top=-1;
	s->size=sizes;

	return SUCCESS;
}

Status isEmptyStack(SqStack *s){   //判断栈是否为空
	if(s->top==-1)  //检查栈中结点个数，-1为零个
		return SUCCESS;

	return ERROR;
}

Status getTopStack(SqStack *s,ElemType *e){   //得到栈顶元素
	char ch;

	if(!s||s->top==-1)		//检查栈是否存在以及是否为空栈
		return ERROR;

	*e=s->elem[s->top];

	return SUCCESS;
}

Status clearStack(SqStack *s){   //清空栈
	if(!s)  //检查栈是否存在
		return ERROR;
	s->top=-1;  //将栈顶变为-1，即是栈的元素为零

	return SUCCESS;
}

Status destroyStack(SqStack *s){  //销毁栈
	if(!s)  //检查栈是否存在
		return ERROR;
	free(s->elem);
	free(s);  //释放栈的空间

	return SUCCESS;
}
Status stackLength(SqStack *s,int *length){   //检测栈长度
	if(!s)  //检查栈是否存在
		return ERROR;
	*length=s->top+1;

	return SUCCESS;
}

Status pushStack(SqStack *s,ElemType data){  //入栈
	char ch;

	if(!s)		//检查栈是否存在
		return ERROR;
	if(s->top>=s->size-1){  //检查是否栈满
		printf("the stack is full!\ndo you want to increase the size of the stack?\n"
			"the operation may lead to danger!(y or Y to increase)");
		ch=getchar();
		while(getchar()!='\n')
			continue;
		if(ch=='y'||ch=='Y'){  //决定是否增加栈的大小
			s->size+=INCREMENTSIZE;
			s->elem=realloc(s->elem,s->size*sizeof(ElemType));  //增加栈的大小

			return ERROR;
		}
	}
	s->top++;  //改变栈顶的位置
	s->elem[s->top]=data;

	return SUCCESS;
}

Status popStack(SqStack *s,ElemType *data){   //出栈
	if(!s||s->top==-1)		//检查栈是否存在以及是否为空栈
		return ERROR;

	*data=s->elem[s->top];
	s->top--; // 改变栈顶的位置

	return SUCCESS;
}


//针对字符的顺序栈
Status initChStack(chStack *s,int sizes){  //初始化栈
	s->elem=(ElemType2*)malloc(sizes*sizeof(ElemType2));
	if(!(s->elem))
		return ERROR;
	s->top=-1;
	s->size=sizes;

	return SUCCESS;
}

Status isEmptyChStack(chStack *s){   //判断栈是否为空
	if(s->top==-1)  //检查栈中结点个数，-1为零个
		return SUCCESS;

	return ERROR;
}

Status getTopChStack(chStack *s,ElemType2 *e){   //得到栈顶元素
	char ch;

	if(!s||s->top==-1)		//检查栈是否存在以及是否为空栈
		return ERROR;

	*e=s->elem[s->top];

	return SUCCESS;
}

Status clearChStack(chStack *s){   //清空栈
	if(!s)  //检查栈是否存在
		return ERROR;
	s->top=-1;  //将栈顶变为-1，即是栈的元素为零

	return SUCCESS;
}

Status destroyChStack(chStack *s){  //销毁栈
	if(!s)  //检查栈是否存在
		return ERROR;
	free(s->elem);
	free(s);  //释放栈的空间

	return SUCCESS;
}
Status chStackLength(chStack *s,int *length){   //检测栈长度
	if(!s)  //检查栈是否存在
		return ERROR;
	*length=s->top+1;

	return SUCCESS;
}

Status pushChStack(chStack *s,ElemType2 data){  //入栈
	char ch;

	if(!s)		//检查栈是否存在
		return ERROR;
	if(s->top>=s->size-1){  //检查是否栈满
		printf("the stack is full!\ndo you want to increase the size of the stack?\n"
			"the operation may lead to danger!(y or Y to increase)");
		ch=getchar();
		while(getchar()!='\n')
			continue;
		if(ch=='y'||ch=='Y'){  //决定是否增加栈的大小
			s->size+=INCREMENTSIZE;
			s->elem=realloc(s->elem,s->size*sizeof(ElemType2));  //增加栈的大小

			return ERROR;
		}
	}
	s->top++;  //改变栈顶的位置
	(s->elem)[s->top]=data;

	return SUCCESS;
}

Status popChStack(chStack *s,ElemType2 *data){   //出栈
	if(!s||s->top==-1)		//检查栈是否存在以及是否为空栈
		return ERROR;

	*data=s->elem[s->top];
	s->top--; // 改变栈顶的位置

	return SUCCESS;
}
