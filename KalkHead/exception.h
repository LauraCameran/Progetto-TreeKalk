#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <string>

class Exception{
private:
    std::string code;
    std::string message;

protected:
    Exception(std::string c, std::string m):code(c), message(m){}

public:
    std::string getMessage() const{return message;}
};


class NodeNotFound: public Exception{
public:
    NodeNotFound(std::string c = "NodeNotFound", std::string m = "Node Not Found"):Exception(c, m){}
};

class DivideByZero: public Exception{
public:
    DivideByZero(std::string c = "DV0", std::string m = "Division By Zero"):Exception(c, m){}
};

class NullRoot: public Exception{
public:
    NullRoot(std::string c = "nullptr", std::string m = "Root pointer is nullptr"):Exception(c, m){}
};

class InteroOverflow: public Exception{
public:
    InteroOverflow(std::string c = "Intero_overflow", std::string m = "Intero in overflow"):Exception(c, m){}
};

class OperationNotAllowed: public Exception{
public:
    OperationNotAllowed(std::string c = "NotAllowed", std::string m = "Operazione non consentita"):Exception(c, m){}
};

class BadDynamicCast: public Exception{
public:
    BadDynamicCast(std::string c = "DynamicCastFail", std::string m = "Dynamic cast non riuscito"):Exception(c, m){}
};

class BadValueConstructor: public Exception{
public:
    BadValueConstructor(std::string c = "BadValueConstructor", std::string m = "Bad value on object constructor"):Exception(c, m){}
};

class BadTypeValue: public Exception{
public:
    BadTypeValue(std::string c = "BadTypeValue", std::string m = "Bad type of value"):Exception(c, m){}
};

#endif // EXCEPTION_H
