# Double Buffer

## Summary

In computer graphics and game development, the double buffer pattern is used to avoid visual artifacts like screen tearing caused by race conditions between the read and write processes. If only one buffer is used and the read pointer (monitor refresh) is faster than the write pointer (GPU rendering), half-finished images might be displayed. This results in frame tearing, where parts of two different frames are visible on the screen simultaneously.

## Concept

To address this issue, double buffering introduces two buffers:

The **front buffer** (active frame buffer), which is currently being displayed on the screen.
The **back buffer**, where the GPU renders the next frame.
Once the GPU completes rendering a frame into the back buffer, the two buffers are swapped. This ensures that only fully rendered frames are displayed, allowing the GPU to calculate independently without fear of displaying half-finished images.

## Limitations

While double buffering prevents tearing, it is not without trade-offs. If the GPU takes too long to render a frame (e.g., in cases of complex calculations), the same old frame in the front buffer may be displayed multiple times, leading to stuttering. This stutter is generally considered preferable to the disruptive visual artifact of screen tearing.

Additionally, if the GPU renders frames faster than the monitor's refresh rate (e.g., GPU at 120 Hz, monitor at 60 Hz), it can lead to screen tearing if the buffers are swapped as soon as the back buffer is full. In this scenario, the monitor may display a mix of frames, with the top half showing one frame and the bottom half showing another.

## VSync

To address the mismatch between GPU and monitor refresh rates, Vertical Synchronization (VSync) can be used. VSync ensures that buffer swapping only occurs during the monitor's vertical blanking interval (when the screen is not actively refreshing). This eliminates tearing but introduces a slight latency, as the GPU must wait for the monitor's refresh cycle to complete. While this latency is often negligible compared to the visual distraction of screen tearing, it can still impact input responsiveness in fast-paced games.

## Beyond Double Buffer

To further enhance performance and reduce latency during VSync wait times, developers can use **triple buffering** or even more buffers. In a triple-buffered system:

- A third buffer is added to the pipeline.
- The GPU can continue rendering into a third back buffer while waiting for the front buffer to be swapped, reducing idle time.
In theory, systems could support an infinite number of buffers to maximize efficiency, particularly with high-end GPUs and low-refresh-rate monitors. However, this is largely unnecessary with modern hardware and displays.

## Double Buffer within Unreal

Unreal Engine, by default, uses a double-buffered system to manage its rendering pipeline. This is implemented via the swap chain, a mechanism provided by graphics APIs like DirectX and Vulkan(can be found with path <UE_5.0 folder>\Engine\Source\Runtime\Windows\D3D11RHI\). The swap chain manages the front and back buffers, ensuring smooth rendering and efficient buffer swapping. While Unreal supports advanced techniques like triple buffering, the default double-buffer system is sufficient for most use cases on modern hardware.

By default, Unreal Engine launches using DirectX (though Vulkan is also supported), and the double-buffering process ensures that visuals are smooth and artifacts like tearing are minimized.
