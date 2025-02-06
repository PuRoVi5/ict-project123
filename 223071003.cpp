#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Flower {
    string name;
    double price;
};

class FlowerShop {
private:
    vector<Flower> flowers;

public:
    void addFlower() {
        Flower flower;
        cout << "Enter flower name: ";
        cin.ignore();
        getline(cin, flower.name);
        cout << "Enter flower price: ";
        cin >> flower.price;
        flowers.push_back(flower);
        cout << "Flower '" << flower.name << "' added successfully!\n";
    }

    void updateFlower() {
        string name;
        cout << "Enter the name of the flower to update: ";
        cin.ignore();
        getline(cin, name);

        bool found = false;
        for (size_t i = 0; i < flowers.size(); ++i) {
            if (flowers[i].name == name) {
                found = true;
                cout << "Current details: Name: " << flowers[i].name
                     << ", Price: " << fixed << setprecision(2) << flowers[i].price << endl;

                cout << "Enter new price: ";
                cin >> flowers[i].price;

                cout << "Flower '" << name << "' updated successfully!\n";
                break;
            }
        }
        if (!found) {
            cout << "Flower '" << name << "' not found!\n";
        }
    }

    void viewAllFlowers() {
        if (flowers.empty()) {
            cout << "No flowers available!\n";
        } else {
            cout << "All Flowers:\n";
            for (size_t i = 0; i < flowers.size(); ++i) {
                cout << i + 1 << ". Name: " << flowers[i].name
                     << ", Price: " << fixed << setprecision(2) << flowers[i].price << endl;
            }
        }
    }

    void run() {
        while (true) {
            cout << "\nFlower Shop Management\n";
            cout << "1. Add Flower\n";
            cout << "2. Update Flower\n";
            cout << "3. View All Flowers\n";
            cout << "4. Quit\n";
            cout << "Enter your choice: ";

            int choice;
            cin >> choice;

            switch (choice) {
                case 1:
                    addFlower();
                    break;
                case 2:
                    updateFlower();
                    break;
                case 3:
                    viewAllFlowers();
                    break;
                case 4:
                    cout << "Thank you for using the Flower Shop Management System. Goodbye!\n";
                    return;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        }
    }
};

int main() {
    FlowerShop shop;
    shop.run();
    return 0;
}
