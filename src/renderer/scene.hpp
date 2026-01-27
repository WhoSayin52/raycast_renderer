#ifndef SCENE_HPP
#define SCENE_HPP

#include "../core.hpp"
#include "../math/math.hpp"

struct LightComponent {
	Vector3f ambient;
	Vector3f diffuse;
	Vector3f specular;
};

struct DirectionalLight {
	Vector3f direction;
	LightComponent light;
};

struct PointLight {
	Vector3f position;
	LightComponent light;
	f32 constant; // always one
	f32 linear;
	f32 quadratic;
};

DirectionalLight direct_lights[] = {
	DirectionalLight{
		.direction = normalize(Vector3f{1.0f, -4.0f, 4.0f}),
		.light = LightComponent{
			.ambient = {0.2f, 0.2f, 0.2f},
			.diffuse = {0.6f, 0.6f, 0.6f},
			.specular = {0.2f, 0.2f, 0.2f}
		}
	},
};

PointLight point_lights[] = {
	PointLight{
		.position = Vector3f{2.0f, 1.0f, 0.0f},
		.light = LightComponent{
			.ambient = {0.2f, 0.2f, 0.2f},
			.diffuse = {0.6f, 0.6f, 0.6f},
			.specular = {0.2f, 0.2f, 0.2f}
		},
		.constant = 1.0f,
		.linear = 0.7f,
		.quadratic = 1.8f
	},
};

struct Material {
	Vector3f diffuse;
	Vector3f specular;
	f32 shininess;
};

struct Rect {
	int x, y, width, height;
};

struct Sphere {
	Vector3f position;
	f32 r;
	Material material;
};

inline Sphere spheres[] = {
	Sphere{
		.position = Vector3f{0.0f, -1.0f, 3.0f},
		.r = 1.0f,
		.material = Material{
			.diffuse = {1.0f, 0.0f, 0.0f},
			.specular = {1.0f, 0.0f, 0.0f},
			.shininess = 100.0f
		} // red
	},
	Sphere{
		.position = Vector3f{2.0f, 0.0f, 4.0f},
		.r = 1.0f,
		.material = Material{
			.diffuse = {0.0f, 0.0f, 1.0f},
			.specular = {0.0f, 0.0f, 1.0f},
			.shininess = 100.0f
		} // blue
	},
	Sphere{
		.position = Vector3f{-2.0f, 0.0f, 4.0f},
		.r = 1.0f,
		.material = Material{
			.diffuse = {0.0f, 1.0f, 0.0f},
			.specular = {0.0f, 1.0f, 0.0f},
			.shininess = 10.0f
		} // green
	},
	Sphere{
		.position = Vector3f{0.0f, -5001.0f, 0.0f},
		.r = 5000.0f,
		.material = Material{
			.diffuse = {1.0f, 1.0f, 0.0f},
			.specular = {1.0f, 1.0f, 0.0f},
			.shininess = 500.0f
		} // yellow
	},
};

#endif // SCENE_HPP
