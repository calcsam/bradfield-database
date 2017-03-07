#include <stdio.h>
#include <string.h>
#include "row.h"
#include "executor.c"

main(int argc, char **argv) {
  FILE *f = fopen("db.csv", "r");
  next(f);
  Row r = next(f);
  char* match;
  while (!(match = doesRowContain(&r, 9, "SOVIET TROOPS IN ORANIENBURG")) ||  feof(f)) {
    r = next(f);
  }
  if (feof(f)) {
    printf("end of file\n");
  }
  printf("found! \n");
  printf("%s \n", getColValue(&r, 1));
  printf("%s \n", getColValue(&r, 2));
  printf("%s \n", getColValue(&r, 3));
  printf("%s \n", getColValue(&r, 4));
};