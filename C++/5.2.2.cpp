#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Store {
    string Name;
    string District;
    string Address;
    int OpenHour;
    int CloseHour;
};

int main() {
    int n, count = 0;
    string district;
    vector<Store> Stores;

    // Вводим количество магазинов
    cout << "Enter the number of stores: ";
    cin >> n;

    // Проверка на корректность количества магазинов
    if (n <= 0 || n > 100) {
        cout << "The number of stores must be between 1 and 100" << endl;
        return 1;
    }

    // Вводим данные о магазинах
    Stores.resize(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter details for the store " << i + 1 << ":" << endl;

        cout << "Name: ";
        cin.ignore();
        getline(cin, Stores[i].Name);

        cout << "District: ";
        getline(cin, Stores[i].District);

        cout << "Address: ";
        getline(cin, Stores[i].Address);

        cout << "Open hour (0-23): ";
        cin >> Stores[i].OpenHour;
        if (Stores[i].OpenHour < 0 || Stores[i].OpenHour > 23) {
            cout << "Open hour must be between 0 and 23" << endl;
            return 1;
        }

        cout << "Close hour (0-23): ";
        cin >> Stores[i].CloseHour;
        if (Stores[i].CloseHour < 0 || Stores[i].CloseHour > 23) {
            cout << "Close hour must be between 0 and 23" << endl;
            return 1;
        }
    }

    // Вводим район для поиска
    cout << "Enter area to search: ";
    cin.ignore();
    getline(cin, district);

    // Выводим книжные магазины данного района, работающие после 18 часов
    cout << "Bookstores in the area " << district << " working after 18:00:" << endl;
    for (const auto& store : Stores) {
        if (store.District == district && store.CloseHour > 18) {
            cout << "Name: " << store.Name << endl;
            cout << "Address: " << store.Address << endl;
            cout << "Working hours: " << store.OpenHour << " - " << store.CloseHour << endl;
            cout << endl;
            count++;
        }
    }

    // Выводим количество таких магазинов
    cout << "Number of such stores: " << count << endl;

    return 0;
}