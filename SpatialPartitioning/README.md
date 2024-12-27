# Spatial Partitioning:

## Summary

Collision checks among a large number of objects within a vast game world can be computationally expensive. The raw time complexity of collision detection is approximately O(n^2), and even optimized approaches like O(n*log(n)) can become a bottleneck for large-scale games. **Spatial Partitioning** addresses this issue by dividing the game world into smaller cells and limiting collision checks to objects in the same or neighboring cells, drastically reducing the number of comparisons required.

## Concept

### Divide the World into Cells

#### 1. Cell Division

- The game world is divided into multiple small cells, each representing a subsection of the world.
- Objects are assigned to cells based on their position.

#### 2. Handle Large Objects

- If an object is larger than a single cell or crosses cell boundaries, multiple adjacent cells are grouped into a larger parent cell.
- This process repeats, creating progressively larger cells until the entire world is represented in a **tree structure**.

#### Tree Structure for Efficiency:

- Each cell is a node in the tree, with smaller cells forming the leaves and larger, grouped cells forming the branches and root.
- To check for collisions, objects only need to compare with:
  - Other objects in the same cell.
  - Objects in directly connected parent or child cells in the tree.

## 2D and 3D Spatial Partitioning

- In 2D, this approach often uses a structure called a **quadtree**, where each cell is divided into four smaller quadrants.
- In 3D, the equivalent is an **octree**, where each cubic region is divided into eight smaller cubes.

## Spatial Partitioning within Unreal

### 1. Octree for Render Optimization

Unreal Engine 5 uses a 3D spatial partitioning structure called an **octree**. The octree divides the game world into cubic regions, where each region is further subdivided into eight smaller cubes along three axes (x, y, z). This hierarchical partitioning is used to optimize **lighting** calculations.

#### Lighting Calculations:
- The octree resides in the `FScene` class and is primarily used by the render thread.
- It determines quickly whether an object exists within a light's area of effect, drastically reducing the number of lighting calculations required.
- By skipping irrelevant regions, the rendering engine avoids unnecessary computation and improves performance.

### 2. World Partition for Large-Scale World

Unreal Engine 5 introduces **World Partition**, a system specifically designed to manage large open worlds. It provides:

#### Single-Layer Cell Division:
- Users define the size of each cell (or "grid") in the world.
- Unlike the octree, World Partition does not create a hierarchical tree structure. Instead, it uses a **flat**, **single-layer grid** for managing world visibility.

#### Integration with Level of Detail (LOD):
- World Partition hooks into the LOD system, ensuring that only the necessary level of detail is rendered for objects visible on-screen.
- Objects farther away appear with lower detail, improving rendering performance without sacrificing visual quality.