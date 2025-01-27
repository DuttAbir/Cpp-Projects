#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<iterator>
#include<string>

using namespace std; 

struct Employee
{
    int id;
    string name;
    double salary;
};

void diaplayEmployee(const Employee &emp){
    cout<<"ID :"<<emp.id<<", Name : "<<emp.name<<", Salary : $"<<emp.salary<<endl;
}

int main()
 { 
    vector<Employee> employees = {
        {101,"Abir", 100000},
        {102,"Soumen", 30000},
        {103,"Sam", 50000},
        {104,"Harry", 60000},
        {105,"Payel", 70000},
    };

    sort(employees.begin(), employees.end(),[](const Employee &e1, const Employee &e2){
        return e1.salary>e2.salary;
    });

    cout<<"Employees sorted by salaries -> High to Low"<<endl;

    for_each(employees.begin(),employees.end(),diaplayEmployee);

    vector<Employee> highEarners;

    copy_if(
        employees.begin(),
        employees.end(),
        back_inserter(highEarners),
        [](const Employee &e){
        return e.salary >50000;
    });

    cout<<"Employees who are high earners"<<endl;

    for_each(highEarners.begin(),highEarners.end(),diaplayEmployee);

    double totalSalary = accumulate(employees.begin(),employees.end(),0.0, [](double sum, const Employee &e){
        return sum + e.salary;
    });


    double avgSalary = totalSalary/ employees.size();

    auto highestPaid = max_element(employees.begin(),employees.end(),[](const Employee &e1, const Employee &e2){
        return e1.salary < e2.salary;
    });

    cout<<avgSalary<<endl;

    

    return 0; 
 } 