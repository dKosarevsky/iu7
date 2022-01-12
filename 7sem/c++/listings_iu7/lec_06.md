Пример 06.1. Прямая и косвенная базы.
```cpp
class A
{
public:
	A(char* s) { cout<<"Creature A"<<s<<";"<<endl; }
};

class B : public A
{
public:
	B() : A(" from B") { cout<<"Creature B;"<<endl; }
};

class C : public B, public A
{
public:
	C() : A(" from C") { cout<<"Creature C;"<<endl; }
};

void main()
{
	C obj;
}
```
Пример 06.2. Виртуальное наследование.
```cpp
class A
{
public:
	A(char* s) { cout<<"Creature A"<<s<<";"<<endl; }
};

class B : virtual public A
{
public:
	B() : A(" from B") { cout<<"Creature B;"<<endl; }
};

class C : public B, virtual public A
{
public:
	C() : A(" from C") { cout<<"Creature C;"<<endl; }
};

void main()
{
	C obj;
}
```
Пример 06.4. Доминирование.
```cpp
class A
{
public:
	void f() { cout<<"Executing f() from A;"<<endl; }
	void f(int i) { cout<<"Executing f(int) from A;"<<endl; }
};

class B : virtual public A
{
public:
	void f() { cout<<"Executing f from B;"<<endl; }
	using A::f; // плохо!!!
};

class C : virtual public A
{
};

class D : virtual public C, virtual public B
{
};

void main()
{
	D obj;

	obj.f();
	obj.f(1);
}
```
Пример 06.5. Доминирование.
```cpp
class A
{
public:
	void f() { cout<<"Executing f from A;"<<endl; }
};

class B : virtual public A
{
public:
	void f() { cout<<"Executing f from B;"<<endl; }
};

class C : public B, virtual public A
{
};

void main()
{
	C obj;

	obj.f();
}
```
Пример 06.8. Множественный вызов методов.
```cpp
class A
{
public:
	void f() { cout<<"Executing f from A;"<<endl; }
};

class B : virtual public A
{
public:
	void f()
	{ 
		A::f();
		cout<<"Executing f from B;"<<endl;
	}
};

class C : virtual public A
{
public:
	void f()
	{ 
		A::f();
		cout<<"Executing f from C;"<<endl;
	}
};

class D : virtual public C, virtual public B
{
public:
	void f()
	{ 
		C::f();
		B::f();
		cout<<"Executing f from D;"<<endl;
	}
};

void main()
{
	D obj;

	obj.f();
}
```
Пример 06.9. Решение проблемы множественного вызова методов.
```cpp
class A
{
protected:
	void _f() { cout<<"Executing f from A;"<<endl; }
public:
	void f() { this->_f(); } 
};

class B : virtual public A
{
protected:
	void _f() { cout<<"Executing f from B;"<<endl; }
public:
	void f()
	{ 
		A::_f();
		this->_f();		
	}
};

class C : virtual public A
{
protected:
	void _f() { cout<<"Executing f from C;"<<endl; }
public:
	void f()
	{ 
		A::_f();
		this->_f();
	}
};

class D : virtual public C, virtual public B
{
protected:
	void _f() { cout<<"Executing f from D;"<<endl; }
public:
	void f()
	{ 
		A::_f(); C::_f(); B::_f();
		this->_f();
	}
};

void main()
{
	D obj;

	obj.f();
}
```
Пример 06.10. Неоднозначности при множественном наследовании.
```cpp
class D
{
public:
	static void fun(C& obj)
	{
		obj.a = 1;	// Error!!!
		obj.b();	// Error!!!
		obj.f();	// Error!!!
		obj.f(1);	// Error!!!
		obj.g = 1;	// Error!!!
		obj.h(); obj.h(1); // Ok!
	}
};

void main()
{
	C obj;

	D::fun(obj);
}
```
Пример 06.7. Замена интерфейса.
```cpp
class A
{
public:
	void f1() { cout<<"Executing f1 from A;"<<endl; }
	void f2() { cout<<"Executing f2 from A;"<<endl; }
};

class B
{
public:
	void f1() { cout<<"Executing f1 from B;"<<endl; }
	void f3() { cout<<"Executing f3 from B;"<<endl; }
};

class C : private A, public B {};

class D
{
public:
	void g1(A& obj)
	{
		obj.f1(); obj.f2();
	}
	void g2(B& obj)
	{
		obj.f1(); obj.f3();
	}
};

void main()
{
	C obj;
	D d;

	// obj.f1();  Error!!! Неоднозначность
	// d.g1(obj); Error!!! Нет приведения к базовому классу при наследовании по схеме private
	d.g2(obj);
}
```
Пример 06.6. Объединение интерфейсов.
```cpp
class A
{
public:
	void f1() { cout<<"Executing f1 from A;"<<endl; }
	void f2() { cout<<"Executing f2 from A;"<<endl; }
};

class B
{
public:
	void f1() { cout<<"Executing f1 from B;"<<endl; }
	void f3() { cout<<"Executing f3 from B;"<<endl; }
};

class C : public A, public B {};

class D
{
public:
	void g1(A& obj)
	{
		obj.f1(); obj.f2();
	}
	void g2(B& obj)
	{
		obj.f1(); obj.f3();
	}
};

void main()
{
	C obj;
	D d;

	d.g1(obj);
	d.g2(obj);
}
```
Пример 06.11. Виртуальные методы.
```cpp
class A
{
public:
	virtual void f() { cout<<"Executing f from A;"<<endl; }
};

class B : public A
{
public:
	virtual void f() override { cout<<"Executing f from B;"<<endl; }
};

class C
{
public:
	static void g(A& obj) { obj.f(); }
};

void main()
{
	B obj;

	C::g(obj);
}
```
