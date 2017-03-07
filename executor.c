#include <stdio.h>
#include <string.h>
#include "row.h"

const char *FILE_NAMES[] = {
  "cia-crest-files-cia-crest-archive-metadata/db.csv",
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
  "url",
  "empty",
  "empty",
  "empty",
  "empty",
};


const int NUM_COLUMNS = 25;
const int COLUMN_WIDTH = 300;

Row getLine(int rowNum, FILE *f) {
  Row newRow;
  for (int k=0; k<25; k++) {
    fseek( f, rowNum * NUM_COLUMNS * COLUMN_WIDTH + (k * COLUMN_WIDTH), SEEK_SET );
    fread(newRow.columns[k], 1, COLUMN_WIDTH, f);
    strcpy(newRow.columnNames[k], &COLUMNS[k]);
    printf("%s,", newRow.columns[k]);
  }
  printf("------ \n");
  return newRow;
}

Row next(FILE *f) {
  Row newRow;
  for (int k=0; k<25; k++) {
    fread(newRow.columns[k], 1, COLUMN_WIDTH, f);
    strcpy(newRow.columnNames[k], &COLUMNS[k]);
  }
  return newRow;
}
