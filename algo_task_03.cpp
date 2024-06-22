#include <iostream>
#include <vector>

using namespace std;

class Item {
public:
  string name;
  int quantity;
  float price;

  Item(string name, int quantity, float price) {
    this->name = name;
    this->quantity = quantity;
    this->price = price;
  }
};

vector<Item> inventory;

void addItem() {
  string name;
  int quantity;
  float price;

  cout << "Masukkan nama barang: ";
  cin >> name;

  cout << "Masukkan jumlah barang: ";
  cin >> quantity;

  cout << "Masukkan harga satuan barang: ";
  cin >> price;

  inventory.push_back(Item(name, quantity, price));
}

// this function to add the param to enter the value

void showInventory() {
  if (inventory.empty()) {
    cout << "Inventaris kosong!" << endl;
    return;
  }

  cout << "Daftar Inventaris:" << endl;
  for (Item item : inventory) {
    cout << " - " << item.name << ": " << item.quantity << " pcs (Rp" << item.quantity * item.price << ")" << endl;
  }
}

// this function above explain about show invetory if null or exists

float calculateTotalValue() {
  float totalValue = 0;
  for (Item item : inventory) {
    totalValue += item.quantity * item.price;
  }
  return totalValue;
}

void showTotalValue() {
  if (inventory.empty()) {
    cout << "Inventaris kosong!" << endl;
    return;
  }

  float totalValue = calculateTotalValue();
  cout << "Nilai total inventaris: Rp. " << totalValue << endl;
}

int main() {
  int choice;

  while (true) {
    cout << "\nMenu Inventaris:" << endl;
    cout << "1. Tambah Barang" << endl;
    cout << "2. Tampilkan Inventaris" << endl;
    cout << "3. Hitung Nilai Total" << endl;
    cout << "4. Keluar" << endl;
    cout << "Masukkan pilihan Anda: ";
    cin >> choice;

    switch (choice) {
      case 1:
        addItem();
        break;
      case 2:
        showInventory();
        break;
      case 3:
        showTotalValue();
        break;
      case 4:
        cout << "Keluar dari program." << endl;
        exit(0);
      default:
        cout << "Pilihan tidak valid!" << endl;
    }
  }

  return 0;
}