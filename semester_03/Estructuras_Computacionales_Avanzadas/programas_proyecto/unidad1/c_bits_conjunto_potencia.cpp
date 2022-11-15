#include <bits/stdc++.h>

using namespace std;

int main()
{

	int n;
	cout << "Cuantos elementos quieres introducir?" << endl;
	cin >> n;

	/*
	int vec[n];
	for (int x = 0; x < n; x++)
	{
		vec[x] = x + 1; // Para que empiece desde 1.
	}
	Como vamos a imprimir al tabla binaria, no vamos a ocupar el vector
	*/

	unsigned int tam_conjuntoPotencia = pow(2, n);
	
	cout << "{}";
	for (int x = 0; x < tam_conjuntoPotencia; x++)
	{
		for (int y = 0; y < n; y++)
		{
			if (x & (1 << y)) 
			{
				cout << 1;
			} else {
				cout << 0;
			}
		}
		cout << "\n";
	}
}