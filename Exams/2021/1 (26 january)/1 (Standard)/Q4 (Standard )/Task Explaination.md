# README for Web Access Log Analysis Task

## Task Description

You are tasked with designing and implementing a program to analyze web access logs. The logs record web access details, including:
1. The IP address of the host performing the access.
2. The username, date, and time of the access.
3. The type of access (GET or POST).
4. The resource accessed and the status code (200 for success, 401 for unauthorized).

### Requirements

1. **Data Storage**:
   - Use an efficient data structure to store web access records.
   - The structure must allow searching for records by either IP address or username.
   - Ensure the storage design respects constraints on time complexity, favoring logarithmic or constant time operations.

2. **Functionality**:
   - Implement a function to read the log file and populate the data structure.
   - Allow querying the data structure by IP address or username to retrieve all associated access records.

3. **Output**:
   - For a given key (IP or username), display the associated access records, including:
     - Timestamp of each access.
     - Type of request (GET/POST).
     - Accessed resource.
     - Status code.

### Input Format

The input file is a plain text file where each line represents one web access record in the following format:
```
<IP> <username> [<timestamp>] <requestType> <resource> <statusCode>
```
Example:
```
178.1.192.32 goodguy [10/01/2021:15:21:43] POST /intranet/login 200
178.1.192.42 nastyguy [10/01/2021:18:56:01] POST /intranet/login 200
34.52.1.33 badguy [10/01/2021:14:04:10] POST /services/ask 200
34.52.1.33 badguy [10/01/2021:14:06:20] POST /intranet/login 401
```

### Output Example

Given the above input file, querying for the IP `34.52.1.33` should produce:
```
Records for key: 34.52.1.33
[10/01/2021:14:06:20] POST /intranet/login 401
[10/01/2021:14:04:10] POST /services/ask 200
```

Querying for the username `badguy` should produce:
```
Records for key: badguy
[10/01/2021:14:06:20] POST /intranet/login 401
[10/01/2021:14:04:10] POST /services/ask 200
```

## Implementation Requirements

### 1. Data Structure
- Use a **hash table** to store records.
- Each key (IP address or username) maps to a linked list of access records.
- The hash function must ensure an even distribution of keys to minimize collisions.

### 2. Functions to Implement

#### `readFile`
- Reads the input file line by line.
- Parses each line into the following components:
  - IP address
  - Username
  - Timestamp
  - Request type (GET/POST)
  - Resource
  - Status code
- Inserts records into the hash table using both the IP address and username as keys.

#### `insertRecord`
- Inserts a record into the hash table for a given key.
- If the key already exists, appends the record to the linked list.
- If the key does not exist, creates a new hash table entry.

#### `searchRecords`
- Searches for records associated with a specific key (IP or username).
- Retrieves and prints all records in the linked list for the given key.

### 3. Program Flow
1. **Initialization**:
   - Initialize the hash table with a fixed size.
2. **File Reading**:
   - Open the input file.
   - Parse and store each line in the hash table.
3. **Query Execution**:
   - Allow the user to query the hash table by entering an IP or username.
   - Print all matching records.

### 4. Complexity Constraints
- Ensure average-case time complexity of \( O(1) \) for lookups and insertions.
- Handle collisions gracefully using linked lists.
- Ensure space complexity scales linearly with the number of unique keys and total records.

## How to Proceed

1. **Plan the Data Structure**
   - Choose the hash table size.
   - Define the structs for hash table entries and linked lists.

2. **Implement Core Functions**
   - Write the hash function.
   - Implement `insertRecord`, `readFile`, and `searchRecords`.

3. **Test the Program**
   - Use the provided example input file.
   - Test queries for various IPs and usernames.

4. **Optimize**
   - Evaluate the hash function's efficiency.
   - Adjust the hash table size if needed.

## Future Enhancements
- Add functionality to delete records by key.
- Implement a dynamic resizing mechanism for the hash table.
- Add error handling for invalid file formats and input queries.

This README provides a step-by-step guide for completing the task, ensuring clarity and alignment with the problem requirements.

