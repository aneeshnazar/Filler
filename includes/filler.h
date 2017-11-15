#ifndef FILLER_H
# define FILLER_H
# include <libft.h>

typedef struct  s_piece
{
  int           x_len;
  int           y_len;
  char          *map;
  int           *indices;
  int           *corners;
  int           num_indices;
}               t_piece;

typedef struct  s_map
{
  int           player;
  int           x_len;
  int           y_len;
  char          *map;
  int           *indices;
  int           num_indices;
  int           x_midpoint;
  int           y_midpoint;
}               t_map;

int   int_arr_len(int *arr);
int   get_p_num(char *str);
int   get_board_x(char *str);
int   get_board_y(char *str);
char  *get_piece(int num_rows);
char  *get_board(int num_rows);
//char  *get_board(int num_rows, int num_cols);
int   *get_indices(char *piece, int p_cols, int m_cols);
int   *get_corners(t_piece piece);
//void  save_map(char *str, t_map *map);
void  save_map(char *str, t_map *map);
int   *get_map_indices(char *map, int player);
int   save_piece(char *str, t_piece *piece, t_map map);
int   place_piece(t_map *map, t_piece piece);
int   get_row(t_map map, int pos);
int   get_col(t_map map, int pos);
#endif
