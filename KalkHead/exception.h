#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <string.h>


using std::string;



class Exception{
private:
    string code;
    string message;
protected:
    Exception(string c, string m):code(c), message(m){}
public:
    string getMessage() const{return message;}
};

class DeleteNotFound: public Exception{
public:
    DeleteNotFound(string c = "Delete", string m = "Delete Not Found"):Exception(c, m){}
};

class DivideByZero: public Exception{
public:
    DivideByZero(string c = "DV0", string m = "Division By Zero"):Exception(c, m){}
};

class NullRoot: public Exception{
public:
    NullRoot(string c = "nullptr", string m = "Root pointer is nullptr"):Exception(c, m){}
};

class InteroOverflow: public Exception{
public:
    InteroOverflow(string c = "Intero_overflow", string m = "Intero in overflow"):Exception(c, m){}
};

class OperationNotAllowed: public Exception{
public:
    OperationNotAllowed(string c = "NotAllowed", string m = "Operazione non consentita"):Exception(c, m){}
};

class BadDynamicCast: public Exception{
public:
    BadDynamicCast(string c = "DynamicCastFail", string m = "Dynamic cast non riuscito"):Exception(c, m){}
};

class BadValueConstructor: public Exception{
public:
    BadValueConstructor(string c = "BadValueConstructor", string m = "Bad value on object constructor"):Exception(c, m){}
};

class BadTypeValue: public Exception{
public:
    BadTypeValue(string c = "BadTypeValue", string m = "Bad type of value"):Exception(c, m){}
};

#endif // EXCEPTION_H
