using System;

namespace Lab5
{
    abstract class Human
    {
        protected int age;

        static private int population = 0; //статический элемент класса       

        protected string[] family;

        public string Name { get; set; }
        public string Surname { get; set; }


        public int Age           //свойства
        {
            get { return age; }
            set { age = value > 0 ? value : 0; }
        }

        public Human()         //конструкторы
        {
            Name = "Lesha";
            Surname = "Kulevich";
            age = 18;
            population++;
        }
        public Human(string name, string surname, int a)
        {
            Name = name;
            Surname = surname;
            age = a;
            population++;
        }
        public override string ToString()  // методы
        {
            string info = " Name: " + Name + ";" + " Surname: " + Surname + " Age: " + age + ";";
            return info;

        }


        public void Increase(int a)    //перегрузка методов
        {
            age += a;
        }


        public static void Show()
        {
            Console.WriteLine(" The population is: " + population);
        }

        public Human(int n)
        {
            family = new string[n];
        }

        public string this[int n]  //индексатор
        {
            get
            {
                return family[n];
            }

            set
            {
                family[n] = value;
            }
        }
    }
}
