# include<iostream>
# include<fstream>
using namespace std;

class student{
    int roll;
    char div;
    char name[30];
    char address[30];
    public:
    void accept(){
        cout<<"Enter the name of the student: \n";
        cin>>name;
        cout<<"Enter the roll no. of the student: \n";
        cin>>roll;
        cout<<"Enter the div of the student: \n";
        cin>>div;
        cout<<"Enter the address of the student: \n";
        cin>>address;
    }
    void display(){
        cout<<name<<"\t"<<roll<<"\t"<<div<<"\t"<<address<<"\n";
    }
    bool checkr(int r){
        if (r == roll)
        {
            return true;
        }
        else{
            return false;
        }
        return false;
        }
};

void addrecord(){
cout<<"Enter the number of the records you want to add: ";
int n; cin>>n;
student s;
ofstream o("student.txt");

for (int i = 0; i < n; i++)
{
    s.accept();
    o.write((char *)&s,sizeof(s));
}
o.close();
}

void addnewrecord(){
cout<<"Enter the number of the records you want to add: ";
int n; cin>>n;
student s;
ofstream o("student.txt", ios::app);
for (int i = 0; i < n; i++)
{
    s.accept();
    o.write((char *)&s,sizeof(s));
}
o.close();
}
void showbyroll(){
    int r;
    cout<<"Enter the Roll to be checked in records\n";
    cin>>r;
    bool flag = false;
    ifstream a("student.txt");
    student s;
    while (a.read((char *)&s,sizeof(s)))
    {
        if(s.checkr(r)){
            cout << "Name \t" << " roll \t" << "div \t" << "address \n";
            s.display();
            flag = true;
            break;
        }
    }
    if (flag == false)
    {
        cout<<"The roll no. doesn't exist in the records \n";
    }
    
a.close();
}
void displayrecord(){
ifstream a("student.txt");
student s;
cout<<"Name \t"<<" roll \t"<< "div \t"<< "address \n";
while (a.read((char *)&s,sizeof(s)))
{
    s.display();
}
a.close();
}
void deletebyroll(){
    cout<<"Enter the roll no. :";
    int r;
    cin>>r;
    ofstream opn("temp.txt");
    ifstream a("student.txt");
    student s;
    bool flag = true;
    while (a.read((char *)&s,sizeof(s)))
    {
        if (s.checkr(r))
        {
            flag = false;
            continue;
        }
        else{
            opn.write((char *)&s,sizeof(s));  
        }
    }
    a.close();
    opn.close();
    if (flag == true)
    {
        cout<<"Roll No. not found in the records\n";
    }
    else{
    remove("student.txt");
    rename("temp.txt", "student.txt");
    cout << "Record deleted succesfully.\n";
    }
    
}
void updatebyroll(){
    cout<<"Enter the roll no. :";
    int r;
    cin>>r;
    ofstream opn("temp.txt");
    ifstream a("student.txt");
    student s;
    bool flag = true;
    while (a.read((char *)&s,sizeof(s)))
    {
        if (s.checkr(r))
        {
            flag = false;
            s.accept();
            opn.write((char *)&s,sizeof(s));
        }
        else{
            opn.write((char *)&s,sizeof(s));  
        }
    }
    a.close();
    opn.close();
    if (flag == true)
    {
        cout<<"Roll No. not found in the records\n";
    }
 else{
    remove("student.txt");
    rename("temp.txt", "student.txt");
    cout << "Record updated succesfully.\n";
    }
}
int main(){
    int ch = 0;
    while (ch != 7)
    {
        cout << "\nSelect option from the below: \n"
             << "1. To Add Record into the file: \n"
             << "2. To Display Records from the file: \n"
             << "3. To Add new Records to the file: \n"
             << "4. Check if roll no exist and display: \n"
             <<"5. Delete Record by roll no. :\n"
             <<"6. Update Record by roll no. :\n"
             << "7. Exit from the program: \n";
        cin>>ch;
        switch (ch)
        {
        case 1:
            addrecord();
            break;
        case 2:
            displayrecord();
            break;
        case 3:
            addnewrecord();
            break;
        case 4:
            showbyroll();
            break;
        case 5:
            deletebyroll();
            break;
        case 6:
            updatebyroll();
            break;

        case 7:
        break;
        default:
            cout << "Select correct option\n";
            break;
        }
}
    return 0;
}