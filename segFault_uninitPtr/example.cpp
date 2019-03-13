#include <iostream>
/*
	Example:
		Segmentation Fault caused by using uninitialized pointer.
*/

class T
{
	public:
		T(){ std::cout << "(T) construction" << std::endl; }
		~T() { std::cout << "(T) destruction" << std::endl; }

	public:
		int i;
		void func()
		{
			std::cout << "func() start" << std::endl;
			i = 0;
			std::cout << "func() end" << std::endl;
		}
};

class CEBase
{
	public:
		CEBase(): ptr_(NULL)
		{
			std::cout << "(CEBase) construction" << std::endl;
		}
		~CEBase()
		{	
			delete ptr_;
			std::cout << "(CEBase) destruction" << std::endl;
		}

		void init_T()
		{
			ptr_ = new T;
		}
	protected:
		T * ptr_;
};

class CE: public CEBase
{
public:
	using CEBase::ptr_;
	CE()
	{
		std::cout << "(CE) construction" << std::endl;
	}
	~CE()
	{
		std::cout << "(CE) destruction" << std::endl;
	}

	void use_T()
	{
		std::cout << "ptr_ value: " << reinterpret_cast<long> (ptr_) << std::endl;	
		ptr_->func();
	}

};

void test2(bool init_=false)
{
	CE * ce_ptr = new CE;
	if (init_)
		ce_ptr->init_T();
	ce_ptr->use_T();
	delete ce_ptr;
}

int main()
{
	std::cout << "ptr initialized" << std::endl;
	test2(true);
	std::cout << std::endl;
	std::cout << "ptr uninitialized" << std::endl;
	test2(false);

	return 0;
}