int a = 10;
int b = 11;
int c = 11;

void main()
{
    bool e;
    print(" a  b  c\n",a," ",b," ",c,"\n");
    e = a < b;
    print("a < b = ",e,"\n");
    e = a > b;
    print("a > b = ",e,"\n");
    e = a <= b;
    print("a <= b = ",e,"\n");
    e = a >= b;
    print("a >= b = ",e,"\n");
    e = a == b;
    print("a == b = ",e,"\n");
    e = a != b;
    print("a != b = ",e,"\n");

    e = b < c;
    print("b < c = ",e,"\n");
    e = b > c;
    print("b > c = ",e,"\n");
    e = b <= c;
    print("b <= c = ",e,"\n");
    e = b >= c;
    print("b >= c = ",e,"\n");
    e = b == c;
    print("b == c = ",e,"\n");
    e = b != c;
    print("b != c = ",e,"\n");
}
