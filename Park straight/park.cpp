#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <conio.h>
using namespace std;
int id = 1;
class Floor
{
public:
    int visited[11][11];
    int number_of_vehicles;

    Floor()
    {
        for (int i = 1; i <= 10; i++)
        {
            for (int j = 1; j <= 10; j++)
            {
                visited[i][j] = 0;
            }
        }
        number_of_vehicles = 0;
    }
};
class building
{
public:
    string name;
    Floor f1, f2, f3;
    building(string name)
    {
        this->name = name;
    }
};

class location
{
public:
    Floor Floor_no;
    int x;
    int y;
};
class vehicle
{
public:
    int type_of_vehicle;
    long long phone_no;
    string vehicle_no;
    bool is_self_drive;
    int duration;
    int charges;
    location of_this_vehicle;
    int id_no;

    vehicle(int type_of_vehicle, long long phone_no, string vehicle_no, bool is_self_drive, int duration)
    {
        this->type_of_vehicle = type_of_vehicle;
        this->phone_no = phone_no;
        this->vehicle_no = vehicle_no;
        this->is_self_drive = is_self_drive;
        this->duration = duration;
        this->charges = duration * 30;
        this->id_no = id;
    }

    void get_E_slip()
    {
        cout << "Your vehicle_no :  " << vehicle_no << endl;
        cout << "Your phone_no is :  " << phone_no << endl;
        cout << "Your duration of parking is :  " << duration << " Hours" << endl;
        cout << "Your charges :  " << charges << endl;
        cout << "Your id is :  " << id_no << endl;
        cout << "Your location of vehicle is  ";
        if (type_of_vehicle == 2)
        {
            cout << "1st ";
        }
        else if (type_of_vehicle == 4)
        {
            if (is_self_drive)
            {
                cout << "2nd ";
            }
            else
            {
                cout << "3rd ";
            }
        }
        cout << "floor ";
        cout << "coordinates are " << of_this_vehicle.x << " " << of_this_vehicle.y << endl;
    }
};

location getlocation(Floor &datum)
{
    location now;
    now.Floor_no = datum;
    int flag = 0;
    for (int i = 1; i < 11 && flag == 0; i++)
    {
        for (int j = 1; j < 11 && flag == 0; j++)
        {
            if (datum.visited[i][j] != 0)
                continue;
            else
            {
                datum.visited[i][j] = id;
                now.x = i;
                now.y = j;
                flag = 1;
            }
        }
    }
    return now;
}
class administrator : public vehicle
{
private:
    string password;

public:
    void set_password()
    {
        string s;

        for (int i = 0; i < vehicle_no.size(); i++)
        {
            s.push_back(vehicle_no[vehicle_no.size() - 1 - i]);
        }

        password = s;
    }

    administrator(int type_of_vehicle, long long phone_no, string vehicle_no, bool is_self_drive, int duration) : vehicle(type_of_vehicle, phone_no, vehicle_no, is_self_drive, duration)
    {
    }

    void display_admin()
    {
        cout << "ENTER PASS KEY OF THIS VEHICLE  " << endl;
        string pass_key;
        cin >> pass_key;
        if (pass_key == password)
        {
            cout << "Your vehicle_no :  " << vehicle_no << endl;
            cout << "Your phone_no is :  " << phone_no << endl;
            cout << "Your duration of parking is : " << duration << " Hours" << endl;
        }
        else
        {
            cout << "PASSWORD IS INCORRECT";
        }
    }
};
void display(Floor W)
{

    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            cout << W.visited[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int main()
{

    cout << "ENTER NAME OF YOUR BUILDING  ";
    string name;
    cin >> name;
    building A(name);
    int total_no_of_vehicle = 0;
    vector<administrator> a;

    for (int i = 0; i < 301; i++)
    {
        administrator ad(0, 0, "a", false, 0);

        a.push_back(ad);
    }
    int count_selfdriven_vehicle = 0, count_4wheeler_vehicle = 0, count_2wheeler_vehicle = 0;

    //USER INTERFACE
    do
    {
        cout << "Press 1 to park your vehicle OR 2 to EXIT OR 3 TO GO TO ADMIN RIGHTS  ";
        int t;
        cin >> t;
        if (t == 3)
        {
            cout << "YOU ARE IN ADMIN SECTION ";
            cout << "ENTER PASSWORD  ";
            char pass_to_admin[5];
            //cin>>pass_to_admin;
            char ch;
            for (int i = 0; i < 4; i++)
            {
                ch = getch();
                pass_to_admin[i] = ch;
                cout << "*";
            }
            cout << endl;
            pass_to_admin[4] = '\0';
            if (strcmp(pass_to_admin, "n007") == 0)
            {
                cout << "PRESS 1 TO GET FLOOR DETAILS OR 2 TO GET VEHICLE DETAILS  ";
                int q;
                cin >> q;
                if (q == 1)
                {
                    display(A.f1);
                    display(A.f2);
                    display(A.f3);
                }
                else if (q == 2)
                {
                    cout << "ENTER VEHICLE NO. OF THE VEHICLE  ";
                    string vehicle_number_check;
                    cin >> vehicle_number_check;
                    bool vehicle_Found = false;
                    for (int i = 1; i < id; i++)
                    {
                        if (a[i].vehicle_no == vehicle_number_check)
                        {
                            a[i].display_admin();
                            vehicle_Found = true;
                            break;
                        }
                    }
                    if (!vehicle_Found)
                    {
                        cout << "Please Enter a valid vehicle number" << endl;
                    }
                }
            }
            else
            {
                cout << "INCORRECT PASSWORD" << endl;
            }
            continue;
        }
        else if (t == 2)
        {
            cout << "Enter your vehicle ID_NO  " << endl;
            int id_check;
            cin >> id_check;
            bool is_Found = false;
            for (int i = 1; i <= 10; i++)
            {
                for (int j = 1; j <= 10; j++)
                {
                    if (A.f1.visited[i][j] == id_check)
                    {
                        A.f1.visited[i][j] = 0;
                        is_Found = true;
                        break;
                    }
                    else if (A.f2.visited[i][j] == id_check)
                    {
                        A.f2.visited[i][j] = 0;
                        is_Found = true;
                        break;
                    }
                    else if (A.f3.visited[i][j] == id_check)
                    {
                        A.f3.visited[i][j] = 0;
                        is_Found = true;
                        break;
                    }
                }
            }
            if (is_Found == false)
            {
                cout << "Please Enter valid vehicle id" << endl;
            }

            continue;
        }
        total_no_of_vehicle++;
        int type_of_vehicle;
        long long phone_no;
        string vehicle_no;
        bool is_self_drive;
        int duration;
        cout << "Enter type of Vehicle : " << endl
             << "Press 2 for 2 wheeler or Press 4 for 4 wheeler  ";
        cin >> type_of_vehicle;
        if (type_of_vehicle == 4)
        {
            cout << "Is your car is self driven " << endl
                 << "Press 1 if Yes or 0 if No  ";
            int choice;
            cin >> choice;
            if (choice == 1)
                is_self_drive = true;
            else
                is_self_drive = false;
        }
        else
        {
            is_self_drive = false;
        }
        if (type_of_vehicle == 2 && A.f1.number_of_vehicles == 100)
        {
            cout << "NO MORE PARKING SPACE" << endl;
            continue;
        }
        if (type_of_vehicle == 4 && is_self_drive && A.f2.number_of_vehicles == 100)
        {
            cout << "NO MORE PARKING SPACE" << endl;
            continue;
        }
        if (type_of_vehicle == 4 && A.f3.number_of_vehicles == 100)
        {
            cout << "NO MORE PARKING SPACE" << endl;
            continue;
        }
        cout << "Enter phone_no  " << endl;
        cin >> phone_no;
        a[id].phone_no = phone_no;
        cout << "Enter vehicle_no  " << endl;
        cin >> vehicle_no;
        a[id].vehicle_no = vehicle_no;
        cout << "Enter duration of parking in hours  " << endl;
        cin >> duration;
        a[id].duration = duration;
        a[id].set_password();

        vehicle v(type_of_vehicle, phone_no, vehicle_no, is_self_drive, duration);

        if (type_of_vehicle == 2)
        {
            //floor - a.f1
            count_2wheeler_vehicle++;
            v.of_this_vehicle = getlocation(A.f1);
        }
        else if (type_of_vehicle == 4 && is_self_drive)
        {
            count_selfdriven_vehicle++;
            v.of_this_vehicle = getlocation(A.f2);
        }
        else
        {
            count_4wheeler_vehicle++;
            v.of_this_vehicle = getlocation(A.f3);
        }

        v.get_E_slip();
        id++;
    } while (1);

    return 0;
}
