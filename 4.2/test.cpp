#include "TableCipher.h"

using namespace std;
//Функции для более удобного написания

string enc (int k, string str)		// Функция для зашифрования
{										
										
    modAlphaCipher ex(k);				
    string stroka = ex.encrypt(str); 	
    return stroka;						
    									
}										

string dec (int k, string str)		// Функция для расшифрования
{										
										
    modAlphaCipher ex(k);				
    string stroka = ex.decrypt(str); 	
    return stroka;						
    									
}										


//Тесты ключей
SUITE (KeyTest)
{
    string test = "ROMANBULGARINFITE";
    int k;
    TEST (ValidKey) {
        CHECK_EQUAL(enc(5,test),"NAIAGFMLNOUIERBRT");
    }
    TEST(NegativeKey) {
        CHECK_THROW(enc(-8,test), cipher_error);
    }
    TEST(LargeKey) {
        CHECK_THROW(enc(100,test), cipher_error);
    }
}
//Тесты encrypt
SUITE(EncryptTest)
{
    TEST(ValidText) {
        CHECK_EQUAL(enc(5,"ROMANBULGARINFITE"),"NAIAGFMLNOUIERBRT");
    }
    TEST(LowText) {
        CHECK_EQUAL(enc(5,"romanbulgarinFITE"),"naIagFmlnouiErbrT");
    }
    TEST(SpaceText) {
        CHECK_THROW(enc(5,"ROMAN BULGARIN FITE"), cipher_error);
    }
    TEST(EmptyText) {
        CHECK_THROW(enc(5," "),cipher_error);
    }
    TEST(ValiDTextWithoutletters) {
        CHECK_THROW(enc(5,"!*><?/,.123"),cipher_error);
    }
    TEST(TextWithNumber) {
        CHECK_THROW(enc(5,"ROMANBULGARINFITE789"),cipher_error);
    }

}
//Тесты decrypt
SUITE(DecryptText)
{
    TEST(ValidTEXT) {
        CHECK_EQUAL(dec(5,"NAIAGFMLNOUIERBRT"),"ROMANBULGARINFITE");
    }
    TEST(LowTEXT) {
        CHECK_EQUAL(dec(5,"naIagFmlnouiErbrT"),"romanbulgarinFITE");
    }
    TEST(SpaceTEXT) {
        CHECK_THROW(dec(5,"NAIAG FMLNOUIE RBRT"),cipher_error);
    }
    TEST(EmptyTEXT) {
        CHECK_THROW(dec(5," "),cipher_error);
    }
    TEST(TextNumberText) {
        CHECK_THROW(dec(5,"QWER777TY"),cipher_error);
    }
    TEST(TextSymbolText) {
        CHECK_THROW(dec(5,"QWER???TY"),cipher_error);
    }

}

int main()
{
    return UnitTest::RunAllTests();
}
