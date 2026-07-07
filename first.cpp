// printf("\xDF");//filled square
//system(cls)
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
class contact
{
public:
    string name;
    string phone;
    string email;
    string city;

    vector<contact> contacts;

    // to add contact
    void addcontact()
    {
        contact c;
        cout << " enter name" << endl;
        cin >> c.name;
        cout << " enter phone number" << endl;
        cin >> c.phone;
        cout << "enter email" << endl;
        cin >> c.email;
        cout << "enter city" << endl;
        cin >> c.city;
        contacts.push_back(c);
        savedata();
        cout << "Contact Saved" << endl;
        cout << "Name:" << c.name << endl;
        cout << "Phone No:" << c.phone << endl;
        cout << "Email:" << c.email << endl;
        cout << "City" << c.city << endl;
        
        cout << "---contact saved---" << endl;
    }

    // to view contact
    void viewcontact()
    {
        for (int i = 0; i < contacts.size(); i++)
        {
            cout << "Contact" << i + 1 << endl;
            cout << "name: " << contacts[i].name << endl;
            cout << "phone: " << contacts[i].phone << endl;
            cout << "email: " << contacts[i].email << endl;
            cout << "City: " << contacts[i].city << endl;
            cout << endl;
        }
    }

    // to delete contact
    void deletecontact()
    {
        if (contacts.empty())
        {
            cout << "\nNo Contact found" << endl;
            return;
        }
        string ph;
        cout << "enter phone number to delete" << endl;
        cin >> ph;
        bool found = false;
        ;
        for (int i = 0; i < contacts.size(); i++)
        {
            if (contacts[i].phone == ph)
            {
                contacts.erase(contacts.begin() + i);
                cout << "\nContact deleted successfully" << endl;
                found = true;
                return;
            }
        }
        savedata();
        if (!found)
        {
            cout << "contact not found" << endl;
            return;
        }
    }

    // to serach by phone
    void searchbyphone()
    {
        if (contacts.empty())
        {
            cout << "Contact empty";
            return;
        }
        string number;
        cout << "Enter phone no to search: ";
        cin>>number;
        //cout << endl;
        bool found = false;
        for (int i = 0; i < contacts.size(); i++)
        {
            if (number == contacts[i].phone )
            {
                cout << "Name:" << contacts[i].name << endl;
                cout << "Phone:" << contacts[i].phone << endl;
                cout << "Email" << contacts[i].email << endl;
                cout << "City:" << contacts[i].city << endl;
                found = true;
                return;
            }
        }

        if (!found)
        {
            cout << "contact not found" << endl;
            return;
        }
    }

    // to serach by name
    void searchbyname()
    {
        if (contacts.empty())
        {
            cout << "Contact empty" << endl;
            return;
        }
        string n;
        bool found = false;
        cout<<"Enter name to find: ";
        cin>>n;
        for (int i = 0; i < contacts.size(); i++)
        {
            if (contacts[i].name == n)
            {
                cout << "name:" << contacts[i].name << endl;
                cout << "phone:" << contacts[i].phone << endl;
                cout << "email:" << contacts[i].email << endl;
                cout << "City:" << contacts[i].city << endl;
                found = true;
            }
        }
        if (!found)
        {
            cout << "Contact not found" << endl;
            return;
        }
    }

    // to update contact
    void updatecontact()
    {
        if (contacts.empty())
        {
            cout << "\nNo contact found" << endl;
            return;
        }
        long long int ph;
        cout << "enter phone number to update" << endl;
        cin >> ph;
        bool found = false;
        for (int i = 0; i < contacts.size(); i++)
        {
            if (contacts[i].phone == "ph")
            {
                cout << "enter new phone number" << endl;
                cin >> contacts[i].phone;
                cout << "enter new name" << endl;
                cin >> contacts[i].name;
                cout << "enter new email" << endl;
                cin >> contacts[i].email;
                cout << "enter new city" << endl;
                cin >> contacts[i].city;
                cout << "----contact updated successfully---" << endl;
                found = true;
            }
        }
        if (!found)
        {
            cout << "\nContact not found" << endl;
        }
    }

    //to sort in asc
    void sortcontactasc()
    {
        for (int i = 0; i < contacts.size() - 1; i++)
        {
            for (int j = 1; j < contacts.size() - i; j++)
            {
                if (contacts[j].name < contacts[j - 1].name)
                {
                    swap(contacts[j], contacts[j - 1]);
                }
            }
        }
        for (int i = 0; i < contacts.size(); i++)
        {
            cout << "Name:" << contacts[i].name << endl;
            cout << "Phone:" << contacts[i].phone << endl;
            cout << "Email" << contacts[i].email << endl;
            cout << "City:" << contacts[i].city << endl;
        }
    }

    //to sort in desc
    void sortcontactdes()
    {
        for (int i = 0; i < contacts.size() - 1; i++)
        {
            for (int j = 1; j < contacts.size() - i; j++)
            {
                if (contacts[j].name > contacts[j - 1].name)
                {
                    swap(contacts[j], contacts[j - 1]);
                }
            }
        }
        for (int i = 0; i < contacts.size(); i++)
        {
            cout << "Name:" << contacts[i].name << endl;
            cout << "Phone:" << contacts[i].phone << endl;
            cout << "Email" << contacts[i].email << endl;
            cout << "City:" << contacts[i].city << endl;
        }
    }

    //to save data to file
    void savedata() {
        ofstream fout("contacts.txt");
        int n= contacts.size();
        for(int i=0; i<n; i++){
            fout<<contacts[i].name<<"|";
            fout<<contacts[i].phone<<"|";
            fout<<contacts[i].email<<"|";
            fout<<contacts[i].city;
            fout<<endl;
        }
        fout.close();
    }

    //to load data from file
    void loaddata()
    {
        ifstream fin("contacts.txt");
         contact temp;

        while (getline(fin, temp.name, '|'))
        {
            getline(fin, temp.phone, '|');
            getline(fin, temp.email, '|');
            getline(fin, temp.city);
        contacts.push_back(temp);
        }

        fin.close();
        // ifstream fin("contacts.txt");
        // string msg;
	    // while(getline(fin,msg)){
		// cout<<msg<<endl;
	    // };
        // fin.close();
    }

    //to exit from program
    void exit()
    {
        cout << "Program Ended" << endl;
        return;
    }

    //to add to fav
    void addfav(){

    }

    //to display fav
    void showfav(){

    }

    //block contact
    void block(){

    }

    //to display block contact
    void showblock(){

    }

    //lock contact
    void lockcontact(){
         
    }
};
int main()
{
    
    contact obj;
    obj.loaddata();
    int choice;
    int ch;
    int c;
    do
    {
        cout << "---contact book---" << endl;
        cout << "1.add contact" << endl;    // done
        cout << "2.view contact" << endl;   // done
        cout << "3.delete contact" << endl; // done
        cout << "4.update contact" << endl; // done
        cout << "5.search contact" << endl; // done
        cout << "6.sort contact" << endl;   //done
        cout << "7.save contact to file" << endl; //done
        cout << "8.Load Contact from file" << endl; //done
        cout<<"9.add to fav"<<endl;
        cout<<"10.show favourites"<<endl;
        cout<<"11.block contact"<<endl;
        cout<<"12.display all block contact"<<endl;
        cout<<"13.lock contact"<<endl;
        cout<<"14.display locked contact"<<endl;
        cout << "0.exit" << endl; // done
        cout << "enter choice" << endl;
        cin >> choice;
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
            obj.updatecontact();
        }
        else if (choice == 5)
        {
            cout << "choose option" << endl;
            cout << "1.Search by phone number" << endl;
            cout << "2.Search by name" << endl;
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
                cout << "invalid option " << endl;
            }
        }
        else if (choice == 6)
        {
            cout << "choose option" << endl;
            cout << "1.sort in ascending order" << endl;
            cout << "2.sort in descending order" << endl;
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
                cout << "Invalid option " << endl;
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
        else if(choice==9){

        }
        else if(choice==10){

        }
        else if(choice==11){

        }
        else if(choice==12){

        }
        else if(choice==13){

        }
        else if(choice==14){
            
        }
        else if (choice == 0)
        {
            obj.exit();
        }
    } while (choice != 0);
}