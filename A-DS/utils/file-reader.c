//
//  file-reader.c
//  A-DS
//
//  Created by Isa Ertunga on 2023-02-27.
//

#include "file-reader.h"


File* init_file(const char* fileName, const char* mode) {
    File* file = (File*)malloc(sizeof(File));
    FILE* fp = fopen(fileName, mode);
    file->filePointer = fp;
    return file;
}

// ------- FIX ------------
int read_from_file(File* file) {
    fscanf(file->filePointer, "%s", file->buffer);
    return 1;
}

void print_buffer(File* file) {
    printf("%s", file->buffer);
}
// ------- FIX ------------

int close_file(File* file) {
    int closeFileReturnValue = fclose(file->filePointer);
    free(file);
    return closeFileReturnValue;
}
