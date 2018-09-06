#include "intero.h"

Intero::Intero(const Intero* t){
    dato = t->dato;
}

Intero::~Intero(){}

bool Intero::operator==(const Tipo* t) const{
    const Intero* tmp = dynamic_cast<const Intero*>(t);

    if(!tmp)
        return  false;
    if(tmp->dato == dato)
        return true;
    else
        return false;
}

Intero* Intero::copia() const{
    // Valgrind segnala leak con la new
    return new Intero(dato);
}

Intero* Intero::operator+(const Tipo* t) const{
    const Intero *p = dynamic_cast<const Intero*>(t);

    if(p)
        return new Intero(this->dato + p->dato);
    else
        return nullptr;
}


Intero* Intero::operator-(const Tipo* t) const{
    const Intero* p = dynamic_cast<const Intero*>(t);
    if(p){
        return new Intero(dato - p->dato);
    }
    else{
        return nullptr;
    }
}

Intero* Intero::operator*(const Tipo* t) const{
    const Intero *p = dynamic_cast<const Intero*>(t);
    if(p){
        return new Intero(dato * p->dato);
    }
    else{
        return nullptr;
    }
}

// Eccezione divide by 0 da gestire
Intero* Intero::operator/(const Tipo* t) const{
    const Intero* p = dynamic_cast<const Intero*>(t);
    if(p){
        if(p->dato == 0)
            throw new DivideByZero("Intero::operator/");

        return new Intero(dato / p->dato);
    }
    else{
        return nullptr;
    }
}

Intero& Intero::operator=(const Tipo& t){
    const Intero& p = dynamic_cast<const Intero&>(t);

    if(this != &p){
        dato = p.dato;
    }

    return *this;
}

bool Intero::operator<(const Tipo* i) const{
    const Intero* p = dynamic_cast<const Intero*>(i);
    if(p && this->dato < p->dato){
        return true;
    }
    else{
        return false;
    }
}

bool Intero::operator>(const Tipo* i) const{
    const Intero* p = dynamic_cast<const Intero*>(i);
    if(p && this->dato > p->dato){
        return true;
    }
    else{
        return false;
    }
}


bool Intero::operator<=(const Tipo* t) const{
    const Intero* p = dynamic_cast<const Intero*>(t);

    if(p && this->dato <= p->dato)
        return true;
    else
        return false;
}


bool Intero::operator>=(const Tipo* t) const{
    const Intero* p = dynamic_cast<const Intero*>(t);
    if(p && this->dato >= p->dato)
        return true;
    else
        return false;
}

void Intero::print(std::ostream& os) const{
    os << to_string();
}

std::ostream& operator<<(std::ostream& os, const Intero* t){
    t->print(os);
    return os;
}

std::string Intero::to_string() const{
    return std::to_string(dato);
}

