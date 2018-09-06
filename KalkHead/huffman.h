#ifndef HUFFMAN_H
#define HUFFMAN_H
#include "tipo.h"
#include "exception.h"
#include <string>

class Huffman: public Tipo{
private:
    int frequency;
    std::string data;

public:

    Huffman(const int& f = 0, const std::string& s = ""):frequency(f),data(s){}
    Huffman(const Huffman*);
    ~Huffman(){}

    // Metodi get
    std::string getData() const;
    int getFrequency() const;

    // Metodi virtuali
    Huffman* operator+(const Tipo*) const;
    Huffman& operator=(const Tipo&);
    Huffman* copia() const;

    bool checkKey(const Tipo*) const;
    bool operator ==(const Tipo*) const;
    bool operator<(const Tipo*) const;
    bool operator>(const Tipo*) const;
    bool operator<=(const Tipo*) const;
    bool operator>=(const Tipo*) const;

    void print(std::ostream &) const;

    friend std::ostream& operator<<(std::ostream& os, const Huffman* x);
    std::string to_string() const;

    // Operazioni non consentite in Huffman
    Huffman* operator-(const Tipo*) const;
    Huffman* operator*(const Tipo*) const;
    Huffman* operator/(const Tipo*) const;


};

#endif  // HUFFMAN_H
