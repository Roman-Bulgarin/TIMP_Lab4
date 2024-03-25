/** 
 * @file TableCipher.h
 * @author Булгарин Р.Р.
 * @version 1.0
 * @date 25.03.2024
 * @copyright ИБСТ ПГУ
 * @brief Заголовочный файл для модуля TableCipher
 * @brief Описание класса modAlphaCipher
 */
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <locale>
#include <codecvt>
#include <algorithm>
#include <UnitTest++/UnitTest++.h>
using namespace std;
/**
* @brief Класс для шифрования и расшифрования текста с помощью алгоритма модифицированного алфавитного шифра
*
* @brief Данный класс предоставляет методы для шифрования и расшифрования текста с помощью алгоритма модифицированного алфавитного шифра.
* @brief Класс имеет встроенный алфавит, состоящий из заглавных букв русского алфавита.
* @brief Ключ шифрования задается при создании объекта класса.
*/
class modAlphaCipher
{
private:
    int newkey;
    string getValidOpenText(const string & s);
public:
    modAlphaCipher()=delete;
    modAlphaCipher(const int& key) :newkey(key) {}; 
    /// Метод для шифрования текста
    /// @param open_text - открытый текст
    /// @return Зашифрованный текст
    string encrypt(const string& open_st); 
    
    /// Метод для расшифрования текста
    /// @param cipher_text - зашифрованный текст
    /// @return Расшифрованный текст
    string decrypt(const string& cipher_st);
};
/// @brief Класс для обработки исключений
class cipher_error: public invalid_argument {
public:
	explicit cipher_error (const string& what_arg):
		invalid_argument(what_arg) {}
	explicit cipher_error (const char* what_arg):
		invalid_argument(what_arg) {}
};
