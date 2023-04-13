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
	book(const std::string& author, const std::string& title, tipiki tip) {
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

class biblioteсa {
public:
void add(const std::string& author, const std::string title, const tipiki tip){
	if (author.empty()  || title.empty() )
	{
		return;
	}
	else
	{
		books.push_back(book(author, title, tip));
	}
	

}

void print_switch() {
	int literary = 0, technical = 0;
	for (const book& i : books) {
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

void print_if() {
	int literary = 0, technical = 0;
	for (const book& i : books) {
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
private:
std::vector <book> books;
};


int main() {
	setlocale(LC_ALL, "Russian");

	biblioteсa all;

	all.add("Михаил Булгаков", "Мастер и Маргарита", tipiki::literary);
	all.add("Есенин", "", tipiki::literary);
	all.add("", "Колобок", tipiki::literary);
	all.add("Аристотель", "математика 1 класс", tipiki::technical);
	all.add("Эдуард Успенский", "Чебурашка", tipiki::literary);
	all.add("ISAYAMA Hajime", "Атака Титанов", tipiki::technical);
	all.add("Лев Толстой", "Война и мир", tipiki::literary);

	all.print_switch();
	all.print_if();
	return 0;
}
