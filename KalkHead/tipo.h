#ifndef TIPO_H
#define TIPO_H
#include <iostream>
#include "exception.h"

class Tipo{
public:

    virtual Tipo* operator +(const Tipo*) const =0;
    virtual Tipo* operator -(const Tipo*) const =0;
    virtual Tipo* operator *(const Tipo*) const =0;
    virtual Tipo* operator /(const Tipo*) const =0;

    virtual Tipo& operator =(const Tipo&) =0;

    virtual bool operator ==(const Tipo*) const =0;
    virtual bool operator <(const Tipo*) const =0;
    virtual bool operator >(const Tipo*) const =0;
    virtual bool operator <=(const Tipo*) const =0;
    virtual bool operator >=(const Tipo*) const =0;

    virtual void print(std::ostream&) const =0;

    virtual ~Tipo(){}
    virtual std::string to_string() const =0;
    virtual Tipo* copia() const =0;
    friend std::ostream& operator<<(std::ostream& os, const Tipo* x){x->print(os); return os; }
};


#endif // TIPO_H
