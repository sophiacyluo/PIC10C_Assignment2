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
    
    if(items.size() == 1)
    {
        result = sum;
    }
    
    result = sum / items.size();
    
    return result;
}

class Scheme
{
public:
    Scheme();
    Scheme(string new_name);
    
    void add_category(Category new_category);
    double final_grade();
    
private:
    string name;
    vector<Category> categories;
};

Scheme::Scheme()
{
    name = "";
    categories = vector<Category>(0);
}

Scheme::Scheme(string new_name)
{
    name = new_name;
    categories = vector<Category>(0);
}

void Scheme::add_category(Category new_category)
{
    categories.push_back(new_category);
}

double Scheme::final_grade()
{
    double sum = 0;
    double result = 0;
    
    for(int i = 0; i < categories.size(); ++i)
    {
        sum = sum + categories[i].calculate();
    }
    
    if(categories.size() == 1)
    {
        result = sum;
    }
    
    result = sum / categories.size() - 1;
    
    return result;
}

int main()
{
    cout << "Please name your grading scheme: ";
    string scheme;
    getline(cin, scheme);
    
    Scheme s(scheme);
    
    while(true)
    {
        cout << "Please enter category name: ";
        string name;
        getline(cin, name);
        
        Category c(name);
        
        s.add_category(c);
        
        while(true)
        {
            cout << "Please enter grade in percentage: ";
            double grade;
            cin >> grade;
            c.add_item(grade);
            
            cout << "Add item? (Y/N): ";
            char answer;
            cin >> answer;
            string remainder;
            getline(cin, remainder);
            
            if(answer == 'N')
            {
                break;
            }
        }
        
        cout << "The average grade of this category is: " << c.calculate() << endl;
        
        cout << "Add another category? (Y/N): ";
        char answer;
        cin >> answer;
        string remainder;
        getline(cin, remainder);
        
        if(answer == 'N')
        {
            break;
        }
    }
    
    cout << "Your final grade is: " << s.final_grade() << endl;
    
    return 0;
}
