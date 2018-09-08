#ifndef INTERO_H
#define INTERO_H
#include "tipo.h"

class Intero: public Tipo{

private:
    int dato;

public:
    ~Intero();
    explicit Intero(const int t = 0):dato(t){}
    explicit Intero(const Intero*);

    Intero* operator+(const Tipo*) const;
    Intero* operator-(const Tipo*) const;
    Intero* operator*(const Tipo*) const;
    Intero* operator/(const Tipo*) const;
    Intero* copia() const;
    Intero& operator=(const Tipo&);
    bool operator ==(const Tipo*) const;
    bool operator>(const Tipo*) const;
    bool operator<(const Tipo*) const;
    bool operator<=(const Tipo*) const;
    bool operator >=(const Tipo*) const;

    std::string to_string() const;
    void print(std::ostream &) const;

    friend std::ostream& operator<<(std::ostream&, const Intero*);
};

#endif // INTERO_H
