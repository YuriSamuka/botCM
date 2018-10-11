#include <iostream>
#include <stdlib.h>
#include <windows.h>

int main()
{
    while (true) {
        std::system("php -f php/trader_Poloniex.php");
        Sleep(1000);
    }
}
