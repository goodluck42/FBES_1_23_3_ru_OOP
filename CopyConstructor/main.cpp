#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class User
{
public:
	~User()
	{
		std::cout << "User::~User()" << '\n';

		delete[] m_login;
		delete[] m_password;
	}

	User(const char* aLogin, const char* aPassword)
	{
		std::cout << "User::User(const char* aLogin, const char* aPassword)" << '\n';

		SetLogin(aLogin);
		SetPassword(aPassword);
	}

	User(const User& aOther)
	{
		std::cout << "User::User(const User& aOther)" << '\n';

		auto loginLen = strlen(aOther.m_login);
		auto passwordLen = strlen(aOther.m_password);

		m_login = new char[loginLen + 1] {};
		m_password = new char[passwordLen + 1] {};

		// variant 1

		for (int i = 0; i < loginLen; ++i)
		{
			m_login[i] = aOther.m_login[i];
		}

		// varinat 2

		std::memcpy(this->m_password, aOther.m_password, passwordLen * sizeof(char));
	}

	User()
	{
		std::cout << "User::User()" << '\n';

		m_login = nullptr;
		m_password = nullptr;
	}

	const char* GetLogin() const
	{
		return m_login;
	}

	void SetLogin(const char* a_login)
	{
		delete[] m_login;

		auto len = strlen(a_login);

		m_login = new char[len + 1] {};

		strcpy(m_login, a_login);
	}

	void SetPassword(const char* a_password)
	{
		auto self = this;

		delete[] m_password;

		auto len = strlen(a_password);

		m_password = new char[len + 1] {};

		strcpy(m_password, a_password);
	}

	const char* GetPassword() const
	{
		return m_password;
	}
private:
	char* m_login;
	char* m_password;
};

class UserDbContext
{
public:
	void AddUser(User* user)
	{
		// ...
	}
};


class A
{
public:
	~A()
	{
		std::cout << "A::~A()" << '\n';
	}
	
	A()
	{
		std::cout << "A::A()" << '\n';
	}
	
	A(int value)
	{
		std::cout << "A::A(int value)" << '\n';
	}
};

class B
{
public:
	~B()
	{
		std::cout << "B::~B()" << '\n';

	}
	
	B() : obj(42)
	{
		std::cout << "B::B()" << '\n';
	}

	A obj;
};


int main()
{
	/* {
		UserDbContext context;
		User user;

		user.SetLogin("vadimka_1337");
		user.SetPassword("vadik_42");

		context.AddUser(&user);
	}*/

	/*{
		const User user{ "vadik228", "vadimkasuper" };

		std::cout << user.GetLogin() << '\n';
	}*/

	{
		B obj;
	}

}