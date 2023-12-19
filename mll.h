#ifndef mllh
#define mllh

#include<iostream>

struct Matkul{
    std::string nama, kode;
    int sks, tingkat;
    Matkul *next;
};
struct Koneksi{
    Matkul *mk;
    Koneksi *next;
};
struct Siswa{
    std::string nama, nim;
    Koneksi *koneksi;
    int tingkat;
    Siswa *next;
};
struct MLLSiswa{
    Siswa *first;
};
struct MLLMatkul{
    Matkul *first;
};

Matkul *createMatkul(std::string nama, std::string kode, int sks, int tingkat);
Koneksi *createKoneksi(Matkul *mk);
Siswa *createSiswa(std::string nama, std::string nim, int tingkat);
void initMLLSiswa(MLLSiswa &mll);
void initMLLMatkul(MLLMatkul &mll);

void insertFirstMatkul(MLLMatkul &mll, std::string nama, std::string kode, int sks, int tingkat);
void insertFirstSiswa(MLLSiswa &mll, std::string nama, std::string nim, int tingkat);
void insertLastMatkul(MLLMatkul &mll, std::string nama, std::string kode, int sks, int tingkat);
void insertLastSiswa(MLLSiswa &mll, std::string nama, std::string nim, int tingkat);

void deleteSiswa(MLLSiswa &mll, Siswa *s);
void deleteMatkul(MLLSiswa &mlls, MLLMatkul &mllm, Matkul *m);

void connect(Siswa *s, Matkul *m);
bool connected(Siswa *s, Matkul *m);

Matkul *searchMatkul(MLLMatkul mll, std::string kode);
Siswa *searchSiswa(MLLSiswa mll, std::string nim);

void printSiswa(Siswa *s);
void printMatkul(Matkul *m);
void printMLLSiswa(MLLSiswa mll);
void printMLLMatkul(MLLMatkul mll);
void printMatkulSiswa(MLLSiswa mlls, MLLMatkul mllm);
void printSiswaMatkul(MLLSiswa mlls, MLLMatkul mllm);
int countParticipant(MLLSiswa mlls, MLLMatkul mllm, Matkul *m);
void printMostLeast(MLLSiswa mlls, MLLMatkul mllm);
void printWithSiswa(MLLSiswa mlls, MLLMatkul mllm, Siswa *s);
void printWithMatkul(MLLSiswa mlls, MLLMatkul mllm, Matkul *m);
#endif 
