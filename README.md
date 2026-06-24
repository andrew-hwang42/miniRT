*This project has been created as part of the 42 curriculum by ahwang, beamrane.*


# Description

miniRT is a simplified ray tracing engine developed as part of the 42 curriculum.

The objective of the project is to generate a 3D scene from a textual description and render it using ray tracing techniques. The renderer computes ray-object intersections, lighting, shadows, and object transformations to produce a realistic image.

The project supports the following geometric primitives:

- Sphere
- Plane
- Cylinder

It also includes:

- Ambient lighting
- Point light sources
- Phong illumination model (ambient and diffuse components)
- Shadow computation
- Camera manipulation
- Real-time object transformations through MiniLibX

The goal of the project is to understand the mathematical foundations of computer graphics, including vector operations, coordinate systems, ray casting, and lighting models.

<br>

## Features

### Rendering

- Ray-object intersection detection
- Sphere rendering
- Plane rendering
- Cylinder rendering
- Ambient lighting
- Diffuse lighting
- Shadow casting

### Scene Management

- Scene parsing from `.rt` files
- Camera initialization
- Light initialization
- Object creation and storage

### Interactive Controls

- Camera manipulation
- Light manipulation
- Object translation
- Object rotation
- Object selection

<br>

## Map Format

Example:

```
	A    0.3           255,255,255
	C    0,0,10        0,0,-1        50
	L    -5,5,5        0.4
	sp   0,0,0         2.0           105,95,160
	pl   0,-5,0        0,1,0         125,135,150
	cy   0,0,-3        0,1,0         2.0          8.0         160,70,80
```

<br>

## Overview

### Ray Tracing Pipeline

1. Generate a ray for each pixel
2. Find the closest object intersection
3. Compute lighting at the hit point
4. Apply ambient, diffuse components
5. Determine shadow visibility
6. Render the final pixel color

### Lighting Model

The renderer uses the Phong illumination model:
- Ambient component
- Diffuse component

We do not apply specular component on this project.

<br>
<br>

# Instruction

## How to run

- To compile, run:
```
	make
```
- To run the project, run:
```
	./miniRT [maps]
```
- For example, to run the program with the map `minirt_scene.rt`,
```
	./miniRT ./maps/minirt_scene.rt
```

<br>

## Object Manipulation with mlx library

### Control Flow

The manipulation system follows a strict input order:

1. Select a mode
2. Select an operation
3. Select an axis
4. Apply the transformation

```
	Mode → Operation → Axis → Direction
```

<br>

---

1. Select a Mode

Before any transformation can be applied, a mode must be selected.

|    key   |         Mode        |
|:---------|:--------------------|
| KEY_C    | Camera              |
| KEY_L    | Light               |
| KEY_1    | Sphere              |
| KEY_2    | Plane               |
| KEY_3    | Cylinder            |

<br>

2. Select an Operation

After selecting a mode, choose the desired operation.

|    key   |      Operation      |
|:---------|:--------------------|
| KEY_M    | Move (Translation)  |
| KEY_R    | Rotate              |

<br>

3. Select an Axis

Choose the axis on which the transformation will be applied.

|    key   |         Axis        |
|:---------|:--------------------|
| KEY_X    | X-axis              |
| KEY_Y    | Y-axis              |
| KEY_Z    | Z-axis              |

<br>

4. Apply the Transformation

Use the arrow keys to apply the selected transformation.

|    key   |         Axis        |
|:---------|:--------------------|
| KEY_UP   | <ul><li>Move: Positive (+)</li><li>Rotate: Clockwise</li></ul> |
| KEY_DOWN | <ul><li>Move: Negative (-)</li><li>Rotate: Counterclockwise</li></ul> |

<br>

---

### Selecting Scene Objects

Multiple spheres, planes, and cylinders may exist in a scene.

To cycle through objects of the same type:

|    key   |         Axis        |
|:---------|:--------------------|
| KEY_F1   | Next sphere         |
| KEY_F2   | Next plane          |
| KEY_F3   | Next cylinder       |

The currently selected object is used for both transformation and object information display.


Example: 

```
	3 → F3 → F3: Selects the third cylinder(cyinder[2]) in the scene.
```

<br>

### Reset Selection state: Key_Q

Press `KEY_Q` to reset all current selections. After pressing `Q`, a new control sequence must be entered from the beginning.

This clears:
- Selected mode
- Selected operation (Move/Rotate)
- Selected axis
- Currently selected sphere index (`sphere[i]`)
- Currently selected plane index (`plane[i]`)
- Currently selected cylinder index (`cylinder[i]`)

---

### Examples

1. Rotate the camera clockwise around the Z-axis

```
	C → R → Z → UP
```

2. Move the light in the negative Y direction

```
	L → M → Y → DOWN
```

3. Move the second sphere (`sphere[1]`) in the positive X direction

```
	1 → F1 → M → X → UP
```

4. Rotate the third cylinder (`cylinder[2]`) counterclockwise around the Y-axis

```
	3 → F3 → F3 → R → Y → DOWN
```

<br>
<br>

# Resources

## Minilibx-linux

[Reference](https://github.com/42paris/minilibx-linux)

<br>

## Raytracing

Ray tracing is a computational method that represents how light behaves when interacting with an object.
Ray tracing tracks the path of light rays how they refract, reflect, or scatter when physically interacting with different structures.

[Reference](https://www.ansys.com/simulation-topics/what-is-ray-tracing)

<br>

## Phong reflection model

Phong reflection describes the way a surface reflects light as a combination of the diffuse reflection of rough surfaces with the specular reflection of shiny surfaces.
It is based on the observation that shiny surfaces have small intense specular highlights, while dull surfaces have large highlights that fall off more gradually.
The model also includes an ambient term to account for the small amount of light that is scattered about the entire scene.

[Reference 1](https://en.wikipedia.org/wiki/Phong_reflection_model)

[Reference 2](https://www.scratchapixel.com/lessons/3d-basic-rendering/phong-shader-BRDF/phong-illumination-models-brdf.html)

<br>

## Implement ray tracing

[Reference](https://raytracing.github.io/books/RayTracingInOneWeekend.html)

<br>

## AI Usage

AI tools were used to assist with:
- Reviewing README structure and wording
- Clarifying ray tracing concepts
- Improving documentation readability

AI tools were not used for design decisions, algorithms, architecture, parsing logic, mathematical implementations, rendering code, or project development.

<br>
<br>
