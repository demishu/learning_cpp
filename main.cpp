#include <iostream>
using namespace std;

template<typename DataType>
class MyArray {
public:
	MyArray(int len) 
	{
		this->m_len = len;
		m_arr = new DataType[len];
		m_size = sizeof(*m_arr);
	}
	MyArray(const MyArray& arr) {
		this->m_len = arr.m_len;
		this->m_arr = new DataType[arr.m_len];
		this->m_size = sizeof(*m_arr);
	}
	void insert_data()
	{
		for (int i = 0; i < this->m_len; i++) {
			DataType temp;
			cout << "�������" << i + 1 << "�������" << endl;
			cin >> temp;
			this->m_arr[i] = temp;
		}
	}
	DataType& operator[](int a) {
		return this->m_arr[a];
	}
	void operator()() const 
	{
		for (int i = 0; i < this->m_len; i++) {
			cout << "Arr�ĵ�" << i + 1 << "��Ϊ��" << this->m_arr[i] << endl;
		}
	}
	MyArray& operator=(const MyArray& arr) {
		this->m_len = arr.m_len;
		this->m_arr = new DataType[arr.m_len];
		this->m_size = sizeof(*m_arr);
	}
	~MyArray() 
	{
		if (this->m_arr != NULL) {
			delete this->m_arr;
			m_arr = NULL;
		}
	}

private:
	DataType* m_arr;
	int m_len;
	int m_size;
};

void test() {
	int arr_len;
	cout << "�������봴����arr��Ԫ��������" << endl;
	cin >> arr_len;
	string datatype;
	cout << "��������Ҫ������arr����������(int, double)" << endl;
	cin >> datatype;
	cout << "�����Ԫ������Ϊ��" << datatype << endl;
	if (datatype == "int") {
		MyArray<int> arr(arr_len);
		arr.insert_data();
		arr();

		int num;
		cout << "���뿴arr�ĵڼ���Ԫ�أ�" << endl;
		cin >> num;
		cout << "arr�ĵ�" << num << "��Ϊ" << arr[num - 1] << endl;

	}
	else if (datatype == "double") {
		MyArray<double> arr(arr_len);
		arr.insert_data();
		arr();

		int num;
		cout << "���뿴arr�ĵڼ���Ԫ�أ�" << endl;
		cin >> num;
		cout << "arr�ĵ�" << num << "��Ϊ" << arr[num-1] << endl;
	}
	else {
		cout << "���Ͳ��ԣ�������" << endl;
		MyArray<int> arr(1);
		return;
	}

}
void main() {
	test();
}