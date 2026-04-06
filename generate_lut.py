import math

L_METRIC = 27720
L_QUARTER = 6930
MAX_VAL = 32767

filename = "hve_lut.h"

with open(filename, "w") as f:
    f.write("/* AUTO-GENERATED FILE: Harmonic Vector Equilibrium LUT */\n")
    f.write("#ifndef HVE_LUT_H\n#define HVE_LUT_H\n\n")
    f.write("#include <stdint.h>\n\n")
    f.write("// Q15 Scaled Quarter-Wave Sine Table for L=27720 metric\n")
    f.write(f"const int16_t sin_quarter_LUT[{L_QUARTER + 1}] = {{\n    ")
    
    for i in range(L_QUARTER + 1):
        # Розрахунок ідеального цілого значення
        val = round(MAX_VAL * math.sin((2.0 * math.pi * i) / L_METRIC))
        f.write(f"{val}, ")
        
        # Перенесення рядка кожні 15 значень для красивого форматування
        if (i + 1) % 15 == 0:
            f.write("\n    ")
            
    f.write("\n};\n\n#endif // HVE_LUT_H\n")

print(f"File {filename} successfully generated with {L_QUARTER + 1} values.")