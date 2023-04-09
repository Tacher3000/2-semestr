#include <iostream>
#include <vector>
#include <string>

enum class tipiki
{
	literary,
	technical
};

class book {
public:
	book(const std::string& author, const std::string& title, const tipiki tip) {
		m_author = author;
		m_title = title;
		m_tip = tip;
	}

	tipiki getting() const {
        return m_tip;
    }
	
private:
	std::string m_author;
	std::string m_title;
	tipiki m_tip;
};

void print_switch(const std::vector <book>* books) {
	int literary = 0, technical = 0;
	for (const book& i : *books) {
		switch (i.getting())
		{
		case(tipiki::literary):
			literary++;
			break;
		case(tipiki::technical):
			technical++;
			break;
		default:
			break;
		}
	}

	std::cout << "вывод через switch" << std::endl << "художественные - " << literary << " технические - " << technical << std::endl;
}

void print_if(const std::vector <book>* books) {
	int literary = 0, technical = 0;
	for (book i : *books) {
		if (i.getting() == tipiki::literary) {
			literary++;
		}
		else if (i.getting() == tipiki::technical)
		{
			technical++;
		}
	}

	std::cout << "вывод через if" << std::endl << "художественные - " << literary << " тезнические - " << technical << std::endl;
}

int main() {
	setlocale(LC_ALL, "Russian");
	std::vector <book> books;
	books.emplace_back(book("Михаил Булгаков", "Мастер и Маргарита", tipiki::literary));
	books.emplace_back(book("Аристотель", "математика 1 класс", tipiki::technical));
	books.emplace_back(book("Эдуард Успенский", "Чебурашка", tipiki::literary));
	books.emplace_back(book("ISAYAMA Hajime", "Атака Титанов", tipiki::technical));
	books.emplace_back(book("Лев Толстой", "Война и мир", tipiki::literary));

	print_switch(&books);
	print_if(&books);
	return 0;
}
