# Linux Administration - Task 6

<p align="center">
    <img src="../Task1_adminLinux/linux_logo.png" width="200" height="150">
</p>

<p align="center">
    <img src="./task6.png">
</p>

---

## Section 1:


### 1. Create a folder called myteam in your home directory and change its permissions to read only for the owner.
<img src="1.png">

---

### 2. Log out and log in by another user
### 3. Try to access (by cd command) the folder (myteam)
<img src="2&3.png">

---

### 4. Using the command Line 
- #### a. Change the permissions of oldpasswd file to give owner read and write permissions and for group write and execute and execute only for the others (using chmod in 2 different ways)
    <img src="4a-1.png">
    <img src="4a-2.png">

---

- #### b. Change your default permissions to be as above.
    <img src="4b.png">
    <p align="center">
    <img src="4b-2.png">
    </p>

---

- #### c. What is the maximum permission a file can have, by default when it is just created? And what is that for directory.
<font size="4">
    Maximum Default Permissions:

    For Files:

        The maximum permissions a file can have by default are 666:
            Owner: rw- (read and write).
            Group: rw- (read and write).
            Others: rw- (read and write).

        This default excludes the execute (x) permission because:

            Files are not assumed to be executable unless explicitly set as such (to avoid security risks).

    For Directories:

        The maximum permissions a directory can have by default are 777:
            Owner: rwx (read, write, execute).
            Group: rwx (read, write, execute).
            Others: rwx (read, write, execute).

        The x (execute) permission for directories is required to:

            Allow entering the directory (cd command).
            Enable listing or accessing files within the directory.
</font>
   <p align="center">
    <img src="4c.png">
   </p>

---

- #### d. Change your default permissions to be no permission to everyone then create a directory and a file to verify.
    <p align="center">
    <img src="4d.png">
   </p>

---

- #### e. State who can access a this file if any with proof.
    <img src="4e.png">

---

### 5. Create a file with permission 444. Try to edit in it and to remove it? Note what happened.

<p align="center">
<img src="5-1.png">
</p>

---

#### 444 means read only for all, On trying to edit it:

<p align="center">
<img src="5-2.png">
</p>

---

#### Removal succeeds because the owner has delete permissions on the directory containing the file, not on the file itself.
#### If the directory lacked write permissions, deletion would be denied.

<p align="center">
<img src="5-3.png">
</p>

---

### 6. What is the difference between the “x” permission for a file and for a directory?

<p align="center">
<img src="6.png">
</p>

---

## Section 2: After creating new dir

### 1. Set the sticky bit on the newly created directory.

<p align="center">
<img src="s2-1.png">
</p>

---

### 2. Set the setgui bit on the created directory

<p align="center">
<img src="s2-2.png">
</p>

---

### 3. Create multiple user accounts.

<p align="center">
<img src="s2-3.png">
</p>

---

### 4. Allow these users to create files within the directory.

<p align="center">
<img src="s2-4-1.png">
</p>

<p align="center">
<img src="s2-4-2.png">
</p>

<p align="center">
<img src="s2-4-3.png">
</p>

---

### 5. Attempt to delete or rename each other's files.

<p align="center">
<img src="s2-5.png">
</p>

---

### 6. Provide a clear output demonstrating the impact of the sticky bit on file deletion and renaming within the directory.

#### Verify deletion attempt results:
#### If the sticky bit is set, only the owner of the file can delete it, regardless of directory write permissions.

---

### 7. Provide a clear output for the directory created.

<p align="center">
<img src="s2-7.png">
</p>

---

## List the permission passwd command has and explain why it has S

<p align="center">
<img src="s3.png">
</p>
<font size="4">
The s indicates the setuid bit is set for the file.

Why Does passwd Have S?

    The passwd command allows a user to change their own password. However, password data is typically stored in a file like /etc/shadow, which is owned by the root user and not accessible to regular users.

    The setuid bit (s) allows the passwd command to:
        Temporarily run with the privileges of the file owner (in this case, root), even when executed by a regular user.
        Modify the /etc/shadow file securely without compromising system security.

Explanation of Permissions

    rwsr-xr-x:
        Owner (rws): The owner (root) has read, write, and execute permissions, with the s indicating setuid.
        Group (r-x): Members of the group can read and execute.
        Others (r-x): All other users can read and execute.

What Does the S Do?

    The S ensures that:
        Only the passwd command is temporarily granted root privileges during execution.
        Users cannot misuse the elevated privileges beyond the scope of changing passwords.
</font>

---

*Ali Mohamed Ali Elmansoury*  
*ITI Embedded Systems - Intake 45*