#include <filler.h>

int   get_p_num(char *str)
{
  int   p_num;

  p_num = (str[ft_find(str, ":") - 2] == '1') ? 1 : 2;
  return (p_num);
}
