#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
public:
    string title;
    string author;

    Book(const string& t, const string& a) : title(t), author(a) {}
};

class Library {
private:
    vector<Book> books;

public:
    void addBook() {
        string title, author;
        cout << "Enter book title: ";
        getline(cin, title);
        cout << "Enter book author: ";
        getline(cin, author);
        books.push_back(Book(title, author));
        cout << "Book added successfully." << endl;
    }

    void displayBooks() {
        if (books.empty()) {
            cout << "No books available in the library." << endl;
        } else {
            cout << "Books available in the library:" << endl;
            for (const auto& book : books) {
                cout << "Title: " << book.title << ", Author: " << book.author << endl;
            }
        }
    }

    void findBook() {
        string title;
        cout << "Enter book title to search: ";
        getline(cin, title);
        bool found = false;
        for (const auto& book : books) {
            if (book.title == title) {
                cout << "Book found: Title: " << book.title << ", Author: " << book.author << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Book not found." << endl;
        }
    }

    void updateBook() {
        string title, newTitle;
        cout << "Enter book title to update: ";
        getline(cin, title);
        cout << "Enter new title: ";
        getline(cin, newTitle);
        bool found = false;
        for (auto& book : books) {
            if (book.title == title) {
                book.title = newTitle;
                cout << "Book updated successfully." << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Book not found." << endl;
        }
    }

    void deleteBook() {
        string title;
        cout << "Enter book title to delete: ";
        getline(cin, title);
        auto it = books.begin();
        bool found = false;
        while (it != books.end()) {
            if (it->title == title) {
                it = books.erase(it);
                cout << "Book deleted successfully." << endl;
                found = true;
                break;
            } else {
                ++it;
            }
        }
        if (!found) {
            cout << "Book not found." << endl;
        }
    }
};

int main() {
    Library library;

    while (true) {
        cout << "\n1. Add Book\n2. Display Books\n3. Find Book\n4. Update Book\n5. Delete Book\n6. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        cin.ignore(); // Ignore newline character
        switch (choice) {
            case 1:
                library.addBook();
                break;
            case 2:
                library.displayBooks();
                break;
            case 3:
                library.findBook();
                break;
        }
    }
return 0;
}
