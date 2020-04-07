using System;

namespace Lab3
{
    class Human
    {
        protected int age;
        public double weight;
        public double height;

        static private int population = 0; //статический элемент класса       

        protected string[] family;

        public string Name { get; set; }
        public string Surname { get; set; }


        public int Age           //свойства
        {
            get { return age; }
            set { age = value > 0 ? value : 0; }
        }

        public double Weight
        {
            get { return weight; }
            set { weight = value > 0 ? value : 0; }
        }

        public double Height
        {
            get { return height; }
            set { height = value > 0 ? value : 0; }
        }


        public Human()         //конструкторы
        {
            Name = "Lesha";
            Surname = "Kulevich";
            age = 18;
            weight = 70.3;
            height = 1.84;
            population++;
        }

        public Human(int a, double h, double w)
        {
            Name = "Lesha";
            Surname = "Kulevich";
            age = a;
            weight = w;
            height = h;
            population++;
        }

        public Human(string n, string s, int a, double h, double w)
        {
            Name = n;
            Surname = s;
            age = a;
            weight = w;
            height = h;
            population++;
        }


        public override string ToString()  // методы
        {
            string info = "Name: " + Name + ";" + "Surname:" + Surname + " Age: " + age + ";" + " Height: " + height + ";" + " Weight: " + weight + ";";
            return info;

        }


        public void Increase(int a)    //перегрузка методов
        {
            age += a;
        }

        public void Increase(int a, double h, double w)
        {
            age += a;
            height += h;
            weight += w;

        }

        public static void Show()
        {
            Console.WriteLine("The population is: " + population);
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
