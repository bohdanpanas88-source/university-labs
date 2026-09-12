#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

struct friends
{
	std::string lastname;
	std::string birthday;
};

void formingFile(friends* Array, int size)
{

	std::ofstream file("friends.txt");
	if (!file.is_open())
	{
		std::cout << "Error! File didnt open." << "\n";
		return;
	}

	std::cin.ignore(1000, '\n');

	for (size_t i = 0; i < size; ++i)
	{
		std::cout << "Friend " << i + 1 << " lastname: ";

		std::getline(std::cin, Array[i].lastname);
		std::cout << "Birthday(--,--,----): ";
		std::getline(std::cin, Array[i].birthday);

		file << Array[i].lastname << " " << Array[i].birthday << "\n";
	}
	file.close();
}

void searchBirthdaySummer()
{
	std::ifstream infile("friends.txt");
	std::ofstream outfile("summerBirthday.txt");

	if (!infile.is_open())
	{
		std::cout << "Error! File didnt open." << "\n";
		return;
	}

	std::string lname, bday;
	std::cout << "\nBorn in summer:\n";

	while (infile >> lname >> bday)
	{
		if (bday.length() >= 5)
		{
			std::string monStr = bday.substr(3, 2);
			int month = std::stoi(monStr);

			if (month >= 6 && month <= 8)
			{
				std::cout << lname << " " << bday << "\n";
				outfile << lname << " " << bday << "\n";
			}
		}
	}
	infile.close();
	outfile.close();
}

int main()
{
	int friendsNumber;
	std::cout << "Enter number of friends: ";
	std::cin >> friendsNumber;

	friends* friendsArray = new friends[friendsNumber];

	formingFile(friendsArray,friendsNumber);
	searchBirthdaySummer();

	delete[] friendsArray;
	return 0;
}
