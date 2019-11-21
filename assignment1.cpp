#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <iomanip>
using namespace std;

template <class T>
class Algos
{
private:
	int const maxSize = 100;
	int length;
	T* arr = new T[maxSize];

public:
	void Swap(T *a, T *b)
	{
		T temp = a;
		a = b;
		b = temp;
	}
	void SelectionSort(bool asc)
	{
		for (int i = 0; i < length; i++)
		{
			int indexOfArray = i;
			int j = i + 1;
			while (j < length)
			{
				if (asc)
				{
					if (arr[j] < arr[indexOfArray])
					{
						indexOfArray = j;
					}
				}
				else
				{
					if (arr[j] > arr[indexOfArray])
					{
						indexOfArray = j;
					}
				}
				j++;
			}

			Swap(arr[indexOfArray], arr[j]);
		}
	}

	void QuickSort(bool asc, int p, int q)
	{
		if (p < q)
		{
			int r = QuickPartition(asc, p, q);
			QuickSort(asc, p, r - 1);
			QuickSort(asc, r + 1, q);
		}
	}

	int QuickPartition(bool asc, int p, int q)
	{
		int i = p - 1;
		for (int j = p; j <= q; j++)
		{
			if (asc)
			{
				if (arr[j] < arr[q])
				{
					i++;
					Swap(arr[i], arr[j]);
				}

			}

			else
			{
				if (arr[j] > arr[q])
				{
					i++;
					Swap(arr[i], arr[j]);
				}
			}
		}
		Swap(arr[i + 1], arr[q]);
		return (i + 1);
	}

	void MergeSort(bool asc, int p, int q)
	{
		if (p < q)
		{
			int r = ((q - p) / 2) + p;
			MergeSort(asc, p, r);
			MergeSort(asc, r + 1, q);
			Merge(asc, p, r, q);
		}
	}

	void Merge(bool asc, int p, int r, int q)
	{
		int leftSize = r - p + 1;
		int rightSize = q - r;
		T* left = new T[leftSize + 1];
		T* right = new T[rightSize + 1];

		for (int i = 0; i < leftSize; i++)
		{
			left[i] = arr[p + i];
		}

		for (int i = 0; i < rightSize; i++)
		{
			right[i] = arr[r + 1 + i];
		}

		if (strcmp(typeid(T).name(), "long") == 0)
		{
			left[leftSize] = LONG_MAX;
			right[rightSize] = LONG_MAX;
		}
		else if (strcmp(typeid(T).name(), "float") == 0)
		{
			left[leftSize] = numeric_limits<float>::max();
				right[rightSize] = numeric_limits<float>::max();
		}

		int i = 0, j = 0;
			for (int k = p; int k <= q; k++)
			{
				if (asc)
				{
					if (left[i] <= right[j])
					{
						arr[k] = left[i++];
					}
					else
						arr[k] = right[j++];
				}
				else
				{
					if (left[i] > right[j])
					{
						arr[k] = left[i++];
					}
					else
						arr[k] = right[j++];
				}
			}
	}

	void RadixSort()
	{
		//
	}

	void AddElement()
	{
		if (length <= maxSize)
		{
			T userIn;
			cout << length << " elements " << endl;
			cout << "Enter Value: ";
			cin >> userIn;
			arr[length++];
			cout << length << " elements " << endl;
		}
	}

	void Display()
	{
		cout << endl;
		cout << "Sorted Array: ";
		for (int i = 0; i < length; ++i)
		{
			cout << arr[i];
			if (i != (length - 1))
				cout << ", ";
		}
	}

	int getLength()
	{
		return length;
	}
};

template<class T>
void showAlgorithmChoice(Algos<T> a1, bool asc)
{
	cout << "Choose sorting algorithms\n1.Quick Sort\n2.Merge Sort\n3.Radix Sort\n4.Selection Sort";
	cout << endl << "Press anything else to exit";

	vector<int> algChoice;
	int algoInput;
	char moreInputs;

	cout << endl << "Enter your input: ";
	cin >> algoInput;

	if (algoInput == 1 || algoInput == 2 || algoInput == 3 || algoInput == 4)
	{
		algChoice.insert(algChoice.end().algoInput);
	}
	else
		exit(0);


	cout << "Would you like to enter more data? ";
	cin >> moreInputs;

	while (moreInputs == 'y')
	{
		cout << endl << "Enter your input: ";
		cin >> algoInput;
		if (algoInput == 1 || algoInput == 2 || algoInput == 3 || algoInput == 4)
		{
			algChoice.insert(algChoice.end().algoInput);
		}
		else
			exit(0);

		cout << "Would you like to enter more data?(y/n) ";
		cin >> moreInputs;
	}

	cout << endl;
	string sortingAlgos[4] = { "Quick","Merge","Radix","Selection" };
	for (int i = 0, n = algChoice.size(); i < n; i++)
	{
		int choice = algChoice.at(i);
		cout << sortingAlgos[choice - 1] << "Sort: ";

		clock_t starting = clock();
		if (choice == 1)
		{
			if (asc)
			{
				a1->QuickSort(asc, 0, a1->getLength() - 1);
			}
			else
				a1->QuickSort(asc, 0, a1->getLength());
		}
		else if (choice == 2)
		{
			a1->MergeSort(asc, 0, a1->getLength() - 1);
		}
		else if (choice == 3)
		{
			//radix sort
		}
		else
		{
			a1->SelectionSort(asc);
		}

		clock_t ending = clock();
		cout << ((ending - starting) / (double)CLOCKS_PER_SECOND) << " secs" << endl;
	}
	a1->Display();
};

template <class T>
void orderMenu(Algos<T> *a1)
{
	cout << "Select the order for sorting\n1.Ascending\n2.Descending ";
	cout << "Enter anything else to exit ";

	int order;
	cout << "Select your option: ";
	cin >> order;

	switch (order)
	{
	case 1:
		showAlgorithmChoice<T>(a1, true);
		break;
	case 2:
		showAlgorithmChoice<T>(a1, false);
		break;
	default:
		exit(0);
	}
}

template <class T>
void addingElements(Algos<T> *a1)
{
	cout << "Enter 1 to add more elements and anything else to exit  ";

	int add;
	cin >> add;
	if (add == 1)
	{
		char contin;
		while (true)
		{
			a1->AddElement();

			cout << "Would you like to add more elements?(y/n) ";
			cin >> contin;
			if (contin != 'y')
				break;
		}

		orderMenu<T>(a1);
	}
	else
		exit(0);
}void mainMenu()
{
	cout << "Select data types of elements\n1.Long\n2.Float\n3.String\n";
	cout << "Enter anything else to enter" << endl;
	int alpha;
	cin >> alpha;

	if (alpha == 1)
	{
		Algos<long> * a1 = new Algos<long>();
		addingElements<long>(a1);
	}
	else if (alpha == 2)
	{
		Algos<float> *a1 = new Algos<float>();
		addingElements<float>(a1);
	}
	else if (alpha == 3)
	{
		Algos<string>* a1 = new Algos<string>();
		addingElements<string>(a1);
	}
	else
		exit(0);
}

int main()
{
	mainMenu();

	system("pause");
	return 0;
}