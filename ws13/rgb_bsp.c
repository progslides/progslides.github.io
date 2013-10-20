#include <stdio.h>

// NOTE: CSI codes with RGB color codes are only supported on KDE environments!
//       -> This is just for demonstration purpose :)
#define CSI_RGB_COLORED_STRIP(r, g, b) printf(\
  "\x1b[48;2;%d;%d;%dm        \x1b[0m", r, g, b)
  
int main()
{
  int color = 0x455386;
  unsigned char red = (color >> 16) & 0xFF;
  unsigned char green = (color >> 8) & 0xFF;
  unsigned char blue = color & 0xFF;
  
  printf("  red component = %3d", red);
  CSI_RGB_COLORED_STRIP(red, 0, 0);
  
  printf("\ngreen component = %3d", green);
  CSI_RGB_COLORED_STRIP(0, green, 0);
  
  printf("\n blue component = %3d", blue);
  CSI_RGB_COLORED_STRIP(0, 0, blue);
  
  printf("\n     adds up to =    ");
  CSI_RGB_COLORED_STRIP(red, green, blue);
  printf("\n");
  
  return 0;
}