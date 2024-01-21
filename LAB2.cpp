// LAB2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <random>
#include <algorithm>

using namespace std;


struct Stat {
    int comparisons;
    int permutation;
};


void print(int* m, int size) {
    for (int i = 0; i < size; i++) {
        cout << m[i] << endl;
    }
    cout << "----------" << endl;
}


Stat sort_selection(int* mas, int size) {

    Stat res{ 0,0 };

    for (int sorted = 0; sorted < size; sorted++) {
        int* min = &mas[sorted];
        for (int i = sorted + 1; i < size; i++) {
            if (mas[i] < *min) min = &mas[i];
            res.comparisons++;
        }
        if (mas[sorted] != *min) {
            swap(mas[sorted], *min);
            res.permutation++;
        }
    }
    print(mas, size);

    return res;
}


Stat sort_insert(int* mas, int size) {

    Stat res{ 0,0 };
    int temp = mas[0];

    for (int sorted = 1; sorted < size; sorted++) {
        temp = mas[sorted];
        for (int i = 0; i < sorted; i++) {
            if (mas[i] > temp) {
                for (int k = sorted; k > i; k--) {
                    mas[k] = mas[k - 1];     
                }
                mas[i] = temp;
                res.permutation++;
                break;
            }
            res.comparisons++;
        }
    }
    print(mas, size);
    return res;
}



int main()
{
    Stat result {0,0};
    Stat result2 { 0,0 };

    random_device rd;
    default_random_engine eng(rd());
    uniform_int_distribution<int> dist(-10000, 10000);

    //57;119;245;502;1031;2114;4335
    int n = 0;
    char method = '0';


    cout << "Enter the number of items:\n";
    cin >> n;
    /*
    while ((method != 'i')&&(method !='s')) {
        cout << "Sorting method (i - insert, s - selection)\n";
        cin >> method;
    }
    */





    int* m = new int[n];
    int* m2 = new int[n];

    

    for (int i = 0; i < n; i++)
    {
        m[i] = dist(eng);
        m2[i] = m[i];
    }

    print(m, n);
    
    //switch (method) {
    //case 'i':
        result = sort_insert(m, n);
    //    break;
    //case 's':
        result2 = sort_selection(m2, n);
    //    break;
    //default:
    //    cout << "incorrect method\n";
    //}
    

    cout << "Insert\n" << "Comparisons: " << result.comparisons << endl << "permutation: " << result.permutation << endl;

    cout << "Selection\n" << "Comparisons: " << result2.comparisons << endl << "permutation: " << result2.permutation << endl;

    delete[] m;
    delete[] m2;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
