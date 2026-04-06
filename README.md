# Harmonic Vector Equilibrium (HVE) Phase Controller

This repository contains the open-source hardware/software architecture and Prior Art disclosure for an integer-based spatial and phase control framework designed for embedded systems.

## The L=27720 Metric
Traditional Cartesian actuator control relies on floating-point arithmetic, which leads to phase drift and quantization errors over time, especially when interfacing with mechanical gear ratios.

This framework utilizes a discrete metric of **L = 27720** units for a full 360° rotation. Being the Least Common Multiple (LCM) of integers 1 through 12, it allows for:
* **Exact integer division** for mechanical transmissions.
* **Bounded quantization error** with zero accumulated phase drift (strict modular integer arithmetic).
* **FPU-free execution** on resource-constrained microcontrollers (e.g., ESP32, STM32).
* **Cross-Disciplinary Scalability** (Medical Imaging/MRI, Neuromodulation, Plasma Confinement, and Telecommunications).

## Documentation
The complete theoretical justification, generalized scope, cuboctahedral vertex mapping, and handling of the 180° singularity are detailed in the included PDF publication:
📄 **[Read the Full Disclosure (PDF)](HVE_Lozovyi_Final.pdf)** *(Note: Ensure the PDF file uploaded matches this name)*

## C Implementation
The pure-integer control law architecture utilizes a memory-optimized quarter-wave Sinusoidal Lookup Table (LUT) scaled for Q15 operations and event-triggered gain scheduling.

## Author
**Oleksandr Lozovyi**
Independent Researcher | Lviv, Ukraine

## License
Published as Open Access Prior Art under the MIT License.
