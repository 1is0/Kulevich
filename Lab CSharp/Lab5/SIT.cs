using System;

namespace Lab5
{
   class SIT : Student
    {
        public string GroupNumber { get; set; }

        Marks mark;


        public SIT() : base()
        {
            GroupNumber = "951001";
            mark.Math = 9;
            mark.Programming = 9;
            mark.Logics = 9;
        }


        public SIT(string name, string surname, int age, int math, int programming, int logics) : base(name, surname, age, "Software for Information Technologies")
        {
            GroupNumber = "951001";
            mark.Math = math;
            mark.Programming = programming;
            mark.Logics = logics;
        }

        public override string ToString()
        {
            return base.ToString() + " Group: " + GroupNumber + ";\n " + "Marks: \n " + "Math - " + mark.Math + ";\n" + " Programming - " + mark.Programming + ";\n" + " Logics - " + mark.Logics + ";\n";
        }

        public void SetParametrs()
        {
            Console.Write("Enter name: ");
            Name = Console.ReadLine();

            Console.Write("Enter surname: ");
            Surname = Console.ReadLine();

            Console.Write("Enter age: ");
            Age = CheckAge();

            Console.Write("Enter course: ");
            Course = (Courses)CheckCourse();

            Console.Write("Enter group number: ");
            GroupNumber = Console.ReadLine();

            Console.Write("Enter marks:\n");
            Console.Write("Math: ");
            mark.Math = CheckInt();

            Console.Write("Programming: ");
            mark.Programming = CheckInt();

            Console.Write("Logics: ");
            mark.Logics = CheckInt();

        }

        public static int CheckCourse()
        {
            int course;
            while (!int.TryParse(Console.ReadLine(), out course) || course < 1 || course > 4)
            {
                Console.Write("Wrong input, try again: ");
            }

            return course;
        }

        public static int CheckAge()
        {
            int age;
            while (!int.TryParse(Console.ReadLine(), out age))
            {
                Console.Write("Wrong input, try again: ");
            }

            return age;
        }

        public static int CheckInt()
        {
            int a;
            while (!int.TryParse(Console.ReadLine(), out a) || a <= 0)
            {
                Console.Write("Wrong input, try again: ");
            }

            return a;
        }

        public static double CheckDouble()
        {
            double a;
            while (!double.TryParse(Console.ReadLine(), out a) || a <= 0)
            {
                Console.Write("Wrong input, try again: ");
            }

            return a;
        }
    }
}
