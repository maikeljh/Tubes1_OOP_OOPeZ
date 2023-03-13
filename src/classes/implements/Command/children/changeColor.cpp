#include "../../../headers/Command/children/changeColor.hpp"

ChangeColor::ChangeColor(){

}

void ChangeColor::executeActionUNO(UnoGame& UnoGame){
    cout << "\nSilakan pilih warna untuk diganti." << endl;
    cout << "1. Red" << endl;
    cout << "2. Green" << endl;
    cout << "3. Blue" << endl;
    cout << "4. Yellow" << endl;
    int colorInput;
    cin >> colorInput;
    
    TableCard<UnoCard>& tableCards = UnoGame.getTableCard();
    UnoCard& topCard = tableCards.getTop();

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