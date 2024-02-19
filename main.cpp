#include <iostream>
using namespace std;

// para o game loop
bool executando = true;

// esse array reprenta o tabuleiro
char table[9] = {'X','X','O','X',0,0,0,0,'O'};

// essa função reseta o jogo
void ResetGame()
{
	for(int i = 0; i < table[i]; i++)
	{
		table[i] = 0;
	}
}

// use essa função pra desenhar o tabuleiro na tela
void DrawTable()
{
	for(int i = 0; i < 9; i++)
	{
		// se i for divisíveis por 3
		if(i % 3 == 0)
		{
			cout << endl; // pula linha
		}
		
		// se dentro do array table tiver o valor 0
		if(table[i] == 0)
		{
			cout << i << " "; // mostra o número i
		}
		
		// senão
		else
		{
			cout << table[i] << " "; // mostra o caractere
		}
	}
}

int main()
{
setlocale(LC_ALL, "portuguese");

//ResetGame();
int lixo;

// game loop
while(executando)
{
	
	DrawTable();
	cout << endl;
	cout << "digite um valor inútil pra sair do game loop: ";
	cin >> lixo;
	executando = false;
}

return 0;
}
