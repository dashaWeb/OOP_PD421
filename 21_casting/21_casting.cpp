//#include <iostream>
//using namespace std;
//
//enum Colors
//{
//	RED = 1, GREEN = 2, BLUE = 3
//};
//
//struct Point
//{
//	int x = 0, y = 0;
//	virtual void print() const
//	{
//		cout << "(" << x << "," << y << ")" << endl;
//	}
//};
//struct Point3D : Point
//{
//	int z = 0;
//	void print() const override
//	{
//		cout << "(" << x << "," << y << "," << z << ")" << endl;
//	}
//};
//struct String
//{
//	string str;
//};
//int main()
//{
//	//char symbol = 90; // неявне
//
//	//cout << "char(122) :: " << (char)122 << endl;
//	//cout << "(int) Colors::RED --> " << (int)Colors::RED << endl;
//
//	//// static class  if exists implicit type1 ----> type2  static_cast<type2>(var Type);
//	//cout << "\n-------------- Static_cast ----------------\n";
//	//cout << "static_cast<char>(122) :: " << static_cast<char>(122) << endl;
//	//cout << "static_cast<int>(Colors::RED) :: " << static_cast<int>(Colors::RED) << endl;
//
//	//char ch{ 0 };
//	//short sh{ 0 };
//	//int i{ 0 };
//	//double d{ 0 };
//
//	//char* ptr_ch{ &ch };
//	//short* ptr_sh{ &sh };
//	//int* ptr_i{ &i };
//	//double* ptr_d{ &d };
//
//	////ch = static_cast<char>(ptr_sh); error 
//	//ch = reinterpret_cast<char>(ptr_sh);
//	////ptr_d = static_cast<double*>(ptr_i);
//	//ptr_d = reinterpret_cast<double*>(ptr_i);
//	//ch = reinterpret_cast<char>(ptr_sh);
//	//sh = static_cast<short>(i);
//
//	//cout << ch << "\t" << d << "\t" << sh << "\n";
//	Point point;
//	point.x = 1;
//	point.y = 2;
//
//	/*String str = (String&)point;
//	cout << "String number :: (String&)point = " << str.str << endl;*/
//
//	Point3D point3d;
//	point3d.x = 5;
//	point3d.y = 10;
//	point3d.z = 15;
//
//
//	//Point point_2 = point3d; // ok = дозволено неявне зведення від похідного типу до базового
//	Point& point_2 = point3d; // ok = дозволено неявне зведення від похідного типу до базового
//	point_2.print();
//
//	/*Point3D point3 = (Point3D&)point_2;
//	point3.print();*/
//
//	cout << typeid(point_2).name() << "\t " << typeid(Point3D).name() << endl;
//	if (typeid(point_2) == typeid(Point3D))
//	{
//		Point3D point3 = static_cast<Point3D&>(point_2);
//		point3.print();
//	}
//	else
//	{
//		cout << "Untenable casting" << endl;
//	}
//
//
//
//}
//
