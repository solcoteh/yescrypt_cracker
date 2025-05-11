Sure! Here's a complete and well-structured `README.md` for your yescrypt password cracker tool:

---

# 🔐 Yescrypt Password Cracker

A simple command-line tool written in Python and C to crack **yescrypt**-hashed passwords using a wordlist (dictionary attack). This tool attempts to match a hashed password with its plaintext version by comparing against each entry in a given wordlist.

---

## 📜 Features

* Accepts hash input from a file.
* Accepts a wordlist file path as an argument.
* Simple, lightweight, and easy to use.
* Supports **yescrypt**, provided your system’s `crypt()` implementation supports it.

---

## 🧰 Requirements

* A Linux or Unix-based system (because it uses the `crypt` module with yescrypt support)
* A valid wordlist (e.g., `rockyou.txt`)

#### For python
```bash
sudo apt install libcrypt-dev python3-dev build-essential
```
#### For C/C++
```bash
sudo apt install libxcrypt-dev
```

---

## 📂 File Structure

```plaintext
.
├── crack.py        # Main script to run the password cracker
├── hash.txt        # File containing the yescrypt hash (one per line)
└── README.md       # Documentation (this file)
```

---

## ⚙️ Usage

### 🔹 1. Prepare Your Files

* Create a `hash.txt` file with your **target yescrypt hash** on the first line:

  ```
  $y$j9T$.n7lcuysBubVbzdLHBqlo.$UKJ2UtEAfAYgtcPWYmf9RqhSxqLpfvdtOs57PKVpRX6
  ```

* Make sure you have a wordlist, e.g., `/usr/share/wordlists/rockyou.txt`.

### 🔹 2. Run the Tool With python

```bash
python3 yescrypt_cracker.py hash.txt /path/to/wordlist.txt
```

Example:

```bash
python3 yescrypt_cracker.py hash.txt /usr/share/wordlists/rockyou.txt
```

---
### 🔹 3. Run the Tool With C

For Compile and Usage
```bash
gcc -o yescrypt_cracker yescrypt_cracker.c -lcrypt
./yescrypt_cracker <hash_file> <wordlist_file>
```
Example:

```bash
./yescrypt_cracker hash.txt /usr/share/wordlists/rockyou.txt
```
---

---

## 📝 Sample Output

```bash
Password found: zExO18pPx2dZ61
```

Or, if the password is not in the list:

```bash
Password not found.
```

---

## ❗ Notes

* This tool only works if your system supports yescrypt through the `crypt()` function.
* Performance depends on the size of the wordlist and your machine’s speed.
* Only one hash per file is supported currently (first line only).

---

## 🚀 To-Do / Improvements

* [ ] Add support for cracking multiple hashes at once.
* [ ] Add support for other hashing schemes.
* [ ] Add progress bar or status output.
* [ ] Add interactive input mode (prompt user for file paths).

---

## ⚠️ Disclaimer

This tool is intended for **educational and authorized testing purposes only**. Do **not** use it to attempt unauthorized access to systems or accounts. The developer is **not responsible** for any misuse.

## 📄 License

This project is released under the Solcoteh License.

---
