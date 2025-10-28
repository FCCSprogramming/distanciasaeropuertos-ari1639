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
double num_r(double min, double max)
{
    int n1 = 0;
    int n2 = 0;
    double n = 0;

    do
    {
        n1 = rand();
        n2 = rand();
        n = n1 / (n2 * 1.0);
    } while (n < min || n > max);

    return n;
}
void llenar_matriz(double **m, int n)
{
    double na;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            na = num_r(100, 1500);
            if (i == j)
            {
                m[i][j] = 0;
            }
            if (i < j)
            {
                m[i][j] = na;
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
            cout << right << setw(10) << fixed << setprecision(2) << m[i][j];
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
void liberar(double **&matriz, int n)
{
    for (int i = 0; i < n; i++)
    {
        delete[] matriz[i];
        matriz[i] = nullptr;
    }
    delete[] matriz;
    matriz = nullptr;
}
int main()
{
    srand(time(0));
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