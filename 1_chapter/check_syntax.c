#include <stdio.h>

#define MAXVAL 1000	/* maximum number of quotes/parenthesis allowed */
#define IN 0		/* inside quotes */
#define OUT 1		/* outside quotes */

void push(int);
int peek(void);
int pop(void);
int isstack_empty(void);

/* checks a c program for rudimentary errors like
 * unbalanced quotes, parenthesis, etc
 */
int main(void)
{
	int c;
	int quote;
	int extra_closing;

	quote = OUT;
	extra_closing = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\"') {
			if (quote == IN) {
				quote = OUT;
				pop();
			} else {
				quote = IN;
				push('\"');		
			}
		} else if (c == '\\') {
			c = getchar();
		} else if (quote == OUT) {
			if (c == '(' || c == '{')
				push(c);
			else if (c == ')' && !isstack_empty() && peek() == '(')
				pop();
			else if (c == '}' && !isstack_empty() && peek() == '{')
				pop();
			else if (c == '}' || c == ')')
				extra_closing = 1;
		}
	}
	if (isstack_empty && !extra_closing)
		printf("Everything seems good!\n");
	else
		printf("ERrOR: UnMatCHed pArEnthESIs\n");
	return 0;
}

/* symbol stack implementation */
int symbols[MAXVAL];
int sp = 0;

void push(int c)
{
	(sp < MAXVAL) ? (symbols[sp++] = c) : printf("error: stack overflow\n");
}

int pop(void)
{
	if (sp > 0) {
		return symbols[--sp];
	} else {
		printf("error: stack underflow\n");
		return -1;
	}
}

int peek(void)
{
	if (sp > 0) {
		return symbols[sp-1];
	} else {
		printf("error: stack empty\n");
		return 0;
	}
}

int isstack_empty(void)
{
	return (sp == 0);
}