#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <algorithm>

using namespace std;

// Курсы валют относительно RUB
map<string, double> exchange_rates = {
    {"RUB", 1.0},
    {"USD", 0.012},
    {"EUR", 0.010},
    {"GBP", 0.009},
    {"CNY", 0.085}
};

double convert_currency(double amount, const string& from_currency, const string& to_currency) {
    double amount_in_rub = amount / exchange_rates[from_currency];
    double result = amount_in_rub * exchange_rates[to_currency];
    return result;
}

void print_available_currencies() {
    cout << "Доступные валюты:" << endl;
    for (const auto& pair : exchange_rates) {
        cout << pair.first << endl;
    }
}

string to_upper(string str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

string to_lower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Конвертер валют\n" << endl;

    while (true) {
        print_available_currencies();

        string from_currency, to_currency;
        double amount;

        cout << "Из какой валюты конвертировать: ";
        cin >> from_currency;
        from_currency = to_upper(from_currency);

        if (exchange_rates.find(from_currency) == exchange_rates.end()) {
            cout << "Валюты нет в списке" << endl;
            continue;
        }

        cout << "В какую валюту конвертировать: ";
        cin >> to_currency;
        to_currency = to_upper(to_currency);

        if (exchange_rates.find(to_currency) == exchange_rates.end()) {
            cout << "Валюты нет в списке" << endl;
            continue;
        }

        cout << "Введите сумму: ";
        cin >> amount;

        if (cin.fail()) {
            cout << "Ошибка: введите число для суммы" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (amount < 0) {
            cout << "Сумма не может быть отрицательной" << endl;
            continue;
        }

        double result = convert_currency(amount, from_currency, to_currency);

        cout.precision(2);
        cout << fixed;
        cout << "Результат: " << amount << " " << from_currency
            << " = " << result << " " << to_currency << endl;

        cout << "Выполнить еще одну конвертацию? (да/нет): ";
        string again;
        cin >> again;
        again = to_lower(again);

        if (again != "да" && again != "yes" && again != "y" && again != "д") {
            break;
        }
    }

    return 0;
}