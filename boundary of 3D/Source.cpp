#include <iostream>
#include <cmath>
#include<vector>
using namespace std;

class Pos
{
public:
	double x;
	double y;
	Pos()
	{
		x = 0;
		y = 0;
	}
	Pos(double a, double b)
	{
		x = a;
		y = b;
	}
	void setPos()
	{
		cout << "請輸入X Y: ";
		cin >> x;
		cin >> y;
	}
	void setPos(double a, double b)
	{
		x = a;
		y = b;
	}
	double getx()
	{
		return x;
	}
	double gety()
	{
		return y;
	}

};

class XYboundCal
{
public:
	
	double U, D, L, R,origin_x, origin_y,BL,BW;
	vector <Pos> bound;//UDLW 上下左右
	vector <Pos> dot;
	
	XYboundCal()
	{
		
	}
	void pushXY(Pos temp)
	{
		dot.push_back(temp);
		if (bound.size()<4)
			bound.push_back(temp);
	}
	void getBound()
	{
		for (int i = 0; i < dot.size(); i++)
		{
			if (dot[i].y > bound[0].y)
				bound[0].y = dot[i].y;
			if (dot[i].y < bound[1].y)
				bound[1].y = dot[i].y;
			if (dot[i].x < bound[2].x)
				bound[2].x = dot[i].x;
			if (dot[i].x > bound[3].x)
				bound[3].x = dot[i].x;
		}
		U = bound[0].gety();//上
		D = bound[1].gety();//下
		L = bound[2].getx();//左
		R = bound[3].getx();//右
		origin_x = bound[2].x;//標記新原點
		origin_y = bound[1].y;
		BL = bound[3].x - bound[2].x;;
		BW = bound[0].y - bound[1].y;
	}
	void print_bound()
	{
		cout << " ( " << origin_x << "," << origin_y << " )  , " << BL << "," << BW << endl;
	}
};
class Test
{
public:
	XYboundCal WORK;
	

	void Test_XYboundCal()
	{
		XYboundCal WORK;
		Pos a(1, 1);
		Pos b(2, 2);
		Pos c(2, 5);
		Pos d(3, 9);
		Pos e(4, 0.5);


		WORK.pushXY(a);
		WORK.pushXY(b);
		WORK.pushXY(c);
		WORK.pushXY(d);
		WORK.pushXY(e);

		WORK.getBound();
		WORK.print_bound();
	}
};

int main()
{
	Test T1;
	T1.Test_XYboundCal();
	

	system("pause");
	return 0;
}

