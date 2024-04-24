#include <iostream>

using namespace std;

class neuron         //класс, обозначающий наш нейрон
{
	double w = 0.3; //значение веса

public:

	double ProccesInputdata(double input)     //метод, отвечающий за вывод значения, просчитанного нейроном == вход*вес
	{
		return (input * w);
	}
	double  RestoreInputData(double output) //обратный метод вывода, для получения из выхода значение входа
	{
		return (output / w);
	}
	void Train(double input, double expected)                //метод тренировки нейрона
	{
		double actresult = input * w;                       //результат, полученный нерйоном на данный момент
		LastError = expected - actresult;                  //величина ошибки на данный момент
		double correct = (LastError / actresult) * speed; //величина треубемой корректировки на данный момент
		w += correct;                                    //изменение веса на величину корректировки
	}

	double LastError;
	double speed = 0.000001; //скорость обучения нейрона. Чем ниже - тем качественнее, но медленнее.
};

int main()
{
	double USD = 1;       //"учитель", обозначающий 
	double EU = 0.82;    //настоящее значение
	neuron n;            //создание объекта "нейрон"
	int i = 0;
	while (n.LastError > n.speed || n.LastError < -n.speed) //цикл обучения
	{
		i++;
		n.Train(USD, EU);
		if (i % 100000 == 0)        //вывод информации об обучении: попытка и значение ошибки
		{
			cout << "error's number: " << i << " Error: " << n.LastError << endl;
		}
	}

	cout << "100 dollar equals " << n.ProccesInputdata(100) << " euro" << endl;       //результаты  
	cout << "10 euro equals " << n.RestoreInputData(10) << " dollars" << endl;
}

