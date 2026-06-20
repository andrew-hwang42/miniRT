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
<br>

---

1. Select a Mode

Before any transformation can be applied, a mode must be selected.

|    key   |         Mode        |
|:---------|--------------------:|
| KEY_C    | Camera              |
| KEY_L    | Light               |
| KEY_1    | Sphere              |
| KEY_2    | Plane               |
| KEY_3    | Cylinder            |

<br>

2. Select an Operation

After selecting a mode, choose the desired operation.

|    key   |      Operation      |
|:---------|--------------------:|
| KEY_M    | Move (Translation)  |
| KEY_R    | Rotate              |

<br>

3. Select an Axis

Choose the axis on which the transformation will be applied.

|    key   |         Axis        |
|:---------|--------------------:|
| KEY_X    | X-axis              |
| KEY_Y    | Y-axis              |
| KEY_Z    | Z-axis              |

<br>

4. Apply the Transformation

Use the arrow keys to apply the selected transformation.

|    key   |         Axis        |
|:---------|--------------------:|
| KEY_UP   | <ul><li>Move: Positive (+)</li><li>Rotate: Clockwise</li></ul> |
| KEY_DOWN | <ul><li>Move: Negative (-)</li><li>Rotate: Counterclockwise</li></ul> |

<br>
<br>

---

### Selecting Scene Objects

Multiple spheres, planes, and cylinders may exist in a scene.

To cycle through objects of the same type:

|    key   |         Axis        |
|:---------|--------------------:|
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

Press `KEY_Q` to reset all current selections. After Qressing `Q`, a new control sequence must be entered from the beginning.

This clears:
- Selected mode
- Selected operation (Move/Rotate)
- Selected axis
- Currently selected sphere index (`sphere[i]`)
- Currently selected plane index (`plane[i]`)
- Currently selected cylinder index (`plane[i]`)

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
