#include <iostream>
#include <string>
using namespace std;

// শুধু নোট লেখার কাজ
class NoteWriter {
private:
    string note;
public:
    void writeNote(string newNote) {
        note = newNote;
        cout << "Note written: " << note << endl;
    }

    string getNote() {
        return note;
    }
};

// শুধু প্রিন্ট করার কাজ
class NotePrinter {
public:
    void printNote(const string& note) {
        cout << "Printing note: " << note << endl;
    }
};

// শুধু PDF-এ সেভ করার কাজ
class PDFSaver {
public:
    void saveToPDF(const string& note) {
        cout << "Saving note to PDF: " << note << ".pdf" << endl;
    }
};

int main() {
    NoteWriter writer;
    writer.writeNote("This is my class note.");

    string currentNote = writer.getNote();

    NotePrinter printer;
    printer.printNote(currentNote);

    PDFSaver saver;
    saver.saveToPDF(currentNote);

    return 0;
}

/*
✅ সুবিধা:
প্রতিটি ক্লাসের একটি দায়িত্ব আছে।

যদি ভবিষ্যতে PDF ফরম্যাট বদলাতে হয়, শুধু PDFSaver class modify করলেই চলবে।

সবকিছু loosely coupled এবং maintain করা সহজ।
*/