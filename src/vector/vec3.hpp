#ifndef VEC3_HPP
#define VEC3_HPP

#include <iostream>

struct mat3x3;
struct vec3 {
   vec3();
   vec3(const double val);
   vec3(const double val[3]);

   ~vec3() = default;
   vec3(const vec3 &) = default;
   vec3(vec3 &&) = default;
   vec3& operator=(const vec3 &vec);
   vec3& operator=(vec3 &&) = default;


   friend std::ostream& operator<<(std::ostream& os, const vec3 &vec);
   bool operator==(const vec3 &vec) const;
   double operator[](const unsigned int i) const;

   vec3 operator+(const vec3 &vec) const;
   vec3 operator-(const vec3 &vec) const;
   vec3 operator*(const vec3 &vec) const;
   vec3 operator*(const mat3x3 &mat) const;
   vec3 operator/(const vec3 &vec) const;

   double norm() const;
   vec3 uvec() const;
   void normalize();

   double dot(const vec3 &vec) const;
   vec3 cross(const vec3 &vec) const;

   double mData[3]{};
};

#endif
