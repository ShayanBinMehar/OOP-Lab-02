#include <iostream>
#include <string>

using namespace std;

struct Product {
    int productID;
    string name;
    int quantity;
    double price;
};

void addProduct(Product*& products, int& numProducts) {
    Product newProduct;
    cout << "Enter Product ID: ";
    cin >> newProduct.productID;

    cout << "Enter Product Name: ";
    cin >> newProduct.name;

    cout << "Enter Quantity: ";
    cin >> newProduct.quantity;

    cout << "Enter Price: ";
    cin >> newProduct.price;

    Product* temp = new Product[numProducts + 1];
    for (int i = 0; i < numProducts; ++i) {
        temp[i] = products[i];
    }
    temp[numProducts] = newProduct;

    delete[] products;

    products = temp;
    numProducts++;
}

void removeProduct(Product*& products, int& numProducts, int productID) {
    int index = -1;
    for (int i = 0; i < numProducts; ++i) {
        if (products[i].productID == productID) {
            index = i;
            break;
        }
    }

    if (index != -1) {

        for (int i = index; i < numProducts - 1; ++i) {
            products[i] = products[i + 1];
        }

        Product* temp = new Product[numProducts - 1];
        for (int i = 0; i < numProducts - 1; ++i) {
            temp[i] = products[i];
        }

        delete[] products;

        products = temp;
        numProducts--;

        cout << "Product with ID " << productID << " removed successfully." << endl;
    } else {
        cout << "Product with ID " << productID << " not found." << endl;
    }
}

void updateProduct(Product* products, int numProducts, int productID) {
    int index = -1;
    for (int i = 0; i < numProducts; ++i) {
        if (products[i].productID == productID) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        cout << "Enter new quantity: ";
        cin >> products[index].quantity;
        cout << "Enter new price: ";
        cin >> products[index].price;
        cout << "Product information updated." << endl;
    } else {
        cout << "Product with ID " << productID << " not found." << endl;
    }
}

void displayInventoryValue(const Product* products, int numProducts) {
    double totalValue = 0;
    for (int i = 0; i < numProducts; ++i) {
        totalValue += products[i].quantity * products[i].price;
    }
    cout << "Total Inventory Value: $" << totalValue << endl;
}

int main() {
    int numProducts = 0;
    Product* products = nullptr;

    int choice;
    do {
        cout << "\nInventory Management System" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. Remove Product" << endl;
        cout << "3. Update Product" << endl;
        cout << "4. Display Inventory Value" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addProduct(products, numProducts);
                break;
            case 2: {
                int productID;
                cout << "Enter Product ID to remove: ";
                cin >> productID;
                removeProduct(products, numProducts, productID);
                break;
            }
            case 3: {
                int productID;
                cout << "Enter Product ID to update: ";
                cin >> productID;
                updateProduct(products, numProducts, productID);
                break;
            }
            case 4:
                displayInventoryValue(products, numProducts);
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    // Deallocate memory
    if (products != nullptr) {
        delete[] products;
    }

    return 0;
}