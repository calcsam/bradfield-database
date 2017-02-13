#include <stdio.h>

const char *FILE_NAMES[] = {
  "cia-crest-files-cia-crest-archive-metadata/test.csv",
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

void filescan(int j) {
  const int NUM_COLUMNS = 50;
  const int COLUMN_WIDTH = 300;

  FILE *f = fopen(FILE_NAMES[j], "r");
  FILE *target = fopen("db.csv", "a");
  char currentRow[NUM_COLUMNS * COLUMN_WIDTH];
  int column = 0;
  int place_in_string = 0;
  int read;
  char * line=NULL;
  size_t len;
  int rows=0;
  int charInLine;

  while ((read = getline((char **)&line, &len, f)) != -1) {
    rows++;
    column=0;
    charInLine=0;
    //printf(line);
    //printf("%d\n", rows);

    while(charInLine < len) {
      while(line[charInLine] != ',' && charInLine < len) {
        currentRow[column * COLUMN_WIDTH + place_in_string] = line[charInLine];
        place_in_string+=(place_in_string < COLUMN_WIDTH);
        charInLine++;
      }
      column+=(column<(NUM_COLUMNS - 2));
      charInLine++;
      place_in_string = 0;
      printf("%s %d %d %d %d %d \n", currentRow, column, place_in_string, charInLine, strlen(currentRow), len);
    }
    write(target, &currentRow, NUM_COLUMNS * COLUMN_WIDTH);
    fprintf(target, "\n");
    if(rows > 10) {
      break;
    }
  }

  fclose(f);
  fclose(target);
};


main(int argc, char **argv) {
  for(int j=0; j<14; j++) {
    filescan(j);
  }
};
