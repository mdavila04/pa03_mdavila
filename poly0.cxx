#ifndef POLY0_H
#define POLY0_H
#include <iostream>  // Provides ostream

namespace main_savitch_3
{
    
    class polynomial
    {
    public:
  // CONSTANTS
  static const unsigned int CAPACITY = 30;
  static const unsigned int MAX_EX = CAPACITY - 1;
  
        // CONSTRUCTOR
  polynomial::polynomial(double c = 0.0, unsigned int exponent = 0)
  {
    assert(exponent <= polynomial::MAX_EX);
    coef[exponent] = c;
    current_degree = 0;
  }

  // MODIFICATION MEMBER FUNCTIONS
  void polynomial::add_to_coef(double amount, unsigned int exponent); //Adds the given amount to the coefficient of the
//     specified exponent.
  {
    assert(exponent <= polynomial::MAX_EX);
    coef[exponent] += amount;
  }
  void polynomial::assign_coef(double coefficient, unsigned int exponent);  //Sets the coefficient for the specified exponent.
  {
    assert(exponent <= polynomial::MAX_EX);
    coef[exponent] = coefficient
  }
  void polynomial::clear( );
  {
    for(int i = 0; i < MAX_EX; i++)
    {
      coef[i] = 0;
    }
  }
  
  // CONSTANT MEMBER FUNCTIONS
  double polynomial::coefficient(unsigned int exponent) const;  //Returns coefficient at specified exponent of this
//     polynomial.
  {
    if(exponent > polynomial::MAX_EX)
    {
      return 0;
    }
    else{
      return coef[exponent];
    }
  }
  unsigned int polynomial::degree( ) const { return current_degree; } //inline implementation returns current degree
  polynomial polynomial::derivative( ) const;
  {
    for(int i = 0; i < MAX_EX; i++)
    {
      p3.coef[i] = p1.coef[i] - p2.coef[i];
    }
    if(c > 1)
    {
      c *= current_degree;
      current_degree = current_degree - 1;
    }

  }
  double polynomial::eval(double x) const;
  unsigned int polynomial::next_term(unsigned int e) const;
  {
    current_degree++;
  }
  unsigned int polynomial::previous_term(unsigned int e) const;
  
  // CONSTANT OPERATORS
  double polynomial::operator( ) (double x) const { return eval(x); }
  
    private:
  double coef[CAPACITY];
  unsigned int current_degree;
    };
    
    // NON-MEMBER BINARY OPERATORS
    polynomial polynomial::operator +(const polynomial& p1, const polynomial& p2);
    {
      polynomial p3;
      for(int i = 0; i < MAX_EX; i++)
    {
      p3.coef[i] = p1.coef[i] + p2.coef[i];
    }
    return p3;
    }
    polynomial polynomial::operator -(const polynomial& p1, const polynomial& p2);
    {
      polynomial p3;
      for(int i = 0; i < MAX_EX; i++)
    {
      p3.coef[i] = p1.coef[i] - p2.coef[i];
    }
    return p3;

    }
    polynomial polynomial::operator *(const polynomial& p1, const polynomial& p2);
    {
      polynomial p3;
      for(int i = 0; i < MAX_EX; i++)
    {
      p3.coef[i] = p1.coef[i] * p2.coef[i];
    }
    return p3;

    }
    
    // NON-MEMBER OUTPUT FUNCTION
    std::ostream& polynomial::operator << (std::ostream& out, const polynomial& p);
    {

    }
    
}
#endif