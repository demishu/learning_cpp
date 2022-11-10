#include <iostream>
using namespace std;

template<typename DataType>
class MyArray {
public:
	MyArray(int len) 
	{
		this->m_len = len;
		this->m_arr = new DataType[len];
		this->m_size = sizeof(*m_arr)*m_len;
		insert_data();
	}
	MyArray(const MyArray& arr) {
		this->m_len = arr.m_len;
		this->m_arr = new DataType[this->m_len];
		for (int i = 0; i < arr.m_len; i++) 
		{
			this->m_arr[i] = arr.m_arr[i];
		}
		this->m_size = sizeof(*m_arr)*m_len;
	}
	void insert_data()
	{
		for (int i = 0; i < this->m_len; i++) {
			DataType temp;
			cout << "请输入第" << i + 1 << "项的数据" << endl;
			cin >> temp;
			this->m_arr[i] = temp;
		}
	}
	DataType& operator[](int a) {
		return this->m_arr[a];
	}
	void operator()() const 
	{
		cout << "Arr有" << this->m_len << "个元素" << endl;
		for (int i = 0; i < this->m_len; i++) {
			cout << "Arr的第" << i + 1 << "项为：" << this->m_arr[i] << endl;
		}
		cout << "Arr共占" << this->m_size <<"个字节" << endl;
	}
	MyArray& operator=(const MyArray& arr) {
		this->m_len = arr.m_len;
		this->m_arr = new DataType[arr.m_len];
		for (int i = 0; i < arr.m_len; i++)
		{
			this->m_arr[i] = arr.m_arr[i];
		}
		this->m_size = arr.m_size;
		return *this;
	}
	~MyArray() 
	{
		if (this->m_arr != NULL) {
			delete[] this->m_arr;
			m_arr = NULL;
		}
	}

private:
	DataType* m_arr;
	int m_len;
	int m_size;
};

//测试有参构造函数还有重载的运算符。
void test() {
	int arr_len;
	cout << "请输入想创建的arr的元素数量：" << endl;
	cin >> arr_len;
	string datatype;
	cout << "请输入想要创建的arr的数据类型(int, double)" << endl;
	cin >> datatype;
	cout << "输入的元素类型为：" << datatype << endl;
	if (datatype == "int") {
		MyArray<int> arr(arr_len);
		arr();

		int num;
		cout << "你想看arr的第几项元素？" << endl;
		cin >> num;
		cout << "arr的第" << num << "项为" << arr[num - 1] << endl;

	}
	else if (datatype == "double") {
		MyArray<double> arr(arr_len);
		arr();

		int num;
		cout << "你想看arr的第几项元素？" << endl;
		cin >> num;
		cout << "arr的第" << num << "项为" << arr[num-1] << endl;
	}
	else {
		cout << "类型不对，请重试" << endl;
		MyArray<int> arr(1);
		return;
	}

}
//测试拷贝构造函数
void test1() {
	MyArray<int> arr(3);
	arr();
	MyArray<int> arr2(arr);
	arr2();
	MyArray<int> arr3 = arr;
	arr3();
	arr = arr2 = arr3;
	arr();
}	
void main() {
	//test();
	test1();
}