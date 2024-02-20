#include <iostream>
using namespace std;

// os estados de tela do jogo
enum state
{
	TURN_X,
	TURN_O,
	X_WIN,
	O_WIN,
	TIE,
};

int estado = TURN_X; // a variável estado muda a tela do jogo
int round = 0; // essa variável serve pra lógica de empate

string status;

// para o game loop
bool executando = true;

// esse array reprenta o tabuleiro
char board[9];

// essa função reseta o jogo
void ResetGame()
{
	for(int i = 0; i < 9; i++)
	{
		board[i] = 0;
	}
	
	round = 0;
}

// essa função verifica se o 'X' ganhou
void checkXWin()
{
	if(board[0] == 'X' && board[1] == 'X' && board[2] == 'X')
	{
		status = "parabéns X ganhou na primeira linha horizontal";
		estado = X_WIN;
	}
	
	if(board[3] == 'X' && board[4] == 'X' && board[5] == 'X')
	{
		status = "parabéns X ganhou na segunda linha horizontal";
		estado = X_WIN;
	}
	
	if(board[6] == 'X' && board[7] == 'X' && board[8] == 'X')
	{
		status = "parabéns X ganhou na terceira linha horizontal";
		estado = X_WIN;
	}
	
	if(board[0] == 'X' && board[3] == 'X' && board[6] == 'X')
	{
		status = "parabéns X ganhou na primeira linha vertical";
		estado = X_WIN;
	}
	
	if(board[1] == 'X' && board[4] == 'X' && board[7] == 'X')
	{
		status = "parabéns X ganhou na segunda linha vertical";
		estado = X_WIN;
	}
	
	if(board[2] == 'X' && board[5] == 'X' && board[8] == 'X')
	{
		status = "parabéns X ganhou na terceira linha vertical";
		estado = X_WIN;
	}
	
	// diagonais
	if(board[0] == 'X' && board[4] == 'X' && board[8] == 'X')
	{
		status = "parabéns X ganhou na primeira diagonal";
		estado = X_WIN;
	}
	
	if(board[2] == 'X' && board[4] == 'X' && board[6] == 'X')
	{
		status = "parabéns X ganhou na segunda diagonal";
		estado = X_WIN;
	}
}


// essa função verifica se o 'O' ganhou
void checkOWin()
{
	if(board[0] == 'O' && board[1] == 'O' && board[2] == 'O')
	{
		status = "parabéns O ganhou na primeira linha horizontal";
		estado = O_WIN;
	}
	
	if(board[3] == 'O' && board[4] == 'O' && board[5] == 'O')
	{
		status = "parabéns O ganhou na segunda linha horizontal";
		estado = O_WIN;
	}
	
	if(board[6] == 'O' && board[7] == 'O' && board[8] == 'O')
	{
		status = "parabéns O ganhou na terceira linha horizontal";
		estado = O_WIN;
	}
	
	if(board[0] == 'O' && board[3] == 'O' && board[6] == 'O')
	{
		status = "parabéns O ganhou na primeira linha vertical";
		estado = O_WIN;
	}
	
	if(board[1] == 'O' && board[4] == 'O' && board[7] == 'O')
	{
		status = "parabéns O ganhou na segunda linha vertical";
		estado = O_WIN;
	}
	
	if(board[2] == 'O' && board[5] == 'O' && board[8] == 'O')
	{
		status = "parabéns O ganhou na terceira linha vertical";
		estado = O_WIN;
	}
	
	// diagonais
	if(board[0] == 'O' && board[4] == 'O' && board[8] == 'O')
	{
		status = "parabéns O ganhou na primeira diagonal";
		estado = O_WIN;
	}
	
	if(board[2] == 'O' && board[4] == 'O' && board[6] == 'O')
	{
		status = "parabéns O ganhou na segunda diagonal";
		estado = O_WIN;
	}
}

// use essa função pra desenhar o tabuleiro na tela
void Drawboard()
{
	for(int i = 0; i < 9; i++)
	{
		// se i for divisível por 3
		if(i % 3 == 0)
		{
			cout << endl; // pula linha
		}
		
		// se dentro do array board tiver o valor 0
		if(board[i] == 0)
		{
			cout << i << " "; // mostra o número i
		}
		
		// senão
		else
		{
			cout << board[i] << " "; // mostra o caractere
		}
	}
}


// use essa função pra colocar 'X' no tabuleiro
void PUT_X()
{
	cout << endl;
	cout << "round: " << round << endl;
	cout << "Vez do x" << endl;
	cout << "digite um número de 0 até 8" << endl;
	static int i = 0;
	cin >> i;
	
	if(i < 0 || i > 8)
	{
		cout << "não temos essa posição" << endl;
		estado = TURN_X;
		return;
	}
	
	if(board[i] == 0)
	{
		board[i] = 'X';
		round++;
		estado = TURN_O;
	}
	
	else
	{
		cout << "temos valor aqui" << endl;
		estado = TURN_X;
	}
}


// use essa função pra colocar 'O' no tabuleiro
void PUT_O()
{
	cout << endl;
	cout << "round: " << round << endl;
	cout << "Vez do o" << endl;
	cout << "digite um número de 0 até 8" << endl;
	static int i = 0;
	cin >> i;
	
	if(i < 0 || i > 8)
	{
		cout << "não temos essa posição" << endl;
		estado = TURN_O;
		return;
	}
	
	if(board[i] == 0)
	{
		board[i] = 'O';
		round++;
		estado = TURN_X;
	}
	
	else
	{
		cout << "temos valor aqui" << endl;
		estado = TURN_O;
	}
}

// essa função desenha o empate
void DrawTie()
{
	cout << endl;
	cout << "oops parece que houve um empate" << endl;
	cout << "deseja continuar: " << endl;
	cout << "[1] sim" << endl;
	cout << "[2] não" << endl;
	static int reposta = 0;
	cin >> reposta;
	if(reposta == 1)
	{
		ResetGame();
		estado = TURN_X;
	}
	
	else
	{
		executando = false;
	}
}


// essa função verifica se teve empate
void checkTie()
{
	if(round >= 9 && estado != X_WIN && estado != O_WIN)
	{
		estado = TIE;
	}
}

// essa função desenha a tela de vitória
void DrawWin()
{
	cout << endl;
	cout << status << endl;
	cout << "deseja continuar: " << endl;
	cout << "[1] sim" << endl;
	cout << "[2] não" << endl;
	static int reposta = 0;
	cin >> reposta;
	
	if(reposta == 1)
	{
		ResetGame();
		estado = TURN_X;
	}
	
	else
	{
		executando = false;
	}
}

// use essa função pra mudar a tela do jogo
void RunGame()
{
	switch(estado)
	{
		case TURN_X: PUT_X(); break;
		case TURN_O: PUT_O(); break;
		case TIE: DrawTie(); break;
		case X_WIN: DrawWin(); break;
		case O_WIN: DrawWin(); break;
		default: ;break;
	}
}

int main()
{
setlocale(LC_ALL, "portuguese");

ResetGame();

// game loop
while(executando)
{
	checkXWin();
	checkOWin();
	checkTie();
	Drawboard();
	RunGame();
}

system("pause");
return 0;
}
