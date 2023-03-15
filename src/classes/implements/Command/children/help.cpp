#include "../../../headers/Command/children/help.hpp"

/* Ctor */
Help::Help(){}

/* Print all available commands to use */
void Help::executeAction(CandyGame &candyGame) {
    cout << "\nBerikut adalah beberapa command yang dapat dilakukan pemain" << endl;
    cout << "1. NEXT : command ini tidak melakukan apa-apa dan giliran diteruskan ke pemain selanjutnya" << endl;
    cout << "2. DOUBLE : command ini digunakan untuk membuat poin hadiah berjumlah 2x dari sebelumnya" << endl;
    cout << "3. CHECKCARD : command ini digunakan untuk melihat kartu yang dimiliki pemain" << endl;
    cout << "4. CHECKTABLECARD : command ini digunakan untuk melihat kartu yang terdapat pada table" << endl;
    cout << "5. HALF : command ini digunakan untuk membuat poin hadiah berjumlah 0.5x dari sebelumnya" << endl;
    cout << "6. RE-ROLL : command ini hanya dapat dilakukan apabila pemain memiliki Re-Roll Card, dimana command ini akan membuang 2 kartu dari main deck pemain dan mengambil ulang 2 kartu dari deck kartu" << endl;
    cout << "7. QUADRUPLE : command ini hanya dapat digunakan apabila pemain memiliki Quadruple Card, dimana command ini akan membuat poin hadiah berjumlah 4x dari sebelumnya" << endl;
    cout << "8. QUARTET : command ini hanya dapat digunakan apabila pemain memiliki Quarter Card, dimana command ini akan membuat poin hadiah berjumlah 0.25x dari sebelumnya" << endl;
    cout << "9. REVERSE : command ini hanya dapat digunakan apabila pemain memiliki Reverse Card, dimana command ini akan memutar arah giliran pada giliran selanjutnya" << endl;
    cout << "10. SWAPCARD : command ini hanya dapat digunakan apabila pemain memiliki SwapCard Card, dimana command ini akan menukar 1 kartu main deck pemilik lain dengan 1 kartu main deck milik pemain lain. Tidak boleh ditukar dengan kartu main deck diri sendiri" << endl;
    cout << "11. SWITCH : command ini hanya dapat digunakan apabila pemain memiliki Switch Card, dimana command ini akan menukarkan 2 kartu main deck milik diri sendiri dengan 2 kartu main deck milik pemain lain. Harus menukar milik diri sendiri dengan pemain lain" << endl;
    cout << "12. ABILITYLESS : command ini hanya dapat digunakan apabila pemain memiliki Abilityless Card, dimana command ini akan mematikan kartu ability pemain lain\n" << endl;
}