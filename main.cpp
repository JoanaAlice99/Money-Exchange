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
        int troco[9];

    public:
        int * calc_troco(float valor, float pagamento){

            for (size_t i=1;i<8;i++){
                if (pagamento == notas_aceites[i]){
                    notas_aceites[0]=1;
                }
            }

            if (notas_aceites[0] != 1){
                menu.erro();
                return 0;
            }else{
                troco[0]=pagamento-valor;
                for (size_t i=0;i<2;i++){
                    switch (i){
                    case 0:
                        troco[i]=(pagamento-valor)*100;
                        break;

                    case 1:
                        troco[i]=troco[0] % 200;

                    default:
                        break;
                    }
                }
                return troco;
            }
        }
        
};

int main(int argc, char const *argv[]){

    Programa programa;
    int *esp;

    esp=programa.calc_troco(3.71,12);

    for (size_t i=0;i<2;i++){
        cout << *(esp+i) << endl;
    }

    system("pause");

    return 0;
}
