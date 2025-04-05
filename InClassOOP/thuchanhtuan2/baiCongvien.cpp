#include<iostream>

using namespace std;

#define priceIntoGate 70000
#define pricePerGame 20000
// trong vé nhập số lượng trò chơi
// kiểm soát số trò chơi của vé 
class  Ticket
{
private:
    int numberOfGames;

public:
    int getNumberOfGames();
    void setNumberOfGames();
};


class Park
{
private:
    Ticket* Tickets;
    int numberOFTickets;

public:
// hàm khởi tạo chạy for nhập từng vé
    Park();
    void setNumberOfTickets();
    void setTickets();
    int calculateSumOfProfit();
    void PrintProfit();
};


int main(){

    Park DamSenPark;
    DamSenPark.PrintProfit();   

    return 0;
}


int Ticket::getNumberOfGames(){
    return numberOfGames;
}

void Ticket::setNumberOfGames(){
    while(true){
        cin >> numberOfGames;
        if( numberOfGames >= 0) break;
        
        cout <<" vui long nhap lai so tro choi cua ve: ";
    }
}

Park::Park(){
    setNumberOfTickets();
    setTickets();
}

void Park::setNumberOfTickets(){
    cout << "vui long nhap so ve: ";

    while(true){
        cin >> numberOFTickets;
        if( numberOFTickets >= 0) break;
        
        cout <<" vui long nhap lai so ve: ";
    }
}

void Park::setTickets(){
    cout << " vui long nhap so tro choi tung ve: \n";
    Tickets = new Ticket[numberOFTickets];

    if(Tickets == NULL) cout << "khong the tao ve duoc \n";

    for(int i = 0 ; i < numberOFTickets ; i++){
        Tickets[i].setNumberOfGames();
    }

}


int Park::calculateSumOfProfit(){
    int sum = 0;

    for(int i = 0 ; i < numberOFTickets ; i++){
        sum += priceIntoGate + Tickets[i].getNumberOfGames() * pricePerGame;
    }

    return sum;
}

void Park::PrintProfit(){
    cout << " Doanh Thu trong ngay hom nay la: ";
    cout << calculateSumOfProfit();
}