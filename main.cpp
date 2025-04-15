
//Biblioteca de entradas e saídas do c++ printf (cout) e scanf (cin) no c 
#include <iostream>
//Biblioteca math.h do c
#include <cmath>
using namespace std;

// Função para calcular o máximo divisor comum (MDC) para que o valor dele seja usado como a variavel divisor e simplifique frações
int mdc(int a, int b) {
        if (b == 0) return a;
        return mdc(b, a % b);
}

// Função para simplificar frações usa o resultado da função mdc n avariavel divisor
void simplificar(int &num, int &den) 
{
        int divisor = mdc(abs(num), abs(den));
        num /= divisor;
        den /= divisor;
        if (den < 0) {
            num *= -1;
            den *= -1;
        }
}

// Função para mostrar a fração
void mostrarFracao(int num, int den) 
{
        cout << num << "/" << den << " ≈ " << (double)num / den << endl;
}

// Funçaõ para Leitura primeiro número
void lerNumero(int &num, int &den) 
{
        int tipo;
        cout << "\nTipo de número:\n1. Inteiro\n2. Fração\n> ";
        cin >> tipo;

        if (tipo == 1) 
        {
            cout << "Digite o inteiro: ";
            cin >> num;
            den = 1;
        }

        else 
        {
            cout << "Numerador: ";
            cin >> num;
            do {
                cout << "Denominador (≠ 0): ";
                cin >> den;
            } while (den == 0);
        }

        simplificar(num, den);
}

//FUNÇÃO MÃE (DANGER)
int main() {
    cout << "<=== Calculadora Científica Parcial ===>\n";

    int numAtual, denAtual;

    lerNumero(numAtual, denAtual);

    while (true) {

                            char operador;
                            cout << "\nOperação (+, -, *, /, ^, r e = para sair): ";
                            
                            //Entrada do operador
                            cin >> operador;

                            //Condição de parada da calculadora
                            if (operador == '=') 
                            {
                                cout << "\nResultado final: ";
                                mostrarFracao(numAtual, denAtual);
                                break;
                            }

                            //Operação de radiciação
                            else if (operador == 'r') 
                            {
                                double raizNum = sqrt(numAtual);
                                double raizDen = sqrt(denAtual);
                                cout << "Raiz quadrada de " << numAtual << "/" << denAtual
                                    << " = " << raizNum << "/" << raizDen
                                    << " ≈ " << (raizNum / raizDen) << endl;
                                continue;
                            }

                            //Ler segundo número
                            int numNovo, denNovo;
                            lerNumero(numNovo, denNovo);

                            switch (operador) 
                            {
                                //Operação de soma
                                case '+':
                                    numAtual = numAtual * denNovo + numNovo * denAtual;
                                    denAtual = denAtual * denNovo;
                                    break;

                                //Operaçaõ de subtração
                                case '-':
                                    numAtual = numAtual * denNovo - numNovo * denAtual;
                                    denAtual = denAtual * denNovo;
                                    break;

                                //Operação de multiplicação
                                case '*':
                                    numAtual *= numNovo;
                                    denAtual *= denNovo;
                                    break;

                                //Operação divisão
                                case '/':
                                    numAtual *= denNovo;
                                    denAtual *= numNovo;
                                    break;

                                //Operação de potência
                                case '^': 
                                {
                                    int exp;
                                    cout << "Digite o expoente: ";
                                    cin >> exp;
                                    numAtual = pow(numAtual, exp);
                                    denAtual = pow(denAtual, exp);
                                    break;
                                }

                                //Faz virar um loop caso outra coisa seja inserida
                                default:
                                    cout << "Operação inválida.\n";
                                    continue;
                            }

                                //Simplifica ao final, caso seja fração
                            simplificar(numAtual, denAtual);
                            cout << "Resultado parcial: ";
                            mostrarFracao(numAtual, denAtual);

    }

    return 0;
}
