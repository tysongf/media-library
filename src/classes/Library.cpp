#include <string>
#include <set>
#include <vector>
#include "LibraryShelf.h"
#include "LibraryItem.h"

class Library {
public:
    Library(std::string&);
    std::string name {};
    static std::vector<LibraryShelf> shelves {};
    bool isValidChoice(char&);
    void display();
    void showMenu();
    char getUserChoice();
private:
    void displayShelves() {};
    std::vector<char> valid_options { 'L', 'A', 'O', 'Q' };
};

Library::Library(std::string& name) : name(name) { };

void Library::display() {
    showLibrary();
    showMenu();
    getUserChoice();
}
void Library::displayShelves() {
    if (shelves.empty()) {
        std::cout << "No shelves! "
    }
    for (int i; i < shelves.size(); ++i) {
        std::cout << "[" << i << "]" << shelves.at(i)->name << std::endl;
    }
}

void Library::showMenu() {
    std::string menu {};
    menu += "---[ OPTIONS ]---\n";
    menu += "[L] List Collections\n";
    menu += "[A] Add New Collection";
    menu += "[O] Open Collection\n";
    menu += "[Q] Quit Program\n\n";
    std::cout << menu;
}

char Library::getUserChoice() {
    std::string input {' '};
    char selected_option{ '\0' };

    do {
        std::cout << ">";
        std::cin >> input || " ";
        char choice = std::toupper(input[0]);

        if (!input.empty()) {
            char choice = std::toupper(input[0]);
            if (isValidChoice(choice)) {
                selected_option = choice;
            }
            else {
                std::cout << "Invalid option. Please try again." << std::endl;
            }
        }

    } while (selected_option == '\0');

    return choice;
}

bool Library::isValidChoice(char& choice) {
    for (char valid_option : LibraryItem::valid_options) {
        if (choice == valid_option) {
            return true;
        }
    }
    return false;
}
