#include <iostream>
#include <memory>
#include "Identifier.hpp"
#include "assert.h"

int main()
{
    std::auto_ptr<IIdentifier> indentifier(new Identifier);

    assert(indentifier->GenerateNextIdentifier("A1")=="A2");
    assert(indentifier->GenerateNextIdentifier("A9")=="B1");
    assert(indentifier->GenerateNextIdentifier("C9")=="E1");
    assert(indentifier->GenerateNextIdentifier("Z9")=="A1-A1");
    assert(indentifier->GenerateNextIdentifier("A1-Z9")=="A2-A1");
    assert(indentifier->GenerateNextIdentifier("Z9-Z9")=="A1-A1-A1");

    return 0;

}
