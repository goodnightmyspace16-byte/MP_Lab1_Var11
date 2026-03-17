exchange_rates = {
    'RUB': 1.0,
    'USD': 0.012,
    'EUR': 0.010,
    'GBP': 0.009,
    'CNY': 0.085,
}

def convert_currency(amount, from_currency, to_currency):
    amount_in_rub = amount / exchange_rates[from_currency]
    result = amount_in_rub * exchange_rates[to_currency]
    return result

def print_available_currencies():
    print("Доступные валюты:")
    for currency in exchange_rates.keys():
        print(f"{currency}")

print("Конвертер валют\n")

while True:
    print_available_currencies()

    try:
        from_currency = input("Из какой валюты конвертировать:").upper()
        if from_currency not in exchange_rates:
            print("Валюты нет в списке")
            continue

        to_currency = input("В какую валюту конвертировать: ").upper()
        if to_currency not in exchange_rates:
            print("Валюты нет в списке")
            continue

        amount = float(input("Введите сумму: "))
        if amount < 0:
            print("Сумма не может быть отрицательной")
            continue

        result = convert_currency(amount, from_currency, to_currency)

        print(f"Результат: {amount} {from_currency} = {result:.2f} {to_currency}")

    except ValueError:
        print("Ошибка: введите число для суммы")

    again = input("Выполнить еще одну конвертацию? (да/нет): ").lower()
    if again not in ['да', 'yes', 'y', 'д']:
        break