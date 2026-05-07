#include <stdio.h>
#include <string.h>
#include "hash.h"

void init_hash_table(HashNode* table) {
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        table[i].is_occupied = 0;
    }
}

/* Tip A: Division Method */
int hash_function_A(int key) {
    return key % TABLE_SIZE;
}

/* Açık Adresleme (Linear Probing) ile Ekleme */
void insert_package(HashNode* table, int id, const char* dest) {
    int index, i, probe;
    index = hash_function_A(id);

    for (i = 0; i < TABLE_SIZE; i++) {
        probe = (index + i) % TABLE_SIZE;
        if (table[probe].is_occupied == 0) {
            table[probe].package_id = id;
            strcpy(table[probe].destination, dest);
            table[probe].is_occupied = 1;
            printf("Paket %d, indeks %d'ye yerlestirildi.\n", id, probe);
            return;
        }
    }
    printf("Hata: Hash tablosu dolu!\n");
}

void search_package(HashNode* table, int id) {
    int index, i, probe;
    index = hash_function_A(id);

    for (i = 0; i < TABLE_SIZE; i++) {
        probe = (index + i) % TABLE_SIZE;
        if (table[probe].is_occupied == 1 && table[probe].package_id == id) {
            printf("Paket Bulundu! ID: %d, Hedef: %s (Indeks: %d)\n", id, table[probe].destination, probe);
            return;
        }
        if (table[probe].is_occupied == 0) {
            break;
        }
    }
    printf("Paket %d bulunamadi.\n", id);
}
