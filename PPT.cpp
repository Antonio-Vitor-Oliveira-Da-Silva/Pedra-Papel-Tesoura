#include <iostream>
#include <cstdlib>
#include <time.h>

#define PEDRA 1
#define PAPEL 2
#define TESOURA 3

using namespace std;

class JogoPPT {
public:
	/* Iniciar o jogo e fazer a comparação. */
	void Jogar(int palpiteJogador) {
		int palpiteCPU = SorteioCPU();

		switch(palpiteCPU) {
			case PEDRA:
				if (palpiteJogador == PEDRA) {
					msgEmpatou("pedra", "pedra");
				}
				else if (palpiteJogador == PAPEL) {
					msgGanhou("pedra", "papel");
				}
				else if (palpiteJogador == TESOURA) {
					msgPerdeu("pedra", "tesoura");
				}
				break;
			
			case PAPEL:
				if (palpiteJogador == PEDRA) {
					msgPerdeu("papel", "pedra");
				}
				else if (palpiteJogador == PAPEL) {
					msgEmpatou("papel", "papel");
				}
				else if (palpiteJogador == TESOURA) {
					msgGanhou("papel", "tesoura");
				}
				break;
			
			case TESOURA:
				if (palpiteJogador == PEDRA) {
					msgGanhou("tesoura", "pedra");
				}
				else if (palpiteJogador == PAPEL) {
					msgPerdeu("tesoura", "papel");
				}
				else if (palpiteJogador == TESOURA) {
					msgEmpatou("tesoura", "tesoura");
				}
				break;
		}
	}

	/* Mensagens para o usuário, indicando se perdeu ou ganhou e 
	 * mostrando a jogada do computador. */
	void msgGanhou(string jogadaCPU, string jogadaJogador) {
		cout << "Parabéns! Você ganhou!" << endl;
		cout << "Você jogou " << jogadaJogador << " e o computador jogou " << jogadaCPU << "." << endl;
	}
	void msgPerdeu(string jogadaCPU, string jogadaJogador) {
		cout << "Que pena! Você perdeu!" << endl;
		cout << "Você jogou " << jogadaJogador << " e o computador jogou " << jogadaCPU << "." << endl;
	}
	void msgEmpatou(string jogadaCPU, string jogadaJogador) {
		cout << "Oops! O jogo empatou!" << endl;
		cout << "Você jogou " << jogadaJogador << " e o computador jogou " << jogadaCPU << "." << endl;
	}

private:
	/* Método de sorteio do computador. */
	int SorteioCPU(void) {
		srand(time(NULL));
		return (rand() % 3) + 1;
	}
};

 void IniciarJogo(void) {
	JogoPPT jogador;
	int palpiteJogador;

	cout << "(1) Pedra" << endl << "(2) Papel" << endl << "(3) Tesoura" << endl;
	cout << "Insira o seu palpite (qualquer outra tecla para sair): ";
	cin >> palpiteJogador;

	if (palpiteJogador != 1 && palpiteJogador != 2 && palpiteJogador != 3) {
		cout << "Saindo..." << endl;
		exit(0);
	}
	else {
		jogador.Jogar(palpiteJogador);
	}
}

int main(void) {
	string versao = "1.0";
	string escolha;

	cout << "==================================" << endl;
	cout << "Pedra Papel e Tesoura - Versão " << versao << endl;
	cout << "==================================" << endl << endl;

	while(true) {
		IniciarJogo();

		cout << endl << "Deseja jogar novamente? [S/n]: ";
		cin >> escolha;

		if (escolha == "n" || escolha == "N") {
			cout << "Saindo..." << endl;
			break;
		}

		cout << endl;
	}

	return 0;
}