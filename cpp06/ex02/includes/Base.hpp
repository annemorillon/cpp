#ifndef BASE_HPP
# define BASE_HPP

class Base
{
	public:

		// Base();
		virtual ~Base();
		// Base(Base const& other);
		// Base operator=(Base const& other);

		Base * generate(void);
		void identify(Base* p);
		void identify(Base& p);

	private:

};

#endif