#ifndef _INDENTIFIER_H_
#define _INDENTIFIER_H_

#include "IIdentifier.hpp"

class Identifier : public IIdentifier
{
public:
    Identifier() = default;
	std::string GenerateNextIdentifier(const std::string &identifier) override;
private:
    char nextChar(bool& overflow, char c);
    char nextLetter(bool& overflow, char c);
    char nextNumber(bool& overflow, char c);

    bool isValidNumber(char c);
    bool isValidLetter(char c);
	bool isSkipLetter(char c);
};

#endif // _INDENTIFIER_H_
