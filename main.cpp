#include <string>
#include <iostream>

using namespace std;

int	main(void)
{
	string enum {
		// I am a little bit dissapointed because I can't use space with this codes
		Aksan = 0,
		Mandy = 1,
		Sahriani = 2
	} nama_siswa;

	cout << "Masukkan nama siswa!" << endl;
	cin >> nama_siswa;

	switch (nama_siswa)
	{
	case 0:
		cout << "Aksan" << endl;
		cout << "C++ Literature :p" << endl;
		cout << "A+" << endl;
		break ;
	case 1:
		cout << "Mandy" << endl;
		cout << "Medical Engineering" << endl;
		cout << "A++" << endl;
		break ;
	case 2:
		cout << "Sahriani" << endl;
		cout << "Japanese Literature" << endl;
		cout << "A" << endl;
		break ;
	default:
		cout << "No such name!" << endl;
	}
}
