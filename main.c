#include <stdio.h>
#include <string.h>

struct color
{
  char* name;
  int escape_code_number;
};

struct color colors[16] =
{
  {"Black", 30},
  {"Red", 31},
  {"Green", 32},
  {"Yellow", 33},
  {"Blue", 34},
  {"Magenta", 35},
  {"Cyan", 36},
  {"White", 37},
  {"Lightblack", 90},
  {"Lightred", 91},
  {"Lightgreen", 92},
  {"Lightyellow", 93},
  {"Lightblue", 94},
  {"Lightmagenta", 95},
  {"Lightcyan", 96},
  {"Lightwhite", 97}
};

void usage(char* name)
{
  printf("Usage\n");
  printf("-----------------\n");
  printf("%s <text|background> <color>\n");
  printf("\x1b[31mSu\x1b[38;5;208mpp\x1b[93mor\x1b[32mte\x1b[34md col\x1b[38;5;93mors : \x1b[0m\n");
  for (int i = 0; i < sizeof(colors)/sizeof(struct color); i++)
  {
    printf("\x1b[%im%s\n", colors[i].escape_code_number, colors[i].name);
  }
  
  printf("-----------------\n");
  printf("\x1b[0m");
  printf("If you use certain terminals (e.g. kitty) changing\n");
  printf("the background color may be ignored if the terminal\n");
  printf("is transparent (opacity is less than 1.0 or 100%)\n");
}

int main(int argc, char** argv)
{
  if (argc != 3)
  {
    printf("Too few arguments!\n");
    usage(*argv);
    return 1;
  }

  if (strcmp(argv[1], "text") == 0)
  {
    for (int i = 0; i < sizeof(colors)/sizeof(struct color); i++)
    {
      if (strcmp(argv[2], colors[i].name) == 0)
      {
        printf("\x1b[%im", colors[i].escape_code_number);
        return 0;
      }
    }
    printf("Invalid color!\n");
    usage(*argv);
    return 0;
  } else if (strcmp(argv[1], "background") == 0)
  {
    for (int i = 0; i < sizeof(colors)/sizeof(struct color); i++)
    {
      if (strcmp(argv[2], colors[i].name) == 0)
      {
        printf("\x1b[%im", colors[i].escape_code_number + 10);
        return 0;
      }
    }
  printf("Invalid color!\n");
    usage(*argv);
    return 0;
  } else
  {
    printf("Invalid first argument!\n");
    usage(*argv);
    return 1;
  }
}

