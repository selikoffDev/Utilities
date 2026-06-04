#include <cmath>

#include "vec3.hpp"

vec3::vec3() {
   for (unsigned int i = 0; i < 3; i++) {
      mData[i] = 0.0;
   }
}

vec3::vec3(const double val) {
   for (unsigned int i = 0; i < 3; i++) {
      mData[i] = val;
   }
}

vec3::vec3(const double val[3]) {
   for (unsigned int i = 0; i < 3; i++) {
      mData[i] = val[i];
   }
}

vec3& vec3::operator=(const vec3& vec) {
   for (unsigned int i = 0; i < 3; i++) {
      mData[i] = vec[i];
   }

   return *this;
}

double vec3::operator[](const unsigned int i) const {
   return mData[i];
}

vec3 vec3::operator+(const vec3 &vec) const {
   vec3 newVec;
   for (unsigned int i = 0; i < 3; i++) {
      newVec.mData[i] = mData[i] + vec[i];
   }

   return newVec;
}

vec3 vec3::operator-(const vec3 &vec) const {
   vec3 newVec;
   for (unsigned int i = 0; i < 3; i++) {
      newVec.mData[i] = mData[i] - vec[i];
   }

   return newVec;
}

vec3 vec3::operator*(const vec3 &vec) const {
   vec3 newVec;
   for (unsigned int i = 0; i < 3; i++) {
      newVec.mData[i] = mData[i]*vec[i];
   }

   return newVec;
}

vec3 vec3::operator/(const vec3 &vec) const {
   vec3 newVec;
   for (unsigned int i = 0; i < 3; i++) {
      newVec.mData[i] = mData[i]/vec[i];
   }

   return newVec;
}

double vec3::sum() const {
   return mData[0] + mData[1] + mData[2];
}

double vec3::norm() const {
   return sqrt((*this**this).sum());
}

vec3 vec3::uvec() const {
   vec3 uvec;
   double norm {this->norm()};
   for (unsigned int i = 0; i < 3; i++) {
      uvec.mData[i] = mData[i]/norm;
   }

   return uvec;
}

void vec3::normalize() {
   double norm = this->norm();
   for (unsigned int i = 0; i < 3; i++) {
      mData[i] /= norm;
   }
}

double vec3::dot(const vec3 &vec) const {
   vec3 mul;
   mul = *this*vec;

   return mul.sum();
}

vec3 vec3::cross(const vec3 &vec) const {
   vec3 newVec;

   return newVec;
}
