using System;

namespace lab7
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Write two rational numbers: \n");
            RationalNumber a = new RationalNumber();
            RationalNumber b = new RationalNumber();
            Console.WriteLine(a.ToString() + "  " + b.ToString());

            Console.WriteLine($"{a} >= {b} = " + (a >= b));
            Console.WriteLine($"{a.ToStringfloat()} >= {b.ToStringfloat()} = " + (a >= b));
            Console.WriteLine($"{a} < {b} = " + (a < b));
            Console.WriteLine($"{a.ToStringfloat()} < {b.ToStringfloat()} = " + (a < b));
            Console.WriteLine($"{a} <= {b} = " + (a <= b));
            Console.WriteLine($"{a.ToStringfloat()} <= {b.ToStringfloat()} = " + (a <= b));
            Console.WriteLine($"{a} != {b} = " + (a != b));
            Console.WriteLine($"{a.ToStringfloat()} != {b.ToStringfloat()} = " + (a != b));
            Console.WriteLine($"{a} - {b} = " + (a - b));
            Console.WriteLine($"{a.ToStringfloat()} - {b.ToStringfloat()} = " + (a - b).ToStringfloat());
            Console.WriteLine($"{a} + {b} = " + (a + b));
            Console.WriteLine($"{a.ToStringfloat()} + {b.ToStringfloat()} = " + (a + b).ToStringfloat());
            Console.WriteLine($"{a} * {b} = " + (a * b));
            Console.WriteLine($"{a.ToStringfloat()} * {b.ToStringfloat()} = " + (a * b).ToStringfloat());
            Console.WriteLine($"{a} / {b} = " + (a / b));
            Console.WriteLine($"{a.ToStringfloat()} / {b.ToStringfloat()} = " + (a / b).ToStringfloat());


            Console.WriteLine("Рациональное число в строковом виде: " + a.ToString());
            Console.WriteLine("Рациональное число как float: " + a.ToStringfloat());
            Console.WriteLine("Рациональное число как double: " + a.ToStringDouble() + "\n");

            Console.ReadLine();
        }
    }
}
