#include "huffman.h"

Huffman::Huffman(const Huffman* x){
    frequency = x->frequency;
    data = x->data;
}

bool Huffman::operator==(const Tipo* t) const{
    const Huffman* x = dynamic_cast<const Huffman*>(t);

    if(!x)
        return false;

    if(frequency == x->frequency && data == x->data)
        return true;

    else
        return false;
}

bool Huffman::checkKey(const Tipo* x) const{
    const Huffman* p = dynamic_cast<const Huffman*>(x);
    if(p && p->data == data)
        return  true;
    else
        return false;
}

Huffman* Huffman::copia() const{
    return new Huffman(frequency, data);
}

Huffman* Huffman::operator+(const Tipo* x) const{
    const Huffman* t = dynamic_cast<const Huffman*>(x);

    if(t)
        return new Huffman(frequency + t->frequency, data + t->data);
    else
        return nullptr;

}

Huffman* Huffman::operator-(const Tipo*) const{
    throw new OperationNotAllowed();
}

Huffman* Huffman::operator *(const Tipo*) const{
    throw new OperationNotAllowed();
}

Huffman* Huffman::operator /(const Tipo*) const{
    throw new OperationNotAllowed();
}

Huffman& Huffman::operator =(const Tipo& t){
    const Huffman& p = dynamic_cast<const Huffman&>(t);
    if(this != &p){
        // Distruzione profonda dei campi
        frequency = p.frequency;
        data = p.data;
    }
    return *this;
}

bool Huffman::operator <(const Tipo* t) const{
    const Huffman* p = dynamic_cast<const Huffman*>(t);
    if(t && p){
        if(frequency < p->frequency)
            return true;
    }
    return false;
}

void Huffman::print(std::ostream &os) const{
    os << to_string();
}

std::ostream& operator<<(std::ostream& os, const Huffman* t){
    if(t!=nullptr){
        t->print(os);
    }
    return os;
}

std::string Huffman::getData() const{
    return data;
}

int Huffman::getFrequency() const{
    return this->frequency;
}

std::string Huffman::to_string() const{
    return data + "|" + std::to_string(frequency);
}

bool Huffman::operator>(const Tipo* t) const{
    const Huffman* p = dynamic_cast<const Huffman*>(t);
    if(t && p){
        if(frequency > p->frequency)
            return true;
    }
    return false;
}
bool Huffman::operator<=(const Tipo* t) const{
    const Huffman* p = dynamic_cast<const Huffman*>(t);
    if(t && p){
        if(frequency <= p->frequency)
            return true;
    }
    return false;
}
bool Huffman::operator>=(const Tipo* t) const{
    const Huffman* p = dynamic_cast<const Huffman*>(t);
    if(t){
        if(frequency >= p->frequency)
            return true;
    }
    return false;
}
