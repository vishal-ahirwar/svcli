

# svcli

**svcli** is a lightweight C++ command-line utility to scan, compile, and run SystemVerilog (`.sv`) files using the `iverilog` simulator.
It simplifies your workflow by automatically detecting Verilog source files in the current directory and building them with a single command.

---

## 📦 Features

* 🔍 Automatically scans `.sv` files in current directory
* 🧪 Compiles with `iverilog -g2005-sv`
* ▶️ Runs the generated `a.out` file automatically
* ⚙️ Optional setup step to copy `svcli` to `/usr/bin/`
* 🧱 Stubs for synthesis and netlist generation (coming soon)

---

## 🚀 Getting Started

### 1. Clone & Build

```bash
git clone https://github.com/vishal-ahirwar/svcli.git
cd svcli
flick build --static
```
or
```
git clone https://github.com/vishal-ahirwar/svcli.git
cd svcli
cmake --preset=osname-static-build
cmake --build build/osname-static-build
./build/osname-static-build/svcli/svcli
```
### 2. Install CLI (optional)

```bash
./svcli --setup
# This copies svcli to /usr/bin/ for global use
```

---

## 📂 Example Usage

Place your `.sv` files (e.g. `alu.sv`, `alu_tb.sv`) in the current directory:

```bash
svcli
```

Output:

```bash
Scanning Files...
Compiling Files...
<simulation output>
```

If no `.sv` files are found, you'll get:

```
No .sv files in current directory!
```

---

## 🔧 Dependencies

* [iverilog](http://iverilog.icarus.com/) (SystemVerilog support)

Install it via your package manager:

```bash
# Debian/Ubuntu
sudo apt install iverilog

# macOS (with Homebrew)
brew install icarus-verilog
```

---

## 📘 Planned Features

* ✅ `.sv` file detection
* ✅ Automatic compilation
* ✅ Simulation run
* ⏳ Netlist generation
* ⏳ PNG diagram from netlist
* ⏳ Yosys/Verilator support (optional)

---

## 🧑‍💻 Author & License

Developed by **Vishal Ahirwar**
Licensed under the **MIT License** – see [LICENSE](LICENSE)

---
