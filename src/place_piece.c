#include <filler.h>

int   exactly_one(t_map map, t_piece piece)
{
  int count;
  int i;
  int j;

  count = 0;
  i = 0;
  while (i < map.num_indices)
  {
    j = 0;
    while (j < piece.num_indices)
    {
      if (map.indices[i] == piece.indices[j])
        ++count;
      ++j;
    }
    ++i;
  }
  return (count == 1);
}

void  add_to_all(t_piece *piece, int fac)
{
  int i;

  i = 0;
  while (i < piece->num_indices)
  {
    piece->indices[i] += fac;
    ++i;
  }
}

void  piece_adjust(t_piece *piece, int num)
{
  add_to_all(piece, num);
}

int   valid(t_map map, t_piece piece, int start)
{
    int i;
    int j;

    i = 0;
    j = start;
/*    while (j < piece.y_len + start)
    {
      if (map.map[j] == '\n')
        return (0);
      ++j;
    }*/
    while (i < piece.num_indices)
    {
      if (map.map[piece.indices[i]] == (map.player == 1 ? 'x' : 'o') ||
          map.map[piece.indices[i]] == (map.player == 1 ? 'X' : 'O'))
        return (0);
      ++i;
    }
    return (1);
}

int   in_map(t_map map, t_piece piece)
{
  int i;
  int len;

  i = 0;
  len = ft_strlen(map.map);
  while (i < piece.num_indices)
  {
    if (piece.indices[i] >= len)
      return (0);
    ++i;
  }
  return (1);
}

int  *find_placements(t_map *map, t_piece piece)
{
  int i;
  int len;
  int *arr;
  int arr_it;

  i = 0;
  arr_it = 0;
  //len = map->x_len * map->y_len - 1;
  len  = ft_strlen(map->map);
  arr = (int *)ft_memalloc(sizeof(int) * (len + 1));
  while (in_map(*map, piece))
  {
    if (exactly_one(*map, piece) && valid(*map, piece, i))
    {
      arr[arr_it] = i;
      ++arr_it;
    }
    piece_adjust(&piece, 1);
    ++i;
  }
  piece_adjust(&piece, -i);
  arr[arr_it] = -1;
  return (arr);
}

void  place_at(t_map *map, t_piece piece, int start)
{
  int i;

  i = 0;
  while (i < piece.num_indices)
  {
    map->map[start + piece.indices[i]] = (map->player == 1 ? 'o' : 'x');
    ++i;
  }
}

int   arr_max(int *arr, int len)
{
  int i;
  int max;

  max = 0;
  i = 0;
  while (i < len)
  {
    if (arr[i] > max)
      max = arr[i];
    ++i;
  }
  return (max);
}

int   pos_from_xy(t_map *map, int row, int col)
{
  return ((map->y_len + 1) * row + col);
}

int   get_row(t_map map, int pos)
{
  return (pos / (map.y_len + 1));
}

int   get_col(t_map map, int pos)
{
  return (pos % (map.y_len + 1));
}

int   get_dist(t_map map, int p1, int p2)
{
  int row_diff;
  int col_diff;

  row_diff = get_row(map, p1) - get_row(map, p2);
  col_diff = get_col(map, p1) - get_col(map, p2);
  return (row_diff * row_diff + col_diff * col_diff);
}

int   min_dist(t_map map, int pos, int *midpoints)
{
  int min;
  int i;

  min = get_dist(map, pos, midpoints[0]);
  i = 0;
  while (i < 4)
  {
    if (min > get_dist(map, pos, midpoints[i]))
      min = get_dist(map, pos, midpoints[i]);
    ++i;
  }
  return (min);
}

int   best_start(t_map *map, int *arr, int pos)
{
  int i;
  int *dist;
  int min;
  int len;

  i = 0;
  len = int_arr_len(arr);
  dist = (int *)ft_memalloc(sizeof(int) * (len + 1));
  dist[len] = -1;
  while (i < len)
  {
    dist[i] = get_dist(*map, arr[i], pos);
    ++i;
  }
  i = 0;
  min = 0;
  while (i < len)
  {
    if (dist[i] < dist[min])
      min = i;
    ++i;
  }
  return (arr[min]);
}

int   cutoff(t_map *map)
{
  int pos;
  char  str[2];
  int x;
  int y;

  str[1] = 0;
  str[0] = map->player == 1 ? 'x' : 'o';
  pos = ft_find(map->map, str);
  if (pos == -1)
    return (pos_from_xy(map, map->x_midpoint, map->y_midpoint));
  else
  {
    x = get_row(*map, pos) > map->x_midpoint ? map->x_len : 0;
    y = get_col(*map, pos) > map->y_midpoint ? map->y_len : 0;
    pos = pos_from_xy(map, x, y);
    return (pos);
  }
}

int  place_piece(t_map *map, t_piece piece)
{
  int *arr;
  int start;
  int tmp;

  arr = find_placements(map, piece);
  if (*arr != -1)
  {
    tmp = cutoff(map);
    start = best_start(map, arr, tmp);
    return (start);
  }
  else
    return (0);
}
