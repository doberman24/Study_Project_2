#include "msoftcon.h"
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;
    float *a = new float [n], middle, temp;
    float sum = 0, pro = 1;
    int i, j, left, right, imax = 0, imin;
    cout << "Введите элементы массива: " << endl;
    for (i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
    for (i = 0; i < n; i++)
        if (i%2 == 0)
            pro *= a[i];
    for (i = imin = 0; i < n; i++)
        if (a[i] == 0)
        {
            imin = i;
            break;
        }
    for (i = n-1; i >= 0; i--)
        if (a[i] == 0)
        {
            imax = i;
            break;
        }
    if (imin < imax)
        for (i = imin+1; i < imax; i++)
            sum += a[i];
    if (imin > imax)
        for (i = imax+1; i < imin; i++)
            sum += a[i];
    cout << "\nИсходный массив a:" << endl;
    for (i = 0; i < n; i++)
		cout << a[i] << " ";
    cout << endl << endl << "Произведение элементов с четными номерами: "
         << pro << endl << "Сумма элементов между нулевыми элементами: " 
         << sum << endl;
    cout << imin << " - минимум" << endl << imax << " - максимум" 
         << endl << endl;

    int *steckL = new int [n], *steckR = new int [n], sp;
    sp = 1;
    steckL[1] = 0;
    steckR[1] = n-1;
    while (sp > 0)
    {
        left = steckL[sp];
        right = steckR[sp];
        sp--;
        while (left < right)
        {
            i = left;
            j = right;
            middle = a[(left + right)/2];
            while (i < j)
            {
                while (a[i] > middle)
                    i++;
                while (a[j] < middle)
                    j--;
                if (i <= j)
                {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                    i++; j--;
                }                  
            }
            if (i < right)
            {
                sp++;
                steckL[sp] = i;
                steckR[sp] = right;
            }
            right = j;
        }
    }           
    cout << "\Отсортированный массив a:" << endl;
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    system ("PAUSE >> void");
    return 0;
}
