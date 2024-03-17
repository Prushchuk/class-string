#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <string>




class Str {
private:
	char* text;
	int size;


public:
	Str() : text{ nullptr }, size{ 0 } {}
	Str(const char* text) {

		this->size = strlen(text);
		this->text = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			this->text[i] = text[i];
		}
		this->text[size] = '\0';
	}
	Str(const Str& str)
	{
		this->size = str.size;
		this->text = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			text[i] = str.text[i];
		}
	}





	friend std::ostream& operator<<(std::ostream& out, const Str& text) {
		out << text.text;
		return out;
	}
	friend std::istream& operator>>(std::istream& in, Str& str)
	{
		str.clear();
		char* tmp = new char[10000];
		in.getline(tmp, 10000);
		str.push_back(tmp);
		return in;
	}



	void push_back(char c) {
		char* tmp = new char[size + 1];
		strncpy(tmp, text, size);
		tmp[size] = c;
		size++;
		delete[] text;
		text = tmp;
		tmp = nullptr;
	}
	void append(int space, char value)
	{
		char* tmp = new char[size + 2];
		strncpy(tmp, text, size);
		char last = tmp[size - 1];


		for (int i = space; i < size; i++)
		{
			tmp[i + 1] = tmp[i];
		}



		tmp[space] = value;
		tmp[size] = last;
		tmp[size + 1] = '\0';
		size++;
		delete[] text;
		text = tmp;
		tmp = nullptr;
	}
	void push_back(const char* c) {
		int NEWsize = size + strlen(c);
		char* tmp = new char[NEWsize + 1];

		strncpy(tmp, text, size);
		strncpy(tmp + size, c, NEWsize - size);


		tmp[NEWsize] = '\0';
		size = NEWsize;
		delete[] text;


		text = tmp;
		tmp = nullptr;
	}
	void replace(int start, int end, const char* value)
	{
		for (int i = start; i <= end; i++)
		{
			text[i] = *value;
		}
	}

	bool operator==(const Str& str)const
	{
		if (size != str.size)
		{
			return false;
		}


		for (int i = 0; i < size; i++)
		{
			if (text[i] != str.text[i])
			{
				return false;
			}
		}

		return true;
	}
	friend bool operator>(const Str& LeftStr, const Str& rightStr)
	{
		if (rightStr == LeftStr)
		{
			return false;
		}

		int size = LeftStr.size > rightStr.size ? rightStr.size : LeftStr.size;

		int numberLeft = 0;
		int numberRight = 0;


		for (int i = 0; i < size; i++)
		{
			if (LeftStr.text[i] > rightStr.text[i])
			{
				numberLeft++;
			}
			if (LeftStr.text[i] < rightStr.text[i])
			{
				numberRight++;
			}
		}

		return numberLeft > numberRight;

	}
	friend bool operator<(const Str& LeftStr, const Str& rightStr)
	{
		if (rightStr == LeftStr)
		{
			return false;
		}

		int size = LeftStr.size > rightStr.size ? rightStr.size : LeftStr.size;

		int numberLeft = 0;
		int numberRight = 0;


		for (int i = 0; i < size; i++)
		{
			if (LeftStr.text[i] < rightStr.text[i])
			{
				numberLeft++;
			}
			if (LeftStr.text[i] > rightStr.text[i])
			{
				numberRight++;
			}
		}

		return numberLeft > numberRight;

	}

	Str operator+(const Str& str) const {
		Str result(*this);
		result.push_back(str.text);
		return result;
	}

	bool operator>=(const Str& str) const {
		return !(*this < str);
	}

	bool operator<=(const Str& str) const {
		return !(*this > str);
	}


	Str operator+(const Str& strLeft)
	{
		Str result(text);

		result.push_back(strLeft.text);


		return result;
	}


	void resize(int newSize) {
		if (newSize < size) {
			text[newSize] = '\0';
		}
		else if (newSize > size) {
			char* tmp = new char[newSize + 1];
			strcpy(tmp, text);
			for (int i = size; i < newSize; ++i) {
				tmp[i] = ' ';
			}
			tmp[newSize] = '\0';
			delete[] text;
			text = tmp;
		}
		size = newSize;
	}

	void push_front(char c) {
		char* tmp = new char[size + 2];
		tmp[0] = c;
		strcpy(tmp + 1, text);
		tmp[size + 1] = '\0';
		++size;
		delete[] text;
		text = tmp;
	}

	void clear() {
		delete[] text;
		text = nullptr;
		size = 0;
	}
	~Str() { clear(); }
};





int main() {


	Str s1 = "ZZZ";
	Str s2 = "AAAA";


	std::string s12 = "ZZZ";
	std::string s22 = "AAAA";


	std::cout << (s1 > s2);
	std::cout << '\n';
	std::cout << s1 + " Hello";

}