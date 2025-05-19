#include <iostream>
#include <map>
#include <string>
using namespace std;

class DomainIP {
private:
    map<string, string> data; // зберігаємо "домен → IP"
    int CodeError;            // код помилки

public:
    // Додавання пари домен-IP
    void add(string domain, string ip) {
        data[domain] = ip;
    }

    // Індексатор [] для отримання IP по домену
    string operator[](string domain) {
        if (data.find(domain) != data.end()) {
            CodeError = 0;
            return data[domain];
        } else {
            CodeError = 1;
            return "IP not found!";
        }
    }

    // Показати всі пари
    void printAll() {
        for (auto& pair : data) {
            cout << pair.first << " -> " << pair.second << endl;
        }
    }

    // Отримати код помилки
    int getError() const {
        return CodeError;
    }
};

// ====== ТЕСТ =======
int main() {
    DomainIP dns;

    dns.add("google.com", "8.8.8.8");
    dns.add("example.com", "93.184.216.34");

    cout << "google.com: " << dns["google.com"] << endl;
    cout << "unknown.com: " << dns["unknown.com"] << endl;

    cout << "CodeError: " << dns.getError() << endl;

    cout << "\nВсі домени:\n";
    dns.printAll();

    return 0;
}
