#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

const char *FILE_NAMES[] = {
  "cia-crest-files-cia-crest-archive-metadata/1_export.csv",
  "cia-crest-files-cia-crest-archive-metadata/2_export.csv",
  "cia-crest-files-cia-crest-archive-metadata/3_export.csv",
  "cia-crest-files-cia-crest-archive-metadata/4_export.csv",
  "cia-crest-files-cia-crest-archive-metadata/5_export.csv",
  "cia-crest-files-cia-crest-archive-metadata/6_export.csv",
  "cia-crest-files-cia-crest-archive-metadata/7_export.csv",
  "cia-crest-files-cia-crest-archive-metadata/8_export.csv",
  "cia-crest-files-cia-crest-archive-metadata/9_export.csv",
  "cia-crest-files-cia-crest-archive-metadata/10_export.csv",
  "cia-crest-files-cia-crest-archive-metadata/11_export.csv",
  "cia-crest-files-cia-crest-archive-metadata/12_export.csv",
  "cia-crest-files-cia-crest-archive-metadata/13_export.csv",
  "cia-crest-files-cia-crest-archive-metadata/14_export.csv",
};

int IN_QUOTES = 1;
int NORMAL = 0;
int COMMA = 2;
int NULL_BYTE = 3;

int shouldShift(int cs) {
  return cs == COMMA;
}

int getIncrement(int cs) {
  if (cs == NULL_BYTE)
    return 0;
  return 1;
}

int getChar(int cs, char character) {
  if (cs == NORMAL || cs == IN_QUOTES) {
    return character;
  }
  return '\0';
}

int nextState(int cs, char character) {
  if (cs == NORMAL && character == '"')
    return IN_QUOTES;
  else if (cs == NORMAL && character == ',')
    return COMMA;
  else if (cs == NORMAL)
    return NORMAL;
  else if (cs == IN_QUOTES && character == '"')
    return NORMAL;
  else if (cs == IN_QUOTES)
    return IN_QUOTES;
  return NULL_BYTE;
}

void filescan(int target, int j) {
  const int NUM_COLUMNS = 25;
  const int COLUMN_WIDTH = 300;

  FILE *f = fopen(FILE_NAMES[j], "r");
  char currentRow[NUM_COLUMNS * COLUMN_WIDTH];
  int column = 0;
  int place_in_string = 0;
  int read;
  char * line=NULL;
  size_t len;
  int rows=0;
  int charInLine;
  int charState;


  while ((read = getline((char **)&line, &len, f)) != -1) {
    rows++;
    column=0;
    charInLine=0;
    charState=NORMAL;

    while(column<(NUM_COLUMNS - 1)) {
      while(place_in_string < COLUMN_WIDTH &&
            charInLine < len) {
        charState = nextState( charState, line[charInLine]);
        currentRow[column * COLUMN_WIDTH + place_in_string] = getChar(charState, line[charInLine]);
        charInLine += getIncrement(charState);
        place_in_string++;
      }
      charState = NORMAL;
      column+=1;
      place_in_string = 0;
    }
    write(target, &currentRow, NUM_COLUMNS * COLUMN_WIDTH);
  }

  fclose(f);
};


main(int argc, char **argv) {
  int target = open("db.csv", O_WRONLY);
  for(int i=0; i<14; i++) {
    filescan(target, i);
    printf("%d \n", i);
  }
  close(target);
};
