#include <iostream>
#include <vector>
using namespace std;
class CShape{
    public:
        virtual void display()=0;
        virtual ~CShape(){}
};
class CPoint: public CShape{
    private:
        int x, y;
    public:
        CPoint(int a, int b):x(a), y(b){}
        CPoint(int x, int y):x(x),y(y){}
        CPoint(const CPoint& other):x(other.x),y(other.y){}
        void display(){
            cout<<"Point: ("<<x<<", "<<y<<")"<<endl;
        }
        friend ostream& operator<<(ostream& out, const CPoint& point);
        friend istream& operator>>(istream& in, CPoint& point);
};
ostream& operator<<(ostream& out, const CPoint& point){
    out<<"Point: ("<<point.x<<", "<<point.y<<")"<<endl;
    return out;
}
istream& operator>>(istream& in, CPoint& point){
    in>>point.x>>point.y;
    return in;
}
class CLine: public CShape{
    private:
        CPoint start, end;
    public:
        CLine(){}
        CLine(int x1,int y1, int x2, int y2):start(x1,y1),end(x2,y2){}
        void display()override{
            cout<<"Line: From"<<start<<"To"<<end<<endl; 
        }
        CPoint getStart()const{
            return start;
        }
        CPoint getEnd()const{
            return end;
        }
        bool contains(const CPoint& point)const{
            int x1=start.x, y1=start.y, x2=end.x, y2=end.y, x3=point.x, y3=point.y;
        }
        friend ostream& operator<<(ostream& out, const CLine& line);
};
ostream& operator<<(ostream& out, const CLine& line){
    out<<"Line:From"<<line.start<<"To"<<line.end;
    return out;
}
int main(){
    CShape* shapes[2];
    shapes[0]=new CPoint(3,4);
    shapes[1]=new CLine(1,1,5,5);
    for (int i=0;i<2;++i){
        shapes[i]->display();
}
    CPoint p;
    cout<<"Enter point: ";
    cin>>p;
    cout<<"Point: "<<p<<endl;
    CLine l;
    cout<<"Line: "<<l<<endl;
    cin >> l.getStart()>>l.getEnd();
    cout<<"Line: "<<l<<endl;
    return 0;
}
    CPoint testPoint(3, 4);
    if (l.contains(testPoint)) {
        cout << "The point " << testPoint << " is on the line " << l << endl;

}