#include <filler.h>

int get_board_x(char *str)
{
  int pos;

  pos = 0;
  while (ft_isalpha(str[pos]))
    ++pos;
  str += pos;
  return (ft_atoi(str));
}
