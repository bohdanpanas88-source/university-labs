#include <cstdio>
#include <thread>
#include <cmath>
#include <string>

void FunkCounting(int id)
{
	double result = 1;
	float step = 0;
	for (size_t i = 0; i < 10; ++i)
	{
		result *= ((2 + step) / (1 + step)) * ((2 + step) / (3 + step));
		step += 2;

		std::string output = std::string(8, ' ') + std::to_string(id) + "| ";
		output += std::string(9, ' ') + std::to_string(i) + "| ";
		output += std::to_string(result) + "\n";
		printf("%s", output.c_str());
	}	
}
int main()
{
	int const thCount = 3;
	std::thread* threads = new std::thread[thCount];

	printf("thread id|iteration #|iteration result\n");
	for (size_t i = 0; i < thCount; ++i)
	{
		threads[i] = std::thread(FunkCounting, i + 1);
	}

	for (size_t i = 0; i < thCount; ++i)
	{
		threads[i].join();
	}

	delete[] threads;

	return 0;
}
