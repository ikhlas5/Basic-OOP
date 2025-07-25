#include <iostream>
using namespace std;

class Product {
    private:
        string id;
        string name;
        string category;
        double price;
        int quantity;

    public:
        Product(string id, string name, string category, double price, int quantity) {
            this->id = id;
            this->name = name;
            this->category = category;
            this->price = price;
            this->quantity = quantity;
        }

        string getId() {
            return this->id;
        }

        void setId(string id) {
            this->id = id;
        }

        string getName() {
            return this->name;
        }

        void setName(string name) {
            this->name = name;
        }

        string getCategory() {
            return this->category;
        }

        void setCategory(string category) {
            this->category = category;
        }

        double getPrice() {
            return this->price;
        }

        void setPrice(double price) {
            this->price = price;
        }

        int getQuantity() {
            return this->quantity;
        }

        void setQuantity(int quantity) {
            this->quantity = quantity;
        }

        int operator>(Product product) {
            if(this->price > product.getPrice()) {
                cout << "Product: " << this->name << "'s price(" << this->price << ") is greater than the product: " << product.getName() << "'s price(" << product.getPrice() << ")." << endl;
                cout << "Return value: " << endl;
                return 1;
            }
            else if(this->price < product.getPrice()) {
                cout << "Product: " << this->name << "'s price(" << this->price << ") is less than the product: " << product.getName() << "'s price(" << product.getPrice() << ")." << endl;
                cout << "Return value: " << endl;
                return -1;
            }
            else {
                cout << "Product: " << this->name << "'s price(" << this->price << ") is equal to the product: " << product.getName() << "'s price(" << product.getPrice() << ")." << endl;
                cout << "Return value: " << endl;
                return 0;
            }
        }

        friend int operator<(Product product1, Product product2) {
            if(product1.quantity < product2.quantity) {
                cout << "Product: " << product1.name << "'s quantity(" << product1.quantity << ") is less than the product: " << product2.name << "'s quantity(" << product2.quantity << ")." << endl;
                cout << "Return value: " << endl;
                return 1;
            }
            else if(product1.quantity > product2.quantity) {
                cout << "Product: " << product1.name << "'s quantity(" << product1.quantity << ") is greater than the product: " << product2.name << "'s quantity(" << product2.quantity << ")." << endl;
                cout << "Return value: " << endl;
                return -1;
            }
            else {
                cout << "Product: " << product1.name << "'s quantity(" << product1.quantity << ") is equal to the product: " << product2.name << "'s quantity(" << product2.quantity << ")." << endl;
                cout << "Return value: " << endl;
                return 0;
            }
        }
};

int main() {
    Product p1("Sh-001", "Sunsilk (500ml)", "Shampoo", 350.0, 22);
    Product p2("Sh-002", "Sunsilk (1000ml)", "Shampoo", 600.0, 12);
    Product p3("Sh-003", "Clinic Plus (500ml)", "Shampoo", 300.0, 42);
    Product p4("Sh-004", "Clinic Plus (1000ml)", "Shampoo", 550.0, 12);

    cout << "Product Price Check:" << endl;
    cout << "(p1 > p4): " << endl << (p1 > p4) << endl;
    cout << "(p3 > p2): " << endl << (p3 > p2) << endl;

    cout << "Product Quantity Check:" << endl;
    cout << "(p2 < p4):" << endl << (p2 < p4) << endl;
    cout << "(p4 < p1):" << endl << (p4 < p1) << endl;
}