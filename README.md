# OS-Lab6
## The task
We are meant to do a little bit of profiling here. We should check the program's performance, spot any weak places, try to fix them and then check the performance once more.
The variant is: The code was given on variants. Mine is: 21 (number of my student's record-book) mod 15 (amount of variants) + 1 (to eliminate the possibility of the variant being equal to 0) = __7__.
## The given program's code
~~~
#include<stdio.h>

void new_func1(void);

void DrawCat(void)
{
    for(int i = 0; i < 100000000000; i++)
	{
		//process of drawing
		sleep(100000);
	}

    return;
}

static void DrawDog(void)
{
    for(int i = 0; i < 100000000000; i++)
	{
		//process of drawing
		sleep(100000);
	}
    return;
}

int main(void)
{
    printf("\n Inside main()\n");
	string typeOfShape;
	scanf("%s", typeOfShape);
	
    int i = 0;

    for(;i<0xffffff;i++);
	switch(typeOfShape){
	case "dog":
	    DrawDog();
		break;
	case "cat":
		DrawCat();
		break;
	}

    return 0;
}
~~~
Found and corrected some C mistakes here, so the code is now compatible. However, it's still C and I wanted C++, so I changed it properly:
~~~
#include <thread>
#include <chrono>
#include <iostream>
using namespace std;

void new_func1(void);

void DrawCat(void)
{
	for (int i = 0; i < 2140000000; i++)
	{
		//process of drawing
		this_thread::sleep_for(chrono::milliseconds(100000));
	}

	return;
}

static void DrawDog(void)
{
	for (int i = 0; i < 2140000000; i++)
	{
		//process of drawing
		this_thread::sleep_for(chrono::milliseconds(100000));
	}
	return;
}

int main()
{
	cout << "\n Inside main()\nWaiting on your input...\n";
	string typeOfShape;
	cin >> typeOfShape;

	int i = 0;

	for (; i < 0xffffff; i++);
	if (typeOfShape == "dog") {
		DrawDog();
	}
	else if (typeOfShape == "cat") {
		DrawCat();
	}

	return 0;
}
~~~
Then I added needed changes to the code see the performance of the app. Decided to go with the manual method.
## The changes to see the performance
I added some lines with ```high_resolution_clock``` to measure the performance.
The resulting files with code are in the repository.
## The results of the unoptimized code
![The unoptimized program's time data](/images/unoptimized.jpg "The unoptimized program's time data")
## The changes to the code to optimize it
+ First of all, I changed the loops from 0 -> i to i -> 0 as it would be faster, comparing the values with 0 always.
+ Next, I changed the ```int i = ...``` in the ```for``` loops to a ```register int i = ...``` as it should suggest the compiler to store this value in the registers.
## The time results of the optimized code
![The optimized program's time data](/images/optimized.jpg "The optimized program's time data")
## The results
So, the results are here: due to the fact there's no memory optimization to be done, I did the little I could. That didn't help on the little data examples and is not likely to influence the data results a lot. Due to the structure of the original code, there's nothing more to be done, if not to change the logic entirely.
