/*
  Evaluateur d'expressions arithmétiques  

  Version 0.1:

  Expression: "12 + 3 * 7 - 99 / 10"
  
            /
          /  \ 
         -    10
       /   \
      +     99
    /   \  
   12    *
       /   \
      3     7

  Version 0.2: handle parentheses
  
  Expression: "(12 + 3) * 7 - (99 / 10)"

              -
           /     \
         *         /
       /   \     /   \
      +     7   99    10
    /   \
   12    3

  Version 0.3: handle parentheses, variables, functions, unary operators,

  Expression: "log(10^x) - sqrt(x*x + y*y)"
  
                -
           /         \
         log        sqrt
          |          |
	  ^          +
        /   \      /   \
       10    x    *     *
                 / \   / \
                x   x y   y
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
typedef struct stack_s {

  //
  long long sp;
  long long *data;

  //
  unsigned size;
  
} stack_t;

//
typedef enum insn_e {
		     ADD = 0x00,
		     SUB,
		     MUL,
		     DIV,
		     MOD,
		     POW
} insn_t;

//
const char *insn_name[] = { "add", "sub", "mul", "div", "mod", "pow" };

//Code generation mode (0 deactivated - 1 activated)
int CG_MODE = 0;

//
stack_t *stack_init(unsigned n)
{
  stack_t *s = malloc(sizeof(stack_t));

  s->sp = -1;
  s->size = n;
  s->data = malloc(sizeof(long long) * n);

  if (s->data)
    memset(s->data, 0, sizeof(long long) * n);
  
  return s;
}

//
void stack_fini(stack_t *s)
{
  if (s)
    {
      s->sp = -1;
      s->size = 0;

      if (s->data)
	free(s->data);
    }
}

//
static inline int stack_push(stack_t *s, long long v)
{
  if (s)
    {
      if (s->sp <= s->size)
	{
	  s->sp++;
	  s->data[s->sp] = v;
	  
	  return 1;
	}
      else
	return 0;
    }
  else
    return 0;
}

//
static inline int stack_pop(stack_t *s, long long *v)
{
  if (s)
    {
      if (s->sp >= 0)
	{
	  *v = s->data[s->sp];
	  s->sp--;

	  return 1;
	}
      else
	return 0;
    }
  else
    return 0;
}
  
//
static inline int stack_top(stack_t *s, long long *v)
{
  if (s)
    {
      if (s->sp >= 0)
	{
	  *v = s->data[s->sp];
	  
	  return 1;
	}
      else
	return 0;
    }
  else
    return 0;
}

//
static inline unsigned walk(char *str)
{
  char *p = str;
  unsigned len = 0;
  
  while (p[len] == ' ')
    len++;
  
  return len;
}

//
static inline char is_digit(char c)
{
  return (c >= '0' && c <= '9');
}

//
static inline char is_operation(char c)
{
  switch (c)
    {
    case '+':
    case '-':
    case '*':
    case '%':
    case '/':
    case '^':
      return 1;

    default:
      return 0;
    }
}

//
static inline insn_t get_operation_instruction(char c)
{
  switch (c)
    {
    case '+':
      return ADD;
      
    case '-':
      return SUB;
      
    case '*':
      return MUL;

    case '/':
      return DIV;
      
    case '%':
      return MOD;

    case '^':
      return POW;
    }
}

//
static inline unsigned get_operation_priority(char c)
{
  switch (c)
    {    
    case '+':
    case '-':
      return 0;
      
    case '*':
    case '/':
    case '%':
      return 1;

    case '^':
      return 2;
    }
}

//
static inline long long get_number(char *str, unsigned *num_len)
{
  unsigned len = 0;
  unsigned long long n = 0;
  
  while (is_digit(str[len]))
    {
      n *= 10;
      n += ((str[len]) - '0') % 10;

      len++;
    }
  
  *num_len = len;

  return n;
}

//
static inline long long do_operation(long long opd1, long long opd2, char opr)
{
  switch (opr)
    {
    case '+':
      return opd1 + opd2;

    case '-':
      return opd1 - opd2;

    case '*':
      return opd1 * opd2;

    case '/':
      if (opd2)
	return opd1 / opd2;
      else
	{
	  //
	  printf("Error: division by 0\n");
	  exit(-1);
	}

    case '%':
      if (opd2)
	return opd1 % opd2;
      else
	{
	  //
	  printf("Error: division by 0\n");
	  exit(-1);
	}

    case '^':
      return pow(opd1, opd2);
      
    default:
      {
	printf("Error: unknown operation\n");
	exit(-1);
      }
    }
}

//
long long parse_eval_expression(char *str)
{
  //
  long long n = 0;
  unsigned long long pos = 0;
  long long opd1, opd2, opr, r;

  //
  if (str)
    {
      unsigned num_len = 0;
      unsigned str_len = strlen(str);
      
      //Operands stack
      stack_t *s_opd = stack_init(100);
      
      //Operators stack
      stack_t *s_opr = stack_init(100);
      
      //
      while (pos < str_len)
	{
	  //Avoid spaces
	  pos += walk(str + pos);
	  
	  //Read a number - should add a check to verify if the symbol is really a number 
	  n = get_number(str + pos, &num_len);
	  pos += num_len;

	  //Code generation
	  if (CG_MODE)
	    {
	      printf("mov rax, %lld\n", n);
	      printf("push rax\n");
	    }
	  
	  //Push the number in the operand's stack
	  stack_push(s_opd, n);
	  
	  //Avoid spaces
	  pos += walk(str + pos);

	  //If remaining symbols left
	  if (pos < str_len)
	    {
	      //If symbol is operator
	      if (is_operation(str[pos]))
		{
		  //If operator stack is not empty
		  if (stack_top(s_opr, &opr))
		    {
		      //If the current operator has equal or greater priority than the top of the stack  
		      if (get_operation_priority(str[pos]) <= get_operation_priority(opr))
			{
			  //Pop the operator and the operands
			  stack_pop(s_opr, &opr);
			  stack_pop(s_opd, &opd2);
			  stack_pop(s_opd, &opd1);
		      
			  //Do the operation of higher priority
			  r = do_operation(opd1, opd2, opr);

			  //Push the result in the operands stack
			  stack_push(s_opd, r);

			  //Code generation
			  if (CG_MODE)
			    {
			      printf("pop rcx          ; ASCII '%c'\n"  , opr);
			      printf("pop rbx          ; %lld\n", opd2);
			      printf("pop rax          ; %lld\n", opd1);
			      printf("%s rax, rbx     ; %lld %c %lld = %lld\n", insn_name[get_operation_instruction((char)opr)], opd1, opr, opd2, r);
			      printf("mov rax, %lld\n", r);
			      printf("push rax\n");
			    }
			}
		      
		      //Push the operator 
		      stack_push(s_opr, (long long)str[pos]);
		      
		      //Code generation
		      if (CG_MODE)
			{
			  printf("mov rax, 0x%02x    ; ASCII '%c'\n", str[pos], str[pos]);
			  printf("push rax\n");
			}
		      
		      //Move forward from current symbol
		      pos++;
	      
		    }
		  else //If stack is empty
		    {
		      //Push the operator
		      stack_push(s_opr, (long long)str[pos]);

		      //Code generation
		      if (CG_MODE)
			{
			  printf("mov rax, 0x%02x    ; ASCII '%c'\n", str[pos], str[pos]);
			  printf("push rax\n");
			}
		      
		      //Move forward from current symbol
		      pos++;
		    }
		}
	      else
		{
		  //
		  printf("Error: unknown symbol '%c' found at position %llu\n", str[pos], pos);
		  exit(-1);
		}
	    }
	}
      
      //Flush the leftover operations to get the final result
      while (stack_pop(s_opr, &opr))
	{
	  stack_pop(s_opd, &opd2);
	  stack_pop(s_opd, &opd1);
	  
	  r = do_operation(opd1, opd2, opr);

	  stack_push(s_opd, r);

	  //Code generation
	  if (CG_MODE)
	    {
	      printf("pop rcx          ; ASCII '%c'\n"  , opr);
	      printf("pop rbx          ; %lld\n", opd2);
	      printf("pop rax          ; %lld\n", opd1);
	      printf("%s rax, rbx     ; %lld %c %lld = %lld\n", insn_name[get_operation_instruction((char)opr)], opd1, opr, opd2, r);
	      printf("mov rax, %lld\n", r);
	      printf("push rax\n");
	    }
	}

      //Get the final result
      stack_pop(s_opd, &r);

      //
      if (CG_MODE)
	printf("pop rax          ; %lld\n", r);
      
      //Free memory
      stack_fini(s_opd);
      stack_fini(s_opr);      
    }

  //
  return r;
}

//
int main(int argc, char **argv)
{
  //Expression position in the arguments list
  unsigned exp_pos = 1;

  //
  if (argc < 2)
    return printf("Usage: %s [-cg] [\"expression\"]\n", argv[0]), 2;
  else
    if (argc == 3)
      if (!strncmp(argv[1], "-cg", 3))
	{
	  exp_pos++;
	  CG_MODE = 1;
	}
      else
	return printf("Usage: %s [-cg] [\"expression\"]\n", argv[0]), 3;
	
  //
  long long n = 0;
  unsigned len = 0;

  //
  n = parse_eval_expression(argv[exp_pos]);

  //
  printf("\n%s = %lld\n", argv[exp_pos], n);
  
  return 0;
}
