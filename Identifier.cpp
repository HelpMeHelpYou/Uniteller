#include "Identifier.hpp"

#include <cstddef>

std::string Identifier::GenerateNextIdentifier(const std::string &identifier)
{
    bool overflow;
    std::string identifierCopy = identifier;

    for ( int i = identifierCopy.length()-1; ; i--)
    {
        if (i < 0)
        {
            identifierCopy.insert(0,"A1-");
            break;
        }

        char c = identifierCopy[i];
        if (c  == '-')
            continue;
        else
            overflow = false;


        identifierCopy.replace(i,1,1,nextChar(overflow,c));
        if (!overflow)
            break;
    }
    return identifierCopy;
}

char Identifier::nextChar(bool& overflow, char c)
{
    if ( isValidNumber(c) )
	{
		return	nextNumber(overflow, c);
	}
    else if (isValidLetter(c))
	{
		return nextLetter(overflow, c);
    }
}

bool Identifier::isSkipLetter(char c)
{
    return c == 'D' ||
           c == 'F' ||
           c == 'G' ||
           c == 'J' ||
           c == 'M' ||
           c == 'Q' ||
           c == 'V';
}

bool Identifier::isValidNumber(char c)
{
    return ('1' <= c) && (c <= '9');
}

bool Identifier::isValidLetter(char c)
{
	return ('A' <= c) && 
        (c <= 'Z') && !isSkipLetter(c);
}

char Identifier::nextNumber(bool& overflow, char c)
{
	if ( c == '9')
	{
		overflow = true;
		return '1';
	}
	else
	{
		overflow = false;
        return ++c;
	}
}

char Identifier::nextLetter(bool& overflow, char c)
{
    if (c == 'Z')
    {
        overflow = true;
        return 'A';
    }
    else
    {
        c++;
        if  (isSkipLetter(c))
        {
            c = nextLetter(overflow,c);
        }
    }

    return c;
}
