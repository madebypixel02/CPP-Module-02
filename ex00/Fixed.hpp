/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <aperez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 12:27:05 by aperez-b          #+#    #+#             */
/*   Updated: 2022/09/10 12:49:37 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP

# define FIXED_HPP

# include <iostream>

class	Fixed
{
	private:
		int					_value;
		static const int	_frac;
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(Fixed const &copy);
		Fixed&	operator=(Fixed const &copy);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
