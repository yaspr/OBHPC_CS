//
static inline unsigned long long rdtsc (void)
{
   unsigned long long a, d;

   __asm__ volatile ("rdtsc" : "=a" (a), "=d" (d));

   return (d<<32) | a;
}
