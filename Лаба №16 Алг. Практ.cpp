#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// Завдання 1
void task1() {
    int n;
    cout << "Введіть розмір масивів: ";
    cin >> n;

    int* a = new int[n];
    int* b = new int[n];
    int* c = new int[n];

    // Заповнення масивів a[i], b[i] випадковими числами
    srand(time(0));
    for (int i = 0; i < n; ++i) {
        *(a + i) = rand() % 21 - 10; // Випадкові числа від -10 до 10
        *(b + i) = rand() % 21 - 10;
    }

    // Обчислення c[i]
    int minA = *min_element(a, a + n);
    int negativeCount = 0;

    for (int i = 0; i < n; ++i) {
        *(c + i) = minA + *(b + i);
        if (*(c + i) < 0) {
            ++negativeCount;
        }
    }

    // Виведення результату
    cout << "Масив a: ";
    for (int i = 0; i < n; ++i) cout << *(a + i) << " ";
    cout << "\nМасив b: ";
    for (int i = 0; i < n; ++i) cout << *(b + i) << " ";
    cout << "\nМасив c: ";
    for (int i = 0; i < n; ++i) cout << *(c + i) << " ";
    cout << "\nКількість від'ємних елементів в масиві c: " << negativeCount << endl;

    delete[] a;
    delete[] b;
    delete[] c;
}

// Завдання 2
void task2() {
    int n;
    cout << "Введіть розмірність матриці (n x n): ";
    cin >> n;

    double** A = new double* [n];
    for (int i = 0; i < n; ++i) {
        A[i] = new double[n];
    }

    srand(time(0));
    // Заповнення матриці випадковими числами
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = rand() % 21 - 10; // Випадкові числа від -10 до 10
        }
    }

    // Різниця між найбільшим і найменшим на головній діагоналі
    double maxDiag = A[0][0], minDiag = A[0][0];
    for (int i = 0; i < n; ++i) {
        maxDiag = max(maxDiag, A[i][i]);
        minDiag = min(minDiag, A[i][i]);
    }
    double diff = maxDiag - minDiag;

    // Перевірка нулів на бічній діагоналі
    bool hasZero = false;
    for (int i = 0; i < n; ++i) {
        if (A[i][n - i - 1] == 0) {
            hasZero = true;
            break;
        }
    }

    // Виведення
    cout << "Матриця A:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "Різниця між max і min на головній діагоналі: " << diff << endl;
    cout << "Стовпець для виведення: ";
    if (hasZero) {
        cout << "1-й стовпець:\n";
        for (int i = 0; i < n; ++i) {
            cout << A[i][0] << endl;
        }
    }
    else {
        cout << "2-й стовпець:\n";
        for (int i = 0; i < n; ++i) {
            cout << A[i][1] << endl;
        }
    }

    for (int i = 0; i < n; ++i) {
        delete[] A[i];
    }
    delete[] A;
}

// Завдання 3
void task3() {
    string name;
    int height;
    cout << "Введіть своє ім'я: ";
    cin >> name;
    cout << "Введіть свій зріст: ";
    cin >> height;

    // Кількість літер у слові
    cout << "Кількість літер у вашому імені: " << name.size() << endl;

    // Ім'я у зворотньому порядку в стовпець
    cout << "Ім'я у зворотньому порядку:\n";
    for (int i = name.size() - 1; i >= 0; --i) {
        cout << name[i] << endl;
    }

    // Додати 10 до зросту
    cout << "Ваш зріст + 10: " << height + 10 << endl;
}

// Завдання 4
void task4() {
    int n;
    cout << "Введіть розмір масиву: ";
    cin >> n;

    vector<int> X(n);
    srand(time(0));
    for (int i = 0; i < n; ++i) {
        X[i] = rand() % 21 - 10; // Випадкові числа від -10 до 10
    }

    // Середнє арифметичне
    double average = accumulate(X.begin(), X.end(), 0.0) / n;

    // Кількість елементів більших за середнє
    int countAboveAverage = count_if(X.begin(), X.end(), [average](int x) { return x > average; });

    // Видалення елементів між мінімальним та максимальним
    auto minIt = min_element(X.begin(), X.end());
    auto maxIt = max_element(X.begin(), X.end());
    if (minIt > maxIt) swap(minIt, maxIt);
    X.erase(minIt + 1, maxIt);

    // Виведення
    cout << "Масив X: ";
    for (int x : X) cout << x << " ";
    cout << "\nСереднє арифметичне: " << average;
    cout << "\nКількість елементів більших за середнє: " << countAboveAverage << endl;
    cout << "Масив після видалення: ";
    for (int x : X) cout << x << " ";
    cout << endl;
}

// Завдання 5
void task5() {
    int n, m, r1, r2;
    cout << "Введіть розмірність матриці (n x m): ";
    cin >> n >> m;
    cout << "Введіть номери рядків r1 і r2: ";
    cin >> r1 >> r2;

    int** A = new int* [n];
    for (int i = 0; i < n; ++i) {
        A[i] = new int[m];
    }

    srand(time(0));
    // Заповнення матриці
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            A[i][j] = rand() % 21 - 10;
        }
    }

    // Сума елементів рядків з r1 по r2
    int sum = 0;
    for (int i = r1 - 1; i <= r2 - 1; ++i) {
        sum += accumulate(A[i], A[i] + m, 0);
    }

    // Виведення
    cout << "Матриця A:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "Сума елементів рядків з " << r1 << " по " << r2 << ": " << sum << endl;

    for (int i = 0; i < n; ++i) {
        delete[] A[i];
    }
    delete[] A;
}

// Головна функція
int main() {
    int choice;

    while (true) {
        cout << "\nМеню:\n";
        cout << "1. Завдання 1\n";
        cout << "2. Завдання 2\n";
        cout << "3. Завдання 3\n";
        cout << "4. Завдання 4\n";
        cout << "5. Завдання 5\n";
        cout << "0. Вихід\n";
        cout << "Оберіть завдання: ";
        cin >> choice;

        switch (choice) {
        case 1: task1(); break;
        case 2: task2(); break;
        case 3: task3(); break;
        case 4: task4(); break;
        case 5: task5(); break;
        case 0: cout << "Вихід...\n"; return 0;
        default: cout << "Невірний вибір. Спробуйте ще раз.\n";
        }
    }
}
