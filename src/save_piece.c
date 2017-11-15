#include <filler.h>

int save_piece(char *str, t_piece *piece, t_map map) {
  piece->x_len = get_board_x(str);
  piece->y_len = get_board_y(str);
  piece->map = get_piece(piece->x_len);
  piece->indices = get_indices(piece->map, piece->y_len, map.y_len);
  piece->corners = get_corners(*piece);
  piece->num_indices = int_arr_len(piece->indices);
  return (place_piece(&map, *piece));
}
