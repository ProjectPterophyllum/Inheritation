#include "stdafx.h"

namespace Geometry
{
	class Shape
	{
	public:
		virtual double get_area() const = 0;
		virtual double get_perimeter() const = 0;
		virtual void draw() const = 0;
		virtual void info() const
		{
			cout << "Площадь: " << get_area() << endl;
			cout << "Периметр: " << get_perimeter() << endl;
			draw();
		}
	};
	class Square : public Shape
	{
		double lenght_side;
	public:
		double get_lenght_side() const
		{
			return lenght_side;
		}
		Square(double side)
		{
			lenght_side = side;
		}
		~Square() {};
		double get_diagonal() const
		{
			return sqrt(lenght_side * lenght_side * 2);
		}
		double get_area() const
		{
			return lenght_side * lenght_side;
		}
		double get_perimeter() const
		{
			return lenght_side * 4;
		}
		void draw() const
		{
			for (int i = 0; i < lenght_side; i++)
			{
				for (int j = 0; j < lenght_side; j++)
				{
					if (i == 0 || i == lenght_side - 1 || j == 0 || j == lenght_side - 1)
						cout << " *";
					else
						cout << "  ";
				}
				cout << endl;
			}
		}
		void info() const
		{
			cout << typeid(*this).name() << endl;
			cout << "Диагональ квадрата: " << get_diagonal() << endl;
			cout << "Длина стороны квадрата: " << get_lenght_side() << endl;
			Shape::info();
		}
	};
	class Rectangle :public Shape
	{
		double width;
		double lenght;
	public:
		Rectangle(int width, int lenght)
		{
			this->width = width;
			this->lenght = lenght;
		}
		~Rectangle() {}
		double get_width()const
		{
			return width;
		}
		double get_lenght() const
		{
			return lenght;
		}
		double get_area() const
		{
			return width * lenght;
		}
		double get_perimeter() const
		{
			return (width + lenght) * 2;
		}
		double get_diagonal()
		{
			return sqrt(pow(width, 2) + pow(lenght, 2));
		}
		void draw() const
		{
#ifdef RECTANGLE_GDI_DRAW
			//
		//На Windows 11,
		// по умолчанию стоит НЕ стандарная консоль, 
		// а PowerShell или же его новое название "Терминал" 
		// в нем этот способ рисования не работает совсем.
		// 
		//Если переключить на обычную консоль в "Конфиденциальность" >> "Средствах разработчика" в настройках самой системы, то все работает.
		//  

		//WinGDI - Windlows Graphics Device Interface
		//1)Получаем обработчик окна консоли:
			HWND hwnd = GetConsoleWindow();
			//2)Получаем контекст устройства окна консоли:
			HDC hdc = GetDC(hwnd);
			//3) Создаем карандаш. Карандаш рисует контур фигуры
			HPEN hPen = CreatePen(PS_SOLID, 10, RGB(255, 0, 0)); //PS_SOLID - Сплошная линия, 5 - толщина линии
			//4) Создаем кисть. Кисть выполняет заливку фигуры
			HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0));
			//5) Нужно выбрать чем и на чем мы будем рисовать
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			::Rectangle(hdc, 100, 100, 300, 200);
			DeleteObject(hPen);
			DeleteObject(hBrush);
			//Освобождаем контекст устройства:
			ReleaseDC(hwnd, hdc);
#endif // RECTANGLE_GDI_DRAW
#ifdef RECTANGLE_SIMPLE_DRAW
			for (int i = 0; i < lenght; i++)
			{
				for (int j = 0; j < width; j++)
				{
					if (i == 0 || i == lenght - 1 || j == 0 || j == width - 1)
						cout << " *";
					else
						cout << "  ";
				}
				cout << endl;
			}
#endif // RECTANGLE_SIMPLE_DRAW

		}
		void info()
		{
			cout << typeid(*this).name() << endl;
			cout << "Диагональ: " << get_diagonal() << endl;
			cout << "Длина: " << get_lenght() << endl;
			cout << "Ширина: " << get_width() << endl;
			Shape::info();
		}
	};
	//class Halo : public Shape
	//{
	//	int diameter;
	//public:
	//	Halo(int diameter)
	//	{
	//		this->diameter = diameter;
	//	}
	//	~Halo() {}
	//	int get_diameter() const
	//	{
	//		return diameter;
	//	}
	//	double get_radius() const
	//	{
	//		return diameter / 2;
	//	}
	//	double get_perimeter() const
	//	{
	//		return (2 * 3.14) * get_radius();
	//	}
	//};
}
void main()
{
	setlocale(LC_ALL, "");
	Geometry::Square square(5);
	/*cout << "Диагональ квадрата: " << square.get_diagonal() << endl;
	cout << "Длина стороны квадрата: " << square.get_lenght_side() << endl;
	cout << "Площадь квадрата: " << square.get_area() << endl;
	cout << "Периметр квадрата: " << square.get_perimeter() << endl;*/
	square.info();
	Geometry::Rectangle rect(25, 15);
	rect.info();
}
