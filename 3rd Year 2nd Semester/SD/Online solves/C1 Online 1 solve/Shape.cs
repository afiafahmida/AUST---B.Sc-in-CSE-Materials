using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace New
{
    public abstract class Shape : IShape
    {
        public abstract double CalculateArea();
        public abstract void Draw();
    }
}
