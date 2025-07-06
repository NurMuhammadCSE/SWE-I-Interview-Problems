#include <iostream>
#include <string>
using namespace std;

class Notebook {
private:
    string note;
public:
    void writeNote(string newNote) {
        note = newNote;
        cout << "Note written: " << note << endl;
    }

    void printNote() {
        cout << "Printing note: " << note << endl;
    }

    void saveToPDF() {
        cout << "Saving note to PDF: " << note << ".pdf" << endl;
    }
};

int main() {
    Notebook myNotebook;
    myNotebook.writeNote("This is my class note.");
    myNotebook.printNote();
    myNotebook.saveToPDF();

    return 0;
}

/*
🔴 সমস্যা:
Notebook class একসাথে ৩টা দায়িত্ব পালন করছে:
Write Note
Print Note
Save Note to PDF

এতে করে ক্লাসটি বড় হচ্ছে এবং পরিবর্তনের সময় একাধিক জায়গায় modify করতে হচ্ছে। এটি SRP লঙ্ঘন করছে।
*/