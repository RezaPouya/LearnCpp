#include <iostream>
#include <sstream>
#include <string>
#include <format>

using String = std::string;

struct Vector2 {
	float X;
	float Y;

	Vector2(float x, float y) : X(x), Y(y) {}

	Vector2 Add(const Vector2& other) const {
		return Vector2(X + other.X, Y + other.Y);
	}

	// 
	Vector2 Multiply(const Vector2& other) const {
		return *this * other;
	}

	Vector2 operator+(const Vector2& other) const {
		return Add(other);
	}

	Vector2 operator*(const Vector2& other) const {
		return Vector2(X * other.X, Y * other.Y);
		//return Multiply(other);
	}

	bool operator==(const Vector2& other)const {
		return X == other.X && Y == other.Y;
	}

	bool operator!=(const Vector2& other)const {
		return !(*this == other);
		//return !operator== (other);
	}

	std::string ToString() const
	{
		std::ostringstream ss;
		ss << "( " << X << " , " << Y << " )";
		return ss.str();  // Returns a new string by value
	}


	std::string ToString2() const {  //  Returns a COPY slower
		return "( " + std::to_string(X) + " , " + std::to_string(Y) + " )";
	}

	std::string ToString3() const {
		return std::format("( {}, {} )", X, Y);  // Requires C++20
	}
};

std::ostream& operator<<(std::ostream& stream, const Vector2& vector) {
	stream << "( " << vector.X << " , " << vector.Y << " )";
	return stream;  // Return the stream by reference
}

int main()
{
	Vector2 position = Vector2(2.4, 4.2);
	Vector2 speed = Vector2(1.1, 1.2);
	Vector2 powerUp = Vector2(1.05, 1.05);

	Vector2 result = position.Add(speed.Multiply(powerUp));

	Vector2 resultOperator = position + speed * powerUp;

	std::cout << resultOperator << std::endl;
	std::cout << resultOperator.ToString() << std::endl;
	std::cin.get();
}

