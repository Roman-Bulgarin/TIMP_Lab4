/** 
 * @file modAlphaCipher.h
 * @author Булгарин Р.Р.
 * @version 1.0
 * @date 25.03.2024
 * @copyright ИБСТ ПГУ
 * @brief Заголовочный файл для модуля modAlphaCipher
 * @brief Описание класса modAlphaCipher
 */
#pragma once
#include <vector>
#include <string>
#include <map>
#include <locale>
#include <codecvt>
using namespace std;
/**  @brief  Класс, который реализует шифрование методом "Гронсвельда"
* @warning Работает только с русскоязычными сообщениями
* */
class modAlphaCipher
{
private:
    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
    /// @brief  Используемый алфавит по порядку для сообщений, которые шифруются методом "Гронсвельда"
    wstring numAlpha =L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; //алфавит по порядку
    /// @brief  Ассоциативный массив "номер по символу"
    map <wchar_t,int> alphaNum; //ассоциативный массив "номер по символу"
    /// @brief  Атрибут, хранящий в себе ключ для шифрования и расшифрования
    vector <int> key; //ключ
    /** @brief  Преобразование строки в вектор
     * @details В вектор записываются числа, которые являются индексами алфавита "numAlpha",применяемый для строки, 
     * которая поступила на вход.
     * @code
     *  vector<int> result;
     *   for(auto c:s) {
     *       result.push_back(alphaNum[c]);
     *   }
     * @endcode
     * @return std::vector <int>, в котором хранятся индексы букв из алфавита "numAlpha"
     */
    vector<int> convert(const wstring& s); //преобразование строка-вектор
    /** @brief Преобразование вектора в строку
     * @details В переменную типа "wstring" с именем "result" записывается строка согласно индексам каждой буквы алфавита "numAlpha".
     * Индексы хранятся в векторе типа "int", который поступил на вход.
     * @code
     *  wstring result;
     *   for(auto i:v) {
     *       result.push_back(numAlpha[i]);
     *   }
     * @endcode
     * @return типа "wstring"
     */
    wstring convert(const vector<int>& v); //преобразование вектор-строка
    /** @brief  Валидация ключа
     * @details Сначала введённый ключ проверяется на пустоту при помощи обычного условия. Если ключ не пустой, то
     * он проверяется на наличие недопустимых символов. 
     * @warning Строчные буквы алфавита переводятся в прописные.
     * @param std::wstring s - ключ, который нужно проверить на наличие ошибок, в виде строки
     * @throw cipher_error, если ключ пустой или в нём присутствуют недопустимые символы
     * @return Ключ в виде строки типа "wstring", который успешно прошёл валидацию
     */
    wstring getValidKey(const wstring & s);
    /** @brief Валидация текста при шифровании или расшифровании
     * @details Сначала введённый текст проверяется на пустоту при помощи обычного условия. Если текст не пустой, то
     * он проверяется на наличие недопустимых символов.
     * @warning Строчные буквы алфавита переводятся в прописные.
     * @param std::wstring s - строка текста для шифрования или расшифрования, которая проверяется на наличие ошибок
     * @throw cipher_error, если текст является пустым или в нём присутствуют недопустимые символы
     * @return Текст в виде строки типа "wstring", который успешно прошёл валидацию
     */
    wstring getValidOpenText(const wstring & s);
    wstring getValidCipherText(const wstring & s);
public:
/// @brief Конструктор без параметров
    modAlphaCipher()=delete; //запретим конструктор без параметров
    /** @brief  Конструктор для ключа
      *    @details Цикл for построен по строке-алфавиту и на каждом шаге добавляет в ассоциативный массив
      *  символ и его номер.
      *  @code
      *     for (unsigned i=0; i<numAlpha.size(); i++) {
      *          alphaNum[numAlpha[i]]=i;
      *      }
      *  @endcode
      *  @param std::wstring - ключ в виде строки
      */ 
    modAlphaCipher(const wstring& skey); //конструктор для установки ключа
    /**
     * @brief Метод для зашифрования
     */
    wstring encrypt(const wstring& open_text); //зашифрование
    /**
     * @brief Метод для расшифрования
     */
    wstring decrypt(const wstring& cipher_text);//расшифрование
};
/// @brief Класс для обработки исключений
class cipher_error: public invalid_argument
{
public:
    explicit cipher_error (const string& what_arg):
        invalid_argument(what_arg) {}
    explicit cipher_error (const char* what_arg):
        invalid_argument(what_arg) {}
};
