#include <filler.h>

int   int_arr_len(int *arr)
{
  int i;

  i = 0;
  while (arr[i] != -1)
    ++i;
  return (i);
}
