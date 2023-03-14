#include "../../../headers/Command/children/changeColor.hpp"
#include <limits>

ChangeColor::ChangeColor(){}

void ChangeColor::executeActionUNO(UnoGame& UnoGame){
    cout << "\nSilakan pilih warna untuk diganti." << endl;
    cout << "1. Red" << endl;
    cout << "2. Green" << endl;
    cout << "3. Blue" << endl;
    cout << "4. Yellow" << endl;

    int colorInput;

    do {
        try{
            cout << "Pilihan : ";
            cin >> colorInput;
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                throw InputActionInvalidExc();
            }
            if(colorInput < 1 || colorInput > 4){
                throw InputNumberInvalidExc();
            }
        } catch(GameException& err){
            cout << err.what() << endl;
        }
    } while(colorInput < 1 || colorInput > 4);
    
    TableCard<UnoCard>& tableCards = UnoGame.getTableCard();
    UnoCard topCard = tableCards.pop();

    if (colorInput<1 || colorInput>4){
        throw InputNumberInvalidExc();
    } else {
        if (colorInput==1){
            topCard.setColor("Red");
        } else if (colorInput==2){
            topCard.setColor("Green");
        } else if (colorInput==3){
            topCard.setColor("Blue");
        } else {
            // colorInput==4
            topCard.setColor("Yellow");
        }
    }
}