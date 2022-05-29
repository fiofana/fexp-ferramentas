/* Programa "MMQ Linear" = obtém parâmetros de uma equação linear de acordo com o método de mínimos quadrados */
#include <iostream>
#include <locale>
using namespace std;

#define N 6

//Soma todas as unidades de um vetor
float somaVetor (float A[], int qtde)
{
  float soma = 0;
    
  for (int i = 0; i < qtde; i++) {
	  soma = soma + A[i];
	}

	cout << "Valor da soma: " << soma;
	cout << endl;
  return soma;
}

//Soma todas as unidades de um vetor e entrega sua média
float calculaDesvios (float A[], int i, int qtde, float media)
{
  float desvio = 0;
    
  desvio = A[i] - media;

  return desvio;
}

//Calcula produto escalar entre dois vetores
float escalar (float A[], float B[], int i)
{
  float prod;
    
  prod = A[i] * B[i];
  return prod;
}

//Calcula quadrado de um vetor
float quadrado (float A[], int i)
{
  float quadrado;
    
  quadrado = A[i] * A[i];
  return quadrado;
}

int main() 
{
  setlocale(LC_ALL, "pt_BR.UTF-8");
  float ValoresX[N], ValoresY[N], desviosX[N], desviosY[N], prodDesvios[N], quadradoDesvioX[N];
	int qtde, i;
  float Xmedio, Ymedio, somaProd, somaQuad, coefLin, coefAng;

	
	cout << "Quantos são os valores? ";
	cin >> qtde;
	
  //Preenche os vetores
	cout << "Digite os valores de x: ";
	for (i = 0; i < qtde; i++) {
		cin >> ValoresX[i];
	}

  cout << "Digite os valores de y: ";
	for (i = 0; i < qtde; i++) {
		cin >> ValoresY[i];
	}

  cout << endl;
  cout << "////////////////////////////////////";
  cout << endl;

  //x e y médios
  Xmedio = somaVetor(ValoresX, qtde)/qtde;
  cout << "Valor do x médio: " << Xmedio << endl;

  Ymedio = somaVetor(ValoresY, qtde)/qtde;
  cout << "Valor do y médio: " << Ymedio << endl;
  cout << endl;

  //Desvios
  cout << "Desvios de x: ";
  for (i=0; i < qtde; i++) {
    desviosX[i] = calculaDesvios(ValoresX, i, qtde, Xmedio);
    cout << desviosX[i] << " ";
  }
  cout << endl;

  cout << "Desvios de y: ";
  for (i=0; i < qtde; i++) {
    desviosY[i] = calculaDesvios(ValoresY, i, qtde, Ymedio);
    cout << desviosY[i] << " ";
  }
  cout << endl;
  cout << endl;

  //Cálculos com desvios
  cout << "Produto dos desvios: ";
  for (i=0; i < qtde; i++) {
    prodDesvios[i] = escalar(desviosX, desviosY, i);
    cout << prodDesvios[i] << " ";
  }
  cout << endl;

  cout << "Desvio de x ao quadrado: ";
  for (i=0; i < qtde; i++) {
    quadradoDesvioX[i] = quadrado(desviosX, i);
    cout << quadradoDesvioX[i] << " ";
   }
  cout << endl;
  cout << endl;

  //Somatórios 
  cout << "Somatório do produto dos desvios: ";
	somaProd = somaVetor(prodDesvios, qtde);
	cout << somaProd << endl;

  cout << "Somatório do quadrado dos desvios de x: ";
	somaQuad = somaVetor(quadradoDesvioX, qtde);
	cout << somaQuad << endl;
  cout << endl;

  //Coeficientes
  cout << "Coeficiente angular: ";
	coefAng = somaProd/somaQuad;
	cout << coefAng << endl;

  cout << "Coeficiente linear: ";
	coefLin = Ymedio - coefAng*Xmedio;
	cout << coefLin << endl;

  cout << "Regressão linear obtida: ";
	cout << "y = " << coefAng << "x + " << coefLin << endl;

  cout << "////////////////////////////////////";

	return 0;
} 
