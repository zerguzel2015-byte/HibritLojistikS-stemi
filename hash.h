#ifndef HASH_H
#define HASH_H
#include "types.h"

void init_hash_table(HashNode* table);
int hash_function_A(int key);
void insert_package(HashNode* table, int id, const char* dest);
void search_package(HashNode* table, int id);

#endif
