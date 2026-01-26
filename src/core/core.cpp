#include "core.hpp"

#include "cmath"

// Vector 2 
constexpr Vector2 operator+(Vector2 v) { return v; }
constexpr Vector2f operator+(Vector2f v) { return v; }
constexpr Vector2 operator-(Vector2 v) { return { -v.x, -v.y }; }
constexpr Vector2f operator-(Vector2f v) { return { -v.x, -v.y }; }

Vector2 operator+(Vector2 v1, Vector2 v2) { return { (v1.x + v2.x), (v1.y + v2.y) }; }
Vector2f operator+(Vector2f v1, Vector2f v2) { return { (v1.x + v2.x), (v1.y + v2.y) }; }

Vector2 operator-(Vector2 v1, Vector2 v2) { return { (v1.x - v2.x), (v1.y - v2.y) }; }
Vector2f operator-(Vector2f v1, Vector2f v2) { return { (v1.x - v2.x), (v1.y - v2.y) }; }

Vector2 operator*(Vector2 v, int scaler) { return { (v.x * scaler), (v.y * scaler) }; }
Vector2f operator*(Vector2f v, f32 scaler) { return { (v.x * scaler), (v.y * scaler) }; }

// Vector 3
constexpr Vector3 operator+(Vector3 v) { return v; }
constexpr Vector3f operator+(Vector3f v) { return v; }
constexpr Vector3 operator-(Vector3 v) { return { -v.x, -v.y, -v.z }; }
constexpr Vector3f operator-(Vector3f v) { return { -v.x, -v.y, -v.z }; }

Vector3 operator+(Vector3 v1, Vector3 v2) { return { (v1.x + v2.x), (v1.y + v2.y), (v1.z + v2.z) }; }
Vector3f operator+(Vector3f v1, Vector3f v2) { return { (v1.x + v2.x), (v1.y + v2.y), (v1.z + v2.z) }; }

Vector3 operator-(Vector3 v1, Vector3 v2) { return { (v1.x - v2.x), (v1.y - v2.y), (v1.z - v2.z) }; }
Vector3f operator-(Vector3f v1, Vector3f v2) { return { (v1.x - v2.x), (v1.y - v2.y), (v1.z - v2.z) }; }

Vector3 operator*(Vector3 v, int scaler) { return { (v.x * scaler), (v.y * scaler), (v.z * scaler) }; }
Vector3f operator*(Vector3f v, f32 scaler) { return { (v.x * scaler), (v.y * scaler), (v.z * scaler) }; }

// vector functions
int dot(Vector3 v1, Vector3 v2) {
	return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}
f32 dot(Vector3f v1, Vector3f v2) {
	return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

Vector2f normalize(Vector2f v) {
	f32 magnitude = sqrt((v.x * v.x) + (v.y * v.y));
	return { (v.x / magnitude), (v.y / magnitude) };
}
Vector3f normalize(Vector3f v) {
	f32 magnitude = sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
	return { (v.x / magnitude), (v.y / magnitude), (v.z / magnitude) };
}
