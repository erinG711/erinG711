#include <iostream>
using namespace std;

string Text;
string Key;

void TextAndKey()
{
    string text;
    cout << "Enter Your Text: ";
    getline(cin, text);
    cin.ignore();

    for(int i = 0; i < text.length(); i++)
    {
        text[i] = toupper(text[i]);
    }

    string keyword;
    cout << "Enter The Keyword: ";
    getline(cin, keyword);
    cin.ignore();

    for(int i = 0; i < keyword.length(); i++)
    {
        keyword[i] = toupper(keyword[i]);
    }

    string KeyToText = "";
    for (int i = 0, j = 0; i < text.length();i++)
    {
        if(text[i] == 32)
        {
            KeyToText += 32;
        } 
        else 
        {
            if(j < keyword.length())
            {
                KeyToText += keyword[j];
                j++;
            } 
            else 
            {
                j = 0;
                KeyToText += keyword[j];
                j++;
            }
        } 
    } 

    Text = text;
    Key = KeyToText;
}

int TableArray[26][26];
void VigenereTable()
{
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            int temp;
            if ((i + 65) + j > 90)
            {
                temp = ((i + 65) + j) - 26;
                TableArray[i][j] = temp;
            } else {
                temp = (i + 65) + j;
                TableArray[i][j] = temp;
            }
        } 
    } 
}

int ItrCount(int keyword, int text)
{
    int counter = 0;
    string result = "";

    for(int i = 0; i < 26; i++)
    {
        if(keyword + i > 90)
        {
            result += (char)(keyword+(i - 26));
        } 
        else 
        {
            result += (char)(keyword+i);
        }
    } 

    for(int i = 0; i < result.length(); i++)
    {
        if(result[i] == text)
        {
            break;
        } 
        else 
        {
            counter++;
        }
    }
    return counter;
}

void cipherEncryption(string Text, string Key)
{
    VigenereTable();
    string encryptedText = "";
    for(int i = 0; i < Text.length(); i++)
    {
        if(Text[i] == 32 && Key[i] == 32)
        {
            encryptedText += " ";
        } 
        else 
        {
            int x = (int)Text[i] - 65;
            int y = (int)Key[i] - 65;
            encryptedText += (char)TableArray[x][y];
        }
    }
    cout << "The Encrypted Text Is: " << encryptedText;
}

void cipherDecryption(string Text, string Key)
{
    string decryptedText = "";
    for(int i = 0; i < Text.length(); i++)
    {
        if(Text[i] == 32 && Key[i] == 32)
        {
            decryptedText += " ";
        } 
        else
        {
            int temp = ItrCount((int)Key[i], (int)Text[i]);
            decryptedText += (char)(65 + temp);
        }
    }
    cout << "The Decrypted Text Is: " << decryptedText;
}


int main()
{
    cout << "Welcome to the Vigenere Cipher.\nPlease choose one of the following options." << endl;
    int choice;
    cout << "1. Encryption\n2. Decryption\n";
    cin >> choice;
    cin.ignore();

    if (choice == 1)
    {
        cout << "Your Choice Was Encryption." << endl;
        TextAndKey();
        cipherEncryption(Text, Key);
    } 
    else if (choice == 2)
    {
        cout << "Your Choice Was Decryption." << endl;
        TextAndKey();
        cipherDecryption(Text, Key);
    } 
    else 
    {
        cout << "Sorry, you can only pick from choices 1 or 2." << endl;
    }

    return 0;
}
