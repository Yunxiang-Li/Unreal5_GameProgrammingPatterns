# Flyweight Pattern:

## Summary

The Flyweight Pattern focuses on reducing memory usage and improving performance by sharing immutable (intrinsic) data among a large collection of objects. This pattern is particularly effective when dealing with objects that share common characteristics, like graphical assets or game entities.

## Concept

- Intrinsic data – Data that is immutable and consistent across all instances of an object(A tree's 3D model and texture in a game)
- Extrinsic data – Data that is mutable and unique to each instance(A tree's position, rotation and scale in the game world)
- Memory costs - Storing data for each instance separately in memory (RAM) is costly, especially for large collections of objects. 

For example, in a game with hundreds of identical trees, flyweight pattern can share the same model and texture for each tree, while only store unique transformation data (extrinsic data) like position and orientation.

## Limitations

If there are multiple types of trees with different models or textures, the Flyweight Pattern alone doesn't address this distinction. Combining the Flyweight Pattern with the Type Object Pattern allows efficient handling of multiple types.

## Flyweight Pattern within Unreal

Unreal Engine inherently uses the Flyweight Pattern for managing assets. All loaded assets, such as textures, models, or materials, are stored in a shared memory pool and referenced wherever needed in the project. However, when a specific instance of an asset requires unique behavior or appearance (e.g., changing the color of one tree while leaving others unchanged), the Flyweight Pattern must be **broken**:
- Unreal creates a dynamic material instance or a copy of the asset.
- This ensures the modified version has its own intrinsic data, while other instances continue to share the original data.
