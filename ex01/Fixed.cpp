/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <aperez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 12:27:37 by aperez-b          #+#    #+#             */
/*   Updated: 2022/09/15 19:27:24 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

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

static int	float_to_fixed(float nb)
{
	int	fixed_nb;
	int	int_part;
	int	float_part;
	int	i;

	i = 0;
	int_part = (int)nb;
	fixed_nb = 0;
	float_part = (float)(nb - (int)nb) * ft_pow(2, 8);
	while (float_part || int_part)
	{
		if (i < 8)
		{
			fixed_nb = fixed_nb + ((float_part & 1) * ft_pow(2, i));
			float_part = float_part >> 1;
		}
		else
		{
			fixed_nb = fixed_nb + ((int_part & 1) * ft_pow(2, i));
			int_part = int_part >> 1;
		}
		i++;
	}
	return (fixed_nb);
}

const int	Fixed::_frac = 8;

Fixed::Fixed(void): _value(0)
{
	std::cout << "Fixed object created with default constructor" << std::endl; 
}

Fixed::Fixed(const int value): _value(float_to_fixed(value))
{
	std::cout << "Fixed object created with int constructor" << std::endl; 
	std::cout << "[DEBUG] value: " << value << ", this->_value: " << this->_value << std::endl; 
}

Fixed::Fixed(const float value): _value(float_to_fixed(value))
{
	std::cout << "Fixed object created with float constructor" << std::endl; 
	std::cout << "[DEBUG] value: " << value << ", this->_value: " << this->_value << std::endl; 
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

Fixed&	Fixed::operator=(const Fixed & copy)
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
