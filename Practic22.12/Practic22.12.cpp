#include <iostream>

using namespace std;

//заполнение двумерный массив одинаковыми числами
int& rf(int index);
int arr[10][2];
//нахождение максимального элемента в массиве и замена его на 0
int& rmax(int n, int d[]);

/*
Задание 1. Даны два массива: А[M] и B[N] (M и N вводятся с клавиатуры). 
Необходимо создать третий массив
минимально возможного размера, в котором нужно собрать элементы обоих массивов.
*/

void f1() {
    srand(time(NULL));

    int M, N;
    cin >> M >> N;
    int* A = new int[M]; // 3
    int* B = new int[N]; // 2
    for (int i = 0; i < M; i++) {
        A[i] = rand() % 20;
        cout << A[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < N; i++) {
        B[i] = rand() % 20;
        cout << B[i] << " ";
    }
    cout << endl;
    int* C = new int[M + N];
    for (int i = 0; i < M + N; i++) {
        if (i < M)
            C[i] = A[i];
        else
            C[i] = B[i - M];

        cout << C[i] << " ";
    }
    cout << endl;
}

/*
Задание 2. Даны два массива: А[M] и B[N] (M и N вводятся с клавиатуры). 
Необходимо создать третий массив
минимально возможного размера, в котором нужно
собрать общие элементы двух массивов без повторений.
*/
void f2() {
    srand(time(NULL));

    int M, N;
    cin >> M >> N;
    int* A = new int[M]; 
    int* B = new int[N]; 
    for (int i = 0; i < M; i++) {
        A[i] = rand() % 10;
        cout << A[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < N; i++) {
        B[i] = rand() % 10;
        cout << B[i] << " ";
    }
    cout << endl;

    int* temp = new int[M + N];
    for (int i = 0; i < M + N; i++) {
        if (i < M)
            temp[i] = A[i];
        else
            temp[i] = B[i - M];

        cout << temp[i] << " ";
    }
    cout << endl;

    int size = M + N;
    for (int i = 0; i < M + N; i++) {
        for (int j = i+1; j < M + N; j++) {
            if (temp[i] == temp[j]) {
                size--;
                break;
            }
        }
    }
    int* C = new int[size];
    bool f;
    for (int i = 0, k = 0; i < M + N; i++) {
        f = false;
        for (int j = 0; j <= k; j++) {
            if (temp[i] == C[j])
                f = true;
        }
        if (!f) {
            C[k] = temp[i];
            k++;           
        }
    }
    cout << endl;
    
    delete[]temp;
    for (int i = 0; i < size; i++) {
        cout << C[i] << " ";
    }
}

int main()
{
    //константный указатель
    //тип_данных* const имя_указателя = адрес;
    /*int a = 12;
    int* const ptr = &a;
    cout << *ptr << " " << a << endl;

    a = 55;
    *ptr = 66;
    cout << *ptr << " " << a << endl;*/
    
    //указатель на константу
    //const тип_данных* имя_указателя;
    /*int a = 73;
    const int* ptr;
    ptr = &a;
    cout << *ptr << " " << a << endl;
    int b = 88;
    ptr = &b;
    cout << *ptr << " " << b << endl;
    //*ptr = 12; - Error
    b = 15;
    cout << *ptr << " " << b << endl;*/

    //константный указатель на константу
    /*int a = 7;
    const int* const ptr = &a;
    int b = 9;
    ptr = &b; // Error
    *ptr = 10;// Error*/

    /*int ivar = 1234;
    int svar = 999;
    int* iptr = &ivar;
    int& iref = ivar;
    int* p = &iref;
    iref = svar;

    cout << "ivar = " << ivar << endl;
    cout << "*iptr = " << *iptr << endl;
    cout << "iref = " << iref << endl;
    cout << "*p = " << *p << endl;*/

    /*int b;
    cout << "Fill array\n";
    for (int i = 0; i < 10; i++) {
        cout << i + 1 << " element: ";
        cin >> b;
        arr[i][0] = b;
        rf(i) = b;
    }
    cout << "Show array\n";
    for (int i = 0; i < 10; i++) {
        cout << arr[i][0] << "  " << rf(i) << endl;
    }*/

    /*int x[] = {10,20,70,30,50};
    int n = 5;
    cout << "rmax(n, x) = " << rmax(n, x) << endl;
    //заменям максимум на число 0
    rmax(n, x) = 0;
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "] = " << x[i] << " ";
    }*/

    //указатель_на_тип = new имя_типа(инициализатор);
    /*int* ip = new int(56);
    //int* other = ip;

    *ip = 78;
    int i = 0;
    delete ip;
    ip = &i;

    //double* mas = new double[50];
    srand(time(NULL));
    int size;
    int* arr;
    cin >> size;
    arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10;
        cout << arr[i] << " ";
    }
    if (arr) {
        delete[] arr;
        arr = nullptr;
    }*/

    //f1();
    f2();

}

int& rf(int index) {
    return arr[index][1]; // возвращает ссылку на на элемент в массиве
}

int& rmax(int n, int d[]) {
    int im = 0;
    for (int i = 1; i < n; i++) {
        im = d[im] > d[i] ? im : i;
    }
    return d[im];
}