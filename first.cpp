#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <windows.h>
#include <iomanip>
using namespace std;
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

        cout << "╔══════════════════════════════════════╗\n";
        cout << "║             ADD CONTACT              ║\n";
        cout << "╚══════════════════════════════════════╝\n";

        cout << " Enter Name         : ";
        cin >> c.name;

        cout << " Enter Phone Number : ";
        cin >> c.phone;

        cout << " Enter Email        : ";
        cin >> c.email;

        cout << " Enter City         : ";
        cin >> c.city;

        system("cls"); // optional
        cout << "╔══════════════════════════════════════╗\n";
        cout << "║             ADD CONTACT              ║\n";
        cout << "╚══════════════════════════════════════╝\n";

        cout << "║ Name         : "
             << left << setw(20)
             << c.name << "  ║\n";

        cout << "║ Phone Number : "
             << left << setw(20)
             << c.phone << "  ║\n";

        cout << "║ Email        : "
             << left << setw(20)
             << c.email << "  ║\n";

        cout << "║ City         : "
             << left << setw(20)
             << c.city << "  ║\n";

        cout << "╚══════════════════════════════════════╝\n";

        contacts.push_back(c);
        savedata();
        cout << endl;
        cout << "-----Contact Saved-----" << endl;
        cout << endl;
        cout << "Name:" << c.name << endl;
        cout << "Phone No:" << c.phone << endl;
        cout << "Email:" << c.email << endl;
        cout << "City: " << c.city << endl;
        cout << endl;
        cout << "-----Contact Saved-----" << endl;
    }

    // TO VIEW CONTACT
    void viewcontact()
    {
        int c = 1;
        for (int i = 0; i < contacts.size(); i++)
        {
            if (contacts[i].lock == true)
            {
                continue;
            }
            cout << endl;
            cout << "╔══════════════════════════════════════════════════╗\n";
            cout << "║                  CONTACT                         ║\n";
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
        }
        cout << endl;
        c++;
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

        cout << "╔══════════════════════════════════════╗\n";
        cout << "║           DELETE CONTACT             ║\n";
        cout << "╚══════════════════════════════════════╝\n";
        cout << " Enter Phone Number : ";
        cin >> ph;

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
                cout << "\n---Contact Deleted Successfully---" << endl;
                found = true;

                break;
            }
        }
        savedata();
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

        cout << "╔══════════════════════════════════════╗\n";
        cout << "║            SEARCH BY NUMBER          ║\n";
        cout << "╚══════════════════════════════════════╝\n";

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
                cout << "╔══════════════════════════════════════════════════╗\n";
                cout << "║                     FOUND                        ║\n";
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
        cout << "╔══════════════════════════════════════╗\n";
        cout << "║            SEARCH BY NAME            ║\n";
        cout << "╚══════════════════════════════════════╝\n";

        cout << "  Enter Phone number : ";
        cin >> n; // <-- INPUT IS HERE
        // cout << " Enter Name to Find: ";
        // cin >> n;
        cout << endl;
        for (int i = 0; i < contacts.size(); i++)
        {
            if (contacts[i].name == n)
            {
                cout << "╔══════════════════════════════════════════════════╗\n";
                cout << "║                     FOUND                        ║\n";
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
                // cout << " Name: " << contacts[i].name << endl;
                // cout << " Phone: " << contacts[i].phone << endl;
                // cout << " Email: " << contacts[i].email << endl;
                // cout << " City: " << contacts[i].city << endl;
                found = true;
            }
        }
        if (!found)
        {
            cout << endl;
            cout << " Contact not found" << endl;
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

        cout << "╔══════════════════════════════════════╗\n";
        cout << "║            OLD PHONE NUMBER          ║\n";
        cout << "╚══════════════════════════════════════╝\n";

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
                cout << "╔══════════════════════════════════════╗\n";
                cout << "║         UPDATE PHONE NUMBER          ║\n";
                cout << "╚══════════════════════════════════════╝\n";

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
                cout << "╔══════════════════════════════════════╗\n";
                cout << "║     CONTACT SUCCESSFULLY UPDATED     ║\n";
                cout << "╚══════════════════════════════════════╝\n";
                found = true;
            }
        }
        if (!found)
        {
            cout << endl;
            // cout << "\nContact Not Found" << endl;
            cout << "\n";
            cout << "╔══════════════════════════════════════╗\n";
            cout << "║          CONTACT NOT FOUND            ║\n";
            cout << "╚══════════════════════════════════════╝\n";
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
        cout << endl;
        // cout << " Enter Name to Update: ";
        // cin >> ph;
        system("cls");
        cout << "╔══════════════════════════════════════╗\n";
        cout << "║             CURRENT NAME             ║\n";
        cout << "╚══════════════════════════════════════╝\n";
        cout << "  Enter Current Name : ";
        cin >> ph; // <-- INPUT IS HERE

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
                cout << "╔══════════════════════════════════════╗\n";
                cout << "║            UPDATE NAME               ║\n";
                cout << "╚══════════════════════════════════════╝\n";

                cout << "  Enter New Name : ";
                cin >> ph;
                contacts[i].name = ph;
                for (int i = ph.length(); i < 18; i++)
                {
                    cout << " ";
                }
                savedata();
                cout << endl;

                cout << "----Contact Updated Successfully---" << endl;
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "\n";
            cout << "╔══════════════════════════════════════╗\n";
            cout << "║          CONTACT NOT FOUND           ║\n";
            cout << "╚══════════════════════════════════════╝\n";
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
        cout << "╔══════════════════════════════════════╗\n";
        cout << "║               OLD EMAIL              ║\n";
        cout << "╚══════════════════════════════════════╝\n";

        cout << " Enter Email to Update: ";
        cin >> ph;
        bool found = false;
        for (int i = 0; i < contacts.size(); i++)
        {
            if (contacts[i].email == ph)
            {
                // cout << " Enter New Email: ";

                cout << "╔══════════════════════════════════════╗\n";
                cout << "║             UPDATE EMAIL             ║\n";
                cout << "╚══════════════════════════════════════╝\n";

                cout << "  Enter New Email : ";
                cin >> contacts[i].email;
                contacts[i].email = ph;
                savedata();
                cout << endl;
                cout << "----Contact Updated Successfully---" << endl;
                found = true;
            }
        }
        if (!found)
        {
            cout << endl;
            cout << "╔══════════════════════════════════════╗\n";
            cout << "║          CONTACT NOT FOUND           ║\n";
            cout << "╚══════════════════════════════════════╝\n";
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
        cout << endl;
        cout << "╔══════════════════════════════════════╗\n";
        cout << "║               OLD CITY               ║\n";
        cout << "╚══════════════════════════════════════╝\n";
        cout << " Enter City to Update: ";
        cin >> ph;
        bool found = false;
        for (int i = 0; i < contacts.size(); i++)
        {
            if (contacts[i].city == ph)
            {
                cout << endl;

                cout << "╔══════════════════════════════════════╗\n";
                cout << "║              UPDATE CITY             ║\n";
                cout << "╚══════════════════════════════════════╝\n";

                cout << " Enter New City: ";
                cin >> contacts[i].city;
                contacts[i].city = ph;
                savedata();
                cout << endl;
                cout << "----Contact Updated Successfully---" << endl;
                found = true;
            }
        }
        if (!found)
        {
            cout << endl;
            cout << "\nContact Not Found" << endl;
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
        ifstream fin("contacts.txt");
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
        cout << "╔══════════════════════════════════════╗\n";
        cout << "║             ADD FAVOURITE            ║\n";
        cout << "╚══════════════════════════════════════╝\n";
        cout << " Enter Favorite Phone Number: ";
        cin >> ph;
        for (int i = 0; i < contacts.size(); i++)
        {
            // cout << "yes";
            if (contacts[i].phone == ph)
            {
                contacts[i].fav = true;
                savedata();
                cout << endl;
                cout << "╔══════════════════════════════════════╗\n";
                cout << "║          ADDED TO FAVOURITE          ║\n";
                cout << "╚══════════════════════════════════════╝\n";
                return;
            }
        }
        cout << endl;
        cout << " Contact Not Found" << endl;
        return;
    }

    // TO DISPLAY FAVOURITE
    void showfav()
    {
        int fl = 0;
        int n = contacts.size();
        for (int i = 0; i < n; i++)
        {
            if (contacts[i].fav == true)
            {
                cout << endl;
                cout << "╔══════════════════════════════════════════════════╗\n";
                cout << "║                FAVOURITE CONTACT                 ║\n";
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
                fl = 1;
                // return;
            }
        }

        if (fl == 0)
            cout << endl;
        cout << " Favorites Not Found.";
    }

    // BLOCK CONTACT
    void blocked()
    {
        string ph;
        cout << endl;
        cout << "╔══════════════════════════════════════════════════╗\n";
        cout << "║                   BLOCK CONTACT                  ║\n";
        cout << "╚══════════════════════════════════════════════════╝\n";
        cout << " Enter Phone Number to Block: ";
        cin >> ph;
        for (int i = 0; i < contacts.size(); i++)
        {
            if (contacts[i].phone == ph)
            {
                contacts[i].block = true;
                savedata();
                cout << endl;
                cout << "╔══════════════════════════════════════════════════╗\n";
                cout << "║                ADDED TO BLOCK LIST               ║\n";
                cout << "╚══════════════════════════════════════════════════╝\n";

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
                cout << "╔══════════════════════════════════════════════════╗\n";
                cout << "║                  BLOCKED CONTACTS                ║\n";
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
                f = 1;
                // return;
            }
        }
        if (f == 0)
            cout << endl;
        cout << " No Blocked Contacts Found" << endl;
    }

    // LOCK CONTACT

    void lockcontact()
    {
        string pass;
        string ph;
        cout << endl;
        cout << " Set Password to Unlock: ";
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

            int n = contacts.size();
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
                    return;
                }
            }
            cout << endl;
            cout << " No Locked Contacts Found";
            return;
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
};
int main()
{

    contact obj;
    obj.loaddata();
    int choice;
    int ch;
    int c;
    int c1;

    do
    {

        SetConsoleOutputCP(CP_UTF8);

        cout << "★━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━★\n";
        cout << "┃         🌸  CONTACT BOOK 🌸            ┃\n";
        cout << "★━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━★\n";
        cout << "┃ 1.  Add Contact                        ┃" << endl; // done
        cout << "┃ 2.  View Contact                       ┃" << endl; // done
        cout << "┃ 3.  Delete Contact                     ┃" << endl; // done
        cout << "┃ 4.  Update Contact                     ┃" << endl; // done
        cout << "┃ 5.  Search Contact                     ┃" << endl; // done
        cout << "┃ 6.  Sort Contact                       ┃" << endl; // done
        cout << "┃ 7.  Save Contact to File               ┃" << endl; // done
        cout << "┃ 8.  Load Contact from File             ┃" << endl; // done
        cout << "┃ 9.  Add to Favourites                  ┃" << endl; // done
        cout << "┃ 10. Show Favourites                    ┃" << endl; // done
        cout << "┃ 11. Block Contact                      ┃" << endl; // done
        cout << "┃ 12. Display All Block Contact          ┃" << endl; // done
        cout << "┃ 13. Lock Contact                       ┃" << endl; // done
        cout << "┃ 14. Display Locked Contact             ┃" << endl; // done
        cout << "┃ 15. Update Password                    ┃" << endl; // done
        cout << "┃ 0.  Exit                               ┃" << endl;
        cout << "┃                                        ┃" << endl;
        cout << "┃ Enter Choice: ";
        cin >> choice;
        // cout << "                                        ║" << endl;

        system("cls"); // removes the Contact Book

        // if (choice == 1)
        // {
        //     obj.addcontact();
        // }
        // else if (choice == 2)
        // {
        //     obj.viewcontact();
        // }
        // else if (choice == 3)
        // {
        //     obj.deletecontact();
        // }
        // // else if (choice == 4)
        // // {
        // //     obj.searchbyphone();
        // // }
        // // else if (choice == 4)
        // // {
        // //     obj.searchbyname();
        // // }
        // else if (choice == 4)
        // {
        //     obj.updatenumber();
        // }
        // // else if (choice == 6)
        // // {
        // //     obj.updatename();
        // // }
        // // else if (choice == 7)
        // // {
        // //     obj.updateemail();
        // // }
        // // else if (choice == 8)
        // // {
        // //     obj.updatecity();
        // // }
        // else if (choice == 5)
        // {
        //     obj.searchcontacts();
        // }
        // else if (choice == 10)
        // {
        //     obj.sortcontactdes();
        // }
        // else if (choice == 11)
        // {
        //     obj.savedata();
        // }
        // else if (choice == 12)
        // {
        //     obj.loaddata();
        // }

        //     if (choice != 0)
        //     {
        //         cout << "\nPress Enter to go back...";
        //         cin.ignore();
        //         cin.get();

        //         system("cls"); // removes Add Contact box
        //     }

        // } while (choice != 0);

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

            // cout << " Choose an Option to Update:" << endl;
            // cout << " 1 => Update Number" << endl;
            // cout << " 2 => Update Name" << endl;
            // cout << " 3 => Update Email" << endl;
            // cout << " 4 => Update City" << endl;
            // cin >> c1;
            system("cls");
            cout << "╔══════════════════════════════════════╗\n";
            cout << "║         UPDATE CONTACT OPTION        ║\n";
            cout << "╠══════════════════════════════════════╣\n";
            cout << "║ 1 -> Update Number                   ║\n";
            cout << "║ 2 -> Update Name                     ║\n";
            cout << "║ 3 -> Update Email                    ║\n";
            cout << "║ 4 -> Update City                     ║\n";
            cout << "╚══════════════════════════════════════╝\n";

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
            cout << "╔══════════════════════════════════════╗\n";
            cout << "║           CHOOSE AN OPTION           ║\n";
            cout << "╠══════════════════════════════════════╣\n";
            cout << "║ 1 -> Search by Phone Number          ║\n";
            cout << "║ 2 -> Search by Name                  ║\n";
            cout << "╚══════════════════════════════════════╝\n";

            // cout << " Choose a Number:" << endl;
            // cout << " 1 => Search by Phone Number" << endl;
            // cout << " 2 => Search by Name" << endl;
            cout << "  Enter Choice : ";
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
            cout << "╔══════════════════════════════════════╗\n";
            cout << "║           CHOOSE AN OPTION           ║\n";
            cout << "╠══════════════════════════════════════╣\n";
            cout << "║ 1 ->  Sort in Ascending Order        ║\n";
            cout << "║ 2 -> Sort in Descending Order        ║\n";
            cout << "╚══════════════════════════════════════╝\n";
            // cout << " Choose Option:" << endl;
            // cout << " 1. Sort in Ascending Order" << endl;
            // cout << " 2. Sort in Descending Order" << endl;
            cout << "  Enter Choice : ";
            cin >> c;
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
        else if (choice == 7)
        {
            obj.savedata();
        }
        else if (choice == 8)
        {
            obj.loaddata();
        }
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
