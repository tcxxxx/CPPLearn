#include <iostream>
/*
	Example (a simpler one):
		Using a NULL pointer to access member functions of a class.
*/

class T
{
	public:
		T(): i(2) { std::cout << "(T) construction" << std::endl; }
		~T() { std::cout << "(T) destruction" << std::endl; }

	public:
		int i;
		void func1()
		{
			std::cout << "func() start" << std::endl;
			std::cout << "func() end" << std::endl;
		}

		void func2()
		{
			std::cout << "func() start" << std::endl;
			i = 1;
			std::cout << "func() end" << std::endl;
		}

		virtual void func3()
		{
			std::cout << "func() start" << std::endl;
			std::cout << "func() end" << std::endl;
		}
};

/*
	TEST: accessing two non-virtual functions:
		func1 does nothing but std::cout;
		func2 tries to operate on the member variable i;
*/
void test(bool init_=false)
{
	T * ptr_ = NULL;
	if (init_)
		ptr_ = new T;

	std::cout << "ptr_ value: " << reinterpret_cast<long> (ptr_) << std::endl;	
	std::cout << "accessing func1:" << std::endl;
	ptr_->func1();
	std::cout << "accessing func2:" << std::endl;
	ptr_->func2();
	delete ptr_;
}

/*
	TEST2: accessing a virtual function member.
*/
void test2(bool init_=false)
{
	T * ptr_ = NULL;
	if (init_)
		ptr_ = new T;
	
	std::cout << "ptr_ value: " << reinterpret_cast<long> (ptr_) << std::endl;	
	std::cout << "accessing func3:" << std::endl;
	ptr_->func3();
	delete ptr_;
}

int main()
{
	// std::cout << "ptr initialized" << std::endl;
	// test(true);
	// std::cout << std::endl;

	std::cout << "ptr uninitialized" << std::endl;
	// accessing a non-virtual member function
	test(false); 
	test2(false);
	return 0;
}