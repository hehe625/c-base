#ifndef _COMPLEX_
#define _COMPLEX_
class complex
{
private:
    double re,im;
public:
/*默认值的构造函数，使用初始化列表的形式，效率最高*/
    complex(double r = 0,double i = 0)
    : re(r),im(i)
    {}
    complex& operator+= (const complex&);
    double real () const {return re;}
    double imag () const {return im;}
    friend complex& _doapl (complex*, const complex&);
    
};

#endif
