#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct tagStack
{
	char * p;
	int iPos;
}Stack;

void BulidStack(Stack *pStack, int size)
{
	pStack->p = (char *)malloc(size * sizeof(char));
	memset(pStack->p, 0, size);
	pStack->iPos= 0;
}

void DestroyStack(Stack *pStack)
{
	free(pStack->p);
}

int Push(Stack *pStack, char ch)
{
	if (pStack->iPos >= 0)
	{
		*(pStack->p + pStack->iPos) = ch;
		++(pStack->iPos);
		return 0;
	}
	return -1;
}

int Pop(Stack *pStack)
{
	--(pStack->iPos);
	if (pStack->iPos >= 0)
	{
		*(pStack->p + pStack->iPos) = '\0';
		return 0;
	}
	return -1;
}
char GetPairChar(char ch)
{
	switch (ch)
	{
		case ')':
			return '(';
		case '}':
			return '{';

		case ']':
			return '[';
		default:
			return '\0';
	}
}

bool IsPush(char ch)
{
	if (ch == '(' || ch == '{' || ch == '[')
	{
		return true;
	}
	return false;
}

bool isValid(char *s)
{
	if ('\0' == *s)
	{
		return true;
	}
	int n = 0;
	char chPre = *s;
	if (!IsPush(chPre))
	{
		return false;
	}

	Stack myStack;
	BulidStack(&myStack, strlen(s) + 1);
	while (*s != '\0')
	{
		char chCur = *s;
		if (IsPush(chCur))
		{
			if (0 != Push(&myStack, chCur))
			{
				return false;
			}
		}
		else
		{
			if ((myStack.iPos >= 1) && 
			(myStack.p[myStack.iPos - 1] == GetPairChar(chCur)))
			{
				if (0 != Pop(&myStack))	
				{
					return false;
				}
			}
			else
			{

				if (0 != Push(&myStack, chCur))
				{
					return false;
				}
			}
		}
		chPre = *s;
		++s;
	}
	if (0 == myStack.iPos)
	{
		DestroyStack(&myStack);
		return true;
	}
	else
	{
		DestroyStack(&myStack);
		return false;
	}

}

int main()
{
	bool bFlag = isValid("{[}[{}{{({)){[}([]{)}({())[}[}");
	printf("%d", bFlag);
	return 0;
}
