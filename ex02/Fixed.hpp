/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <aperez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 12:27:05 by aperez-b          #+#    #+#             */
/*   Updated: 2022/09/22 13:51:00 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP

# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
	private:
		int					_value;
		static const int	_frac;
	public:
		/* Contstructors & Destructors */
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed(void);
		Fixed(Fixed const &copy);
		
		/* Basic Operators */
		Fixed	&operator=(Fixed const &copy);
		Fixed	operator+(Fixed const &copy) const;
		Fixed	operator-(Fixed const &copy) const;
		Fixed	operator*(Fixed const &copy) const;
		Fixed	operator/(Fixed const &copy) const;
		bool	operator==(Fixed const &copy) const;
		bool	operator!=(Fixed const &copy) const;
		bool	operator<=(Fixed const &copy) const;
		bool	operator>=(Fixed const &copy) const;
		bool	operator<(Fixed const &copy) const;
		bool	operator>(Fixed const &copy) const;
		
		/* Other Operators */
		Fixed	&operator++(void);
		Fixed	&operator--(void);
		Fixed	operator++(int value);
		Fixed	operator--(int value);
		
		/* Min and max functions */
		static const Fixed	&min(Fixed const &copy1, Fixed const &copy2);
		static const Fixed	&max(Fixed const &copy1, Fixed const &copy2);

		/* Getters and setters */
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		
		/* Conversion to int and float */
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream	&operator<<(std::ostream &str, Fixed const &fixed_nbr);

#endif
