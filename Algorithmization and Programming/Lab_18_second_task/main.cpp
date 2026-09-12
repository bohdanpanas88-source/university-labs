#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <chrono>
#include <thread>

void analyze_sample(int sample_id, int i, int Reagent_V)
{
	double Density_i = i * 5.0;
	double AnalysisTime = Density_i / Reagent_V;
	printf("\tsample %i analyzed.\n", sample_id);
}

int main()
{
	int* i = new int[20];
	int* V = new int[20];
	int* sample_id = new int[20];
	const int quantity = 3;
	double* Reagent_V = new double[quantity];
	
	for (size_t j = 0; j < quantity; ++j)
	{
		printf("\nEnter ID sample(sample_id), index task(i) and your variant: ");
		scanf("%i" "%i" "%i", &sample_id[j], &i[j], &V[j]);
	}

	auto start = std::chrono::high_resolution_clock::now();
	
	for (size_t j = 0; j < quantity; j++)
	{
		Reagent_V[j] = 10.0 - (V[j] / 3.0);
		analyze_sample(sample_id[j], i[j], Reagent_V[j]);
	}

	auto end = std::chrono::high_resolution_clock::now();
	long result = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	printf("\nwith sequential execution spent time: %ld microseconds\n", result);

	start = std::chrono::high_resolution_clock::now();
	std::thread analis1 = std::thread(analyze_sample, sample_id[0], i[0], Reagent_V[0]);
	std::thread analis2 = std::thread(analyze_sample,sample_id[1], i[1], Reagent_V[1]);
	std::thread analis3 = std::thread(analyze_sample, sample_id[2], i[2], Reagent_V[2]);

	analis1.join();
	analis2.join();
	analis3.join();

	end = std::chrono::high_resolution_clock::now();
	result = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	printf("\nwith parallel execution spent time: %ld microseconds\n", result);

	delete[] i;
	delete[] V;
	delete[] sample_id;
	delete[] Reagent_V;

	return 0;
}
