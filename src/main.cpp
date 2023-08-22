#include "./classes/Library.cpp"
#include <string>

int main() {
	Library myLibrary = Library("My Library");
	std::cout << "Welcome to " << myLibrary.name;
	myLibrary.display();
}