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
  FILE *f = fopen(FILE_NAMES[j], "r");
  char currentRow[50][300];
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
        currentRow[column][place_in_string] = line[charInLine];
        place_in_string+=(place_in_string < 300);
        charInLine++;
      }
      column+=(column<48);
      charInLine++;
      place_in_string = 0;
    }

    if (strstr(currentRow[9],"SOVIET TROOPS IN ORANIENBURG")) {
      printf(currentRow[2]);
    }
  }

  fclose(f);
};


main(int argc, char **argv) {
  for(int j=0; j<14; j++) {
    filescan(j);
  }
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