using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace New
{
    public class Rectangle:Shape
    {
        public double length;
        double width;

        public Rectangle(double length, double width)
        {
            this.length = length;
            this.width = width;
        }
        
        

        public override double CalculateArea()
        { 
          return length*width;
        }

        public override void Draw()
        {
            Console.WriteLine($"Length: {length}, Width: {width}");
        }
    }
}
