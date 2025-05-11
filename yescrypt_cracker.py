import crypt
import sys

def crack_yescrypt(target_hash, wordlist_path):
    try:
        with open(wordlist_path, 'r', errors='ignore') as f:
            for line in f:
                password = line.strip()
                hashed = crypt.crypt(password, target_hash)
                if hashed == target_hash:
                    return f"Password found: {password}"
        return "Password not found."
    except FileNotFoundError:
        return f"Wordlist file not found: {wordlist_path}"

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python3 script.py <hash_file> <wordlist_path>")
        sys.exit(1)

    hash_file_path = sys.argv[1]
    wordlist_path = sys.argv[2]

    try:
        with open(hash_file_path, 'r') as hf:
            target_hash = hf.readline().strip()
    except FileNotFoundError:
        print(f"Hash file not found: {hash_file_path}")
        sys.exit(1)

    result = crack_yescrypt(target_hash, wordlist_path)
    print(result)
