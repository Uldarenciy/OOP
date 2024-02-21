#include <iostream>
#include <cmath>

struct Vector3f
{
    float x, y, z;
};

Vector3f operator+(const Vector3f& a, const Vector3f& b) 
{
    Vector3f result = {a.x + b.x, a.y + b.y, a.z + b.z};
    return result;
}

Vector3f operator-(const Vector3f& a, const Vector3f& b) 
{
    Vector3f result = {a.x - b.x, a.y - b.y, a.z - b.z};
    return result;
}

Vector3f operator*(const Vector3f& a, float b) 
{
    Vector3f result = {a.x * b, a.y * b, a.z * b};
    return result;
}

Vector3f operator*(float b, const Vector3f& a) 
{
    Vector3f result = {a.x * b, a.y * b, a.z * b};
    return result;
}

Vector3f operator/(Vector3f& a, float b) 
{
    Vector3f result = {a.x / b, a.y / b, a.z / b};
    return result;
}

float operator*(const Vector3f& a, const Vector3f& b) // теорема косинусов
{
    float length_a = sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
    float length_b = sqrt(b.x * b.x + b.y * b.y + b.z * b.z);
    Vector3f c = b - a;
    float length_c = sqrt(c.x * c.x + c.y * c.y + c.z * c.z);
    float cos = (length_a * length_a + length_b * length_b - length_c * length_c) / (2 * length_a * length_b);
    float result = length_a * length_b * cos;
    return result;
}

bool operator==(const Vector3f& a, const Vector3f& b)
{
    if (a.x == b.x and a.y == b.y and a.z == b.z)
    {
        return true;
    }
    return false;
}

bool operator!=(const Vector3f& a, const Vector3f& b)
{
    if (a.x != b.x or a.y != b.y or a.z != b.z)
    {
        return true;
    }
    return false;
}

Vector3f operator*=(Vector3f& a, float b) 
{
    a = a * b;
    return a;
}

Vector3f operator-(Vector3f& a)
{
    a *= -1.00f;
    return a;
}

Vector3f operator+(Vector3f& a)
{
    return a;
}

Vector3f operator/=(Vector3f& a, float b) 
{
    a = a / b;
    return a;
}

Vector3f operator+=(Vector3f& a, const Vector3f& b) 
{
    a = a + b;
    return a;
}

Vector3f operator-=(Vector3f& a, const Vector3f& b) 
{
    a = a - b;
    return a;
}

std::ostream& operator<<(std::ostream& out, const Vector3f& a)
{
    out << "(" << a.x << ", " << a.y << ", " << a.z << ")";
    return out;
}

std::istream& operator>>(std::istream& in, Vector3f& a) 
{
    in >> a.x >> a.y >> a.z;
    return in;
}

float squaredNorm(const Vector3f& a)
{
    return a.x * a.x + a.y * a.y + a.z * a.z;
}

float norm(const Vector3f& a)
{
    return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

void normalize(Vector3f& a)
{
    a = a / norm(a);
}