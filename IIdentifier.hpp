#ifndef _I_IDENTIFIER_HPP_
#define _I_IDENTIFIER_HPP_

#include <string>
/// <Summary>
/// Функция генерирует новый идентификатор на основе значения переданного идентификатора
/// </Summary>
/// <param name="identifier">Идентификатор последовательности</param>
/// <returns>
/// Следующий идентификатор
/// </returns>
class IIdentifier
{
public:
virtual std::string GenerateNextIdentifier(const std::string &identifier) = 0;
};
#endif // _I_IDNTIFIER_HPP_
