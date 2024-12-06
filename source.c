#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void initMultiList(MultiList *list) {
    list->firstParent = NULL;
}

NodeParent *createParent(int nomorNota, int nomorMeja, const char *tanggal) {
    NodeParent *newParent = (NodeParent *)malloc(sizeof(NodeParent));
    newParent->data.nomorNota = nomorNota;
    newParent->data.nomorMeja = nomorMeja;
    newParent->data.totalBelanja = 0;
    strcpy(newParent->data.tanggal, tanggal);
    newParent->next = NULL;
    newParent->firstChild = NULL;
    return newParent;
}

NodeChild *createChild(const char *nama, int jumlah, int harga) {
    NodeChild *newChild = (NodeChild *)malloc(sizeof(NodeChild));
    strcpy(newChild->data.nama, nama);
    newChild->data.jumlah = jumlah;
    newChild->data.harga = harga;
    newChild->next = NULL;
    return newChild;
}

void addParent(MultiList *list, NodeParent *newParent) {
    newParent->next = list->firstParent;
    list->firstParent = newParent;
}

void addChild(NodeParent *parent, NodeChild *newChild) {
    newChild->next = parent->firstChild;
    parent->firstChild = newChild;
    parent->data.totalBelanja += newChild->data.jumlah * newChild->data.harga;
}

void printAll(MultiList *list) {
    NodeParent *p = list->firstParent;
    while (p != NULL) {
        printf("Nota %d (Meja %d) - %s\n", p->data.nomorNota, p->data.nomorMeja, p->data.tanggal);
        NodeChild *c = p->firstChild;
        while (c != NULL) {
            printf("  %s x%d @Rp%d\n", c->data.nama, c->data.jumlah, c->data.harga);
            c = c->next;
        }
        printf("Total: Rp%d\n\n", p->data.totalBelanja);
        p = p->next;
    }
}

// Implementasi lainnya: deleteParent, deleteChild, laporanOmzet, laporanTerbanyak

int main() {
    MultiList list;
    initMultiList(&list);

    NodeParent *parent1 = createParent(1, 101, "2024-12-04");
    addChild(parent1, createChild("Nasi Goreng", 2, 20000));
    addChild(parent1, createChild("Teh Manis", 2, 5000));
    addParent(&list, parent1);

    NodeParent *parent2 = createParent(2, 102, "2024-12-04");
    addChild(parent2, createChild("Ayam Bakar", 1, 25000));
    addParent(&list, parent2);

    printAll(&list);

    laporanOmzet(&list); // Implementasi laporan omzet
    laporanTerbanyak(&list); // Implementasi laporan makanan/minuman terbanyak

    return 0;
}