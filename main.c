#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    double h, l, t, p, a1, a2, v3, m2, m4, v4, t4, a4;
    printf("Enter higher pressure of shock tube \n");
    scanf("%lf", &h);
    printf("Enter lower pressure of shock tube \n");
    scanf("%lf", &l);
    printf("Enter temperature of ambient \n");
    scanf("%lf", &t);
    
    p=(h+l)/2;
    a1=pow((1.4*287*t), 0.5);
    a2=a1;
    

    v3= 2*a1*(1-pow(p/h, 0.4/2.8))/0.4;
    printf("Induced velocity from expansion waves by test value = %lf\n", v3);
    m2 = (pow(((p/l)*2.4+0.4)/(2*1.4), 0.5));
    printf("Supersonic mach no from shock waves by test value = %lf\n", m2);
    m4 = pow((2/0.4+pow(m2, 2))/(2.8*pow(m2, 2)/0.4-1), 0.5);
    printf("Subsonic mach no from shock waves by test value = %lf\n", m4);
    t4 = t*((2*1.4*pow(m2, 2)-0.4)*(2+0.4*pow(m2, 2))/(2.4*2.4*pow(m2, 2)));
    a4=pow((1.4*287*t4), 0.5);
    v4 = m2*a2-m4*a4;
    printf("Induced velocity from shock waves by test value = %lf\n", v4);
    
    if (fabs(v3)>fabs(v4))
    {
        while (fabs(v3-v4)>0.01)
        {
            
            v3= 2*a1*(1-pow(p/h, 0.4/2.8))/0.4;
            
            m2 = (pow(((p/l)*2.4+0.4)/(2*1.4), 0.5));
            
            m4 = pow((2/0.4+pow(m2, 2))/(2.8*pow(m2, 2)/0.4-1), 0.5);
            
            t4 = t*((2*1.4*pow(m2, 2)-0.4)*(2+0.4*pow(m2, 2))/(2.4*2.4*pow(m2, 2)));
            a4=pow((1.4*287*t4), 0.5);
            v4 = m2*a2-m4*a4;
            p=p+0.005;
        }
    
    }
        
    
    else if (fabs(v3)<fabs(v4))
    {
        while (fabs(v3-v4)>0.01)
        {
            
            v3= 2*a1*(1-pow(p/h, 0.4/2.8))/0.4;
            
            m2 = (pow(((p/l)*2.4+0.4)/(2*1.4), 0.5));
            
            m4 = pow((2/0.4+pow(m2, 2))/(2.8*pow(m2, 2)/0.4-1), 0.5);
            
            t4 = t*((2*1.4*pow(m2, 2)-0.4)*(2+0.4*pow(m2, 2))/(2.4*2.4*pow(m2, 2)));
            a4=pow((1.4*287*t4), 0.5);
            v4 = m2*a2-m4*a4;
            p=p-0.005;
        }
    }
    
    printf("\n Induced velocity from expansion waves  = %lf", v3);
    printf("\n Induced velocity from shock waves  = %lf", v4);
    printf("\npressure value is %lf", p);
    
    
    
    

    return 0;
}






