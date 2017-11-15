#include <filler.h>

int   *get_p_indices(char *piece)
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
  return (arr);
}

int  get_tr_corner(int first_row, int *arr, int r_len)
{
  int i;
  int len;

  i = 0;
  len = int_arr_len(arr);
  while (i < len)
  {
    if (arr[i] / r_len > first_row)
      break;
    ++i;
  }
  return (i - 1);
}

int   get_bl_corner(int last_row, int *arr, int r_len)
{
  int i;
  int len;

  len = int_arr_len(arr);
  i = len - 1;
  while (i >= 0)
  {
    if (arr[i] / r_len < last_row)
      break;
    --i;
  }
  return (i + 1);
}

int   *get_corners(t_piece piece)
{
  int len;
  int *arr;
  int *tmp_ind;

  arr = (int *)ft_memalloc(sizeof(int) * 5);
  tmp_ind = get_p_indices(piece.map);
  len = int_arr_len(tmp_ind);
  arr[4] = -1;
  arr[0] = 0;
  arr[3] = len - 1;
  arr[1] = get_tr_corner(tmp_ind[arr[0]] / piece.y_len, tmp_ind, piece.y_len);
  arr[2] = get_bl_corner(tmp_ind[arr[3]] / piece.y_len - 1, tmp_ind, piece.y_len);
  return (arr);
}
