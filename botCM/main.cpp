#include <iostream>
#include <stdlib.h>
#include <windows.h>

int main()
{
    long timer = 0;
    while (true) {
        if (timer == 300000) {
            timer = 0;
        }

        std::system("php -f php/Poloniex_get_tickers.php");
        timer += 1000; //2 minutos
        Sleep(1000); //2 minutos
    }
}
