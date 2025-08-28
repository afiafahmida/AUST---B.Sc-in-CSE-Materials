using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace New
{
    class Program
    {
        static void Main(string[] args)
        {
            Rectangle rectangle = new Rectangle(5.5, 3.2);

            double area = rectangle.CalculateArea();
            Console.WriteLine("Area of the rectangle:" + area);
            rectangle.Draw();

            Circle circle = new Circle(2);

            double radius = circle.CalculateArea();
            Console.WriteLine("Area of the circle:" + radius);
            circle.Draw();

            Square square = new Square(2);

            double side = square.CalculateArea();
            Console.WriteLine("Area of the square:" + side);
            square.Draw();
        }
        
    }
}