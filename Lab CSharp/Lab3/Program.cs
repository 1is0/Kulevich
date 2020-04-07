using System;

namespace Lab3
{
  class Program
    {
        static void Main(string[] args)
        {

            Human.Show();          //работа со статическим элементом
            Console.WriteLine();


            Human manTwo = new Human(19, 1.79, 79);
            Console.WriteLine(manTwo);
            Console.WriteLine();

            Human manOne = new Human();

            manOne.Name = "Nastya";
            manOne.Surname = "Kruglaya";
            manOne.Age = 18;
            manOne.Height = 1.73;
            manOne.Weight = 50.2;
            Console.WriteLine(manOne);
            Console.WriteLine();

            Human.Show();     //работа со статическим элементом
            Console.WriteLine();

            manOne.Increase(2);
            Console.WriteLine(manOne);
            Console.WriteLine();

            manOne.Increase(2, 0.11, 4.5);
            Console.WriteLine(manOne);
            Console.WriteLine();



            Human familyMembers = new Human(4);         //использование индексатора
            familyMembers[0] = "Mother";
            familyMembers[1] = "Father";
            familyMembers[2] = "Grandmother";
            familyMembers[3] = "Grandfather";
            Console.WriteLine("Family: " + familyMembers[0] + "," + familyMembers[1] + "," + familyMembers[2] + "," + familyMembers[3]);
            Console.WriteLine();

            Console.ReadKey();
        }
    }

}
