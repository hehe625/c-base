#include <iostream>
#include "complex.h"
/*传递折无需知道接收者是以reference形式接收，当传递者不论是引用还是对象，reference都可以接收
 *当一个好的设计者，设计引用接收传递
 */
inline complex& _doapl(complex* thu , const complex & r)
{
    thu->re += r.re;
    thu->im += r.im;
    return *thu;/*object*/
}
/**
 * @brief 
 * 考虑连加，c3 += c2 += c1,如果函数设计成void，c1 + c2执行后的结果没有返回值，执行完就完了。
 * tip：如果设计函数操作符，有连续操作，就一定要有返回值。
 * @param r 
 * @return complex& 
 */
complex &complex::operator+=(const complex& r)
{
    return _doapl(this,r);
}
/*全域函数*/
inline double imag (const complex& x)
{
    return x.imag();
}
inline double real (const complex& x)
{
    return x.real();
}
/**
 * @brief 全局操作符重载，无this point
 * 绝不可使用by reference return之后如果用引用接收，出了函数，local object就消失了，reference也就没有意义
 * 返回一个local object 绝对不可以by reference
 * @param x 
 * @param y 
 * @return complex 
 */
inline complex operator + (const complex& x, const complex& y)
{
    /*注意这种语法typename() complex()*/
    return complex (real(x) + real(y), imag(x) + imag(y));
}
inline complex operator + (const complex& x, double y)
{
    return complex (real(x) + y, imag(x));
}
inline complex operator + (double x, const complex& y)
{
    return complex (x + real(y), imag(x) + imag(y));
}
/*这里的返回值可以是by reference 但是标准库并没有这样写*/
inline complex operator + (const complex& x)
{
    return x;
}
inline complex operator - (const complex& x)
{
    return complex(-real(x), -imag(x));
}
inline bool operator == (const complex& x, const complex& y)
{
    return real(x) == real(y) && imag(x) == imag(y);
}
inline bool operator == (const complex& x, double y)
{
    return real(x) == y && imag(x) == 0;
}
inline bool operator == (double x, const complex& y)
{
    return x == real(y) && imag(x) == 0;
}
