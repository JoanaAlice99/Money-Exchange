#include <iostream>

using namespace std;

class Menu{
    public:
        void erro(){
            cout << "\nNota invalida";
        }
        
        void menu(){
            cout << "\n\t\t\tCAIXA DE PAGAMENTO\n\tSo sao aceites notas entre 5, 10, 20, 50, 100, 200, 500";
        }
};

class Programa{
    private:
        Menu menu;
        int notas_aceites[8] = {0,5,10,20,50,100,200,500};
        //int troco[9];

        int troco;

        int euro_2;
        int euro_1;
        int cent_50;
        int cent_20;
        int cent_10;
        int cent_5;
        int cent_2;
        int cent_1;

    public:
        void calc_troco(float valor, int pagamento){

            for (size_t i=1;i<8;i++){
                if (pagamento == notas_aceites[i]){
                    notas_aceites[0]=1;
                }
            }

            if (notas_aceites[0] != 1){
                menu.erro();
                //return 0;
            }else{
                //Total Troco
                troco=(pagamento-valor)*100;
                cout << "Troco> " << troco << endl;

                //Troco 2€
                euro_2=troco/200;
                troco=troco%200;
                cout << "2.00> " << euro_2 << "Troco> " << troco << endl;

                //Troco 1€
                euro_1=troco/100;
                troco=troco%100;
                cout << "1.00> " << euro_1 << "Troco> " << troco << endl;

                //Troco 0.50€
                cent_50=troco/50;
                troco=troco%50;
                cout << "0.50> " << cent_50 << "Troco> " << troco << endl;

                //Troco 0.20€
                cent_20=troco/20;
                troco=troco%20;
                cout << "0.20> " << cent_20 << "Troco> " << troco << endl;

                //Troco 0.10€
                cent_10=troco/10;
                troco=troco%10;
                cout << "0.10> " << cent_10 << "Troco> " << troco << endl;

                //Troco 0.05€
                cent_5=troco/5;
                troco=troco%5;
                cout << "0.5> " << cent_50 << "Troco> " << troco << endl;

                //Troco 0.02€
                cent_2=troco/2;
                troco=troco%2;
                cout << "0.02> " << cent_2 << "Troco> " << troco << endl;
                
                //Troco 0.01€
                cent_1=troco;
                cout << "0.01> " << cent_1 << "Troco> " << troco << endl;

                //return 
            }
        }
        
};

int main(int argc, char const *argv[]){

    Programa programa;
    int *esp;

    programa.calc_troco(3.71,10);

    for (size_t i=0;i<=8;i++){
        cout << *(esp+i) << endl;
    }

    system("pause");

    return 0;
}


/*

def calcchange(purchamt, payamt):
change = payamt - purchamt

cents = change*100+0.01

print cents
dollars = int(cents /100)
cents = cents %100
quarters = int(cents/25)
cents = cents %25
dimes = int(cents/10)
cents = cents %10
nickels = int(cents/5)
cents = cents %5
pennies = int(cents)

return change, dollars, quarters, dimes, nickels, pennies

*/