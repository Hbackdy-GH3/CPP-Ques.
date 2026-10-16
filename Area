#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

class Shape{
public:
    string Name;
public:
    Shape(string name){
        Name=name;
    }
    virtual float area() const=0;
    virtual float perimeter() const=0;
    virtual ~Shape(){}
};

class Circle: public Shape{
public:
    float Radius;
    Circle(float radius): Shape("circle"){
        if(radius<0){
            cout<<"Please enter positive value of radius!!..."<<"\n";
            Radius=0;
        }else{
        Radius=radius;
        }
    }
    float area() const{
        // cout<<"Area: "<<std::setprecision(4)<< std::fixed<<3.14*Radius*Radius<<"\n";
        return 3.14*Radius*Radius;
    }
    float perimeter() const{
        // cout<<"Perimeter: "<<std::setprecision(4)<< std::fixed<<2*3.14*Radius<<"\n";
        return 2*3.14*Radius;
    }
    ~Circle() override{}
};

class Rectangle: public Shape{
public:
    float L;
    float B;
    Rectangle(float l, float b): Shape("rectangle"){
        if(l<0 || b<0){
            cout<<"Please enter positive values!!..."<<"\n";
            L=0;
            B=0;
        }else{
            L=l;
            B=b;
        }
        
    }
    float area() const{
        // cout<<"Area: "<<std::setprecision(4)<< std::fixed<<L*B<<"\n";
        return L*B;
    }
    float perimeter() const{
        // cout<<"Perimeter: "<<std::setprecision(4)<< std::fixed<<2*(L+B)<<"\n";
        return 2*(L+B);
    }
    ~Rectangle() override{}
};
class Triangle: public Shape{
public:
    float A;
    float B;
    float C;
    Triangle(float a, float b, float c): Shape("triangle"){
        int right=0;
        if(a<0 || b<0 || c<0){
            cout<<"Please enter positive values!!..."<<"\n";
        }else if(a+b<=c){
            cout<<"Invalid case"<<"\n";
        }
        else if(a+c<=b){
            cout<<"Invalid case"<<"\n";
        }
        else if(c+b<=a){
            cout<<"Invalid case"<<"\n";
        }else{
            A=a;
            B=b;
            C=c;
            right=1;
        }
        if(right==0){
            A=0;
            B=0;
            C=0;
        }
    }
    float area() const{
        float s=(A+B+C)/2;
            float area=sqrt((s)*(s-A)*(s-B)*(s-C));
        return area;
            // cout<<"Area: "<<std::setprecision(4)<< std::fixed<<area<<"\n";
    }
     float perimeter() const{
        // cout<<"Perimeter: "<<std::setprecision(4)<< std::fixed<<(A+B+C)<<"\n";
         return (A+B+C);
    }
    ~Triangle() override{};
};

void display(const Shape& shape){
    cout<<"====="<<shape.Name<<"====="<<"\n";
    cout<<"Area: "<<shape.area()<<"\n";
    cout<<"Perimeter: "<<shape.perimeter()<<"\n";
    cout<<"=========================="<<"\n";
    
}

int main() {

    Shape* s[3];
    s[0]=new Circle(23);
    s[1]=new Rectangle(20.9,18.6);
    s[2]=new Triangle(60,80,100);

    string largestName;
    float largestArea=0;
    for(int i=0;i<3;i++){
        display(*s[i]);
        // largestArea < s[i]->area() ? largestArea=s[i]->area() : largestArea=largestArea;
        if(largestArea < s[i]->area()){
            largestArea=s[i]->area();
            largestName=s[i]->Name;
        }
    }
    cout<<"Largest Area is "<<largestArea<<" and shape is of "<<largestName<<"\n";

    for(int i=0;i<3;i++){
        delete s[i];
    }
    
    return 0;
}
