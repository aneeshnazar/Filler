int   any(int *arr, int fac, int (*f)(int, int))
{
  int len;
  int i;

  i = 0;
  len = int_arr_len(arr);
  while (i < len)
  {
    if (f(arr[i], fac))
      return (1);
    ++i;
  }
  return (0);
}
