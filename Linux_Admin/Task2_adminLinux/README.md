
# Linux Administration - Task 2  
<img src="../Task1_adminLinux/linux_logo.png" width="200" height="150" align="center">

## Questions

1. [Binary Search](#1-binary-search)  
2. [Run from any Dir](#2-run-from-any-dir)  
3. [Na2na2a](#3-na2na2a)

## Answers

### 1. Binary Search

```c
#include<stdio.h>
#include<stdlib.h>

int binarySearch(int arr[], int low, int high, int key)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main(void)
{
    int *ptr;
    int n, data;

    printf("Enter size of the array: ");
    scanf("%d", &n);

    ptr = (int*)calloc(n, sizeof(int));
    if(ptr == NULL)
    {
        printf("Memory Allocation Failed
");
        exit(0);
    }
    else
    {
        printf("Memory Successfully Allocated
");
    }

    printf("Enter array elements: 
");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &ptr[i]);
    }

    printf("Array elements: 
");
    for (int i = 0; i < n; i++)
    {
        printf("%d
", ptr[i]);
    }

    printf("Enter the number to be searched for: ");
    scanf("%d", &data);

    int result = binarySearch(ptr, 0, n - 1, data);
    if (result == -1)
        printf("Element is not found in the array
");
    else
        printf("Element is found at index %d
", result);

    free(ptr);
}
```

* I wrote it on Vim by myself, and I encountered many syntax errors. So, I used Vim multiple times to correct them. :)

---

### Errors:

1. **Error Screenshot 1**  
   <img src="errors.png">

2. **Error Screenshot 2**  
   <img src="errors2.png">

---

### After Corrections:

1. **Function Correction 1**  
   <img src="func_corr.png">

2. **Main Correction**  
   <img src="func_corr2.png">

---

### Function Test:

* Test Screenshot  
   <img src="test1.png">

---

### 2. Run from any Dir

* I ran it from the `~/Documents` directory.  
   <img src="test2_any_dir.png">

---

### 3. Na2na2a

#### 1. List the available shells in your system:

   <img src="shells.png">

#### 2. List the environment variables in your current shell:

   <img src="env.png">
   <img src="env_cont.png">

#### 3. Display your current shell name:

   * In the last photo.

#### 4. Execute the following command:  
   ```bash
   echo \ 
   ```
   Then press Enter.  
   **What is the purpose of `\`?**

   The backslash (`\`) is used as an escape character or line continuation symbol in most Unix-like shells, including Bash.  
   
   **Purpose of the Backslash (`\`):**
   
   1. **Line Continuation:**  
      If you place a backslash (`\`) at the end of a line and press Enter, the shell understands that the command is not complete yet and expects more input on the next line. The `\` escapes the newline character, effectively allowing you to write a long command over multiple lines.

   2. **Escape Character:**  
      The backslash also escapes special characters, preventing them from being interpreted by the shell.

#### 5. Create a Bash shell alias named **PrintPath** for the `echo $PATH` command:

<img src="printPath.png">

---

*Ali Mohamed Ali Elmansoury<br>
ITI Embedded Systems - Intake 45*