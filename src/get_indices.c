#include <filler.h>

int   *get_indices(char *piece, int p_cols, int m_cols)
{
  int *arr;
  int len;
  int i;
  int j;

  len = ft_countif(piece, '*');
  i = 0;
  j = -1;
  arr = (int *)ft_memalloc(sizeof(int) *(len + 1));
  arr[len] = -1;
  while (i < len)
  {
    if (piece[++j] == '*')
      arr[i++] = j;
  }
  i = -1;
  while (arr[++i] != -1)
    arr[i] = (arr[i] / (p_cols + 1)) * (m_cols - p_cols) + arr[i];
  return (arr);
}
