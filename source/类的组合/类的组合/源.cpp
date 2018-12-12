#include<iostream>
using namespace std;
class Point
{
public:
	Point(int xx,int yy);
	Point() = default;
	~Point();
	Point(const Point&p);
	int GetX() {
		return x;
	}
	int GetY() {
		return y;
	}

private:
	int x, y;

};
Point::Point(int xx,int yy):x(xx),y(yy) {
	cout << "Calling constructor of Point" << endl;
}
Point::Point(const Point&p)
{
	x = p.x;
	y = p.y;
	cout << "Calling the copy constructor of Point" << endl;
}

Point::~Point()
{
}
class Line
{
public:
	Line(Point p1,Point p2);
	~Line();
	Line(const Line &l);
	double getLength() { return len; }

private:
	Point p1, p2;
	double len;
};

Line::Line(Point mp1,Point mp2):p1(mp1),p2(mp2)
{
	cout << "Calling constructor of Line" << endl;
	double x = static_cast<double>(p1.GetX() - p2.GetX());
	double y = static_cast<double>(p1.GetY() - p2.GetY());
	len = sqrt(x*x + y * y);
}
Line::Line( const Line &l){//如果不存在Point的默认构造函数，会报错？？？
	p1 = l.p1;
	p2 = l.p2;
	len = l.len;
	cout << "Calling the copy constructor of Line" << endl;
}
Line::~Line()
{
}
int main() {
	Point p1(1, 1), p2(3, 4);
	Line line(p1, p2);
	Line line2(line);
	cout << "The length of the line is: "<<line.getLength()<<endl;
	cout << "The length of the line2 is: "<<line2.getLength()<<endl;
	return 0;
}