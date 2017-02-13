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

struct Column {

   int account_number;
   char *first_name;
   char *last_name;
   float balance;
};
*/
void filescan(int j) {
  printf("here1 \n");
  FILE *f = fopen("db.csv", "r");
  char currentRow[50][300];
  int column = 0;
  int place_in_string = 0;
  int read;
  char * line=NULL;
  size_t len;
  int rows=0;
  int charInLine;
  int c;

  printf("here \n");
  while ((c = fgetc(f)) != EOF) {
    currentRow[column][place_in_string] = (char)c;

    if ((column - 1) % 50 == 0) {
      printf("----");
      if (strstr(currentRow[9],"SOVIET TROOPS IN ORANIENBURG")) {
        printf(currentRow[2]);
      }
      memset(&currentRow[0][0], 0, 30*500);
      place_in_string=0;
      column=0;
    } else if ((place_in_string - 1) % 300 == 0) {
      printf("%s \n", currentRow[column]);
      place_in_string=0;
      column++;
    } else {
      place_in_string++;
    }
  }

  fclose(f);
};


main(int argc, char **argv) {
  printf("here2 \n");
  //for(int j=0; j<14; j++) {
    filescan(1);
  //}
};

const char *COLUMNS = {
  "collection",
  "content_type",
  "document_creation_date",
  "document_number",
  "document_page_count",
  "document_release_date",
  "document_type",
  "file",
  "more1_link",
  "more1_title",
  "more2_link",
  "more2_title",
  "more3_link",
  "more3_title",
  "more4_link",
  "more4_title",
  "more5_link",
  "more5_title",
  "publication_date",
  "release_decision",
  "sequence_number",
  "title",
  "url"
};