/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <aperez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 12:27:37 by aperez-b          #+#    #+#             */
/*   Updated: 2022/09/19 12:54:55 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <ios>

static	float ft_pow(float base, int exp)
{
	float	result;

	if (!exp)
		return (1);
	if (exp < 0)
	{
		base = 1 / base;
		exp *= -1;
	}
	result = base;
	while (--exp)
		result *= base;
	return (result);
}

const int	Fixed::_frac = 8;

Fixed::Fixed(void): _value(0)
{
	std::cout << "Fixed object created with default constructor" << std::endl; 
}

Fixed::Fixed(const int value): _value(value * ft_pow(2, this->_frac))
{  
	std::cout << "Fixed object created with int constructor" << std::endl; 
} 

Fixed::Fixed(const float value): _value(value * ft_pow(2, this->_frac))
{  
	std::cout << "Fixed object created with float constructor" << std::endl; 
} 

Fixed::~Fixed(void)
{
	std::cout << "Fixed object destroyed" << std::endl;
}

Fixed::Fixed(Fixed const & copy)
{
	std::cout << "Fixed object copied" << std::endl;
	*this = copy;
}

float	Fixed::toFloat(void) const
{
	return (this->_value * ft_pow(2, -this->_frac));
}

int	Fixed::toInt(void) const
{
	return (this->_value * ft_pow(2, -this->_frac));
}

Fixed&	Fixed::operator=(Fixed const &copy)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_value = copy.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(const int raw)
{
	this->_value = raw;
}

std::ostream	&operator<<(std::ostream &str, Fixed const &fixed_nbr)
{
	return (str << fixed_nbr.toFloat());
}


