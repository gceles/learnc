#include <stdio.h>
#include <stdlib.h>	/* for atof */
#include <math.h>

#define MAXOP	100	/* max size of operand or operator */
#define NUMBER	'0'	/* signal that a number was found */
#define EXP	'1'	/* signal that a exponent is found */
#define SIN	'2'	/* signal that a sine is found */
#define POW	'3'	/* signal that a power is found */

int getop(char []);
void push(double);
double pop(void);

/* reverse polish calculator */
main()
{
    int type;
    int op2;
    char s[MAXOP];
    
    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push((int) pop() % op2);
            else
                printf("error: zero divisor");
            break;
        case EXP:
            push(exp(pop()));
            break;
        case SIN:
            push(sin(pop()));
            break;
        case POW:
            op2 = pop();
            push(pow(pop(), op2));
            break;            
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}


#define MAXVAL	100	/* maximum depth of val stack */

int sp = 0;		/* next free stack position */
double val[MAXVAL];	/* value stack */

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* peek: print the top element of stack without popping */
void peek(void)
{
    if (sp > 0)
        printf("%g\n", val[sp-1]);
    else
        printf("error: stack empty\n");
}

/* swap: swap the top two element of stack */
void swap(void)
{
    double top = pop();
    double second = pop();
    push(top);
    push(second);
}

/* clrstack: clear the stack */
void clrstack(void)
{
    sp = 0;
}


#include <ctype.h>

int getch(void);
void ungetch(int);

/* get next character or numeric operand */
int getop(char s[])
{
    int i, c, tmp;
    
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    i = 0;
    if (!isdigit(c) && c != '.') {
        if (c == '-') {
            if (isdigit(c = getch())) {	/* if the next character is a digit */
                s[i] = '-';		/* treat it as a part of number */
                ungetch(c);		/* push the digit back */
            }
            else {
                ungetch(c);
                return '-';
            }
        }
        else
            return c;
    }
    if (isdigit(c))	/* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c =='.')	/* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}


#define BUFSIZE	100

int buf = EOF;		/* for storing a pushed back variable */

int getch(void)		/* get a (possibly pushed-back) character */
{
    int temp;
    if (buf != EOF) {
        temp = buf;
        buf = EOF;
        return temp;
    }
    else
        return getchar();
}

void ungetch(int c)	/* push character back on input */
{
    buf = c;
}

/* ungets: push an entire string back on input */
void ungets(char s[])
{
    int i = 0;
    
    while (s[i+1] != '\0')
        i++;
    while (i >= 0)
        ungetch(s[i--]);
}