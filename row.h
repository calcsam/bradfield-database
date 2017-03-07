
/*
#include <string.h>

const int NUM_COLUMNS = 23;



COLUMN_SIZE = 150;

void filter() {

  return
}

void return_next_matching_row(void (*filter)(Row), Row (*get_next)(int)) {
  Row r = get_next();
  while(!filter(r)) {
    r = get_next()
  }
  return r;
}


struct Executor {
  QueryPlan qp;
  Filesystem f;

  Row get_next(){
    char * line = NULL:
    line = f.get_next();
    while ((keep_reading=qp.read(&line)) != -1) {
      line = f.get_next();
    }
    return line;
  }
};

struct Row {
  char* text;
  char* get_column(int col) {
    char* substr[150];
    memcpy( substr, &text[col * 150], 150);
    return substr;
  }

}

char*

typedef struct {
  int operation (char * line, ) = // pointer to a function
  int read(char * line) {

  }
} QueryPlan;

struct Filesystem {
  // doesn't account for case that a file might be empty
  File openFile f;
  int fileNum = 0;
  void get_next_line(){
    char * line = NULL:
    size_t len;
    if ((read = getline((char **)&line, &len, f)) != -1) {
      return line;
    } else {
      advance_file(f)
      if (f == -NULL) {
        return -NULL;
      }
      return getline((char **)&line, &len, f));
    }
  }
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
  void advance_file() {
    f.close();
    fileNum++;
    f = fopen(FILE_NAMES[fileNum], "r")
  }
}



struct Table {
   Row
};

struct Row {
   int account_number;
   char *first_name;
   char *last_name;
   float balance;
};

*/

#ifndef ROW_H
#define ROW_H

#include <stdio.h>
#include <string.h>

typedef struct Cells {
   char *columnName;
   char *value;
} Cell;

typedef struct Rows
{
  int id;
  char columnNames[25][50];
  char columns[25][301];
  char* (*getColValue)(int col);
} Row;

char* getColValue(Row *self, int col) {
  return self->columns[col];
}

char* doesRowContain(Row *self, int col, char* searchString) {
  return strstr(self->columns[col], searchString);
}

#endif