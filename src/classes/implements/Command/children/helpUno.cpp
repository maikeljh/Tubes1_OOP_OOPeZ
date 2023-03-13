#include "../../../headers/Command/children/helpUno.hpp"

HelpUno::HelpUno() : Command() {}

void HelpUno::executeActionUNO(UnoGame &unogame) {
    cout << "Berikut adalah command-command yang dapat digunakan oleh pemain: " << endl;
    cout << "1. DRAW : command ini digunakan untuk mengambil kartu dari deck kartu" << endl;
    cout << "2. PASS : command ini digunakan apabila pemain memutuskan untuk tidak menaruh kartu" << endl;
    cout << "3. SAYUNO : command ini digunakan apabila pemain hanya memiliki 1 kartu saja (penjelasan lebih lanjut ada di rules game UNO)" << endl;
    cout << "4. PICKCARD : command ini digunakan untuk mengambil kartu dari deck kartu" << endl;
    cout << "5. CHECKCARD : command ini digunakan untuk mengecek kartu apa saja yang dimiliki pemain" << endl;
}