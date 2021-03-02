/*

* Class: CS 3305/section4

* Term: Spring 2019

* Name: Heather Willis

* Instructor: Monisha Verma

* Assignment: 2

*/

#include<cmath>

#include "complex_number.h"

	complex_number::complex_number(double r, double i){

		real_part = r;

		imag_part = i;
	}

	double complex_number::get_real_part () const{

		return real_part;
	}

	double complex_number::get_imag_part () const{

		return imag_part;
	}

	complex_number operator + (const complex_number& c1, const complex_number& c2){

		complex_number ob;

		ob.real_part=c1.real_part+c2.real_part;

		ob.imag_part=c1.imag_part+c2.imag_part;

		return(ob);
	}

	std::ostream& operator << (std::ostream& output, const complex_number& c){

		output<<"("<<c.real_part<<")+("<<c.imag_part<<"i)"<<endl;

		return(output);
	}

	complex_number operator - (const complex_number& c1, const complex_number& c2){

		complex_number ob;

		ob.real_part=c1.real_part-c2.real_part;

		ob.imag_part=c1.imag_part-c2.imag_part;

		return(ob);
	}

	complex_number operator * (const complex_number& c1, const complex_number& c2){

		complex_number ob;

		ob.real_part=(c1.real_part*c2.real_part)+(0-(c1.imag_part*c2.imag_part));

		ob.imag_part=(c1.real_part*c2.imag_part)+(c1.imag_part*c2.real_part);

		return(ob);
	}

	complex_number operator / (const complex_number& c1, const complex_number& c2){

		complex_number ob;

		double den=c2.real_part*c2.real_part+c2.imag_part+c2.imag_part;

		ob.real_part=(c1.real_part*c2.real_part+c1.imag_part*c2.imag_part)/den;

		ob.imag_part=((c1.imag_part*c2.real_part)-(c1.real_part*c2.imag_part))/den;

		return(ob);
	}

	complex_number conjugate (const complex_number& c){

		complex_number ob;

		ob.real_part=c.real_part;

		ob.imag_part=0-c.imag_part;

		return(ob);
	}

	double complex_modulus (const complex_number& c){

		return(sqrt(c.real_part*c.real_part+c.imag_part*c.imag_part));
	}

	bool operator == (const complex_number& c1, const complex_number& c2){

		if(c1.real_part==c2.real_part&&c1.imag_part==c2.imag_part)

		return(true);

		return(false);
	}

	bool operator != (const complex_number& c1, const complex_number& c2){

		if(c1.real_part==c2.real_part&&c1.imag_part==c2.imag_part)

		return(false);

		return(true);
	}
