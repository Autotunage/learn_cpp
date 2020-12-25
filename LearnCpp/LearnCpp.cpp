#include <iostream>
using namespace std;

int getRandomNumber(int min, int max)
{
    //return min + rand() % max;
    return min + (rand() % ((max - min) + 1));

}

int countOfNumbers(int randomNumber) // счетчик кол-ва символов
{
    int countNumber = 0;
    while (randomNumber > 0)
    {
        randomNumber = randomNumber / 10;
        countNumber++;
    }

    return countNumber;
} 
void getIntoArray(int* randomArray, int countNumber, int randomNumber) //вгоняем число в динамический массив
{
    for (int i = 0; i < countNumber; ++i)
    {
        randomArray[i] = randomNumber % 10;
        randomNumber = randomNumber / 10;
    }

   swap(randomArray[0], randomArray[countNumber - 1]);
} 

int checkUserLenght(int userNumber)
{
    int userLenght = 0;
    while (userNumber > 0)
    {
        userNumber = userNumber / 10;
        userLenght++;
    }

    return userLenght;
}

void userNumberInArray(int* arr, int userLenght, int userNumber)
{
    for (int i = 0; i < userLenght; ++i)
    {
        arr[i] = userNumber % 10;
        userNumber = userNumber / 10;

    }
    swap(arr[0], arr[userLenght - 1]);
}

int checkArrayEquals(int* randomArray, int* arr, int randomLenght)
{
    int atPlace = 0;
    for (int j = 0; j < randomLenght; ++j)
    {
        
        if (randomArray[j] == arr[j])
        {
            ++atPlace;
        }
    }

    return atPlace;
}


int checkMatchAll(int* randomArray, int* arr, int randomLenght)
{
    int indexArrayEqual = 0;
    
    for (int i = 0; i < randomLenght; ++i)
    {
        for (int j = 0; j < randomLenght; ++j)
        {
            if (randomArray[i] == arr[j])
            {
                if (indexArrayEqual < 3)
                {
                    indexArrayEqual++;
                }
            }

        }
    }

    return indexArrayEqual;
}

int main()
{
    setlocale (LC_ALL, "RUS");

    srand(static_cast<unsigned int>(time(0)));
    rand(); //вызываем функцию для сброса значения, чтобы стартовое число каждый раз при запуске было другое

    int min = 0, max = 999; // диапазон значений 
    int userNumber = 0;
    int randomNumber = getRandomNumber(min, max); //генерируем рандомное число
    int randomLenght = countOfNumbers(randomNumber); //узнаем кол-во символов в числе для размера будущего массива

    int* randomArray = new int[countOfNumbers(randomNumber)]; //создаем динамический массив размером кол-ва символов (например число 123 - размер 3, 12345 - размер 5)
    getIntoArray(randomArray, countOfNumbers(randomNumber), randomNumber); //заполняем массив

    cout << "Компьютер загадал трехзначное число в диапазоне 0-999. Отгадайте!\n"
        << "После каждой попытки компьютер сообщит насколько вы близки к истине" << endl;
    
    cout << "Тестовое рандомное число: " << randomNumber << endl;
    cout << "Кол-во символов в рандомном числе: " << countOfNumbers(randomNumber) << endl;

    while (userNumber != randomNumber)
    {
        cout << "Ваш вариант числа: ";
        cin >> userNumber;

        int* arr = new int[checkUserLenght(userNumber)]; //динамический массив для пользовательского числа
        userNumberInArray(arr, checkUserLenght(userNumber), userNumber); //вгоняем число в массив

        cout << endl;

        cout << "Угадано: " << checkMatchAll(randomArray, arr, randomLenght) << " ";  //проверка на то, попал ли юзер хоть в одной значение
        cout << "На своих местах: " << checkArrayEquals(randomArray, arr, randomLenght) << endl; //проверка на то, на своем ли месте угаданное значение
        delete[] arr;
        arr = nullptr;
    }

    cout << "*****Ура! Вы угадали!*****" << endl;

    delete[] randomArray;
    randomArray = nullptr;

    return 0;
}

