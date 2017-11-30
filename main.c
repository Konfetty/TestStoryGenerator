#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define VALIDNUMBEROFARGUMENTS 2

typedef enum _ErrCode_
{
  ALL_OK = 0,
  INVALID_NUMBER_OF_ARGUMENTS = 1,
  INVALID_ARGUMENT = 2
} ErrCode;

int main(int argc, char *argv[])
{
  if(strcmp(argv[1], "--help") == 0)
  {
    printf("Usage: %s [number of files to generate in power of 2]\n"
             "For Example: parameter \"6\" means \"2^6\" = 64,\n"
             "so (64 - 1) textfiles will be created", argv[0]);
  }
  if (argc != VALIDNUMBEROFARGUMENTS)
  {
    printf("[ERR] Only one Parameter allowed. For example: \"3\"");
    return INVALID_NUMBER_OF_ARGUMENTS;
  }
  int modifier_input = atoi(argv[1]);

  unsigned int number_of_nodes = (unsigned int)pow(2,modifier_input);
  unsigned int max_input = (unsigned int)pow(2, 31);
  if (number_of_nodes > max_input)
  {
    printf(
      "[ERR] This number is a bit too large for your Computer. "
        "Try to stay below 2^31");
    return INVALID_ARGUMENT;
  }
  unsigned int max_number_of_fathers = (number_of_nodes / 2) - 1;

  for (unsigned int title_number = 1;
       title_number <= number_of_nodes - 1; title_number++)
  {

    char title_text[8 + 10 + 1] = "Kapitel_";
    char title_digits[11] = "\0";
    sprintf(title_digits, "%d", title_number);
    strcat(title_text, title_digits);
    strcat(title_text, ".txt");


    FILE *file = fopen(title_text, "w");

    fprintf(file, "%s\n", title_text);

    if (title_number <= max_number_of_fathers)
    {
      fprintf(file, "Kapitel_%i.txt\n", title_number * 2);
      fprintf(file, "Kapitel_%i.txt\n", (title_number * 2) + 1);
    }
    else
    {
      fprintf(file, "-\n");
      fprintf(file, "-\n");
    }

    fprintf(file, "Dies ist ein automatisch generierter Text.\n"
      "Er hat nichts zu bedeuten!\n"
      "Auch gibt es keine wirkliche Entscheidungsmöglichkeiten.\n"
      "Also wähle einfach A, wenn du weiter willst, oder B,\n"
      "wenn du ein komplett anderes Erlebnis haben möchtest!\n"
    );

    fclose(file);
  }

  return ALL_OK;
}
