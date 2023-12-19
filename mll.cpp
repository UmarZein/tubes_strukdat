#include "mll.h"

Matkul *createMatkul(std::string nama, std::string kode, int sks, int tingkat) {
    Matkul *m = new Matkul;
    m->nama = nama; 
    m->kode = kode; 
    m->sks = sks;
    m->tingkat = tingkat;
    m->next = nullptr;
    return m;
}
Koneksi *createKoneksi(Matkul *mk) {
    Koneksi *k = new Koneksi; 
    k->mk = mk; 
    k->next = nullptr;
    return k;
}
Siswa *createSiswa(std::string nama, std::string nim, int tingkat) {
    Siswa *s = new Siswa; ///
    s->nama = nama;
    s->nim = nim;
    s->tingkat = tingkat;
    s->koneksi = nullptr;
    s->next = nullptr;
    return s;
}
void initMLLSiswa(MLLSiswa &mll){
    mll.first = nullptr;
}
void initMLLMatkul(MLLMatkul &mll){
    mll.first = nullptr;
}

void insertFirstMatkul(MLLMatkul &mll, std::string nama, std::string kode, int sks, int tingkat){
    Matkul *x = createMatkul(nama, kode, sks, tingkat);
    x->next = mll.first;
    mll.first = x;
}
void insertFirstSiswa(MLLSiswa &mll, std::string nama, std::string nim, int tingkat){
    Siswa *x = createSiswa(nama, nim, tingkat);
    x->next = mll.first;
    mll.first = x;
}
void insertLastMatkul(MLLMatkul &mll, std::string nama, std::string kode, int sks, int tingkat){
    Matkul *m = mll.first;
    Matkul *x = createMatkul(nama, kode, sks, tingkat);
    if (m==nullptr){
        mll.first = x;
    } else {
        while (m->next!=nullptr){
            m=m->next;
        }
        m->next = x;
    }
}
void insertLastSiswa(MLLSiswa &mll, std::string nama, std::string nim, int tingkat){
    Siswa *m = mll.first;
    Siswa *x = createSiswa(nama, nim, tingkat);
    if (m==nullptr){
        mll.first = x;
    } else {
        while (m->next!=nullptr){
            m=m->next;
        }
        m->next = x;
    }
}
void connect(Siswa *s, Matkul* m){
    if (m->tingkat>s->tingkat){
        std::cout << "tingkat siswa dibawah tingkat mata pelajaran\n";
        return;
    } else {
        Koneksi *k = s->koneksi;
        int total_sks = 0;
        if (k==nullptr){
            s->koneksi = createKoneksi(m);
        } if (k!=nullptr) {
            while (k->next!=nullptr){
                k=k->next;
                total_sks += k->mk->sks;
            }
            if (total_sks>24){
                std::cout << "terlalu banyak sks\n";
            } else {
                k->next = createKoneksi(m);
            }
        }
    }
}
bool connected(Siswa *s, Matkul *m){
    if (s==nullptr){return false;}
    Koneksi *k = s->koneksi;
    while (k!=nullptr){
        if (k->mk==m){return true;}
        k=k->next;
    }
    return false;
}

Matkul *searchMatkul(MLLMatkul mll, std::string kode){
    Matkul *m = mll.first;
    while (m!=nullptr){
        if (m->kode==kode){
            return m;
        }
        m = m->next;
    }
    return nullptr;
}
Siswa *searchSiswa(MLLSiswa mll, std::string nim){
    Siswa *s = mll.first;
    while (s!=nullptr){
        if (s->nim==nim){
            return s;
        }
        s = s->next;
    }
    return nullptr;
}

void deleteSiswa(MLLSiswa &mll, Siswa *s){
    Siswa* p = mll.first;
    if (p!=nullptr) {
        while (p->next!=nullptr){
            if (p->next==s){
                p->next=s->next;
            } else {
                p=p->next;
            }
        }
        if (mll.first==s){
            mll.first = mll.first->next;
        }
    }
}
void deleteMatkul(MLLSiswa &mlls, MLLMatkul &mllm, Matkul *m){
    Siswa *s = mlls.first;
    Koneksi *k;
    while (s!=nullptr){
        k=s->koneksi;
        
        if (k!=nullptr){
            while (k->next!=nullptr){
                if (k->next->mk==m){
                    k->next=k->next->next;
                } else {
                    k=k->next;
                }
            }
            if (s->koneksi->mk==m){
                s->koneksi=s->koneksi->next;
            }
        }
        s=s->next;
    }

    Matkul *p = mllm.first;
    if (p!=nullptr) {
        while (p->next!=nullptr){
            if (p->next==m){
                p->next=m->next;
            } else {
                p=p->next;
            }
        }
        if (mllm.first==m){
            mllm.first = mllm.first->next;
        }
    }
}

void printSiswa(Siswa *s){
    std::cout << s->nama 
        << ':' << s->nim 
        << '\n';;
}
void printMatkul(Matkul *m){
    std::cout << m->nama 
        << ':' << m->kode
        << ':' << m->sks
        << ':' << m->tingkat
        << '\n';
}
void printMLLSiswa(MLLSiswa mll){
    Siswa *s = mll.first;
    while (s!=nullptr){
        printSiswa(s);
        s=s->next;
    }
    std::cout << '\n';
}
void printMLLMatkul(MLLMatkul mll){
    Matkul *m = mll.first;
    while (m!=nullptr){
        printMatkul(m);
        m=m->next;
    }
    std::cout << '\n';
}
void printMatkulSiswa(MLLSiswa mlls, MLLMatkul mllm){
    Matkul *m = mllm.first;
    while (m!=nullptr){
        printWithMatkul(mlls, mllm, m);
        m=m->next;
    }
}
void printSiswaMatkul(MLLSiswa mlls, MLLMatkul mllm){
    Siswa *s = mlls.first;
    while (s!=nullptr){
        printWithSiswa(mlls, mllm, s);
        s=s->next;
    }
}
int countParticipant(MLLSiswa mlls, MLLMatkul mllm, Matkul *m){
    int n = 0;
    Siswa *s = mlls.first;
    while (s != nullptr){
        if (connected(s, m)){
            n++;
        }
        s=s->next;
    }
    return n;
}
void printMostLeast(MLLSiswa mlls, MLLMatkul mllm){
    if (mllm.first==nullptr){return;}
    Matkul *most = mllm.first;
    Matkul *least = mllm.first;
    Matkul *m = mllm.first->next;
    int count;
    while (m!=nullptr){
        count = countParticipant(mlls, mllm, m); 
        if (count < countParticipant(mlls, mllm, least)){
            least = m;
        } else if (count > countParticipant(mlls, mllm, most)){
            most = m;
        }
        m=m->next;
    }
    std::cout << "most ("<<countParticipant(mlls, mllm, most)<<" participants): "; printMatkul(most);
    std::cout << "least ("<<countParticipant(mlls, mllm, least)<<" participants): "; printMatkul(least);
}
void printWithSiswa(MLLSiswa mlls, MLLMatkul mllm, Siswa *s){
    printSiswa(s);

    Koneksi *k=s->koneksi;
    while (k!=nullptr){
        std::cout << '\t';
        printMatkul(k->mk);
        k=k->next;
    }
}
void printWithMatkul(MLLSiswa mlls, MLLMatkul mllm, Matkul *m){
    printMatkul(m);

    Siswa *s=mlls.first;
    while (s!=nullptr){
        if (connected(s, m)){
            std::cout << '\t';
            printSiswa(s);
        }
        s=s->next;
    }
}
