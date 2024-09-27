# php-beast-8

**php-beast-8** is an updated version of the [php-beast](https://github.com/iceheart/php-beast) PHP extension, modified to be compatible with PHP 8.x and compiled for both Windows and Linux platforms. This extension allows you to encrypt and protect your PHP source code from unauthorized access and modification.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
  - [Prerequisites](#prerequisites)
  - [Building on Linux](#building-on-linux)
  - [Building on Windows](#building-on-windows)
- [Usage](#usage)
  - [Encrypting PHP Files](#encrypting-php-files)
  - [Running Encrypted Files](#running-encrypted-files)
- [Compatibility](#compatibility)
- [Acknowledgments](#acknowledgments)
- [License](#license)

## Introduction

**php-beast-8** provides a way to protect your PHP scripts by encrypting the source code. This is particularly useful for distributing PHP applications without exposing the source code to end-users. The original `php-beast` extension was not compatible with PHP 8.x; this project updates the extension to work with PHP 8 and includes precompiled binaries for both Windows and Linux.

## Features

- **PHP 8 Compatibility**: Works seamlessly with PHP 8.x versions.
- **Cross-Platform Support**: Compiled binaries available for both Windows and Linux.
- **Source Code Encryption**: Protects your PHP scripts by encrypting the source code.
- **Easy Integration**: Minimal changes required to integrate into existing projects.
- **Recompiled Binaries**: Includes recompiled binaries for immediate use.

## Installation

### Prerequisites

- **PHP 8.x Source Code**: Required for building the extension from source.
- **Build Tools**:
  - **Linux**: `gcc`, `make`, `phpize`, and other development tools.
  - **Windows**: Visual Studio, PHP SDK, and appropriate build tools.
- **Autoconf**: For generating configuration scripts (Linux).

### Building on Linux

1. **Clone the Repository**:

   ```bash
   git clone https://github.com/Frank-The-Coder/php-beast-8.git
   cd php-beast-8
   ```

2. **Navigate to the Extension Directory**:

   ```bash
   cd beast
   ```

3. **Prepare the Build Environment**:

   ```bash
   phpize
   ```

4. **Configure the Build**:

   ```bash
   ./configure
   ```

5. **Compile the Extension**:

   ```bash
   make
   ```

6. **Install the Extension**:

   ```bash
   sudo make install
   ```

7. **Enable the Extension**:

   Add the following line to your `php.ini` file:

   ```ini
   extension=beast.so
   ```

8. **Restart PHP**:

   Restart your web server or PHP-FPM service to load the new extension.

### Building on Windows

1. **Set Up Build Environment**:

   - Install **Visual Studio** and the **PHP SDK** for Windows.
   - Ensure that you have the necessary build tools and environment variables set.

2. **Clone the Repository**:

   Use Git Bash or another Git client to clone the repository:

   ```bash
   git clone https://github.com/Frank-The-Coder/php-beast-8.git
   cd php-beast-8\beast
   ```

3. **Prepare the Build Environment**:

   Run the `buildconf` script if necessary.

4. **Configure the Build**:

   Use the `configure` script or appropriate commands for Windows to configure the build.

5. **Compile the Extension**:

   Use Visual Studio's developer command prompt:

   ```cmd
   nmake
   ```

6. **Install the Extension**:

   Copy the compiled `beast.dll` to your PHP `ext` directory.

7. **Enable the Extension**:

   Add the following line to your `php.ini` file:

   ```ini
   extension=beast.dll
   ```

8. **Restart PHP**:

   Restart your web server to load the new extension.

## Usage

### Encrypting PHP Files

Use the provided `encrypt.php` script to encrypt your PHP files.

1. **Navigate to the Encryption Script**:

   ```bash
   cd tools
   ```

2. **Encrypt a PHP File**:

   ```bash
   php encrypt.php /path/to/source.php /path/to/encrypted.php
   ```

   - **source.php**: The original PHP file you want to encrypt.
   - **encrypted.php**: The output encrypted file.

### Running Encrypted Files

Encrypted files run like normal PHP scripts as long as the `php-beast-8` extension is enabled.

```bash
php /path/to/encrypted.php
```

## Compatibility

Tested on:

- **PHP 8.0**
- **PHP 8.1**
- **PHP 8.2**
- **PHP 8.3**
- **PHP 8.4**

Supports both Windows and Linux platforms.

## Acknowledgments

- **Original php-beast Project**: This project is based on [php-beast](https://github.com/iceheart/php-beast) by **iceheart**. Full credit goes to the original authors for their foundational work.
- **Contributors**: Thanks to everyone who contributed to updating the extension for PHP 8 compatibility.

## License

This project is licensed under the [MIT License](LICENSE). The original `php-beast` project is also licensed under the MIT License.
