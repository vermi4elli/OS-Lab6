#include <thread>
#include <chrono>
#include <iostream>
using namespace std;

int DrawCatCalled = 0;
int DrawDogCalled = 0;

void DrawCat(const int& size)
{
	cout << "====> Inside DrawCat()\n";
	DrawCatCalled++;
	for (register int i = size; i > 0; i--)
	{
		//process of drawing
		this_thread::sleep_for(chrono::milliseconds(1));
	}

	return;
}

static void DrawDog(const int& size)
{
	cout << "====> Inside DrawDog()\n";
	DrawDogCalled++;
	for (register int i = size; i > 0; i--)
	{
		//process of drawing
		this_thread::sleep_for(chrono::milliseconds(1));
	}
	return;
}

int main()
{
	auto beginning = std::chrono::high_resolution_clock::now();
	cout << "====> Inside main()\n";
	cout << "Waiting on your input...\n";

	string typeOfShape;
	cin >> typeOfShape;

	auto inputTime = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diffInput = inputTime - beginning;
	cout << "The input's total is: " << diffInput.count() << endl;

	int i = 0, tries = 1;

	for (int i = tries; i > 0; i--) {
		if (typeOfShape == "dog") {
			DrawDog(100);
		}
		else if (typeOfShape == "cat") {
			DrawCat(1000);
		}
	}


	auto ending = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diffMainPart = ending - inputTime;
	cout << "The main part's total is: " << diffMainPart.count() <<
		"\n - DrawCat() has been called " << DrawCatCalled << " times;" <<
		"\n - DrawDog() has been called " << DrawDogCalled << " times;" << endl;

	std::chrono::duration<double> diffTotal = ending - beginning;
	cout << "The program's total is: " << diffTotal.count() << endl;
	return 0;
}
