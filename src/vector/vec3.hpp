#ifndef VEC3_HPP
#define VEC3_HPP

struct vec3 {
   vec3();
   vec3(const double val);
   vec3(const double val[3]);

   vec3& operator=(const vec3 &vec);
   double operator[](const unsigned int i) const;

   vec3 operator+(const vec3 &vec) const;
   vec3 operator-(const vec3 &vec) const;
   vec3 operator*(const vec3 &vec) const;
   vec3 operator/(const vec3 &vec) const;

   double sum() const;
   double norm() const;
   vec3 uvec() const;
   void normalize();

   double dot(const vec3 &vec) const;
   vec3 cross(const vec3 &vec) const;

   double mData[3]{};
};

#endif
