# Guia de Configuração e Instalação

## 1. Instalação do Make

### 1.1 Linux

- **Ubuntu/Debian:** `sudo apt install make`
- **Arch Linux:** `sudo pacman -S make`
- **Fedora:** `sudo dnf install make`

### 1.2 Windows

Instale o Make usando o Chocolatey:
```
choco install make
```

### 1.3 MacBook

Se não estiver instalado, use:
```
xcode-select --install
```

## 2. Instalação do Compilador C++

### 2.1 Windows

Baixe e instale o MinGW através do [site oficial](https://www.mingw-w64.org/). Após a instalação, configure as variáveis de ambiente para incluir o caminho para o `g++`.

### 2.2 Linux

- **Ubuntu/Debian:** `sudo apt install g++`
- **Arch Linux:** `sudo pacman -S gcc`
- **Fedora:** `sudo dnf group install "Development Tools"`

### 2.3 MacBook

O compilador geralmente é instalado junto com o Xcode.
```
xcode-select --install
```