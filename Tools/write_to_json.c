#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define JSON_FILE "data.json"
enum FILE_STATE { EMPTY_FILE = 0, NOT_FOUND, VALITE_JSON, INVALID_JSON };

struct json_obj {
  char *date;
  char *file;
  char *e_process;
  char *e_p_event;
  char *e_username;
  char *e_p_Umask;
  char *e_p_state;
};

size_t validate_json(char *json_file) {
  char CC;
  FILE *json_fp = NULL;
  if ((json_fp = fopen(json_file, "r")) == NULL) {
    fprintf(stderr, "Failed to open json file: %s", strerror(errno));
    return NOT_FOUND;
  }

  CC = fgetc(json_fp);
  if (CC != '[') {
    if (CC == EOF) {
      fclose(json_fp);
      return EMPTY_FILE;
    } else {
      fclose(json_fp);
      return INVALID_JSON;
    }
  }

  /**
   * seeking to the last three bytes of the file, which normally should be
   * ']\r\n' -> This is necessary for json decoders
   */
  fseek(json_fp, -(long)sizeof(char) * 3, SEEK_END);
  CC = fgetc(json_fp);
  fclose(json_fp);

  if (CC != ']')
    return INVALID_JSON;

  return VALITE_JSON;
}

void writer_json_obj(FILE *json_fp, struct json_obj data) {
  if (json_fp != NULL) {
    fputs("{", json_fp);
    fprintf(json_fp, "\"date\": \"%s\",", data.date);
    fprintf(json_fp, "\"file\": \"%s\",", data.file);
    fprintf(json_fp, "\"e_process\": \"%s\" ,", data.e_process);
    fprintf(json_fp, "\"e_p_event\": \"%s\",", data.e_p_event);
    fprintf(json_fp, "\"e_p_state\": \"%s\",", data.e_p_state);
    fprintf(json_fp, "\"e_username\": \"%s\"", data.e_username);
    fputs("}", json_fp);
  }
}

void append_to_file(FILE *json_fp, struct json_obj data) {
  size_t flag = validate_json(JSON_FILE);
  switch (flag) {
  case VALITE_JSON:
    fseek(json_fp, -(long)sizeof(char) * 3, SEEK_END);
    fwrite(",", sizeof(char), 1, json_fp);
    writer_json_obj(json_fp, data);
    fputs("]\r\n", json_fp);
    break;
  case EMPTY_FILE:
    fputc('[', json_fp);
    writer_json_obj(json_fp, data);
    fputs("]\r\n", json_fp);
    break;
  default:
    exit(EXIT_FAILURE);
  }
}

int main(int argc, char *argv[]) {

  FILE *json_fp = NULL;
  if (access(JSON_FILE, F_OK) != 0) {
    if ((json_fp = fopen(JSON_FILE, "w")) == NULL) {
      fprintf(stderr, "Failed to create the json file: %s", strerror(errno));
      exit(EXIT_FAILURE);
    }
    fclose(json_fp);
  }

  if ((json_fp = fopen(JSON_FILE, "r+")) == NULL) {
    fprintf(stderr, "Failed to open json file: %s", strerror(errno));
    exit(EXIT_FAILURE);
  }

  struct json_obj data = {"Thu Oct 17 16:22:01 2024",
                          "/home/Uname/Documents/workspace/filemond/.gitignore",
                          "git",
                          "FILE ACCESSED",
                          "c0d_0x",
                          "0022",
                          "(running)"};

  append_to_file(json_fp, data);
  fclose(json_fp);

  return EXIT_SUCCESS;
}
