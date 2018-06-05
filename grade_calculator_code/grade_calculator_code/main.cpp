#include<string>
#include<vector>
#include<iostream>

using namespace std;

class Category
{
public:
    Category();
    Category(string new_name);
    
    void add_item(double new_item);
    double calculate();
    
private:
    string name;
    vector<double> items;
};

Category::Category()
{
    name = "";
    items = vector<double>(0);
}

Category::Category(string new_name)
{
    name = new_name;
    items = vector<double>(0);
}

void Category::add_item(double new_item)
{
    items.push_back(new_item);
}

double Category::calculate()
{
    double sum = 0;
    double result = 0;
    
    for(int i = 0; i < items.size(); ++i)
    {
        sum = sum + items[i];
    }
    
    result = sum / items.size();
    
    return result;
}

class Scheme
{
public:
    Scheme();
    Scheme(string new_name, int new_categories);
    
private:
    string name;
    vector<Category> categories;
};

int main()
{
    cout << "Please enter category name: ";
    string name;
    getline(cin, name);
    
    Category a(name);
    
    while(true)
    {
        cout << "Add item? (Y/N): ";
        char answer;
        cin >> answer;
        string remainder;
        getline(cin, remainder);
        
        if(answer == 'N')
        {
            break;
        }
        
        cout << "Please enter grade in percentage: ";
        double grade;
        cin >> grade;
        a.add_item(grade);
    }
    
    cout << "The average grade of this category is: " << a.calculate() << endl;
    
    return 0;
}
