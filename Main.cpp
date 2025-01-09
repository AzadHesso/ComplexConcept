#include <iostream>
#include <string>
#include <bits/stdc++.h>

// После ключевого слова requires мы можем пречислить список требований, 
// которые мы накладыаем на типы, которые мы передали
template <typename T> concept ComplexConcept = requires(T v) {

	// метод hash(), который возвращает тип, конвертируемый в long
	{ v.hash() } -> std::convertible_to<long>;

	// метод toString(), который возвращает std::string
	// (т.е. тип метода toString() должен быть в точности std::string)
	{ v.toString() } -> std::same_as<std::string>;

	// отсутствие у типа T виртуального деструктора
	std::has_virtual_destructor<T>::value == false;
};


struct Number {
	int _num{ 0 };

	long hash() {
		return static_cast<long>(_num);
	}

	std::string toString() const {
		return std::to_string(_num);
	}
};


struct Number2 {
	virtual ~Number2() {}
};


void PrintType(ComplexConcept auto& t) {
	std::cout << t.toString() << '\n';
}


int main() {
	Number x{ 5 };
	PrintType(x);
	std::cout << std::boolalpha << std::has_virtual_destructor<Number>::value << std::endl;
	std::cout << std::boolalpha << std::has_virtual_destructor<Number2>::value << std::endl;
}