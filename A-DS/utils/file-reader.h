//
//  file-reader.h
//  A-DS
//
//  Created by Isa Ertunga on 2023-02-27.
//

#ifndef file_reader_h
#define file_reader_h

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 255

typedef struct File {
    FILE* filePointer;
    char buffer[BUFFER_SIZE];
    // Extend with length etc...
} File;

File* init_file(const char* fileName, const char* mode);

int read_from_file(File* file);
void print_buffer(File* file);

int close_file(File* file);

#endif /* file_reader_h */
