#include <filler.h>
#include <stdio.h> //remove this

int main(void) {
  t_map   map;
  t_piece piece;
  char    *str;
  int     pos;
  int     i;

  i = 0;
  pos = 0;
  get_next_line(0, &str);
  map.player = get_p_num(str);
  while (get_next_line(0, &str) > 0)
  {
    //if (!ft_strncmp(str, "$$$", 3))

    if (!ft_strncmp(str, "Plateau", 7))
    {
      save_map(str, &map);
      //ft_strdel(&str);
    }
    if (!ft_strncmp(str, "Piece", 5))
    {
      pos = save_piece(str, &piece, map);
      //ft_strdel(&str);
      //ft_putendl(map.map);
      ft_putnbr(get_row(map, pos));
      ft_putchar(' ');
      ft_putnbr(get_col(map, pos));
      ft_putchar('\n');
    }

  }
  /*
while (piece.indices[i] != -1)
  {
    map.map[piece.indices[i]] = num == 1 ? 'x' : 'o';
    ++i;
  }
  i = 0;
  while (map.indices[i] != -1)
  {
    ft_putnbr(map.indices[i]);
    ft_putchar(',');
    ++i;
  }*/
  //pos = place_piece(&map, piece);
  //ft_putendl(map.map);

  return 0;
}
/*
int   main(void)
{
  int num;
  int board_dims[2];
  int piece_dims[2];
  char *str;
  char *map;
  char *piece;
  int  *indices;

  while (get_next_line(0, &str))
  {
    if (!ft_strncmp(str, "$$$", 3))
    {
      num = get_p_num(str);
    }
    if (!ft_strncmp(str, "Plateau", 7))
    {
      board_dims[0] = get_board_x(str);
      board_dims[1] = get_board_y(str);
      map = get_board(board_dims[0]);
    }
    if (!ft_strncmp(str, "Piece", 5))
    {
      piece_dims[0] = get_board_x(str);
      piece_dims[1] = get_board_y(str);
      piece = get_piece(piece_dims[0]);
      indices = get_indices(piece, piece_dims[1], board_dims[1]);
    }
    ft_strdel(&str);
  }
  ft_putchar('\n');
  ft_putnbr(num);
  ft_putchar('\n');
  ft_putnbr(board_dims[0]);
  ft_putchar('x');
  ft_putnbr(board_dims[1]);
  ft_putchar('\n');
  ft_putnbr(piece_dims[0]);
  ft_putchar('x');
  ft_putnbr(piece_dims[1]);
  ft_putchar('\n');
  ft_putendl(piece);
  while (*indices != -1)
  {
    map[*indices] = 'x';
    ++indices;
  }
  ft_putendl(map);
  ft_putchar('\n');
}*/
