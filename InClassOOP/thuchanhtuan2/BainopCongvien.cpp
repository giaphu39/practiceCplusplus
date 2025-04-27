#include<iostream>

using namespace std;

#define PRICE_INTO_GATE 70000
#define PRICE_PER_GAME 20000
// trong vé nhập số lượng trò chơi
// kiểm soát số trò chơi của vé 
class Ticket
{
private:
    int iNumberOfGames;

public:
    int getNumberOfGames();
    void setNumberOfGames();
    
    void inputTicket();
    int calculatePrice();
};


class Park
{
private:
    Ticket* Tickets;
    int iNumberOFTickets;

public:
    Park(Ticket* tickets = NULL, int numberOfTickets = 0);
    Park(const Park& obj);
    Park& operator=(const Park& obj);

    void input();
    void inputTickets();
    void inputNumberOfTickets();
    void setNumberOfTickets();

    int calculateSumOfProfit();

    void PrintProfit();

    ~Park();
};


int main(){

    Park DamSenPark;
    DamSenPark.input();
    DamSenPark.PrintProfit();   

    cout <<endl;

    Park SuoiTien (DamSenPark);
    SuoiTien.PrintProfit();

    cout << endl;

    SuoiTien.input();
    DamSenPark = SuoiTien;
    DamSenPark.PrintProfit();

    return 0;
}


int Ticket::getNumberOfGames(){
    return iNumberOfGames;
}

void Ticket::setNumberOfGames(){
    while(true){
        cin >> iNumberOfGames;
        if( iNumberOfGames >= 0) break;
        
        cout <<" vui long nhap lai so tro choi cua ve: ";
    }
}

void Ticket::inputTicket(){
    while(true){
        cin >> iNumberOfGames;
        if( iNumberOfGames >= 0) break;
        
        cout <<" vui long nhap lai so tro choi cua ve: ";
    }
}

int Ticket::calculatePrice(){
    return PRICE_INTO_GATE + iNumberOfGames * PRICE_PER_GAME;
}


void Park::input(){
    inputNumberOfTickets();
    inputTickets();
}

Park::Park(Ticket* tickets , int numberOfTickets): Tickets(tickets), iNumberOFTickets(numberOfTickets) {}

Park::Park(const Park& obj){
    iNumberOFTickets = obj.iNumberOFTickets;
    Tickets = new Ticket[iNumberOFTickets];

    for(int i = 0 ; i < iNumberOFTickets ; i++){
        Tickets[i] = obj.Tickets[i];
    }
}

Park& Park::operator=(const Park& obj){
    if(this == &obj) return *this; // kiem tra tu gan

    iNumberOFTickets = obj.iNumberOFTickets;
    
    if(Tickets != NULL) delete[] Tickets;

    Tickets = new Ticket[iNumberOFTickets];

    for(int i = 0 ; i < iNumberOFTickets ; i++){
        Tickets[i] = obj.Tickets[i];
    }

    return *this;
}

void Park::inputTickets(){
    cout << " vui long nhap so tro choi tung ve: \n";
    Tickets = new Ticket[iNumberOFTickets];

    if(Tickets == NULL) cout << "khong the tao ve duoc \n";

    for(int i = 0 ; i < iNumberOFTickets ; i++){
        Tickets[i].inputTicket();
    }

}

void Park::inputNumberOfTickets(){
    while(true){
        cin >> iNumberOFTickets;
        if( iNumberOFTickets >= 0) break;
        
        cout <<" vui long nhap lai so ve: ";
    }
}

void Park::setNumberOfTickets(){
    cout << "vui long nhap so ve muon doi: ";

    while(true){
        cin >> iNumberOFTickets;
        if( iNumberOFTickets >= 0) break;
        
        cout <<" vui long nhap lai so ve: ";
    }
}

int Park::calculateSumOfProfit(){
    int sum = 0;

    for(int i = 0 ; i < iNumberOFTickets ; i++){
        sum += Tickets[i].calculatePrice();
    }

    return sum;
}

void Park::PrintProfit(){
    cout << " Doanh Thu trong ngay hom nay la: ";
    cout << calculateSumOfProfit();
}

Park::~Park(){
    if(Tickets != NULL) delete[] Tickets;
}