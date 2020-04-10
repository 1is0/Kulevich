using System;

namespace Lab5
{
  class Program
    {
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


            int sp;
            Console.Write("Choose your specialty: Informatics - 1, SIT - 2, CSN - 3 ");
            while (!int.TryParse(Console.ReadLine(), out sp) || sp < 1 || sp > 3)
            {
                Console.Write("Wrong input, try again: ");
            }
            switch (sp)
            {
                case 1:
                    Informatics informaticStudentOne = new Informatics();
                    informaticStudentOne.SetParametrs(); 
                    Console.WriteLine(); 
                    Console.WriteLine(informaticStudentOne);  break;
                case 2:
                    SIT softwareStudentOne = new SIT();
                    softwareStudentOne.SetParametrs();
                    Console.WriteLine();
                    Console.WriteLine(softwareStudentOne);  break;
                case 3:
                    CSN computingStudentOne = new CSN();
                    computingStudentOne.SetParametrs();
                    Console.WriteLine();
                    Console.WriteLine(computingStudentOne);  break;
            }


            Human.Show();    
            Console.WriteLine();

            Console.ReadKey();
        }
    }
}
