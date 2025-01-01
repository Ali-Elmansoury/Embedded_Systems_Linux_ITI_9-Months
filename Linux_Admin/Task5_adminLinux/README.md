# Linux Administration - Task 5

<p align="center">
    <img src="../Task1_adminLinux/linux_logo.png" width="200" height="150">
</p>

<p align="center">
    <img src="./task5-1.png">
</p>

## Section 1: User and Group Management

<p> Create a Bash script that creates a user named 'yourName' and adds them to the 'FamilyName' group, checking for existing user and group, and displaying relevant information. </p>

### Script: `userAddToGroup.sh`

```bash
#!/bin/bash
if [[ $EUID -ne 0 ]]; then
  echo "This script must be run as root. Use sudo."
  exit 1
fi
read -p "Enter group name: " FamilyName
read -p "Enter user name: " UserName
read -s -p "Enter password: " Password
if getent group $FamilyName
then
    echo "Group named: $FamilyName already exists"
else
    sudo groupadd $FamilyName
    echo "Group named: $FamilyName has been created"
fi
if getent passwd $UserName
then
    echo "User named: $UserName already exists"
else
    sudo useradd -m $UserName -p $Password
    echo "User named: $UserName has been created"
fi
sudo usermod -aG $FamilyName $UserName
echo "User named: $UserName has been added to group named: $FamilyName"
echo "Displaying user information for user named: $UserName"
id $UserName
echo "Displaying group information for group named: $FamilyName"
getent group $FamilyName
echo "Script has been executed successfully"

echo "Deleting user $UserName and their home directory..."
sudo userdel -r "$UserName"

echo "Deleting group $FamilyName..."
sudo groupdel "$FamilyName"
```
<img src="./task5-1-res.png">

---

## Section 2: Secondary Group

<img src="./task5-2.png">

<p>
1. Create a supplementary (Secondary) group called pgroup with group ID of 30000 <br>
2. Lock any user created account so they can't log in <br>
3. Delete user account <br>
4. Delete group account </p>

### Script: `supplGroup_lockUsr.sh`

```bash
#!/bin/bash
if [[ $EUID -ne 0 ]]; then
  echo "This script must be run as root. Use sudo."
  exit 1
fi

read -p "Enter group name: " FamilyName
read -p "Enter user name: " UserName
read -s -p "Enter password: " Password

if getent group $FamilyName
then
    echo "Group named: $FamilyName already exists"
else
    sudo groupadd $FamilyName
    echo "Group named: $FamilyName has been created"
fi

if getent passwd $UserName
then
    echo "User named: $UserName already exists"
else
    sudo useradd -m $UserName -p $Password
    echo "User named: $UserName has been created"
fi

sudo usermod -aG $FamilyName $UserName

echo "User named: $UserName has been added to group named: $FamilyName"
echo "Displaying user information for user named: $UserName"

id $UserName

echo "Displaying group information for group named: $FamilyName"
getent group $FamilyName

secondaryGroup=pgroup

if getent group $secondaryGroup
then
    echo "Group named: $secondaryGroup already exists"
else
    sudo groupadd -g 30000 $secondaryGroup
    echo "Group named: $secondaryGroup with GID 30000 has been created"
fi 

sudo usermod -aG $secondaryGroup $UserName
echo "$UserName added to group $secondaryGroup."

sudo passwd -l "$UserName"
echo "User $UserName is now locked."

sudo usermod --expiredate 1 "$UserName"
echo "User $UserName account has been expired and is now locked from logging in."

echo "Script has been executed successfully"

su - "$UserName"

echo "Deleting user $UserName and their home directory..."
sudo userdel -r "$UserName"

echo "Deleting group $FamilyName..."
sudo groupdel "$FamilyName"

echo "Deleting group $secondaryGroup..."
sudo groupdel "$secondaryGroup"
```

- At first i tried to lock the profile from the script and to tried to change user after executing the script, but it didnt switch. 
    <img src="./task5-2-res1.png">

---

- When i added the command to switch user in the script, it switched successfuly, then i knew that `passwd -l` only locks the password not the whole user.
    <img src="./task5-2-res2.png">

---

- So i searched for a command to lock the user completely, i found `usermod --expiredate 1`, The 1 in the command sudo usermod --expiredate 1 "$UserName" is a special value that represents a Unix timestamp corresponding to January 1, 1970, at 00:00:00 UTC (the beginning of the Unix epoch).
By setting the expiration date to 1, you're essentially marking the user's account as expired in the past, which makes it impossible for the user to log in because the account is considered to have expired long ago.
    <img src="./task5-2-res3.png">

---

### Difference between `adduser` and `useradd` with an example

- `adduser` is a higher-level command that interacts more with the user and the system. It creates a user account and prompts for the required information like password, full name, etc. It is more user-friendly.
- `useradd` is a lower-level command, which is more direct and less interactive. It requires the administrator to specify all user parameters directly.

**Example using `adduser`:**
```bash
sudo adduser john_doe
```
This will prompt the user for additional information, such as the password and user details.

**Example using `useradd`:**
```bash
sudo useradd -m -s /bin/bash john_doe
```
This command directly adds the user `john_doe` with a default shell of `/bin/bash`.

---

*Ali Mohamed Ali Elmansoury*  
*ITI Embedded Systems - Intake 45*