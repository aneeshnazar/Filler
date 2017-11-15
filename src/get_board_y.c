#include <filler.h>

int get_board_y(char *str)
{
  int pos;

  pos = ft_find(str, ":") - 1;
  while (ft_isdigit(str[pos]))
    --pos;
  str += pos;
  return (ft_atoi(str));
}
