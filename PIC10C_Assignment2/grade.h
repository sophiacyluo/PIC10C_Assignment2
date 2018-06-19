#ifndef GRADE_H
#define GRADE_H

#include<string>
#include<vector>
#include<iostream>

using namespace std;

class Category
{
public:
    Category();
    Category(string new_name, double new_weight);

    void add_item(double new_item);
    double calculate();
    double get_weight() const;

private:
    string name;
    vector<double> items;
    double result;
    double weight;
};

Category::Category()
{
    name = "";
    items = vector<double>(0);
    result = 0;
    weight = 0;
}

Category::Category(string new_name, double new_weight)
{
    name = new_name;
    items = vector<double>(0);
    result = 0;
    weight = new_weight;
}

void Category::add_item(double new_item)
{
    items.push_back(new_item);
}

double Category::calculate()
{
    double sum = 0;

    for(int i = 0; i < items.size(); ++i)
    {
        sum = sum + items[i];
    }

    if(items.size() == 1)
    {
        result = sum;
    }
    else
        result = sum / items.size();

    return result;
}

double Category::get_weight() const
{
    return weight;
}

class Scheme
{
public:
    Scheme();
    Scheme(string new_name);

    void add_category(Category new_category);
    void scheme_grade();
    double get_grade() const;

private:
    string name;
    vector<Category> categories;
    double grade;
};

Scheme::Scheme()
{
    name = "";
    categories = vector<Category>(0);
    grade = 0;
}

Scheme::Scheme(string new_name)
{
    name = new_name;
    categories = vector<Category>(0);
    grade = 0;
}

void Scheme::add_category(Category new_category)
{
    categories.push_back(new_category);
}

void Scheme::scheme_grade()
{
    for(int i = 0; i < categories.size(); ++i)
    {
        grade = grade + (categories[i].calculate() * categories[i].get_weight());
    }
}

double Scheme::get_grade() const
{
    return grade;
}

class Course
{
public:
    Course();
    Course(string new_name);

    void add_scheme(Scheme new_scheme);
    double final_grade();

private:
    string name;
    vector<Scheme> schemes;
    double total;
};

Course::Course()
{
    name = "";
    total = 0;
}

Course::Course(string new_name)
{
    name = "";
    total = 0;
}

void Course::add_scheme(Scheme new_scheme)
{
    schemes.push_back(new_scheme);
}

double Course::final_grade()
{
    if(schemes.size() == 1)
        total = schemes[0].get_grade();
    else
    {
        for(int i = 0; i < schemes.size(); ++i)
        {
            if(schemes[i].get_grade() > total)
                total = schemes[i].get_grade();
        }
    }

    return total;
}


#endif // GRADE_H
