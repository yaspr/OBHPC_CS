/*
  Newton Raphson iteration for root approximation. 
  
  f(x) = 0, find x. 
  
  x_(n+1) = x_n - (f(x_n) / f'(x_n))

 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
typedef unsigned char byte;
typedef unsigned long long u64;

//x^2 - 2 = 0. The solution is x = sqrt(2) = 1.4142135623...
double f1(double x)
{
  return (x * x) - 2;
}

//
double f1_prime(double x)
{
  return (2 * x);
}

//cos(x) - x^3  = 0. The solution is x = 0.8654740331016...
double f2(double x)
{
  return cos(x) - (x * x * x);
}

//
double f2_prime(double x)
{
  return ((-sin(x)) - 3 * (x * x));
}

//x^2 - 2 * x + 1 = 0. The solution is x = 1.
double f3(double x)
{
  return (x * x) - (2 * x) + 1;
}

//
double f3_prime(double x)
{
  return (2 * x) - 2;
}

//
byte newton_raphson(double (*f)(double),                 //Function
		    double (*f_prime)(double),           //Function derivative
		    u64 n,                               //Max iterations
		    double prec,                         //Solution accuracy/precision
		    double *r,                           //Solution
		    u64 *niter)                          //Effective number of iterations
{
  u64 i;
  byte done = 0;
  double bias = 1e-9;
  double x0 = 0.5, x1 = 0.0; 

  printf("%s\t\t%s\t%s\n", "x1", "|x1 - x0|", "|x1| * precision");
  
  for (i = 0; !done && i < n; i++)
    {
      double y = f(x0);
      double y_prime = f_prime(x0) + bias; //Add small bias to avoid division by 0
      
      x1 = x0 - (y / y_prime);

      printf("%.12lf\t%.12lf\t%.12lf\n", x1, fabs(x1 - x0), fabs(x1) * prec);
      
      done = (fabs(x1 - x0) <= fabs(x1) * prec);

      x0 = x1;
    }

  (*r) = x1;
  (*niter) = i;
  
  printf("\n");
  
  return done;
}

//
int main(int argc, char **argv)
{
  u64 n = 100;
  double r1, r2, r3;
  double prec = 1e-9;
  u64 niter1, niter2, niter3;
  byte state1 = newton_raphson(f1, f1_prime, n, prec, &r1, &niter1);
  byte state2 = newton_raphson(f2, f2_prime, n, prec, &r2, &niter2);
  byte state3 = newton_raphson(f3, f3_prime, n, prec, &r3, &niter3);

  if (state1)
    printf("Root found: x = %.16lf, niter = %llu\n", r1, niter1);
  else
    printf("Not root found, did not converge.\n");
  
  if (state2)
    printf("Root found: x = %.16lf, niter = %llu\n", r2, niter2);
  else
    printf("Not root found, did not converge.\n");

  if (state3)
    printf("Root found: x = %.16lf, niter = %llu\n", r3, niter3);
  else
    printf("Not root found, did not converge.\n");

  return 0;
}
