using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace New
{
    public class Square : Rectangle
    {
        double side;
        

        public Square(double side) : base(side, side)
        {
            
            
        }

      
        public override void Draw()
        {
            Console.WriteLine($"Length: {base.length}");
        }
    }
}
