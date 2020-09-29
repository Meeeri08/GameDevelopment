#include <iostream>

using namespace std;


template <class T>
class Vector3
{
private:
	T x, y, z;


public:
	Vector3() {}
	Vector3(T x, T y, T z) { this->x = x; this->y = y; this->z = z; }
	Vector3(T x, T y) { this->x = x; this->y = y; }

	Vector3 operator+(const Vector3& otherVector) {
		Vector3 vec;
		vec.x = this->x + otherVector.x;
		vec.y = this->y + otherVector.y;
		vec.z = this->z + otherVector.z;
		return vec;
	}

	Vector3 operator-(const Vector3& otherVector) {
		Vector3 vec;
		vec.x = this->x - otherVector.x;
		vec.y = this->y - otherVector.y;
		vec.z = this->z - otherVector.z;
		return vec;
	}


	void operator+=(const Vector3& otherVector) {

		Vector3 vec = *this;
		vec.x += otherVector.x;
		vec.y += otherVector.y;
		vec.z += otherVector.z;
	}

	void operator-=(const Vector3& otherVector) {

		Vector3 vec = *this;
		vec.x -= otherVector.x;
		vec.y -= otherVector.y;
		vec.z -= otherVector.z;
	}

	void operator=(const Vector3& otherVector) {

		this->x = otherVector.x;
		this->y = otherVector.y;
		this->z = otherVector.z;
	}

	bool operator==(const Vector3& otherVector) const
	{
		return this->x == otherVector.x && this->y == otherVector.y && this->z == otherVector.z;

	}

	//methods
	void Normalize() {

		float mag = sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
		this->x = this->x / mag;
		this->y = this->y / mag;
		this->z = this->z / mag;

	}

	void Zero() {
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}

	bool isZero() {
		return this->x == 0 && this->y == 0 && this->z == 0;
	}


	int DistanceTo(const Vector3& otherVector) {
		return sqrt(pow(this->x - otherVector.x) + pow(this->y - otherVector.y) + pow(this->z - otherVector.z));

	}


};

int main() {

	Vector3 <int>a;
	Vector3 <int>b(2, 2, 2);
	Vector3 <int>c(1, 1, 1);

	a = b - c;
	b += c;
	c -= a;
	bool x = a == b;
	cout << x;

	system("pause");
	return 0;

}