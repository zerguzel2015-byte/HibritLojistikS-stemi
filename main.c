#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "hash.h"
#include "graph.h"

void print_memory_report(HashNode* h_table, GraphNode* g_table) {
    int i;
    EdgeNode* temp;

    printf("\n--- BELLEK IZLEME RAPORU ---\n");
    printf("%-20s %-15s %-30s %-20s\n", "Bellek Adresi", "Veri Tipi", "Icerik", "Pointer Baglantisi");
    printf("--------------------------------------------------------------------------------------\n");

    /* Hash Tablosu Bellek Durumu */
    for(i = 0; i < TABLE_SIZE; i++) {
        if(h_table[i].is_occupied) {
            printf("%-20p %-15s ID:%-4d Hedef:%-13s %-20s\n",
                   (void*)&h_table[i], "HashNode", h_table[i].package_id, h_table[i].destination, "NULL (Acik Adresleme)");
        }
    }

    /* Graf Bellek Durumu */
    for(i = 0; i < MAX_CITIES; i++) {
        printf("%-20p %-15s Sehir:%-20s ", (void*)&g_table[i], "GraphNode", g_table[i].city_name);
        if(g_table[i].head != NULL) {
            printf("Edge -> %p\n", (void*)g_table[i].head);

            temp = g_table[i].head;
            while(temp != NULL) {
                printf("%-20p %-15s Hedef Indeks:%-11d ", (void*)temp, "EdgeNode", temp->target_vertex);
                if(temp->next != NULL) {
                    printf("Next -> %p\n", (void*)temp->next);
                } else {
                    printf("Next -> NULL\n");
                }
                temp = temp->next;
            }
        } else {
            printf("Edge -> NULL\n");
        }
    }
    printf("--------------------------------------------------------------------------------------\n");
}

int main() {
    HashNode hash_table[TABLE_SIZE];
    GraphNode graph[MAX_CITIES];

    /* Sistemleri Başlat */
    init_hash_table(hash_table);
    init_graph(graph);

    /* Graf Veri Girişi (Şehirler ve Bağlantılar) */
    add_city(graph, 0, "Istanbul");
    add_city(graph, 1, "Ankara");
    add_city(graph, 2, "Izmir");
    add_city(graph, 3, "Bursa");
    add_city(graph, 4, "Antalya");

    add_edge(graph, 0, 1); /* İstanbul -> Ankara */
    add_edge(graph, 0, 3); /* İstanbul -> Bursa */
    add_edge(graph, 1, 2); /* Ankara -> İzmir */
    add_edge(graph, 3, 2); /* Bursa -> İzmir */
    add_edge(graph, 2, 4); /* İzmir -> Antalya */

    /* Hash Veri Girişi (Paketler) - En az 5 veri */
    printf("--- PAKETLER EKLENIYOR (Acik Adresleme) ---\n");
    insert_package(hash_table, 104, "Ankara");  /* İndeks 4 */
    insert_package(hash_table, 204, "Izmir");   /* İndeks 4 dolu, 5'e geçer (Linear Probing) */
    insert_package(hash_table, 305, "Bursa");   /* İndeks 5 dolu, 6'ya geçer */
    insert_package(hash_table, 401, "Antalya"); /* İndeks 1 */
    insert_package(hash_table, 509, "Istanbul");/* İndeks 9 */

    /* İşlevleri Test Etme */
    printf("\n--- PAKET SORGULAMA ---\n");
    search_package(hash_table, 204);
    search_package(hash_table, 999);

    printf("\n--- GRAF GEZINME (DFS) ---\n");
    printf("Baslangic: Istanbul (0)\nRota: ");
    reset_visited(graph);
    dfs(graph, 0);
    printf("SON\n");

    /* Bellek Raporunu Yazdır */
    print_memory_report(hash_table, graph);

    return 0;
}
