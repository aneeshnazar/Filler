#include <filler.h>

void save_map(char *str, t_map *map)
{
  map->x_len = get_board_x(str);
  map->y_len = get_board_y(str);
  map->map = get_board(map->x_len);
  map->indices = get_map_indices(map->map, map->player);
  map->num_indices = int_arr_len(map->indices);
  map->x_midpoint = map->x_len / 2;
  map->y_midpoint = map->y_len / 2;
}
/*
void save_map(char *str, t_map *map)
{
  map->x_len = get_board_x(str);
  map->y_len = get_board_y(str);
  map->map = get_board(map->x_len);
}
*/
