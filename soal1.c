/*============================================================
 *  EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 03 - Structures and Dynamic Arrays
 *   Hari dan Tanggal    : Rabu 29 April 2026
 *   Nama (NIM)          : Lutfi Hasan (13224091)
 *   Nama File           : soal1.c
 *   Deskripsi           : Menghasilkan urutan yang sesuai dengan prioritas pengelompokkan dimulai dari alfaberis naik -> tahun naik -> nilai turun -> dan nama alfaberis naik 
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nama[50];
    char kategori[50];
    int tahun;
    int nilai;
} artefak;

int compareArtefak(artefak a, artefak b) {
    if (strcmp(a.kategori, b.kategori) == 0)){
      if (a.tahun != b.tahun) {
          return a.tahun - b.tahun;
      }
    }
    if (a.tahun == b.tahun) {
      if (a.nilai != b.nilai) {
          return (a.nilai < b.nilai) ? 1 : -1;
      }
    }

    return strcmp(a.nama, b.nama);
}

void sortArtefak(artefak arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (compareArtefak(arr[j], arr[j+1]) > 0) {
                artefak tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    
    artefak *arr = (artefak*) malloc(N * sizeof(artefak));
    if (arr == NULL) { 
        printf("ERROR\n"); 
        exit(1); 
    }
    
    for (int i = 0; i < N; i++) {
        scanf("%s %s %d %d", arr[i].nama, arr[i].kategori, &arr[i].tahun, &arr[i].nilai);
    }
    
    sortArtefak(arr, N);
    
    for(int i = 0; i < N; i++){
    printf("%s %s %d %d\n", arr[i].nama, arr[i].kategori, arr[i].tahun, arr[i].nilai);
    }

    free(arr);

    return 0;
}

