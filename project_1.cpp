#include<iostream>
using namespace std;
const int Max_Specialization = 20;
const int Max_Queue = 5;
string names[Max_Specialization + 1][Max_Queue + 1];
int status[Max_Specialization + 1][Max_Queue + 1];
int queue_len[Max_Specialization + 1];
int menu(){
    int ch = -1;
    while(ch == -1){
        cout << "Enter your choice :" << endl;
        cout << "1) Add new patient" << endl;
        cout << "2) Print all patients" << endl;
        cout << "3) Get next patient" << endl;
        cout << "4) Exit" << endl;
        cin >> ch;
        if(ch < 1 || ch > 4){
            cout << "enter proper choice";
            ch = -1;
        }
    }
    return ch;
}
void shift_left(int spec){
    int len = queue_len[spec];
    for(int i = 1; i < len; ++i){
        names[spec][i - 1] = names[spec][i];
        status[spec][i - 1] = status[spec][i];
    }
}
void shift_right(int spec){
    int len = queue_len[spec];
    for(int i = len - 1; i >= 0; --i){
        names[spec][i + 1] = names[spec][i];
        status[spec][i + 1] = status[spec][i];
    }
}
bool add_patient(){
    int spec;
    string name;
    int st;
    cout << "Enter Specialization, name, status: ";
    cin >> spec >> name >> st;
    cout << endl;
    int added = queue_len[spec];
    if (added >= 5){
        cout << "Sorry, We cannot add more patients for this specialization\n";
        return false;
    }
    if(st == 0){
        names[spec][added] = name;
        status[spec][added] = st;
    }
    else{
        shift_right(spec);
        names[spec][0] = name;
        status[spec][0] = st;
    }
    queue_len[spec] ++;
    return true;
}
void print_patient(int spec){
    int len = queue_len[spec];
    if(len == 0)
    return;
    cout << "There are " << len << " patients in specialization " << spec << endl;
    for(int i = 0; i < len; ++i){
        cout << names[spec][i] << "     ";
        if (status[spec][i] == 0)
        cout << "regular\n";
        else
        cout << "urgent\n";
    }
    cout << endl;
}
void print_all_patients(){
    cout << "**********************\n";
    for(int spec = 0; spec < 20; ++spec){
        print_patient(spec);
    }
    cout << "\n\n";
}
void get_next_patient(){
    cout << "Enter specialization:     ";
    int spec;
    cin >> spec;
    int len = queue_len[spec];
    if(len == 0){
        cout << "No patients at the moment. Have rest, Dr\n";
        return;
    }
    cout << names[spec][0] << " please go with the Dr\n";
    shift_left(spec);
    queue_len[spec]--;
}
void Hospital_system(){
    while(true){
        int choice = menu();
        if(choice == 1)
        add_patient();
        else if(choice == 2)
        print_all_patients();
        else if (choice == 3)
        get_next_patient();
        else if (choice == 4)
        break;
    }
}
int main(){
    Hospital_system();
    return 0;
}