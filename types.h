#ifndef TYPES_H
#define TYPES_H

#define TABLE_SIZE 10
#define MAX_CITIES 5

/* Hash Tablosu için Paket Düğümü */
typedef struct {
    int package_id;
    char destination[50];
    int is_occupied;
} HashNode;

/* Graf için Kenar (Bağlantı) Düğümü */
typedef struct EdgeNode {
    int target_vertex;
    struct EdgeNode* next;
} EdgeNode;

/* Graf için Şehir (Tepe Noktası) Düğümü */
typedef struct {
    char city_name[50];
    EdgeNode* head;
    int visited;
} GraphNode;

#endif
