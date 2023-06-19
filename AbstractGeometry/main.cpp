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
			cout << endl;
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
#ifdef SIMPLE_SQUARE_DRAW
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
#endif // SIMPLE_SQUARE_DRAW
#ifdef GDI_SQUARE_DRAW
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, 10, RGB(0, 0, 255));
			HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 0));
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			::Rectangle(hdc, 300, 5, 350, 55);
			DeleteObject(hPen);
			DeleteObject(hBrush);
			ReleaseDC(hwnd, hdc);
#endif // GDI_SQUARE_DRAW

		}
		void info() const
		{
			cout << typeid(*this).name()
				<< endl
				<< "Диагональ квадрата: " << get_diagonal()
				<< endl
				<< "Длина стороны квадрата: " << get_lenght_side()
				<< endl;
			Shape::info();
		}
	};
	class Rectangle :public Shape
	{
		double width;
		double lenght;
	public:
		Rectangle(double width, double lenght)
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

			/* На Windows 11, по умолчанию стоит НЕ стандарная консоль, а PowerShell или же его новое название "Терминал", в нем этот способ рисования не работает совсем.
			 Если переключить на обычную консоль в "Конфиденциальность" >> "Средствах разработчика" в настройках самой системы, то все работает.

			 (?)Возможно нужно захватывать другое окно, я попробовал то что нашел в интернете по этой теме, ничего не работает, либо я применил это не правильно.
			 (?)Либо использовать GDI+, Direct2D или что-то иное, не знаю, не получилось разобраться
			 (?)Либо попробовать создать какое-то отдельное окно, не консольное и перенести все рисование, а так же информацию туда, но этому я пока не научился*/


			 //WinGDI - Windlows Graphics Device Interface
			 //1)Получаем обработчик окна консоли:
			HWND hwnd = GetConsoleWindow();
			//2)Получаем контекст устройства окна консоли:
			HDC hdc = GetDC(hwnd);
			//3) Создаем карандаш. Карандаш рисует контур фигуры:
			HPEN hPen = CreatePen(PS_SOLID, 10, RGB(0, 255, 0)); //PS_SOLID - Сплошная линия, 5 - толщина линии
			//4) Создаем кисть. Кисть выполняет заливку фигуры:
			HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 0));
			//5) Нужно выбрать чем и на чем мы будем рисовать:
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			::Rectangle(hdc, 300, 80, 400, 130);
			//6) Удаляем объекты Карандаш и Кисть:
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
			cout << typeid(*this).name()
				<< endl
				<< "Диагональ: " << get_diagonal()
				<< endl
				<< "Длина: " << get_lenght()
				<< endl
				<< "Ширина: " << get_width()
				<< endl;
			Shape::info();
		}
};
	class Halo : public Shape //Circle
	{
		double diameter;
	public:
		Halo(double diameter)
		{
			this->diameter = diameter;
		}
		~Halo() {}
		double get_diameter() const
		{
			return diameter;
		}
		double get_radius() const
		{
			return diameter / 2;
		}
		double get_perimeter() const
		{
			return 2 * M_PI * get_radius();
		}
		double get_area() const
		{
			return M_PI * pow(get_radius(), 2);
		}
		void draw() const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, 10, RGB(0, 100, 150));
			HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 0));
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			Ellipse(hdc, 300, 150, 350, 200);
			DeleteObject(hPen);
			DeleteObject(hBrush);
			ReleaseDC(hwnd, hdc);
		}
		void info()
		{
			cout << typeid(*this).name()
				<< endl
				<< "Диаметр: " << get_diameter()
				<< endl
				<< "Радиус: " << get_radius()
				<< endl;
			Shape::info();
		}
	};
	class Triangle :public Shape
	{
		double lenght_side;
	public:
		Triangle(double lenght_side)
		{
			this->lenght_side = lenght_side;
		}
		~Triangle(){}
		double get_lenght_side() const
		{
			return lenght_side;
		}
		double get_height() const
		{
			return sqrt(pow(lenght_side, 2) - pow(lenght_side / 2, 2));
		}
		double get_area() const
		{
			return (lenght_side / 2) * get_height();
		}
		double get_perimeter() const
		{
			return lenght_side * 3;
		}
		void draw() const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, 10, RGB(100, 100, 150));
			HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 0));
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			POINT vertices[] = { {330, 230}, {380, 300}, {280, 300} };
			Polygon(hdc, vertices, sizeof(vertices) / sizeof(vertices[0]));
			DeleteObject(hPen);
			DeleteObject(hBrush);
			ReleaseDC(hwnd, hdc);
		}
		void info()
		{
			cout << typeid(*this).name()
				<< endl
				<< "Длинна стороны: " << get_lenght_side()
				<< endl
				<< "Высота треугольника: " << get_height()
				<< endl;
			Shape::info();
		}
	};
}
void main()
{
	setlocale(LC_ALL, "");
	Geometry::Square square(5);
	square.info();
	Geometry::Rectangle rect(25, 15);
	rect.info();
	Geometry::Halo circle(10);
	circle.info();
	Geometry::Triangle triangle(10);
	triangle.info();
}
