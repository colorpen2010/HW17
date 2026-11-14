#include <iostream>
#include <windows.h>

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:
    void input() {
        cout << "Введите числитель: ";
        cin >> numerator;

        cout << "Введите знаменатель: ";
        cin >> denominator;

        while (denominator == 0) {
            cout << "Знаменатель не может быть равен нулю. Введите ещё раз: ";
            cin >> denominator;
        }
    }

    void print() const {
        cout << numerator << "/" << denominator;
    }

    Fraction add(const Fraction& other) const {
        Fraction result;
        result.numerator = numerator * other.denominator + other.numerator * denominator;
        result.denominator = denominator * other.denominator;
        return result;
    }

    Fraction subtract(const Fraction& other) const {
        Fraction result;
        result.numerator = numerator * other.denominator - other.numerator * denominator;
        result.denominator = denominator * other.denominator;
        return result;
    }

    Fraction multiply(const Fraction& other) const {
        Fraction result;
        result.numerator = numerator * other.numerator;
        result.denominator = denominator * other.denominator;
        return result;
    }

    Fraction divide(const Fraction& other) const {
        Fraction result;
        result.numerator = numerator * other.denominator;
        result.denominator = denominator * other.numerator;
        return result;
    }

    bool isZero() const {
        return numerator == 0;
    }
};

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    Fraction first;
    Fraction second;

    cout << "Введите первую дробь:\n";
    first.input();

    cout << "Введите вторую дробь:\n";
    second.input();

    Fraction result;

    result = first.add(second);
    cout << "Сумма: ";
    result.print();
    cout << '\n';

    result = first.subtract(second);
    cout << "Разность: ";
    result.print();
    cout << '\n';

    result = first.multiply(second);
    cout << "Произведение: ";
    result.print();
    cout << '\n';

    if (second.isZero()) {
        cout << "Делить на нулевую дробь нельзя.\n";
    } else {
        result = first.divide(second);
        cout << "Частное: ";
        result.print();
        cout << '\n';
    }

    return 0;
}
