#include <stdio.h>
#include <TXLib.h>
#include <math.h>                                 //uses for pow()

int main(void)
{
    double a, b, c;                               //equality odds a*x^2 + b*x + c = 0
    double dis;                                   //discriminant

    printf("������, ��� ��������� �������� ������ ���������� ���������!\n");
    printf("����� ����� �������� ����� ������\n");
    printf("������� ����������� a, b � c ����� ������\n");

    while (scanf("%lf %lf %lf", &a, &b, &c)) {

        //case, when it's linear equation
        if (a == 0) {                             //case, when a = 0: b*x + c = 0(infinity or 1 or 0 solves)
            if (b == 0) {                         //case, when a = b = 0: c = 0
                if (c == 0)                       //case, when a = b = c = 0: 0 = 0
                    printf("����������� ���������� ������\n");
                else
                    printf("������ ���\n");
            } else
                printf("���� ������ x=%lf\n", -c/b);

        //case, when it's quadratic equation(2 or 1 or 0 solves)
        } else {
            dis = b*b - 4*a*c;
            if (dis > 0)
                printf("��� ������� x1 = %lf, x2 = %lf\n",
(-b - pow(dis, 0.5))/(2*a), (-b + pow(dis, 0.5))/(2*a));
            else if (dis == 0)
                printf("���� ������ x = %lf\n", -b/(2*a));
            else
                printf("������ ���\n");
        }
        printf("������� ����������� a, b � c ����� ������\n");

    }

    printf("��������� ���������! �������� ���!\n");

}
