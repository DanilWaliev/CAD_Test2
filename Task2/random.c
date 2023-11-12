#ifndef time
#include <time.h>
#endif
#ifndef stdlib
#include <stdlib.h>
#endif

double GetRandomDouble(void)
{
  return rand() * 0.001;
}

int GetRandomInt(void)
{
  return rand() % 10000;
}
