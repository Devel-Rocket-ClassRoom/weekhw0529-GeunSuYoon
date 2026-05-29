#include <iostream>
#include "./HW1/Homework1.h"
#include "./HW2/Homework2.h"

int main()
{
	bool	HW1Continue = true;

	srand(time(NULL));
	while (HW1Continue)
	{
		Homework01_Run();
		printf("계속하시려면 그냥 엔터를 눌러주세요.\n");
		printf("그만하시려면 아무 키나 입력한 뒤 엔터를 눌러주세요.\n");
		std::string	InputLine;
		std::getline(std::cin, InputLine);
		if (InputLine.size())
			HW1Continue = false;
		system("cls");
	}
    Homework02_Run();
}
