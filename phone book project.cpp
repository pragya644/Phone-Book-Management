#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Phone
{
public:
    string Data;
    long long int Mobile;
    Phone *next;
    Phone *prev;

    Phone(string Value, long long int Num)
    {
        Data = Value;
        Mobile = Num;
        next = NULL;
        prev = NULL;
    }
};

void InsertAtHead(Phone *&head, string Value, long long int num)
{
    Phone *n = new Phone(Value, num);
    n->next = head;
    if (head != NULL)
    {
        head->prev = n;
    }

    head = n;
}

void InsertNumber(Phone *&head, string Value, long long int num)
{

    if (head == NULL)
    {
        InsertAtHead(head, Value, num);
        return;
    }
    Phone *n = new Phone(Value, num);

    Phone *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

bool IsCheck(pair<string, long long int> p1, pair<string, long long int> p2)
{
    if (p1.first > p2.first)
    {
        return false;
    }
    else if (p2.first > p1.first)
    {
        return true;
    }
    else
    {
        if (p1.second > p2.second)
            return false;
        else
            return true;
    }
}

Phone *SortList(Phone *&head)
{
    multimap<string, long long int> mp;
    vector<pair<string, long long int>> v;
    Phone *head2 = NULL;

    Phone *temp = head;
    while (temp != NULL)
    {
        mp.insert(pair<string, long long int>(temp->Data, temp->Mobile));
        temp = temp->next;
    }

    for (auto &i : mp)
    {
        v.push_back(i);
    }
    sort(v.begin(), v.end(), IsCheck);

    for (auto &it : v)
    {
        InsertNumber(head2, it.first, it.second);
    }
    head = head2;
    return head2;
}

int TotalContacts(Phone *head)
{
    Phone *temp = head;
    int Count = 0;
    while (temp != NULL)
    {
        Count++;
        temp = temp->next;
    }
    return Count;
}

bool Searching(Phone *head, long long int num)
{
    Phone *temp = head;
    int n = int(log10(num) + 1);
    int Count = 0;

    while (temp != NULL)
    {
        long long int val = temp->Mobile;
        long long int num2 = num;
        bool result = true;
        if (num == val)
        {
            result = true;
        }
        else if (num != val and n == 10)
        {
            result = false;
        }
        else
        {
            int Search[10], i = 0;
            while (num2 > 0)
            {
                Search[i] = num2 % 10;
                num2 = num2 / 10;
                i++;
            }
            Search[i] = '\0';

            for (int j = 0; j < i / 2; j++)
            {
                int temp = Search[j];
                Search[j] = Search[i - 1 - j];
                Search[i - 1 - j] = temp;
            }
            int j = 0, ans2[10];
            i = 0;

            while (val > 0)
            {
                ans2[i] = val % 10;
                val = val / 10;
                i++;
            }
            ans2[i] = '\0';

            for (j = 0; j < i / 2; j++)
            {
                int temp = ans2[j];
                ans2[j] = ans2[i - 1 - j];
                ans2[i - 1 - j] = temp;
            }
            i = 0, j = 0;
            result = false;

            while (i < 10 && j < n)
            {

                if (Search[j] == ans2[i])
                {

                    i++;
                    j++;

                    if (j == n)
                    {
                        result = true;
                    }
                }
                else
                {
                    i = i - j + 1;
                    j = 0;
                }
            }
        }
        if (result == true)
        {

            cout << "\nName: " << temp->Data << " Mobile: " << temp->Mobile;
            Count++;
        }
        temp = temp->next;
    }

    if (Count == 0)
    {
        cout << "\nContact Not Present.";
    }

    // return result;
}

bool SearchByName(Phone *head, string Name)
{
    Phone *temp = head;
    bool Search = false;

    while (temp != NULL)
    {
        if (temp->Data == Name)
        {
            cout << "\nName: " << temp->Data << " Mobile: " << temp->Mobile;
            Search = true;
        }

        temp = temp->next;
    }
    if (Search == false)
    {
        cout << "\nContact Not Present.";
    }

    return Search;
}

void UpdateContact(Phone *&head, long long int num)
{
    Phone *temp = head;
    int n = int(log10(num) + 1);
    int Count = 0;

    while (temp != NULL)
    {
        long long int val = temp->Mobile;
        long long int num2 = num;
        bool result = true;
        if (num == val)
        {
            result = true;
        }
        else if (num != val and n == 10)
        {
            result = false;
        }
        else
        {
            int Search[10], i = 0;
            while (num2 > 0)
            {
                Search[i] = num2 % 10;
                num2 = num2 / 10;
                i++;
            }
            Search[i] = '\0';

            for (int j = 0; j < i / 2; j++)
            {
                int temp = Search[j];
                Search[j] = Search[i - 1 - j];
                Search[i - 1 - j] = temp;
            }
            int j = 0, ans2[10];
            i = 0;

            while (val > 0)
            {
                ans2[i] = val % 10;
                val = val / 10;
                i++;
            }
            ans2[i] = '\0';

            for (j = 0; j < i / 2; j++)
            {
                int temp = ans2[j];
                ans2[j] = ans2[i - 1 - j];
                ans2[i - 1 - j] = temp;
            }
            i = 0, j = 0;
            result = false;

            while (i < 10 && j < n)
            {

                if (Search[j] == ans2[i])
                {

                    i++;
                    j++;

                    if (j == n)
                    {
                        result = true;
                    }
                }
                else
                {
                    i = i - j + 1;
                    j = 0;
                }
            }
        }
        if (result == true)
        {
            string Name;
            long long int mob;
            int choice;

            cout << "\nName: " << temp->Data << " Mobile: " << temp->Mobile;

            cout << "\n\nDo you want to update this record: \nPress 0 for No and Press 1 for Yes";
            cout << "\nEnter your choice: ";
            cin >> choice;

            if (choice == 1)
            {
                cout << "\n\nEnter Updated Record: ";
                cout << "\nEnter New Name: ";
                fflush(stdin);
                getline(cin, Name);
                fflush(stdin);

                cout << "Enter new Phone Number: ";
                cin >> mob;

                temp->Data = Name;
                temp->Mobile = mob;
            }

            Count++;
        }
        temp = temp->next;
    }

    if (Count == 0)
    {
        cout << "\nContact Not Present.";
    }
}

void UpdateByName(Phone *&head, string Name)
{
    Phone *temp = head;
    bool Search = false;

    while (temp != NULL)
    {
        if (temp->Data == Name)
        {
            Search = true;
            string name;
            long long int mob;
            int choice;

            cout << "\nName: " << temp->Data << " Mobile: " << temp->Mobile;

            cout << "\n\nDo you want to update this record: \nPress 0 for No and Press 1 for Yes";
            cout << "\nEnter your choice: ";
            cin >> choice;

            if (choice == 1)
            {
                cout << "\n\nEnter Updated Record: ";
                cout << "\nEnter New Name: ";
                fflush(stdin);
                getline(cin, name);
                fflush(stdin);

                cout << "Enter new Phone Number: ";
                cin >> mob;

                temp->Data = name;
                temp->Mobile = mob;
            }
        }

        temp = temp->next;
    }
    if (Search == false)
    {
        cout << "\nContact Not Present.";
    }
}

void Display(Phone *head)
{
    head = SortList(head);
    Phone *n = head;

    if (n == NULL)
        cout << "\nNO RECORDS PRESENT.\n";
    else
    {
        cout << "\n****DISPLAYING DETAILS**\n";
        while (n != NULL)
        {
            cout << " Name: " << n->Data << " Mobile: " << n->Mobile << "\n";
            n = n->next;
        }
        cout << "\n************\n";
    }
}

void AddNumber(Phone *&head)
{
    string Name;
    long long int num;
    cout << "\nEnter the Name of Person: ";
    fflush(stdin);
    getline(cin, Name);
    fflush(stdin);
    cout << "\nEnter the Mobile Number of Person: ";
    cin >> num;
    InsertNumber(head, Name, num);
}

int main()
{
    Phone *head = NULL;
    int i = 1, choice, choice2;
    string Name;
    long long int num;

    while (i)
    {
        cout << "\n\n******************************************************************************************";
        cout << "\n\t\t\tWELCOME TO PHONEBOOK MANAGEMENT SYSTEM\n";
        cout << "******************************************************************************************\n";
        cout << "\nPress 1 to Insert Number ";
        cout << "\nPress 2 to Search Number ";
        cout << "\nPress 3 to Update Number ";
        cout << "\nPress 4 to Display PhoneBook";
        cout << "\nPress 5 to Count Total Records";
        cout << "\nPress 6 to Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {

            AddNumber(head);
            cout << "\nNumber Added Successfully.\n";
        }

        break;

        case 2:
        {
            cout << "\n Press 1 to Search by Name ";
            cout << "\n Press 2 to Search by Phone Number ";
            cout << "\nEnter your choice: ";
            int Schoice;
            cin >> Schoice;

            if (Schoice == 1)
            {
                cout << "Enter the name you want to search: ";
                fflush(stdin);
                getline(cin, Name);
                fflush(stdin);

                SearchByName(head, Name);
            }

            if (Schoice == 2)
            {
                cout << "Enter the Mobile Number you want to search: ";
                cin >> num;

                Searching(head, num);
            }
        }
        break;

        case 3:
        {
            cout << "\n Press 1 to Update by Name ";
            cout << "\n Press 2 to Update by Phone Number ";
            cout << "\nEnter your choice: ";
            int Uchoice;
            cin >> Uchoice;

            if (Uchoice == 1)
            {
                cout << "\nEnter the name you want to Update: ";
                fflush(stdin);
                getline(cin, Name);
                fflush(stdin);
                UpdateByName(head, Name);
            }

            if (Uchoice == 2)
            {
                cout << "\nEnter the Mobile Number you want to Update: ";
                cin >> num;
                UpdateContact(head, num);
            }
            cout<<"\n Number Updated Successfully ";
        }
        break;
        case 4:
        {
            Display(head);
            break;
        }
        case 5:
        {
            cout << "\n*******************";
            cout << "\nTotal Contacts in PhoneBook: " << TotalContacts(head);
            cout << "\n*******************\n";
        }
        break;
        case 6:
        {
            exit(0);
        }

        default:
        {
            cout << "\nWrong Choice Entered.Enter Again.\n";
        }
        break;
        }
    }
}
