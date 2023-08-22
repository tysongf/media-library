#include <string>
#include <unordered_set>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

class LibraryShelf {
public:
    std::string name;
    std::set<LibraryItem> items;

    LibraryShelf(const std::string& shelfName)
        : name(shelfName) {}

    struct CompareProperty {
        std::string property;
        bool direction;

        bool operator()(const LibraryItem& lhs, const LibraryItem& rhs) const {
            if (property == "author") {
                return direction ? (lhs.author < rhs.author) : (lhs.author > rhs.author);
            }
            if (property == "title") {
                return direction ? (lhs.title < rhs.title) : (lhs.title > rhs.title);
            }
            return false; // Default case
        }
    };

    void showMenu() {
        std::string menu {};
        menu += "---[ OPTIONS ]---\n";
        menu += "[E] Edit Shelf\n";
        menu += "[L] Look at Books\n";
        menu += "[D] Deposit Books\n";
        menu += "[R] Return to Library\n";
        menu += "[Q] Quit Program\n\n";
        std::cout << menu;
    }

    void sortItemsBy(const std::string& property, bool direction) {
        CompareProperty compare = { property, direction };
        std::set<LibraryItem, CompareProperty> sortedSet(compare);
        sortedSet.insert(items.begin(), items.end());
        items = sortedSet;
    }

    void addItem(const LibraryItem& item) {
        items.insert(item);
    }

    void removeItem(const LibraryItem& item) {
        items.erase(item);
    }

    void transferItem()

};
