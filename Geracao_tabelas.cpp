#include <iostream> 
#include <string>
using namespace std;

constexpr int LINHAS = 10;
constexpr int COLUNAS = 56;

class Tabela_verdade
{
private:

	string variavel1;
	string variavel2;
	string prop_a = "var1";
	string prop_b = "var2";
	string disjun = "disjuncao";
	string conjun = "conjuncao";
	string implic = "implicacao";
	string bicond = "bicondicional";
	string tabela_formatada[LINHAS][COLUNAS];
public:
	Tabela_verdade(string var1, string var2);
	void imprime_tabela();
};

Tabela_verdade::Tabela_verdade(string var1 = "var1", string var2 = "var2")
{	
	variavel1 = var1;
	variavel2 = var2;
	if (variavel1 != "var1" && variavel2 != "var2")
	{
		var1 = variavel1[0];
		var2 = variavel2[0];
	}
	if (var1 == "var1" && var2 == "var2") // se não forem passados parametros de entrada, será criada apenas a estrutura da tabela formatada
	{
		for (int i = 0; i < LINHAS; i++) //  Criacao da estrutura da tabela
		{
			for (int j = 0; j < COLUNAS; j++)
			{
				if ((j == 0) || (j == 5) || (j == 10) || (j == 20) || (j == 30) || (j == 41) || (j == 55))
					tabela_formatada[i][j] = '|';
				else if ((i % 2) == 1)
					tabela_formatada[i][j] = '-';
				else if (i == 0)
				{
					if (j == 1)
						tabela_formatada[i][j] = var1;
					else if (j == 6)
						tabela_formatada[i][j] = var2;
					else if (j == 11)
						tabela_formatada[i][j] = conjun;
					else if (j == 21)
						tabela_formatada[i][j] = disjun;
					else if (j == 31)
						tabela_formatada[i][j] = implic;
					else if (j == 42)
						tabela_formatada[i][j] = bicond;
				}
				else
					tabela_formatada[i][j] = " ";
			}
		}
	}
	else // se forem passados parametros de variaveis, a tabela formatada utilizará as variáveis e os valores da matriz booleana
	{
		for (int i = 0; i < LINHAS; i++) //  Criacao da estrutura da tabela
		{
			for (int j = 0; j < COLUNAS; j++)
			{
				if ((j == 0) || (j == 5) || (j == 10) || (j == 20) || (j == 30) || (j == 41) || (j == 55))
					tabela_formatada[i][j] = '|';
				else if ((i % 2) == 1)
					tabela_formatada[i][j] = '-';
				else if (i == 0)
				{
					if (j == 1)
					{
						tabela_formatada[i][j] = " " + var1 + "  ";

					}
					else if (j == 6)
					{
						tabela_formatada[i][j] = " " + var2 + "  ";
					}
					else if (j == 11)
					{
						string conjuncao = "  " + var1 + " ^ " + var2 + "  ";
						tabela_formatada[i][j] = conjuncao;
					}
					else if (j == 21)
					{
						string disjuncao = "  " + var1 + " v " + var2 + "  ";
						tabela_formatada[i][j] = disjuncao;
					}
					else if (j == 31)
					{
						string implicacao = "  " + var1 + " -> " + var2 + "  ";
						tabela_formatada[i][j] = implicacao;
					}
					else if (j == 42)
					{
						string bicondicional = "   " + var1 + " <-> " + var2 + "   ";
						tabela_formatada[i][j] = bicondicional;
					}
				}
				else
					tabela_formatada[i][j] = " ";
			}
		}
		for (int i = 0; i < LINHAS; i++) // preenche valores booleanos da tabela (escritos como strings V ou F)
		{
			for (int j = 0; j < COLUNAS; j++)
			{
				if ((i % 2) == 0 && i != 0)
					if (j == 2)
					{
						if (i == 2)
							tabela_formatada[i][j] = "V";
						else if (i == 4)
							tabela_formatada[i][j] = "V";
						else if (i == 6)
							tabela_formatada[i][j] = "F";
						else if (i == 8)
							tabela_formatada[i][j] = "F";
					}
					else if (j == 7)
					{
						if (i == 2)
							tabela_formatada[i][j] = "V";
						else if (i == 4)
							tabela_formatada[i][j] = "F";
						else if (i == 6)
							tabela_formatada[i][j] = "V";
						else if (i == 8)
							tabela_formatada[i][j] = "F";
					}
					else if (j == 15)
					{
						if (i == 2)
							tabela_formatada[i][j] = "V";
						else if (i == 4)
							tabela_formatada[i][j] = "F";
						else if (i == 6)
							tabela_formatada[i][j] = "F";
						else if (i == 8)
							tabela_formatada[i][j] = "F";
					}
					else if (j == 25)
					{
						if (i == 2)
							tabela_formatada[i][j] = "V";
						else if (i == 4)
							tabela_formatada[i][j] = "V";
						else if (i == 6)
							tabela_formatada[i][j] = "V";
						else if (i == 8)
							tabela_formatada[i][j] = "F";

					}
					else if (j == 36)
					{
						if (i == 2)
							tabela_formatada[i][j] = "V";
						else if (i == 4)
							tabela_formatada[i][j] = "F";
						else if (i == 6)
							tabela_formatada[i][j] = "V";
						else if (i == 8)
							tabela_formatada[i][j] = "V";
					}
					else if (j == 48)
					{
						if (i == 2)
							tabela_formatada[i][j] = "V";
						else if (i == 4)
							tabela_formatada[i][j] = "F";
						else if (i == 6)
							tabela_formatada[i][j] = "F";
						else if (i == 8)
							tabela_formatada[i][j] = "V"; 
					}
			}
			cout << endl;
		}
	}
	cout << "\n" << endl;
	Tabela_verdade::imprime_tabela();
}

void Tabela_verdade::imprime_tabela()
{	
	if (variavel1 != "var1" && variavel2 != "var2")
	{
		cout << "variavel " << variavel1[0] << " = " << variavel1 << endl;
		cout << "variavel " << variavel2[0] << " = " << variavel2 << "\n" << endl;
	}
	for (int i = 0; i < LINHAS; i++)
	{
		for (int j = 0; j < COLUNAS; j++)
		{
			cout << tabela_formatada[i][j];
		}
		cout << endl;
	}
}

int main()
{
	string var1;
	string var2;
	cout << "Insira a variavel 1:"; cin >> var1;
	cout << "Insira a variavel 2:"; cin >> var2;
	Tabela_verdade t1(var1, var2);
	Tabela_verdade t2;
	return 0;
}