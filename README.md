# Beast Encryption Project

The Beast Encryption Project provides a suite of C modules for implementing cross-platform encryption and secure file handling. This project includes algorithms for AES, DES, and Base64 encryption, as well as features for memory management, logging, and caching to optimize performance across Linux and Windows platforms.

## Features

- **AES, DES, and Base64 Encryption**:

  - Implements AES128 and DES encryption algorithms with support for various modes (e.g., ECB, CBC).
  - Includes low-level bitwise operations for secure and efficient data manipulation.
  - Base64 encoding and decoding functions to handle binary data in text-based formats.

- **Custom Memory Management**:

  - Uses a shared memory manager (`beast_mm.c`) that provides memory allocation and deallocation for secure data handling.
  - Supports concurrent data access through a locking mechanism to ensure thread safety.

- **Logging and Caching**:

  - Includes a logging module (`beast_log.c`) to log encryption operations and manage system events.
  - A custom caching system (`cache.c`) with hash-based data retrieval and expiration to optimize access to frequently used data.

- **Network and File Handling**:
  - Network card validation and filtering via `networkcards.c`.
  - File encryption with custom headers (`header.c`) for identifying encrypted files.

## Installation

1. **Clone the Repository**:

   ```bash
   git clone https://github.com/Frank-The-Coder/beast_encryption.git
   cd beast_encryption
   ```

2. **Compile the C Code**:
   - **Linux**:
     ```bash
     gcc -o beast *.c -lpthread
     ```
   - **Windows**: Use a compatible C compiler (e.g., Visual Studio) to compile all `.c` files.

## Usage

Once compiled, the project can be used to encrypt files, log operations, and manage memory:

```bash
./beast <input_file> <output_file> -e  # Encrypt
./beast <input_file> <output_file> -d  # Decrypt
```

### Example Functions

- `aes_encrypt_handler`: Encrypts data using AES128.
- `des_encrypt_handler`: Encrypts data using DES with ECB/CBC modes.
- `beast_mm_allocate`: Allocates memory securely within a shared memory space.
- `beast_write_log`: Logs system events with levels (DEBUG, NOTICE, ERROR).

## Supported Platforms

- **Linux**: Fully tested on Debian and Red Hat distributions.
- **Windows**: Compatible with Windows 10 and later.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
