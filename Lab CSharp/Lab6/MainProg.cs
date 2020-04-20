using System;
using System.Collections;

namespace Lab6
{
    class Program
    {

        static public void SetParametrs(Student st)
        {
            Console.Write("Enter name: ");
            st.Name = Console.ReadLine();

            Console.Write("Enter surname: ");
            st.Surname = Console.ReadLine();

            Console.Write("Enter age: ");
            st.Age = CheckAge();

            Console.Write("Enter course: ");
            st.Course = (Courses)CheckCourse();

            Console.Write("Enter group number: ");
            st.GroupNumber = Console.ReadLine();

            Console.Write("Enter marks:\n");
            Console.Write("Math: ");
            st.studentMarks.math = CheckInt();

            Console.Write("Programming: ");
            st.studentMarks.programming = CheckInt();

            Console.Write("Logics: ");
            st.studentMarks.logics = CheckInt();

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
            while (!int.TryParse(Console.ReadLine(), out a) || a <= 0 || a > 10)
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

        public static void SetArray(Student[] list)
        {
            for (int i = 0; i < list.Length; i++)
            {
                int sp;
                Console.Write("Choose your specialty: Informatics - 1, SIT - 2, CSN - 3 ");
                while (!int.TryParse(Console.ReadLine(), out sp) || sp < 1 || sp > 3)
                {
                    Console.Write("Wrong input, try again: ");
                }
                switch (sp)
                {
                    case 1:
                        list[i] = new Informatics { Specialty = "Informatics" };
                        SetParametrs(list[i]);
                        Console.WriteLine(); break;
                    case 2:
                        list[i] = new SIT { Specialty = "Software for Information Technologies" };
                        SetParametrs(list[i]);
                        Console.WriteLine(); break;
                    case 3:
                        list[i] = new CSN { Specialty = "Computing Systems and Networks" };
                        SetParametrs(list[i]);
                        Console.WriteLine(); break;
                }
            }

            Console.WriteLine("List of students:");
            for (int i = 0; i < list.Length; i++)
            {
                Console.WriteLine(list[i]);
            }
        }
        static void Main(string[] args)
        {
            Human.Show();
            Console.WriteLine();

            Student studentOne = new Student("Lesha", "Kulevich", 18, "Informatics");
            Console.WriteLine(studentOne);
            Console.WriteLine();

            Informatics informaticStudent = new Informatics("Lesha", "Kulevich", 18, 9, 10, 9);
            Console.WriteLine(informaticStudent);

            SIT softwareStudent = new SIT("Pavel", "Slyazh", 18, 8, 9, 9);
            Console.WriteLine(softwareStudent);

            CSN computingStudent = new CSN("Nastya", "Romanchuk", 18, 10, 10, 9);
            Console.WriteLine(computingStudent);

            Human.Show();
            Console.WriteLine();


            Student[] list = new Student[2];
            SetArray(list);
            Console.WriteLine();

            if (list[0].CompareTo(list[1]) == 0) Console.WriteLine("Students know C# at the same level\n");
            if (list[0].CompareTo(list[1]) == 1) Console.WriteLine("First student knows C# better than second\n");
            if (list[0].CompareTo(list[1]) == -1) Console.WriteLine("First student knows C# worse than second\n");

            Console.WriteLine("Copy of the first student: ");
            Student st1 = (Student)list[0].Clone();
            Console.WriteLine(st1);

            Console.WriteLine("Copy of the second student:");
            Student st2 = (Student)list[1].Clone();
            Console.WriteLine(st2);

            foreach (Student s in list)
            {
                Console.WriteLine($"{s.Name}  {s.Surname} - Level: {s.CountLevel()}");
            }
            
            Human.Show();
            Console.WriteLine();

            Console.ReadKey();
        }
     }
}
