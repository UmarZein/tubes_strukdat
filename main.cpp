#include "mll.h"
#include<iostream>
int main(){
    MLLMatkul mllm;
    MLLSiswa mlls;
    initMLLMatkul(mllm);
    initMLLSiswa(mlls);
    Siswa *anas = insertSiswa(mlls, "Anas", "F001");
    Siswa *boris = insertSiswa(mlls, "Boris", "F002");
    Siswa *ceri = insertSiswa(mlls, "Ceri", "K001");
    Siswa *deni = insertSiswa(mlls, "Dani", "K001");

    Matkul *mtk = insertMatkul(mllm, "matematika", "mtk", 6, 1);
    Matkul *ipa = insertMatkul(mllm, "ipa", "ipa", 6, 1);
    Matkul *ips = insertMatkul(mllm, "ips", "ips", 5, 1);
    Matkul *pkn = insertMatkul(mllm, "pkn", "pkn", 4, 1);

    Matkul *kim = insertMatkul(mllm, "kimia", "kim", 6, 2);
    Matkul *bio = insertMatkul(mllm, "biologi", "bio", 6, 2);
    Matkul *sej = insertMatkul(mllm, "sejarah", "sej", 5, 2);
    Matkul *geo = insertMatkul(mllm, "geografi", "geo", 4, 2);

    connect(anas,  mtk);
    connect(anas,  ipa);
    connect(anas,  pkn);
    
    connect(boris, ips);
    connect(boris, kim);
    connect(boris, sej);
    connect(boris, geo);

    connect(ceri,  kim);
    connect(ceri,  bio);
    connect(ceri,  geo);

    connect(deni,  pkn);
    connect(deni,  sej);
    connect(deni,  geo);

    printSiswaMatkul(mlls, mllm);
    std::cout << "-----------\n";
    printMatkulSiswa(mlls, mllm);
    std::cout << "-----------\n >> delete matkul: sejarah\n";
    deleteMatkul(mlls, mllm, sej);

    std::cout << "-----------\n";
    printSiswaMatkul(mlls, mllm);
    std::cout << "-----------\n";
    printMatkulSiswa(mlls, mllm);

    std::cout << "-----------\n >> delete siswa: deni\n";
    deleteSiswa(mlls, deni);
    std::cout << "-----------\n";
    printSiswaMatkul(mlls, mllm);
    std::cout << "-----------\n";
    printMatkulSiswa(mlls, mllm);
    std::cout << "-----------\n";
    printMostLeast(mlls, mllm);
}
