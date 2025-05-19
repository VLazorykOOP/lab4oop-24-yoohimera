#include <iostream>
using namespace std;

class VectorDouble {
private:
    double* data;     // масив чисел
    int size;         // кількість елементів
    int codeError;    // код помилки
    static int count; // кількість створених об'єктів

public:
    // Конструктор без параметрів
    VectorDouble() {
        size = 1;
        data = new double[size]{0};
        codeError = 0;
        count++;
    }

    // Конструктор з розміром
    VectorDouble(int s) {
        size = s;
        data = new double[size]{0};
        codeError = 0;
        count++;
    }

    // Конструктор з розміром і значенням
    VectorDouble(int s, double value) {
        size = s;
        data = new double[size];
        for (int i = 0; i < size; i++) data[i] = value;
        codeError = 0;
        count++;
    }

    // Деструктор
    ~VectorDouble() {
        delete[] data;
        count--;
    }

    // Вивід
    void print() const {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    // Доступ до елементу по індексу
    double& operator[](int i) {
        if (i < 0 || i >= size) {
            codeError = 1;
            static double dummy = 0;
            return dummy;
        }
        return data[i];
    }

    // Отримати код помилки
    int getError() const {
        return codeError;
    }

    // Отримати кількість об'єктів
    static int getCount() {
        return count;
    }
};

int VectorDouble::count = 0;

// ====== ТЕСТ =========
int main() {
    VectorDouble v1(3, 2.5); // вектор з трьох елементів, всі 2.5
    v1.print();              // Виведе: 2.5 2.5 2.5

    cout << "Element [1]: " << v1[1] << endl;
    cout << "Wrong index [10]: " << v1[10] << endl;
    cout << "Error code: " << v1.getError() << endl;

    cout << "Total objects: " << VectorDouble::getCount() << endl;

    return 0;
}
