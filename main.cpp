#include <iostream>
#include <cmath>
#include "vec3.h"
#include "ray.h"

// Check if a ray hits a sphere
bool hitSphere(const Vec3& center, double radius, const Ray& r) {
    Vec3 oc = r.origin - center;
    auto a = r.direction.length() * r.direction.length();
    auto half_b = dot(oc, r.direction);
    auto c = oc.length() * oc.length() - radius * radius;
    auto discriminant = half_b * half_b - a * c;
    return (discriminant > 0);
}

// Calculate color based on ray hits
Vec3 rayColor(const Ray& r) {
    if (hitSphere(Vec3(0, 0, -1), 0.5, r)) {
        return Vec3(1, 0, 0); // Red sphere
    }
    Vec3 unit_direction = r.direction * (1.0 / r.direction.length());
    double t = 0.5 * (unit_direction.y + 1.0);
    return Vec3(1.0, 1.0, 1.0) * (1.0 - t) + Vec3(0.5, 0.7, 1.0) * t;
}

int main() {
    const int image_width = 400;
    const int image_height = 200;

    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    Vec3 lower_left_corner(-2.0, -1.0, -1.0);
    Vec3 horizontal(4.0, 0.0, 0.0);
    Vec3 vertical(0.0, 2.0, 0.0);
    Vec3 origin(0.0, 0.0, 0.0);

    for (int j = image_height - 1; j >= 0; --j) {
        for (int i = 0; i < image_width; ++i) {
            double u = double(i) / (image_width - 1);
            double v = double(j) / (image_height - 1);
            Ray r(origin, lower_left_corner + horizontal * u + vertical * v);
            Vec3 color = rayColor(r);

            int ir = static_cast<int>(255.999 * color.x);
            int ig = static_cast<int>(255.999 * color.y);
            int ib = static_cast<int>(255.999 * color.z);

            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }
}
