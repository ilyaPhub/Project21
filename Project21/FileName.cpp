#include <iostream>
using namespace std;

class MyString {
    char* str;           
    int length;         
    static int objectCount; 
public:
    MyString() {
        length = 80;
        str = new char[length + 1]; 
        strcpy(str, "");
        objectCount++;
    }

    MyString(int len) {
        length = len;
        str = new char[length + 1];
        strcpy(str, "");
        objectCount++;
    }

    MyString(const char* s) {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
        objectCount++;
    }

    ~MyString() {
        delete[] str;
    }

    void MyStrcpy(MyString& obj) {
        if (this != &obj) {
            delete[] str;
            length = obj.length;
            str = new char[length + 1];
            strcpy(str, obj.str);
        }
    }

    int MyStrStr(const char* substr) {
        char* pos = strstr(str, substr);
        if (pos != nullptr)
            return pos - str; 
        return -1;
    }

    int MyChr(char c) {
        char* pos = strchr(str, c);
        if (pos != nullptr)
            return pos - str;
        return -1;
    }

    int MyStrLen() const {
        return length;
    }

    void MyStrCat(MyString& b) {
        length += b.length;
        char* newStr = new char[length + 1];
        strcpy(newStr, str);
        strcat(newStr, b.str);
        delete[] str;
        str = newStr;
    }

    void MyDelChr(char c) {
        int newLength = 0;
        for (int i = 0; i < length; ++i) {
            if (str[i] != c)
                str[newLength++] = str[i];
        }
        str[newLength] = '\0';
        length = newLength;
    }

    int MyStrCmp(MyString& b) {
        int cmp = strcmp(str, b.str);
        if (cmp < 0) return -1;
        if (cmp > 0) return 1;
        return 0;
    }

    void Print() const {
        cout << str << endl;
    }

    static int GetObjectCount() {
        return objectCount;
    }
};

int MyString::objectCount = 0;

int main() {
    MyString s1; 
    MyString s2(20); 
    MyString s3("Hello, world!"); 

    s1.MyStrcpy(s3);  
    cout << "s1 після копіювання: ";
    s1.Print();

    cout << "Індекс підрядка \"world\": " << s1.MyStrStr("world") << endl;
    cout << "Індекс символа 'o': " << s1.MyChr('o') << endl;

    s1.MyStrCat(s3);  
    cout << "s1 після об'єднання з s3: ";
    s1.Print();

    s1.MyDelChr('o'); 
    cout << "s1 після видалення 'o': ";
    s1.Print();

    cout << "Порівняння s1 і s3: " << s1.MyStrCmp(s3) << endl;

    cout << "Кількість створених об'єктів: " << MyString::GetObjectCount() << endl;

    return 0;
}
