#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
// Autor: Ari-20250108H
/*
Profe avance la mayor parte del codigo durante la clase, hoy solo le hice ajustes como arreglar la funcion menor_distancia
y la funcion llenar_matriz, ademas de eso añadi la funcion liberar
*/
void llenar_matriz(double **m, int n)
{
    srand(time(0));
    int n1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            n1 = rand() % 1501 + 100;
            if (i == j)
            {
                m[i][j] = 0;
            }
            if (i < j)
            {
                m[i][j] = n1;
                m[j][i] = m[i][j];
            }
        }
    }
}
void imprimir(double **m, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << right << setw(10) << m[i][j];
        }
        cout << endl;
        cout << endl;
        cout << endl;
    }
}
double promedio(double **m, int n)
{
    double prom = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j)
            {
                prom += m[i][j];
            }
        }
    }
    return prom / (n * n);
}
double menor_distancia(double **m, int n, int *menor_i, int *menor_j)
{
    double menor = m[0][1];
    *menor_i = 0;
    *menor_j = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j)
            {

                if (m[i][j] < menor)
                {
                    *menor_i = i;
                    *menor_j = j;
                    menor = m[i][j];
                }
            }
        }
    }
    return menor;
}
void liberar(double **matriz, int n)
{
    for (int i = 0; i < n; i++)
    {
        delete matriz[i];
        matriz[i] = nullptr;
    }
}
int main()
{
    int n;
    int i;
    int j;
    cout << "Ingrese el numero de aeropuertos: ";
    cin >> n;
    double **matriz = new double *[n];
    for (int i = 0; i < n; i++)
    {
        matriz[i] = new double[n];
    }
    llenar_matriz(matriz, n);
    cout << "Matriz mostrada: " << endl;
    imprimir(matriz, n);
    cout << "Promedio de distancias: " << promedio(matriz, n) << endl;
    cout << "Menor distancia entre aeropuertos: " << menor_distancia(matriz, n, &i, &j) << " km" << endl;
    cout << "La menor distancia es ente el aeropuerto [" << i + 1 << "] y el aeropuerto [" << j + 1 << "]";
    liberar(matriz, n);
    return 0;
}