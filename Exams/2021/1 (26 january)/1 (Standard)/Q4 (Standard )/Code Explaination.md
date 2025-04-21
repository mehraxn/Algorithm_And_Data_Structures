# README for Web Access Log Analysis in C

This project implements a system to store and query web access logs based on IP addresses or usernames. The data structure and logic used ensure efficient storage and retrieval to meet the requirements outlined in the problem statement.

## Problem Description

A web server logs all web access details, including:
1. The IP address of the host performing the access.
2. The username, date, and time of the access.
3. The type of access (GET or POST).
4. The resource accessed and the status code (200 for success, 401 for unauthorized).

Given such data, the program must:
- Store the information in a data structure suitable for fast access by IP address or username.
- Support efficient queries to retrieve all access records for a specific key (IP or username).
- Ensure average or near-constant time complexity for searches.

## Data Structure Used

### Hash Table

A **hash table** is chosen to store and index the data efficiently. The key design decisions are:
1. **Key**: Each entry in the hash table uses an IP address or username as the key.
2. **Value**: Each key points to a linked list of access records.
3. **Hash Function**: A custom hash function computes the hash index for each key.

This structure ensures:
- **Fast Access**: Average \( O(1) \) for insertions and lookups, with a worst-case of \( O(n) \) for hash collisions.
- **Flexibility**: Supports dynamic insertion of records.

## Code Structure

### 1. Hash Table and Linked List Structures

#### `AccessRecord`
A struct that represents a single access record:
- `timestamp`: The date and time of the access.
- `requestType`: Type of request (GET or POST).
- `resource`: The resource accessed.
- `statusCode`: HTTP status code.
- `next`: Pointer to the next record in the list.

#### `HashTableEntry`
A struct representing an entry in the hash table:
- `key`: The IP address or username.
- `records`: A linked list of `AccessRecord`s.
- `next`: Pointer to the next entry in case of hash collisions.

### 2. Functions

#### `unsigned int hash(const char *key)`
Computes the hash index for a given key using a simple polynomial accumulation method. Ensures distribution across the hash table size.

#### `void insertRecord(const char *key, const char *timestamp, const char *requestType, const char *resource, int statusCode)`
Inserts a new access record into the hash table:
- Searches for the key in the hash table.
- If the key exists, appends the record to the linked list.
- If the key doesn’t exist, creates a new entry in the hash table and initializes its list.

#### `void readFile(const char *filename)`
Reads the log file and populates the hash table:
- Parses each line to extract the IP, username, timestamp, request type, resource, and status code.
- Inserts the data into the hash table by both IP and username.

#### `void searchRecords(const char *key)`
Searches for access records associated with a specific key (IP or username):
- Locates the hash table entry.
- Iterates through the linked list to print each record.

#### `int main()`
The entry point of the program:
- Initializes the hash table.
- Reads the input file (`web_access_log.txt`).
- Demonstrates example searches for specific IPs and usernames.

## Complexity Analysis

### Storage
- Each key in the hash table has an associated linked list of access records.
- Space complexity is proportional to the number of unique keys and total records: \( O(n + m) \), where \( n \) is the number of keys and \( m \) is the number of records.

### Search and Insertion
- Average-case time complexity: \( O(1) \) for hash table operations.
- Worst-case time complexity: \( O(n) \) for hash collisions, where \( n \) is the number of entries.

## File Format

The input file must have the following format for each log entry:
```
<IP> <username> [<timestamp>] <requestType> <resource> <statusCode>
```
Example:
```
178.1.192.32 goodguy [10/01/2021:15:21:43] POST /intranet/login 200
178.1.192.42 nastyguy [10/01/2021:18:56:01] POST /intranet/login 200
34.52.1.33 badguy [10/01/2021:14:04:10] POST /services/ask 200
```

## How to Use

1. Prepare the log file (e.g., `web_access_log.txt`) with the required format.
2. Compile the program using GCC:
   ```
   gcc -o web_access_log web_access_log.c
   ```
3. Run the program:
   ```
   ./web_access_log
   ```
4. Example searches are pre-programmed in `main`. Modify or add more searches as needed.

## Example Output

Given the input file:
```
178.1.192.32 goodguy [10/01/2021:15:21:43] POST /intranet/login 200
178.1.192.42 nastyguy [10/01/2021:18:56:01] POST /intranet/login 200
34.52.1.33 badguy [10/01/2021:14:04:10] POST /services/ask 200
34.52.1.33 badguy [10/01/2021:14:06:20] POST /intranet/login 401
```

Search for `34.52.1.33`:
```
Records for key: 34.52.1.33
[10/01/2021:14:06:20] POST /intranet/login 401
[10/01/2021:14:04:10] POST /services/ask 200
```

Search for `badguy`:
```
Records for key: badguy
[10/01/2021:14:06:20] POST /intranet/login 401
[10/01/2021:14:04:10] POST /services/ask 200
```

## Notes

1. The hash table size (“HASH_TABLE_SIZE”) can be adjusted for larger datasets.
2. The program assumes valid input format. Additional error handling may be added for robustness.
3. Memory management is handled using `malloc` and linked list structures. Ensure proper cleanup in production scenarios.

## Future Enhancements

1. Implement a dynamic resizing mechanism for the hash table.
2. Add support for deleting keys or records.
3. Enhance the hash function for better distribution in large datasets.

---

This README provides a comprehensive guide to the design, implementation, and usage of the web access log analysis program. Modify and extend the code as needed for your specific requirements.

