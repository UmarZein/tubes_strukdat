#include "mll.h"
#include<iostream>
int main(){
    MLLMatkul mllm;
    MLLSiswa mlls;
    initMLLMatkul(mllm);
    initMLLSiswa(mlls);
    insertFirstSiswa(mlls, "Anas", "F001", 1); // insert last
    insertLastSiswa(mlls, "Boris", "F002", 2);
    insertFirstSiswa(mlls, "Ceri", "K001", 2);
    insertLastSiswa(mlls, "Deni", "K002", 1);

    insertFirstMatkul(mllm, "matematika", "mtk", 6, 1); // insert first
    insertLastMatkul(mllm, "ipa", "ipa", 6, 1);
    insertFirstMatkul(mllm, "ips", "ips", 5, 1);
    insertLastMatkul(mllm, "pkn", "pkn", 4, 1);

    insertFirstMatkul(mllm, "kimia", "kim", 6, 2);
    insertLastMatkul(mllm, "biologi", "bio", 6, 2);
    insertFirstMatkul(mllm, "sejarah", "sej", 5, 2);
    insertLastMatkul(mllm, "geografi", "geo", 4, 2);
   
    Siswa *anas = searchSiswa(mlls, "F001");
    Siswa *boris = searchSiswa(mlls, "F002");
    Siswa *ceri = searchSiswa(mlls, "K001");
    Siswa *deni = searchSiswa(mlls, "K002");

    Matkul *mtk = searchMatkul(mllm, "mtk");
    Matkul *ipa = searchMatkul(mllm, "ipa");
    Matkul *ips = searchMatkul(mllm, "ips");
    Matkul *pkn = searchMatkul(mllm, "pkn");
    Matkul *kim = searchMatkul(mllm, "kim");
    Matkul *bio = searchMatkul(mllm, "bio");
    Matkul *sej = searchMatkul(mllm, "sej");
    Matkul *geo = searchMatkul(mllm, "geo");

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
    connect(deni,  ipa);
    connect(deni,  ips);

    printSiswaMatkul(mlls, mllm);
    std::cout << "-----------\n";
    printMatkulSiswa(mlls, mllm);
    std::cout << "-----------mencari matkul sejarah\n";
    sej = searchMatkul(mllm, "sej");
    std::cout << "-----------\n >> delete matkul: sejarah\n";
    deleteMatkul(mlls, mllm, sej);

    std::cout << "-----------\n";
    printSiswaMatkul(mlls, mllm);

    std::cout << "-----------mencari siswa dengan NIM K002\n";
    deni = searchSiswa(mlls, "K001");  
    std::cout << "-----------\n >> delete siswa: "<<deni->nama<<"\n";
    deleteSiswa(mlls, deni);
    std::cout << "-----------\n";
    printSiswaMatkul(mlls, mllm);
    std::cout << "-----------\n";
    printMostLeast(mlls, mllm);
}
