#include <iostream>

using namespace std;

class Menu{
    public:
        void erro(){
            cout << "\nNota invalida";
        }
        
        void menu_troco(){
            cout << "\n\t\t\tCAIXA DE PAGAMENTO\n\tSo sao aceites notas entre 5, 10, 20, 50, 100, 200, 500\n\n";
        }

        void menu_principal(){
            cout << "\n\t\t\tCAIXA DE PAGAMENTO\n\t1 - Calcular Troco\n0 - Sair\n\nInput> ";
        }

};

class Programa{
    private:
        int notas_aceites[8] = {0,5,10,20,50,100,200,500};

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

        int eax[9];

    public:
        int * calc_troco(float valor, int pagamento){

            for (size_t i=1;i<8;i++){
                if (pagamento == notas_aceites[i]){
                    notas_aceites[0]=1;
                }
            }

            if (notas_aceites[0] != 1){
                eax[0]=1;
                return eax;
            }else{
                eax[0]=0;

                troco = pagamento-valor;
                cout << "Troco> " << troco << endl;

                centimos = troco*100+0.01;

                //Troco 2€
                euro_2=centimos/200;
                centimos=centimos%200;
                eax[1]=euro_2;

                //Troco 1€
                euro_1=centimos/100;
                centimos=centimos%100;
                eax[2]=euro_1;

                //Troco 0.50€
                cent_50=centimos/50;
                centimos=centimos%50;
                eax[3]=cent_50;

                //Troco 0.20€
                cent_20=centimos/20;
                centimos=centimos%20;
                eax[4]=cent_20;

                //Troco 0.10€
                cent_10=centimos/10;
                centimos=centimos%10;
                eax[5]=cent_10;

                //Troco 0.05€
                cent_5=centimos/5;
                centimos=centimos%5;
                eax[6]=cent_5;

                //Troco 0.02€
                cent_2=centimos/2;
                centimos=centimos%2;
                eax[7]=cent_2;
                            
                //Troco 0.01€
                cent_1=centimos;
                eax[8]=cent_1;
                
                return eax; 
            }
        }
        
};

int main(int argc, char const *argv[]){

    Programa programa;
    Menu menu;
    int *esp;

    float valor;
    int pagamento;
    int input;

    esp=programa.calc_troco(3.71,10);

    while (true){
        menu.menu_principal();
        cin >> input;
        switch (input){
            case 1:
                menu.menu_troco();
                cout << "Valor> "; cin >> valor;
                cout << "Pagamento> "; cin >> pagamento; 
                esp=programa.calc_troco(valor,pagamento);
                if (*(esp+0)==1){
                    menu.erro();
                }else{
                    for (size_t i=1;i<=8;i++){
                        if(*(esp+i)!=0){
                            if (*(esp+i)>1){

                                switch (i){
                                    case 1:
                                        cout << *(esp+i) << " moedas de 2 euros";
                                        break;
                                    case 2:
                                        cout << *(esp+i) << " moedas de 1 euro";
                                        break;
                                    case 3:
                                        cout << *(esp+i) << " moedas de 50 centimos";
                                        break;
                                    /*etc..*/
                                    
                                    default:
                                        break;
                                }
                                
                            }else{

                                switch (i){
                                    case 1:
                                        cout << *(esp+i) << " moeda de 2 euros";
                                        break;
                                    case 2:
                                        cout << *(esp+i) << " moeda de 1 euro";
                                        break;
                                    case 3:
                                        cout << *(esp+i) << " moeda de 50 centimos";
                                        break;
                                    /*etc..*/
                                    
                                    default:
                                        break;
                                }

                            }
                            
                            
                        }
                    }
                    
                }
                
                
                break;
            case 0:
                break;
            default:
                break;
        }
    }
    

    for (size_t i=0;i<=8;i++){

        cout << *(esp+i) << endl;
    }

    system("pause");

    return 0;
}
