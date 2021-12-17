#include<iostream>
#include<string.h>
#include<fstream>
#include<vector>
#include<iomanip>
using namespace std;
struct ph
{
    char name2[20];
    int num2;
};
int see_num()
{
    char ch;
    ifstream fin;
    fin.open("phone.txt");
    fin >> resetiosflags(ios::skipws);
    while(1)
    {

        fin >> ch;
        if(fin.eof())
        break;
        cout << ch;
    }
    fin.close();
    return 0;
}
int add_num()
{
    char ch,another='y';
    const char *name3;
    int add_num,a=1,b,con_st,x=0;
    /*cout << "Enter number of contacts you would like to add :" << endl;
    cin >> add_num;*/
    ph na[50];
    while(another=='y')
    {
        cin >> na[x].name2;
        cin >> na[x].num2;
        x++;
        cout << "want to enter another contact number(y/n)" << endl;
        cin >> another;
    }
    vector<string> name;
    string line,word;
    ifstream fin;
    fin.open("phone.txt");
    while(fin)
    {
        name.clear();
        getline(fin,line);
        stringstream s(line);
        while(getline(s,word,' '))
        {
            name.push_back(word);
            name3=name[0].c_str();
            strcpy(na[x].name2,name3);
            
        }
        con_st=stoi(name[1]);
        na[x].num2=con_st;
        x++;
    }
    
    fin.close();
    for(int i=0;i<x;i++)
    {
        for(int k=0;k<x;k++)
        {
            b=strcmp(na[i].name2,na[k].name2);
            if(b<0)
            {
                strcpy(na[x-1].name2,na[i].name2);
                strcpy(na[i].name2,na[k].name2);
                strcpy(na[k].name2,na[x-1].name2);
                na[x-1].num2=na[i].num2;
                na[i].num2=na[k].num2;
                na[k].num2=na[x-1].num2;
            }
        }
    }
    //cout << x;
    ofstream fout;
    fout.open("phone.txt");
    for(int i=0;i<x-1;i++)
    {
        fout << na[i].name2 << " " << na[i].num2 << endl;
        cout << na[i].name2 << " " << na[i].num2 << endl;
        
    }
    fout.close();
    return 0;
}
int edit_num()
{
    ph na[50];
    char arr[20],arr_new[20];
    const char *che;
    int a,ph_check,ph_no,up_no=0,up_phsw,i=0;
    cout << "enter name of contact you would like to edit" << endl;
    cin >> arr;
    //cin >> ph_no;
    vector<string> check;
    string line,word;
    ifstream fin;
    fin.open("phone.txt");
    while(fin)
    {
        check.clear();
        getline(fin,line);
        stringstream s(line);
        while(getline(s,word,' '))
        {
            check.push_back(word);
            che=check[0].c_str();
            a=strcmp(che,arr);
        } 
            if(a==0)
            {
                cout << "match found" << endl;
                cout << "enter new name" << endl;
                cin >> arr_new;
                //strcpy(na[up_no].name2,arr_new);
                ifstream fin2;
                fin2.open("phone.txt");
                vector<string> ed;
                string ed_line,ed_word;
                while(fin2)
                {
                    ed.clear();
                    getline(fin2,ed_line);
                    stringstream s1(ed_line);
                    while(getline(s1,ed_word,' '))
                    {
                        ed.push_back(ed_word);
                        che=ed[0].c_str();
                        strcpy(na[i].name2,che);
                    }
                    na[i].num2=stoi(ed[1]);
                    i++;
                }
                strcpy(na[up_no].name2,arr_new);
                for(int k=0;k<i;k++)
                {
                    for(int j=0;j<i;j++)
                    {
                        up_phsw=strcmp(na[k].name2,na[j].name2);
                        if(up_phsw<0)
                        {
                            strcpy(na[i-1].name2,na[k].name2);
                            strcpy(na[k].name2,na[j].name2);
                            strcpy(na[j].name2,na[i-1].name2);
                            na[i-1].num2=na[k].num2;
                            na[k].num2=na[j].num2;
                            na[j].num2=na[i-1].num2;
                        }
                        
                    }
                }
                ofstream fout;
                fout.open("phone.txt");
                for(int x=0;x<i-1;x++)
                fout << na[x].name2 << " " << na[x].num2 << endl;
                break;
                
            }
            
            up_no++;
    }
    return 0;
}
int del_num()
{
    int a=0,b=0,e;
    char rem_1,rem_name[20];
    const char *rem_com;
    ph na[50];
    cout << "enter name you of contact you would like to remove:" << endl;
    cin >> rem_name;
    vector<string> rem;
    string rem_line,rem_word;
    ifstream fin3;
    fin3.open("phone.txt");
    while(fin3)
    {
        rem.clear();
        getline(fin3,rem_line);
        stringstream s2(rem_line);
        while(getline(s2,rem_word,' '))
        {
            rem.push_back(rem_word);
            rem_com=rem[0].c_str();
        }
            if(strcmp(rem_name,rem_com)==0)
            {
                continue;
            }
            else
            {
                strcpy(na[b].name2,rem_com);
                na[b].num2=stoi(rem[1]);
                b++;
                
            }
        
        
    }
    
    ofstream fout3;
    fout3.open("phone.txt");
    for(int i=0;i<b;i++)
    fout3 << na[i].name2 << " " << na[i].num2 << endl;
    return 0;
}
int main()
{
    int choice;
    char ch;
    cout << "Enter 1 to see current contact numbers" << endl;
    cout << "Enter 2 to add a contact number" << endl;
    cout << "Enter 3 to edit any contact number" << endl;
    cout << "Enter 4 to delete any contact number" << endl;
    cin >> choice;
    if(choice==1)
    {
        cout << "Here is your saved contacts list" << endl;
        see_num();
    }
    else if(choice==2)
    {
        add_num();
    }
    else if(choice==3)
    {
        edit_num();
    }
    else
    {
        del_num();
    }
    
    return 0;
}
