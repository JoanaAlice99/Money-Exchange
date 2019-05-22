#include <iostream>

using namespace std;

int main(int argc, char const *argv[]){

    float valor;
    int pagamento;
    float troco;
    int centimos;

    int euro_2;
    int euro_1;
    int cent_50;
    int cent_20;
    int cent_10;
    int cent_5;
    int cent_2;
    int cent_1;

    cout << "Valor> "; cin >> valor;
    cout << "Pagamento> "; cin >> pagamento;

    troco = pagamento-valor;
    cout << "Troco> " << troco << endl;

    centimos = troco*100+0.01;

    //Troco 2€
    euro_2=centimos/200;
    centimos=centimos%200;
    if (euro_2!=0){
        cout << euro_2 << " moedas de 2 euros " << endl;
    }

    //Troco 1€
    euro_1=centimos/100;
    centimos=centimos%100;
    if (euro_1!=0){
        cout << euro_1 << " moedas de 1 euro" << endl;
    }

    //Troco 0.50€
    cent_50=centimos/50;
    centimos=centimos%50;
    if (cent_50!=0){
        cout << cent_50 << " moedas de 50 centimos" << endl;
    }

    //Troco 0.20€
    cent_20=centimos/20;
    centimos=centimos%20;
    if (cent_20!=0){
        cout << cent_20 << " moedas de 20 centimos" << endl;
    }

    //Troco 0.10€
    cent_10=centimos/10;
    centimos=centimos%10;
    if (cent_10!=0){
        cout << cent_10 << " moedas de 10 centimos" << endl;
    }

    //Troco 0.05€
    cent_5=centimos/5;
    centimos=centimos%5;
    if (cent_5!=0){
        cout << cent_5 << " moedas de 5 centimos" << endl;
    }

    //Troco 0.02€
    cent_2=centimos/2;
    centimos=centimos%2;
    if (cent_2!=0){
        cout << cent_2 << " moedas de 2 centimos" << endl;
    }
                
    //Troco 0.01€
    cent_1=centimos;
    if (cent_1!=0){
        cout << cent_1 << " moedas de 1 centimo" << endl;
    }

    system("pause");  

    return 0;
}
