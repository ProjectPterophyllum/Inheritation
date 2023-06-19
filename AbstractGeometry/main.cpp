﻿#include "stdafx.h"

namespace Geometry
{
	enum Color
	{
		red = 0x000000FF,
		green = 0x0000FF00,
		blue = 0x00FF0000,
		grey = 0x00AAAAAA,
		yellow = 0x0000FFFF,
		white = 0x00FFFFFF,
		black = 0x00000000
	};
	enum Limits
	{
		MIN_START_X = 100,
		MAX_START_X = 1000,
		MIN_START_Y = 100,
		MAX_START_Y = 800,
		MIN_LINE_WIDTH = 1,
		MAX_LINE_WIDTH = 30,
		//-----------------------
		MIN_LENGHT = 20,
		MAX_LENGHT = 1000
	};
#define SHAPE_TAKE_PARAM Color color, int start_x, int start_y, int line_widht
#define SHAPE_GIVE_PARAM color, start_x, start_y, line_widht
	class Shape
	{
	protected:
		Color color;
		int start_x;
		int line_width;
		int line_width;

	public:
		Shape(SHAPE_TAKE_PARAM)
		{
			set_color(color);
			set_start_x(start_x);
			set_start_y(start_y);
			set_line_width(line_width);
		}
		Color get_color() const
		{
			return color;
		}
		int get_start_x() const
		{
			return start_x;
		}
		int get_start_y() const
		{
			return line_width;
		}
		int get_line_width() const
		{
			return line_width;
		}
		void set_color(Color color)
		{
			this->color = color;
		}
		void set_start_x(int start_x)
		{
			if (start_x < Limits::MIN_START_X) start_x = Limits::MIN_START_X;
			if (start_x > Limits::MAX_START_X) start_x = Limits::MAX_START_X;
			this->start_x = start_x;
		}
		void set_start_y(int start_y)
		{
			if (start_y < Limits::MIN_START_Y) start_y = Limits::MIN_START_Y;
			if (start_y > Limits::MAX_START_Y) start_y = Limits::MAX_START_Y;
			this->start_x = start_y;
		}
		void set_line_width(int line_width)
		{
			if (line_width < Limits::MIN_LINE_WIDTH) line_width = Limits::MIN_LINE_WIDTH;
			if (line_width > Limits::MAX_LINE_WIDTH) line_width = Limits::MAX_LINE_WIDTH;
			this->line_width = line_width;
		}
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
	class Rectangle :public Shape
	{
		double width;
		double lenght;
	public:
		Rectangle(double width, double lenght, SHAPE_TAKE_PARAM) : Shape(SHAPE_GIVE_PARAM)
		{
	
		}
		~Rectangle() {}
		void set_width(double width)
		{
			if (width < MIN_LENGHT)width = MIN_LENGHT;
			if (width > MAX_LENGHT) width = MAX_LENGHT;
			this->width = width;
		}
		void set_lenght(double lenght)
		{
			if (lenght < MIN_LENGHT)lenght = MIN_LENGHT;
			if (lenght > MAX_LENGHT)lenght = MAX_LENGHT;
			this->lenght = lenght;
		}
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
			HPEN hPen = CreatePen(PS_SOLID, 10, color); //PS_SOLID - Сплошная линия, 5 - толщина линии
			//4) Создаем кисть. Кисть выполняет заливку фигуры:
			HBRUSH hBrush = CreateSolidBrush(color);
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
	class Square :public Rectangle
	{
	public:
		Square(double side, SHAPE_TAKE_PARAM) :Rectangle(side, side, SHAPE_GIVE_PARAM) {}
		~Square() {}
	};
	class Halo : public Shape //Circle
	{
		double diameter;
	public:
		Halo(double diameter, SHAPE_TAKE_PARAM) :Shape(SHAPE_GIVE_PARAM)
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
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);
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

	};

	class EquilaterallTriangle :public Triangle
	{
		double lenght_side;
	public:
		EquilaterallTriangle(double lenght_side, SHAPE_TAKE_PARAM) : Shape(SHAPE_GIVE_PARAM)
		{
			this->lenght_side = lenght_side;
		}
		~EquilaterallTriangle() {}
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
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);
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
