#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <windows.h>
#include <limits>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
using namespace std;

void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void menuLine(string text)
{
    setColor(9); // Blue border
    cout << "┃ ";

    setColor(15); // White text
    cout << left << setw(38) << text;

    setColor(9); // Blue border
    cout << " ┃" << endl;
}

class contact
{
public:
    string name;
    string phone;
    string email;
    string city;
    bool fav = false;
    bool lock = false;
    bool block = false;
    // string status= "0";
    vector<contact> contacts;

    // TO ADD CONTACT
    void addcontact()
    {
        contact c;
        setColor(9);
        cout << "╔══════════════════════════════════════╗\n";
        cout << "║";

        setColor(15);
        cout << "            ADD CONTACT              ";

        setColor(9);
        cout << " ║\n";
        cout << "╚══════════════════════════════════════╝\n";
        setColor(15);
        cout << " Enter Name         : ";
        // cin >> c.name;
        cin.ignore();
        getline(cin, c.name);

        cout << " Enter Phone Number : ";
        cin >> c.phone;

        cout << " Enter Email        : ";
        cin >> c.email;

        cout << " Enter City         : ";
        // cin >> c.city;
        cin.ignore();
        getline(cin, c.city);

        system("cls"); // optional
        setColor(9);
        cout << "╔═════════════════════════════════════════════╗\n";
        cout << "║";

        setColor(15);
        cout << left << setw(45)
             << (" Name         : " + c.name);

        setColor(9);
        cout << "║\n";

        cout << "║";

        setColor(15);
        cout << left << setw(45)
             << (" Phone Number : " + c.phone);

        setColor(9);
        cout << "║\n";

        cout << "║";

        setColor(15);
        cout << left << setw(45)
             << (" Email        : " + c.email);

        setColor(9);
        cout << "║\n";

        cout << "║";

        setColor(15);
        cout << left << setw(45)
             << (" City         : " + c.city);

        setColor(9);
        cout << "║\n";
        cout << "╚═════════════════════════════════════════════╝\n";

        contacts.push_back(c);
        savedata();
        cout << endl;
        cout << "-----Contact Saved-----" << endl;
        cout << endl;
    }

    // TO VIEW CONTACT
    void viewcontact()
    {

        for (int i = 0; i < contacts.size(); i++)
        {
            if (contacts[i].lock == true)
            {
                continue;
            }
            cout << endl;
            // Blue border
            setColor(9);
            cout << "╔══════════════════════════════════════════════════╗\n";
            cout << "║";

            // White heading
            setColor(15);
            cout << "                   VIEW CONTACT              ";

            // Blue border
            setColor(9);
            cout << "     ║\n";
            cout << "╚══════════════════════════════════════════════════╝\n";

            // ---------- Name ----------
            setColor(9);
            cout << "║ ";

            setColor(15);
            cout << left << setw(15) << "👤 Name"
                 << "    : "
                 << left << setw(24) << contacts[i].name;

            setColor(9);
            cout << "      ║\n";

            // ---------- Phone ----------
            setColor(9);
            cout << "║ ";

            setColor(15);
            cout << left << setw(15) << "📞 Phone Number"
                 << "  : "
                 << left << setw(27) << contacts[i].phone;

            setColor(9);
            cout << "   ║\n";

            // ---------- Email ----------
            setColor(9);
            cout << "║ ";

            setColor(15);
            cout << left << setw(15) << "📧 Email"
                 << "    : "
                 << left << setw(30) << contacts[i].email;

            setColor(9);
            cout << "║\n";

            // ---------- City ----------
            setColor(9);
            cout << "║ ";

            setColor(15);
            cout << left << setw(15) << "📍 City"
                 << "    : "
                 << left << setw(27) << contacts[i].city;

            setColor(9);
            cout << "   ║\n";

            // Bottom border
            setColor(9);
            cout << "╚══════════════════════════════════════════════════╝\n";
            cout << endl;
        }
    }
    // TO DELETE CONTACT
    void deletecontact()
    {
        if (contacts.empty())
        {
            cout << endl;
            cout << "\nNo Contact Found" << endl;
            return;
        }
        string ph;
        // cout << "enter phone number to delete";
        // cin >> ph;

        setColor(9);
        cout << "╔══════════════════════════════════════════════════╗\n";
        cout << "║";

        // White heading
        setColor(15);
        cout << "                  DELETE CONTACT           ";

        // Blue border
        setColor(9);
        cout << "       ║\n";
        cout << "╚══════════════════════════════════════════════════╝\n";

        setColor(15);
        cout << " Enter Phone Number : ";
        cin >> ph;
        cout << endl;
        // cout << "║ Phone Number : "
        //              << left << setw(20)
        //              << c.phone << "  ║\n";
        // cout << "║ Enter Phone Number : "
        // cin >> ph;

        bool found = false;
        ;
        for (int i = 0; i < contacts.size(); i++)
        {
            if (contacts[i].phone == ph)
            {

                contacts.erase(contacts.begin() + i);
                setColor(9);
                cout << "╔══════════════════════════════════════════════════╗\n";
                cout << "║";

                // White heading
                setColor(15);
                cout << "             CONTACT DELETED SUCCESSFULLY        ";

                // Blue border
                setColor(9);
                cout << " ║\n";
                cout << "╚══════════════════════════════════════════════════╝\n";
                found = true;

                break;
            }
        }

        if (found)
        {
            savedata();
        }

        if (!found)
        {
            cout << endl;
            cout << "-----Contact Not Found-----" << endl;
            return;
        }
    }

    // TO SEARCH BY PHONE NUMBER
    void searchbyphone()
    {
        if (contacts.empty())
        {

            cout << "\nContact Empty" << endl;
            return;
        }
        string number;

        system("cls");

        setColor(9);
        cout << "╔══════════════════════════════════════════════════╗\n";
        cout << "║";

        // White heading
        setColor(15);
        cout << "            SEARCH BY NUMBER              ";

        // Blue border
        setColor(9);
        cout << "        ║\n";
        cout << "╚══════════════════════════════════════════════════╝\n";
        setColor(15);
        cout << "  Enter Phone number : ";
        cin >> number; // <-- INPUT IS HERE

        // cout << "Enter phone no to search: ";
        // cin >> number;
        cout << endl;

        bool found = false;
        for (int i = 0; i < contacts.size(); i++)
        {
            
            if (number == contacts[i].phone)
            {
                if (contacts[i].lock)
            {
                cout << "Contact Locked";
                return;
            }
                setColor(9);
                cout << "╔══════════════════════════════════════════════════╗\n";
                cout << "║";

                // White heading
                setColor(15);
                cout << "            FOUND               ";

                // Blue border
                setColor(9);
                cout << "                  ║\n";
                cout << "╚══════════════════════════════════════════════════╝\n";
                setColor(9);
                cout << "║ ";

                setColor(15);
                cout << left << setw(15) << "👤 Name"
                     << "    : "
                     << left << setw(24) << contacts[i].name;

                setColor(9);
                cout << "      ║\n";

                // ---------- Phone ----------
                setColor(9);
                cout << "║ ";

                setColor(15);
                cout << left << setw(15) << "📞 Phone Number"
                     << "  : "
                     << left << setw(27) << contacts[i].phone;

                setColor(9);
                cout << "   ║\n";

                // ---------- Email ----------
                setColor(9);
                cout << "║ ";

                setColor(15);
                cout << left << setw(15) << "📧 Email"
                     << "    : "
                     << left << setw(30) << contacts[i].email;

                setColor(9);
                cout << "║\n";

                // ---------- City ----------
                setColor(9);
                cout << "║ ";

                setColor(15);
                cout << left << setw(15) << "📍 City"
                     << "    : "
                     << left << setw(27) << contacts[i].city;

                setColor(9);
                cout << "   ║\n";

                // Bottom border
                setColor(9);
                cout << "╚══════════════════════════════════════════════════╝\n";

                found = true;
                return;
            }
        }

        if (!found)
        {
            cout << endl;
            cout << " Contact Not Found" << endl;
            return;
        }
    }

    // TO SEARCH BY NAME
    void searchbyname()
    {
        if (contacts.empty())
        {
            cout << endl;
            cout << " Contact Empty" << endl;
            return;
        }
        string n;
        bool found = false;
        cout << endl;
        setColor(9);
        cout << "╔══════════════════════════════════════════════════╗\n";
        cout << "║";

        // White heading
        setColor(15);
        cout << "                   SEARCH BY NAME              ";

        // Blue border
        setColor(9);
        cout << "   ║\n";
        cout << "╚══════════════════════════════════════════════════╝\n";
        setColor(15);

        cout << "  Enter Name : ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, n); // <-- INPUT IS HERE
        // cout << " Enter Name to Find: ";
        // cin >> n;
        cout << endl;
        for (int i = 0; i < contacts.size(); i++)
        {

            if (contacts[i].name == n)
            {
                if (contacts[i].lock)
                {
                    cout << "Contact Locked";
                    return;
                }
                setColor(9);
                cout << "╔══════════════════════════════════════════════════╗\n";
                cout << "║";

                // White heading
                setColor(15);
                cout << "                      FOUND               ";

                // Blue border
                setColor(9);
                cout << "        ║\n";
                cout << "╚══════════════════════════════════════════════════╝\n";
                setColor(9);
                cout << "║ ";

                setColor(15);
                cout << left << setw(15) << "👤 Name"
                     << "    : "
                     << left << setw(24) << contacts[i].name;

                setColor(9);
                cout << "      ║\n";

                // ---------- Phone ----------
                setColor(9);
                cout << "║ ";

                setColor(15);
                cout << left << setw(15) << "📞 Phone Number"
                     << "  : "
                     << left << setw(27) << contacts[i].phone;

                setColor(9);
                cout << "   ║\n";

                // ---------- Email ----------
                setColor(9);
                cout << "║ ";

                setColor(15);
                cout << left << setw(15) << "📧 Email"
                     << "    : "
                     << left << setw(30) << contacts[i].email;

                setColor(9);
                cout << "║\n";

                // ---------- City ----------
                setColor(9);
                cout << "║ ";

                setColor(15);
                cout << left << setw(15) << "📍 City"
                     << "    : "
                     << left << setw(27) << contacts[i].city;

                setColor(9);
                cout << "   ║\n";

                // Bottom border
                setColor(9);
                cout << "╚══════════════════════════════════════════════════╝\n";

                // cout << " Name: " << contacts[i].name << endl;
                // cout << " Phone: " << contacts[i].phone << endl;
                // cout << " Email: " << contacts[i].email << endl;
                // cout << " City: " << contacts[i].city << endl;
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << endl;
            cout << "---------CONTACT NOT FOUND----------" << endl;
            return;
        }
    }

    // TO UPDATE BY NUMBER
    void updatenumber()
    {
        if (contacts.empty())
        {
            cout << "\nNo Contact Found" << endl;
            return;
        }
        string ph;

        cout << endl;
        // cout << " Enter Phone Number to Update: ";
        // cin >> ph;

        system("cls");

        setColor(9);
        cout << "╔══════════════════════════════════════════════════╗\n";
        cout << "║";

        // White heading
        setColor(15);
        cout << "                 OLD PHONE NUMBER              ";

        // Blue border
        setColor(9);
        cout << "   ║\n";
        cout << "╚══════════════════════════════════════════════════╝\n";

        setColor(15);

        cout << "  Enter Old Phone : ";
        cin >> ph; // <-- INPUT IS HERE

        for (int i = ph.length(); i < 17; i++)
        {
            cout << " ";
        }

        cout << endl;
        bool found = false;
        for (int i = 0; i < contacts.size(); i++)
        {
            if (contacts[i].phone == ph)
            {
                // cout << " Enter New Phone Number: ";
                // cin >> ph;
                setColor(9);
                cout << "╔══════════════════════════════════════════════════╗\n";
                cout << "║";

                // White heading
                setColor(15);
                cout << "                 UPDATE PHONE NUMBER              ";

                // Blue border
                setColor(9);
                cout << "║\n";
                cout << "╚══════════════════════════════════════════════════╝\n";

                setColor(15);

                cout << "  Enter New Phone : ";
                cin >> ph;
                contacts[i].phone = ph;
                for (int i = ph.length(); i < 18; i++)
                {
                    cout << " ";
                }

                savedata();
                cout << endl;
                // cout << "----Contact Successfully Updated ---" << endl;
                setColor(9);
                cout << "╔══════════════════════════════════════════════════╗\n";
                cout << "║";

                // White heading
                setColor(15);
                cout << "             CONTACT UPATED SUCCESSFULLY          ";

                // Blue border
                setColor(9);
                cout << "║\n";
                cout << "╚══════════════════════════════════════════════════╝\n";

                setColor(15);
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << endl;
            // cout << "\nContact Not Found" << endl;
            cout << "\n";
            cout << "-------CONTACT NOT FOUND----------!";
        }
    }
    void updatename()
    {
        if (contacts.empty())
        {
            cout << endl;
            cout << "\nNo contact found" << endl;
            return;
        }
        string ph;
        string p;
        cout << endl;
        // cout << " Enter Name to Update: ";
        // cin >> ph;
        system("cls");
        setColor(9);
        cout << "╔══════════════════════════════════════════════════╗\n";
        cout << "║";

        // White heading
        setColor(15);
        cout << "                    CURRENT NAME              ";

        // Blue border
        setColor(9);
        cout << "    ║\n";
        cout << "╚══════════════════════════════════════════════════╝\n";

        setColor(15);
        cout << "  Enter Current Name : ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, ph); // <-- INPUT IS HERE

        for (int i = ph.length(); i < 17; i++)
        {
            cout << " ";
        }
        cout << endl;
        bool found = false;
        for (int i = 0; i < contacts.size(); i++)
        {
            if (contacts[i].name == ph)
            {
                cout << endl;
                // cout << " Enter New Name: ";
                // cin >> contacts[i].name;
                setColor(9);
                cout << "╔══════════════════════════════════════════════════╗\n";
                cout << "║";

                // White heading
                setColor(15);
                cout << "                    UPDATE NAME              ";

                // Blue border
                setColor(9);
                cout << "     ║\n";
                cout << "╚══════════════════════════════════════════════════╝\n";

                setColor(15);

                cout << "  Enter New Name : ";
                getline(cin, p);
                contacts[i].name = p;
                for (int j = p.length(); j < 18; j++)
                {
                    cout << " ";
                }
                savedata();
                cout << endl;

                setColor(9);
                cout << "╔══════════════════════════════════════════════════╗\n";
                cout << "║";

                // White heading
                setColor(15);
                cout << "            CONTACT UPDATED SUCCESSFULLY        ";

                // Blue border
                setColor(9);
                cout << "  ║\n";
                cout << "╚══════════════════════════════════════════════════╝\n";

                setColor(15);
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "\n";
            cout << "CONTACT NOT FOUND!";
        }
    }

    // UPDATE EMAIL
    void updateemail()
    {
        if (contacts.empty())
        {
            cout << endl;
            cout << "\nNo Contact Found" << endl;
            return;
        }
        string ph;
        cout << endl;
        system("cls");
        setColor(9);
        cout << "╔══════════════════════════════════════════════════╗\n";
        cout << "║";

        // White heading
        setColor(15);
        cout << "                     OLD EMAIL         ";

        // Blue border
        setColor(9);
        cout << "           ║\n";
        cout << "╚══════════════════════════════════════════════════╝\n";

        setColor(15);
        cout << " Enter Email to Update: ";
        cin >> ph;
        bool found = false;
        for (int i = 0; i < contacts.size(); i++)
        {
            if (contacts[i].email == ph)
            {
                // cout << " Enter New Email: ";

                setColor(9);
                cout << "╔══════════════════════════════════════════════════╗\n";
                cout << "║";

                // White heading
                setColor(15);
                cout << "                      NEW EMAIL         ";

                // Blue border
                setColor(9);
                cout << "          ║\n";
                cout << "╚══════════════════════════════════════════════════╝\n";

                setColor(15);
                string p;
                cout << "  Enter New Email : ";
                cin >> p;
                contacts[i].email = p;
                savedata();
                cout << endl;
                setColor(9);
                cout << "╔══════════════════════════════════════════════════╗\n";
                cout << "║";

                // White heading
                setColor(15);
                cout << "            CONTACT UPDATED SUCCESSFULLY        ";

                // Blue border
                setColor(9);
                cout << "  ║\n";
                cout << "╚══════════════════════════════════════════════════╝\n";

                setColor(15);
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << endl;
            cout << "---------CONTACT NOT FOUND---------";
        }
    }

    // UPDATE CITY
    void updatecity()
    {
        if (contacts.empty())
        {
            cout << endl;
            cout << "\nNo Contact Found" << endl;
            return;
        }
        string ph;
        string name;
        cout << endl;
        system("cls");
        setColor(9);
        cout << "╔══════════════════════════════════════════════════╗\n";
        cout << "║";

        // White heading
        setColor(15);
        cout << "                    UPDATE CITY       ";

        // Blue border
        setColor(9);
        cout << "            ║\n";
        cout << "╚══════════════════════════════════════════════════╝\n";

        setColor(15);
        cout << " Enter Name: ";
        getline(cin >> ws, name);
        cout << " Enter Name of old City: ";
        getline(cin >> ws, ph);
        bool found = false;
        for (int i = 0; i < contacts.size(); i++)
        {
            if (contacts[i].city == ph && contacts[i].name == name)
            {
                cout << endl;

                setColor(9);
                cout << "╔══════════════════════════════════════════════════╗\n";
                cout << "║";

                // White heading
                setColor(15);
                cout << "                    UPDATE CITY         ";

                // Blue border
                setColor(9);
                cout << "          ║\n";
                cout << "╚══════════════════════════════════════════════════╝\n";

                setColor(15);
                string newcity;
                cout << " Enter New City: ";
                getline(cin >> ws, newcity);
                contacts[i].city = newcity;
                savedata();
                cout << endl;
                setColor(9);
                cout << "╔══════════════════════════════════════════════════╗\n";
                cout << "║";

                // White heading
                setColor(15);
                cout << "            CONTACT UPDATED SUCCESSFULLY        ";

                // Blue border
                setColor(9);
                cout << "  ║\n";
                cout << "╚══════════════════════════════════════════════════╝\n";

                setColor(15);
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << endl;
            cout << "\n-------CONTACT NOT FOUND-------" << endl;
        }
    }

    // TO SORT IN ASCENDING ORDER
    void sortcontactasc()
    {
        for (int i = 0; i < contacts.size() - 1; i++)
        {
            for (int j = 0; j < contacts.size() - i - 1; j++)
            {
                if (contacts[j].name > contacts[j + 1].name)
                {
                    swap(contacts[j], contacts[j + 1]);
                }
            }
        }

        savedata();
        for (int i = 0; i < contacts.size(); i++)
        {
            setColor(9);
            cout << "╔══════════════════════════════════════════════════╗\n";
            cout << "║";

            // White heading
            setColor(15);
            cout << "                   SORTED CONTACTS               ";

            // Blue border
            setColor(9);
            cout << "     ║\n";
            cout << "╚══════════════════════════════════════════════════╝\n";
            setColor(9);
            cout << "║ ";

            setColor(15);
            cout << left << setw(15) << "👤 Name"
                 << "    : "
                 << left << setw(24) << contacts[i].name;

            setColor(9);
            cout << "      ║\n";

            // ---------- Phone ----------
            setColor(9);
            cout << "║ ";

            setColor(15);
            cout << left << setw(15) << "📞 Phone Number"
                 << "  : "
                 << left << setw(27) << contacts[i].phone;

            setColor(9);
            cout << "   ║\n";

            // ---------- Email ----------
            setColor(9);
            cout << "║ ";

            setColor(15);
            cout << left << setw(15) << "📧 Email"
                 << "    : "
                 << left << setw(30) << contacts[i].email;

            setColor(9);
            cout << "║\n";

            // ---------- City ----------
            setColor(9);
            cout << "║ ";

            setColor(15);
            cout << left << setw(15) << "📍 City"
                 << "    : "
                 << left << setw(27) << contacts[i].city;

            setColor(9);
            cout << "   ║\n";

            // Bottom border
            setColor(9);
            cout << "╚══════════════════════════════════════════════════╝\n";
        }
    }

    // TO SORT IN DESCENDING ORDER
    void sortcontactdes()
    {
        for (int i = 0; i < contacts.size() - 1; i++)
        {
            for (int j = 0; j < contacts.size() - i - 1; j++)
            {
                if (contacts[j].name < contacts[j + 1].name)
                {
                    swap(contacts[j], contacts[j + 1]);
                }
            }
        }
        savedata();
        for (int i = 0; i < contacts.size(); i++)
        {
            setColor(9);
            cout << "╔══════════════════════════════════════════════════╗\n";
            cout << "║";

            // White heading
            setColor(15);
            cout << "                   SORTED CONTACTS              ";

            // Blue border
            setColor(9);
            cout << "     ║\n";
            cout << "╚══════════════════════════════════════════════════╝\n";
            setColor(9);
            cout << "║ ";
            setColor(15);
            cout << left << setw(15) << "👤 Name"
                 << "    : "
                 << left << setw(24) << contacts[i].name;

            setColor(9);
            cout << "      ║\n";

            // ---------- Phone ----------
            setColor(9);
            cout << "║ ";

            setColor(15);
            cout << left << setw(15) << "📞 Phone Number"
                 << "  : "
                 << left << setw(27) << contacts[i].phone;

            setColor(9);
            cout << "   ║\n";

            // ---------- Email ----------
            setColor(9);
            cout << "║ ";

            setColor(15);
            cout << left << setw(15) << "📧 Email"
                 << "    : "
                 << left << setw(30) << contacts[i].email;

            setColor(9);
            cout << "║\n";

            // ---------- City ----------
            setColor(9);
            cout << "║ ";

            setColor(15);
            cout << left << setw(15) << "📍 City"
                 << "    : "
                 << left << setw(27) << contacts[i].city;

            setColor(9);
            cout << "   ║\n";

            // Bottom border
            setColor(9);
            cout << "╚══════════════════════════════════════════════════╝\n";
        }
    }

    // TO SAVE DATA TO FILE
    void savedata()
    {
        ofstream fout("contacts.txt");
        int n = contacts.size();
        string s, s1, s2;
        for (int i = 0; i < n; i++)
        {
            s = to_string(contacts[i].fav);
            s1 = to_string(contacts[i].block);
            s2 = to_string(contacts[i].lock);
            fout << contacts[i].name << "|";
            fout << contacts[i].phone << "|";
            fout << contacts[i].email << "|";
            fout << contacts[i].city << "|";

            contacts[i].fav = (s == "1");
            contacts[i].block = (s1 == "1");
            contacts[i].lock = (s2 == "1");

            fout << s << "|";
            fout << s1 << "|";
            fout << s2;

            fout << endl;
        }
        fout.close();
    }

    // TO LOAD DATA FROM FILE
    void loaddata()
    {
        contacts.clear();
        ifstream fin("contacts.txt");
        if (!fin)
        {
            return;
        }
        contact temp;
        string s1, s2, s;
        while (getline(fin, temp.name, '|'))
        {
            //      s = to_string(fav);
            //      s1 = to_string(block);
            //      s2 = to_string(lock);
            getline(fin, temp.phone, '|');
            getline(fin, temp.email, '|');
            getline(fin, temp.city, '|');

            getline(fin, s, '|');
            getline(fin, s1, '|');
            getline(fin, s2);
            temp.fav = (s == "1");
            temp.block = (s1 == "1");
            temp.lock = (s2 == "1");

            contacts.push_back(temp);
            // cout<<"0";
        }

        fin.close();
    }

    // TO EXIT FROM PROGRAM
    void exit()
    {
        cout << "✧══════════════════════════════════════✧\n";
        cout << "║         🌸 PROGRAM ENDED 🌸          ║\n";
        cout << "✧══════════════════════════════════════✧\n";
        // cout << "---------Program Ended-----------" << endl;
        return;
    }

    // TO ADD TO FAVOURITE
    void addfav()
    {
        string ph;
        cout << endl;
        setColor(9);
        cout << "╔══════════════════════════════════════════════════╗\n";
        cout << "║";

        // White heading
        setColor(15);
        cout << "                  ADD TO FAVOURITES              ";

        // Blue border
        setColor(9);
        cout << " ║\n";
        cout << "╚══════════════════════════════════════════════════╝\n";
        setColor(15);
        cout << " Enter Favorite Phone Number: ";
        cin >> ph;
        for (int i = 0; i < contacts.size(); i++)
        {
            // cout << "yes";
            if (contacts[i].phone == ph)
            {
                if (contacts[i].fav)
                {
                    cout << "Already in Favourite List." << endl;
                    return;
                }
                contacts[i].fav = true;
                savedata();
                cout << endl;
                setColor(9);
                cout << "╔══════════════════════════════════════════════════╗\n";
                cout << "║";

                // White heading
                setColor(15);
                cout << "                 ADDED TO FAVOURITES              ";

                // Blue border
                setColor(9);
                cout << "║\n";
                cout << "╚══════════════════════════════════════════════════╝\n";
                setColor(15);
                return;
            }
            // cout << endl;
            // cout << " Contact Not Found" << endl;
            // return;
        }
        cout << endl;
        cout << " Contact Not Found" << endl;
        return;
    }

    // TO DISPLAY FAVOURITE
    void showfav()
    {
        bool found = false;
        int n = contacts.size();
        for (int i = 0; i < n; i++)
        {
            if (contacts[i].fav && !contacts[i].lock)
            {
                found = true;
                cout << endl;
                setColor(9);
                cout << "╔══════════════════════════════════════════════════╗\n";
                cout << "║";

                // White heading
                setColor(15);
                cout << "                  FAVOURITES LIST             ";

                // Blue border
                setColor(9);
                cout << "    ║\n";
                cout << "╚══════════════════════════════════════════════════╝\n";

                // ---------- Name ----------

                setColor(15);
                setColor(9);
                cout << "║ ";

                setColor(15);
                cout << left << setw(15) << "👤 Name"
                     << "    : "
                     << left << setw(24) << contacts[i].name;

                setColor(9);
                cout << "      ║\n";

                // ---------- Phone ----------
                setColor(9);
                cout << "║ ";

                setColor(15);
                cout << left << setw(15) << "📞 Phone Number"
                     << "  : "
                     << left << setw(27) << contacts[i].phone;

                setColor(9);
                cout << "   ║\n";

                // ---------- Email ----------
                setColor(9);
                cout << "║ ";

                setColor(15);
                cout << left << setw(15) << "📧 Email"
                     << "    : "
                     << left << setw(30) << contacts[i].email;

                setColor(9);
                cout << "║\n";

                // ---------- City ----------
                setColor(9);
                cout << "║ ";

                setColor(15);
                cout << left << setw(15) << "📍 City"
                     << "    : "
                     << left << setw(27) << contacts[i].city;

                setColor(9);
                cout << "   ║\n";

                // Bottom border
                setColor(9);
                cout << "╚══════════════════════════════════════════════════╝\n";
                cout << endl;

                // return;
            }
        }

        if (!found)
        {
            cout << endl;
            cout << " Favorites Not Found.";
        }
    }

    // BLOCK CONTACT
    void blocked()
    {
        string ph;
        cout << endl;
        setColor(9);
        cout << "╔══════════════════════════════════════════════════╗\n";
        cout << "║";

        // White heading
        setColor(15);
        cout << "                  BLOCK CONTACTS       ";

        // Blue border
        setColor(9);
        cout << "           ║\n";
        cout << "╚══════════════════════════════════════════════════╝\n";

        setColor(15);
        cout << " Enter Phone Number to Block: ";
        cin >> ph;
        for (int i = 0; i < contacts.size(); i++)
        {
            if (contacts[i].phone == ph)
            {
                contacts[i].block = true;
                savedata();
                cout << endl;
                setColor(9);
                cout << "╔══════════════════════════════════════════════════╗\n";
                cout << "║";

                // White heading
                setColor(15);
                cout << "                ADDED TO BLOCKED LIST       ";

                // Blue border
                setColor(9);
                cout << "      ║\n";
                cout << "╚══════════════════════════════════════════════════╝\n";

                setColor(15);
                return;
            }
        }
        cout << endl;
        cout << " Contact Not Found" << endl;
        return;
    }

    // TO DISPLAY BLOCK CONTACT
    void showblock()
    {
        int f = 0;
        int n = contacts.size();
        for (int i = 0; i < n; i++)
        {
            if (contacts[i].block == true)
            {
                cout << endl;
                setColor(9);
                cout << "╔══════════════════════════════════════════════════╗\n";
                cout << "║";

                // White heading
                setColor(15);
                cout << "                  BLOCKED LIST             ";

                // Blue border
                setColor(9);
                cout << "       ║\n";
                cout << "╚══════════════════════════════════════════════════╝\n";

                // ---------- Name ----------

                setColor(15);
                setColor(9);
                cout << "║ ";

                setColor(15);
                cout << left << setw(15) << "👤 Name"
                     << "    : "
                     << left << setw(24) << contacts[i].name;

                setColor(9);
                cout << "      ║\n";

                // ---------- Phone ----------
                setColor(9);
                cout << "║ ";

                setColor(15);
                cout << left << setw(15) << "📞 Phone Number"
                     << "  : "
                     << left << setw(27) << contacts[i].phone;

                setColor(9);
                cout << "   ║\n";

                // ---------- Email ----------
                setColor(9);
                cout << "║ ";

                setColor(15);
                cout << left << setw(15) << "📧 Email"
                     << "    : "
                     << left << setw(30) << contacts[i].email;

                setColor(9);
                cout << "║\n";

                // ---------- City ----------
                setColor(9);
                cout << "║ ";

                setColor(15);
                cout << left << setw(15) << "📍 City"
                     << "    : "
                     << left << setw(27) << contacts[i].city;

                setColor(9);
                cout << "   ║\n";

                // Bottom border
                setColor(9);
                cout << "╚══════════════════════════════════════════════════╝\n";
                
                // cout << " Contact: " << i + 1 << endl;
                // cout << " Name: " << contacts[i].name << endl;
                // cout << " Phone: " << contacts[i].phone << endl;
                // cout << " Email: " << contacts[i].email << endl;
                // cout << " City: " << contacts[i].city << endl;
                cout << endl;
                f = 1;
                // return;
            }
        }
        if (f == 0)
        {
            cout << endl;
            cout << " No Blocked Contacts Found" << endl;
        }
    }

    // LOCK CONTACT

    void lockcontact()
    {
        string pass;
        string ph;
        cout << endl;
        cout << " Set Password for lock: ";
        cin >> pass;
        savePassword(pass);
        cout << endl;
        cout << " Enter Phone Number to Lock: ";
        cin >> ph;
        for (int i = 0; i < contacts.size(); i++)
        {
            if (contacts[i].phone == ph)
            {
                contacts[i].lock = true;
                savedata();
                cout << endl;
                cout << " Added to Locked List" << endl;
                return;
            }
        }
        cout << endl;
        cout << " Contact Not Found" << endl;
        return;
    }

    // TO SAVE THE PASSWORD
    void savePassword(string pass)
    {
        ofstream fout("password.txt");
        fout << pass;
        fout.close();
    }

    // DISPLAY ALL LOCKED CONTACTS
    void showlock()
    {
        string ps;
        cout << endl;

        cout << "╔══════════════════════════════════════════════════╗\n";
        cout << "║                    PASSWORD                      ║\n";
        cout << "╚══════════════════════════════════════════════════╝\n";
        cout << " Enter Password to Unlock: ";
        cin >> ps;
        ifstream fin("password.txt");
        string pass;
        getline(fin, pass);
        if (ps == pass)
        {
            bool found = false;
            int n = contacts.size();
            system("cls");
            for (int i = 0; i < n; i++)
            {

                if (contacts[i].lock == true)
                {

                    cout << endl;
                    cout << "╔══════════════════════════════════════════════════╗\n";
                    cout << "║                 LOCKED CONTACTS                  ║\n";
                    cout << "╚══════════════════════════════════════════════════╝\n";
                    cout << "║ "
                         << left << setw(15) << "👤 Name"
                         << "    : "
                         << left << setw(24) << contacts[i].name
                         << "      ║\n";

                    cout << "║ "
                         << left << setw(15) << "📞 Phone Number"
                         << "  : "
                         << left << setw(27) << contacts[i].phone
                         << "   ║\n";

                    cout << "║ "
                         << left << setw(15) << "📧 Email"
                         << "    : "
                         << left << setw(30) << contacts[i].email
                         << "║\n";

                    cout << "║ "
                         << left << setw(15) << "📍 City"
                         << "    : "
                         << left << setw(27) << contacts[i].city
                         << "   ║\n";

                    cout << "╚══════════════════════════════════════════════════╝\n";
                    // cout << " Contact: " << i + 1 << endl;
                    // cout << " Name: " << contacts[i].name << endl;
                    // cout << " Phone: " << contacts[i].phone << endl;
                    // cout << " Email: " << contacts[i].email << endl;
                    // cout << " City: " << contacts[i].city << endl;
                    cout << endl;
                    found = true;
                }
            }
            if (found == false)
            {
                cout << "No Contact Found" << endl;
            }
        }
        else
        {
            cout << endl;
            cout << " Wrong Password" << endl;
        }
        fin.close();
    }

    // UPDATE PASSWORD
    void updatePassword()
    {
        string ps;
        string p;
        cout << endl;
        cout << "╔══════════════════════════════════════════════════╗\n";
        cout << "║                   OLD PASSWORD                   ║\n";
        cout << "╚══════════════════════════════════════════════════╝\n";
        cout << " Enter Previous Password: ";
        cin >> ps;
        cout << endl;
        ifstream fin("password.txt");
        string pass;
        getline(fin, pass);
        if (pass == ps)
        {
            cout << endl;
            cout << "╔══════════════════════════════════════════════════╗\n";
            cout << "║                   NEW PASSWORD                   ║\n";
            cout << "╚══════════════════════════════════════════════════╝\n";
            cout << " Enter New Password: ";
            cin >> p;
            savePassword(p);
            cout << endl;
            cout << " Password Updated!" << endl;
        }
    }
    // unlock function
    void unlock()
    {
        string ps;
        cout << "╔══════════════════════════════════════════════════╗\n";
        cout << "║                  UNLOCK CONTACT                  ║\n";
        cout << "╚══════════════════════════════════════════════════╝\n";
        cout << " Enter Password to Proceed: ";
        cin >> ps;
        ifstream fin("password.txt");
        string pass;
        getline(fin, pass);
        if (ps == pass)
        {
            string ph;
            cout << " Enter Phone Number to Unlock: ";
            cin >> ph;
            system("cls");
            for (int i = 0; i < contacts.size(); i++)
            {
                if (contacts[i].phone == ph)
                {
                    contacts[i].lock = false;
                    savedata();
                    cout << endl;
                    cout << "Removed from Locked List" << endl;
                    return;
                }
            }
        }
        else
        {
            cout << "Incorrect password.";
        }
        cout << endl;
        cout << " Contact Not Found" << endl;
        return;
    }
    // unblock function
    void unblock()
    {
        string ph;
        cout << "╔══════════════════════════════════════════════════╗\n";
        cout << "║                  UNBLOCK CONTACT                 ║\n";
        cout << "╚══════════════════════════════════════════════════╝\n";
        cout << " Enter Phone Number to Unblock: ";
        cin >> ph;
        for (int i = 0; i < contacts.size(); i++)
        {
            if (contacts[i].phone == ph)
            {
                contacts[i].block = false;
                savedata();
                cout << endl;
                cout << "Removed from Blocked List" << endl;
                return;
            }
        }
        cout << endl;
        cout << " Contact Not Found" << endl;
        return;
    }
    // unfav function
    void unfav()
    {
        string ph;
        cout << "╔══════════════════════════════════════════════════╗\n";
        cout << "║               REMOVE FROM FAVOURITES             ║\n";
        cout << "╚══════════════════════════════════════════════════╝\n";
        cout << " Enter Phone Number: ";
        cin >> ph;
        for (int i = 0; i < contacts.size(); i++)
        {
            if (contacts[i].phone == ph)
            {
                contacts[i].fav = false;
                savedata();
                cout << endl;
                cout << "Removed from Favorites List" << endl;
                return;
            }
        }
        cout << endl;
        cout << " Contact Not Found" << endl;
        return;
    }
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    contact obj;
    obj.loaddata();
    int choice;
    int ch;
    int c;
    int c1;

    do
    {
        setColor(9);
        cout << "★━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━★\n";
        cout << "┃           🌸 CONNECTIFY 🌸             ┃\n";
        cout << "★━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━★\n";
        menuLine("1.  Add Contact");
        menuLine("2.  View Contact");
        menuLine("3.  Delete Contact");
        menuLine("4.  Update Contact");
        menuLine("5.  Search Contact");
        menuLine("6.  Sort Contact");
        menuLine("7.  Save Contact to File");
        menuLine("8.  Load Contact from File");
        menuLine("9.  Add to Favourites");
        menuLine("10. Show Favourites");
        menuLine("11. Block Contact");
        menuLine("12. Display All Block Contact");
        menuLine("13. Lock Contact");
        menuLine("14. Display Locked Contact");
        menuLine("15. Update Password");
        menuLine("16. Remove from favorites");
        menuLine("17. Unblock Number");
        menuLine("18. Unlock Number");
        menuLine("0.  Exit");
        setColor(14);
        cout << " Enter Choice: ";
        setColor(15);

        cin >> choice;
        system("cls"); // removes the Contact Book

        if (choice == 1)
        {
            obj.addcontact();
        }
        else if (choice == 2)
        {
            obj.viewcontact();
        }
        else if (choice == 3)
        {
            obj.deletecontact();
        }
        else if (choice == 4)
        {

            system("cls");
            setColor(9);
            cout << "╔══════════════════════════════════════════════╗\n";

            setColor(9);
            cout << "║";
            setColor(15);
            cout << setw(44) << left << "          UPDATE CONTACT OPTION";
            setColor(9);
            cout << "  ║\n";

            setColor(9);
            cout << "╠══════════════════════════════════════════════╣\n";

            // Option 1
            setColor(9);
            cout << "║ ";
            setColor(15);
            cout << left << setw(41) << "1. Update Number";
            setColor(9);
            cout << "    ║\n";

            // Option 2
            setColor(9);
            cout << "║ ";
            setColor(15);
            cout << left << setw(41) << "2. Update Name";
            setColor(9);
            cout << "    ║\n";

            // option 3
            setColor(9);
            cout << "║ ";
            setColor(15);
            cout << left << setw(41) << "3. Update Email";
            setColor(9);
            cout << "    ║\n";

            // option 4
            setColor(9);
            cout << "║ ";
            setColor(15);
            cout << left << setw(41) << "4. Update City";
            setColor(9);
            cout << "    ║\n";

            setColor(9);
            cout << "╚══════════════════════════════════════════════╝\n";
            setColor(15);
            cout << "  Enter Choice : ";
            cin >> c1;

            for (int i = to_string(c1).length(); i < 21; i++)
            {
                cout << " ";
            }

            if (c1 == 1)
            {
                obj.updatenumber();
            }
            else if (c1 == 2)
            {
                obj.updatename();
            }
            else if (c1 == 3)
            {
                obj.updateemail();
            }
            else
            {
                obj.updatecity();
            }
        }
        else if (choice == 5)
        {
            system("cls");
            setColor(9);
            cout << "╔══════════════════════════════════════════════╗\n";

            setColor(9);
            cout << "║";
            setColor(15);
            cout << setw(44) << left << "          CHOOSE AN OPTION";
            setColor(9);
            cout << "  ║\n";

            setColor(9);
            cout << "╠══════════════════════════════════════════════╣\n";

            // Option 1
            setColor(9);
            cout << "║ ";
            setColor(15);
            cout << left << setw(41) << "1. Search by Phone Number";
            setColor(9);
            cout << "    ║\n";

            // Option 2
            setColor(9);
            cout << "║ ";
            setColor(15);
            cout << left << setw(41) << "2. Search by Name";
            setColor(9);
            cout << "    ║\n";

            setColor(9);
            cout << "╚══════════════════════════════════════════════╝\n";

            setColor(15);
            cout << "\nEnter Choice : ";
            cin >> ch;
            if (ch == 1)
            {
                obj.searchbyphone();
            }
            else if (ch == 2)
            {
                obj.searchbyname();
            }
            else
            {
                cout << " Invalid Option" << endl;
            }
        }

        else if (choice == 6)
        {
            system("cls");
            setColor(9);
            cout << "╔══════════════════════════════════════════════╗\n";

            setColor(9);
            cout << "║";
            setColor(15);
            cout << setw(44) << left << "          CHOOSE AN OPTION";
            setColor(9);
            cout << "  ║\n";

            setColor(9);
            cout << "╠══════════════════════════════════════════════╣\n";

            // Option 1
            setColor(9);
            cout << "║ ";
            setColor(15);
            cout << left << setw(41) << "1. Sort in Ascending Order";
            setColor(9);
            cout << "    ║\n";

            // Option 2
            setColor(9);
            cout << "║ ";
            setColor(15);
            cout << left << setw(41) << "2. Sort in Descending Orer";
            setColor(9);
            cout << "    ║\n";

            setColor(9);
            cout << "╚══════════════════════════════════════════════╝\n";

            setColor(15);
            // cout << " Choose Option:" << endl;
            // cout << " 1. Sort in Ascending Order" << endl;
            // cout << " 2. Sort in Descending Order" << endl;
            cout << "  Enter Choice : ";
            cin >> c;
            system("cls");
            if (c == 1)
            {
                obj.sortcontactasc();
            }
            else if (c == 2)
            {
                obj.sortcontactdes();
            }
            else
            {
                cout << " Invalid Option " << endl;
            }
        }
        // else if (choice == 7)
        // {
        //     obj.savedata();
        // }
        // else if (choice == 8)
        // {
        //     obj.loaddata();
        // }
        else if (choice == 9)
        {
            obj.addfav();
        }
        else if (choice == 10)
        {
            obj.showfav();
        }
        else if (choice == 11)
        {
            obj.blocked();
        }
        else if (choice == 12)
        {
            obj.showblock();
        }
        else if (choice == 13)
        {
            obj.lockcontact();
        }
        else if (choice == 14)
        {
            obj.showlock();
        }
        else if (choice == 15)
        {
            obj.updatePassword();
        }
        else if (choice == 16)
        {
            obj.unfav();
        }
        else if (choice == 17)
        {
            obj.unblock();
        }
        else if (choice == 18)
        {
            obj.unlock();
        }
        else if (choice == 0)
        {
            obj.exit();
        }
        if (choice != 0)
        {
            cout << "\nPress Enter...";
            cin.ignore();
            cin.get();
            system("cls");
        }
    }

    while (choice != 0);

    return 0;
}
