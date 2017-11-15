#include <filler.h>

static int   total_count(char *str, char c)
{
  return (ft_countif(str, ft_toupper(c)) + ft_countif(str, c));
}

int   *get_map_indices(char *str, int player)
{
  int len;
  int *arr;
  int i;
  int j;
  char p;

  p = (player == 1) ? 'o' : 'x';
  len = total_count(str, p);
  arr = (int *)ft_memalloc(sizeof(int) * (len + 1));
  arr[len] = -1;
  i = 0;
  j = -1;
  while (i < len)
  {
    if (ft_tolower(str[++j]) == p)
      arr[i++] = j;
  }
  return (arr);
}
