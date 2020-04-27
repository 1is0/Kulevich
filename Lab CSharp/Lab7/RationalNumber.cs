using System;

namespace lab7
{
  class RationalNumber : IComparable<RationalNumber>, IEquatable<RationalNumber>
    {
        private int numerator;
        private int denominator;

        public static int NOD(int a, int b)
        {
            if (a == 0)
                return b;
            else
                return Math.Abs(NOD(b % a, a));
        }

        public RationalNumber()
        {
            int a;
            int b;
            Console.Write("Write numerator ");
            while (!int.TryParse(Console.ReadLine(), out a))
            {
                Console.Write("Wrong input, try again: ");
            }
            Console.Write("Write denominator ");
            while (!int.TryParse(Console.ReadLine(), out b) || b <=0)
            {
                Console.Write("Wrong input, try again: ");
            }
            numerator = a;
            denominator = b;
        }
        public RationalNumber(int a, int b=1)
        {
            numerator = a;
            denominator = b;
        }

        public int CompareTo(RationalNumber other)
        {
            if (other == null)
                return 1;
            int newNum1 = this.numerator * other.denominator;
            int newNum2 = other.numerator * this.denominator;
            return newNum1 - newNum2;
        }

        private void Simplify()
        {
            int nod = NOD(denominator, numerator);
            denominator /= nod;
            numerator /= nod;
        }

        private int CountIntPart()
        {
            int number;
            if (numerator > denominator)
                number = numerator / denominator;
            else
                number = 0;
            return number;
        }

        public bool Equals(RationalNumber other)
        {
            if (other != null && this.CompareTo(other) == 0)
                return true;
            else
                return false;
        }

        public override bool Equals(object obj)
        {
            if (obj is RationalNumber && Equals((RationalNumber)obj))
                return true;
            else
                return false;
        }

        public static bool operator >(RationalNumber number1, RationalNumber number2)
        {
            
            if (number1.CompareTo(number2) > 0)
                return true;
            else
                return false;
        }

        public static bool operator <(RationalNumber number1, RationalNumber number2)
        {
            if (number1.CompareTo(number2) < 0)
                return true;
            else
                return false;
        }

        public static bool operator >=(RationalNumber number1, RationalNumber number2)
        {
            if (number1.CompareTo(number2) < 0)
                return false;
            else
                return true;
        }

        public static bool operator <=(RationalNumber number1, RationalNumber number2)
        {
            if (number1.CompareTo(number2) > 0)
                return false;
            else
                return true;
        }

        public static bool operator ==(RationalNumber number1, RationalNumber number2)
        {
            if (number1 is null && number2 is null)
                return true;
            else if ((number1 is null && !(number2 is null)) || (!(number1 is null) && number2 is null))
                return false;
            else
            {
                if (number1.CompareTo(number2) == 0)
                    return true;
                else
                    return false;
            }
        }

        public static bool operator !=(RationalNumber number1, RationalNumber number2)
        {
            if (number1 == number2)
                return false;
            else
                return true;
        }

        public static RationalNumber operator -(RationalNumber number)
        {
            int newNumerator = -number.numerator;
            RationalNumber newNumber = new RationalNumber(newNumerator, number.denominator);
            return newNumber;
        }

        public static RationalNumber operator -(RationalNumber number1, RationalNumber number2)
        {
            RationalNumber result = new RationalNumber(0);
            result.numerator = number1.numerator * number2.denominator - number2.numerator * number1.denominator;
            result.denominator = number1.denominator * number2.denominator;
            result.Simplify();
            return result;
        }

        public static RationalNumber operator +(RationalNumber number1, RationalNumber number2)
        {
            RationalNumber result = new RationalNumber(0);
            result.numerator = number1.numerator * number2.denominator + number2.numerator * number1.denominator;
            result.denominator = number1.denominator * number2.denominator;
            result.Simplify();
            return result;
        }

        public static RationalNumber operator *(RationalNumber number1, RationalNumber number2)
        {
            RationalNumber result = new RationalNumber(0);
            result.numerator = number1.numerator * number2.numerator;
            result.denominator = number1.denominator * number2.denominator;
            result.Simplify();
            return result;
        }

        public static RationalNumber operator /(RationalNumber number1, RationalNumber number2)
        {
            RationalNumber result = new RationalNumber(0);
            result.numerator = number1.numerator * number2.denominator;
            result.denominator = number1.denominator * number2.numerator;
            if (result.denominator < 0)
            {
                result.denominator = -result.denominator;
                result.numerator = -result.numerator;
            }
            result.Simplify();
            return result;
        }

        public static explicit operator int(RationalNumber number)
        {
            return number.CountIntPart();
        }

        public static implicit operator float(RationalNumber number)
        {
            return (float)number.numerator / number.denominator;
        }

        public static implicit operator double(RationalNumber number)
        {
            return (double)number.numerator / number.denominator;
        }

        public static implicit operator RationalNumber(int a)
        {
            return new RationalNumber(a);
        }

        public override string ToString()
        {
            int intPart = CountIntPart();
            int num = numerator - intPart * denominator;
            int denom = denominator;
            if (intPart == 0 && num == 0)
                return 0.ToString();
            else if (intPart == 0)
                return String.Format("{0}/{1}", num, denom);
            else if (intPart != 0 && num == 0)
                return intPart.ToString();
            else
                return String.Format("{0} {1}/{2}", intPart, num, denom);
        }

        public string ToStringfloat()
        {
            return ((float)numerator / denominator).ToString();
        }

        public string ToStringDouble()
        {
            return ((double)numerator / denominator).ToString();
        }
    }
}
