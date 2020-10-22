//
// Created by Sasha on 20.09.2020.
//

#ifndef ALOCATOR_MAIN_H
#define ALOCATOR_MAIN_H

#endif //ALOCATOR_MAIN_H
typedef struct header Header;
typedef struct allocator Allocator;

struct header {
    char isUsed;
    size_t size;
    Header *next_block;
};

struct allocator {
    void *memoryBuffer;
    size_t size;
    Header *_head;
};

void init (Allocator *_allocator ,size_t size);
void *mem_alloc(Allocator *_allocator, size_t size);
void splitBlock(Allocator *_allocator, Header *header, size_t size);
void *mem_realloc(Allocator *_allocator, void *memPointer, size_t size);
void *first_fit(Header *head, size_t searchSize);
void mem_free(void *memPointer);
void mem_dump(Allocator *allocator);
size_t align(int n);