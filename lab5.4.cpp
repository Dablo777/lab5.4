// Лабораторна робота № 5.4
#include <iostream>
#include <cmath>
using namespace std;
double S0(const int K, const int N)
{
	double s = 0;
	for (int i = K; i <= N; i++)
		s += pow(i, 2) / (pow(K, 2) + pow(N, 2));
	return s;
}
double S1(const int K, const int N, const int i)
{
	if (i > N)
		return 0;
	else
		return pow(i, 2) / (pow(K, 2) + pow(N, 2)) + S1(K, N, i + 1);
}
double S2(const int K, const int N, const int i)
{
	if (i < K)
		return 0;
	else
		return pow(i, 2) / (pow(K, 2) + pow(N, 2)) + S2(K, N, i - 1);
}
double S3(const int K, const int N, const int i, double t)
{
	t = t + pow(i, 2) / (pow(K, 2) + pow(N, 2));
	if (i >= N)
		return t;
	else
		return S3(K, N, i + 1, t);
}
double S4(const int K, const int N, const int i, double t)
{
	t = t + pow(i, 2) / (pow(K, 2) + pow(N, 2));
	if (i <= K)
		return t;
	else
		return S4(K, N, i - 1, t);
}
int main()
{
	int K, N;
	int i;
	cout << "K = "; cin >> K;
	cout << "N = "; cin >> N;
	cout << "(iter) S0 = " << S0(K, N) << endl;
	cout << "(rec up ++) S1 = " << S1(K, N, i) << endl;
	cout << "(rec up --) S2 = " << S2(K, N, i) << endl;
	cout << "(rec down ++) S3 = " << S3(K, N, i, 0) << endl;
	cout << "(rec down --) S4 = " << S4(K, N, i, 0) << endl;
	return 0;
}