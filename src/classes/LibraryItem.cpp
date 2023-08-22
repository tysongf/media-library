#include <string>
#include <cctype>

class LibraryItem {
    string uuid;
    string author;
    string title;
    string length;
    string description;
    
    static std::vector<char> valid_options { 'T', 'A', 'D', 'R', 'Q' };

    LibraryItem(
        const string& uuid {},
        const string& title {},
        const string& author {},
        const string& release_date {},
        const string& details {},
        ) :
        uuid(uuid), title(title), author(author) description(description)
    { }

    void display() {
        showItem();
        showMenu();
        getUserChoice();
    }

    void showItem() {
        std::string info {};
        info += "Title: " << this->title << "\n";
        info += "Author: " << this->author << "\n";
        info += "Description: " << this->description << "\n\n";
    }

    void showMenu() {
        std::string menu {};
        menu += "---[ OPTIONS ]---\n";
        menu += "[T] Edit Title\n";
        menu += "[A] Edit Author\n";
        menu += "[D] Edit Description\n";
        menu += "[M] Move to Basket\n";
        menu += "[R] Return to Shelf\n";
        menu += "[Q] Quit Program\n\n";
        std::cout << menu;
    }

    Library::moveBooks()

    char getUserChoice() {
        std::string input {' '};
        char selected_option{ '\0' };

        do {
            std::cout << ">";
            std::cin >> input || " ";
            char choice = std::toupper(input[0]);

            if (!input.empty()) {
                char choice = std::toupper(input[0]);
                if (isValid(choice)) {
                    selected_option = choice;
                }
                else {
                    std::cout << "Invalid option. Please try again." << std::endl;
                }
            }

        } while (selected_option == '\0');

        return choice;
    }

    bool isValid(char choice) {
        for (char valid_option : LibraryItem::valid_options) {
            if (choice == valid_option) {
                return true;
            }
        }
        return false;
    }

    void editProperty(string& property, string& propName) {
        std::cout << "Enter new " << propName << ": ";

        std::string newValue;
        std::cin >> newValue;
        property = newValue;

        std::cout << "\n" << propName << " has been updated successfully.\n";
        pauseForEnter();
    }

    void pauseForEnter() {
        std::cout << "Press [ENTER] to continue";
        std::cin; // Wait for user to hit ENTER
        std::cout << "\x1B[2J"; // ANSI CLEAR SCREEN
        display();
    }

};
