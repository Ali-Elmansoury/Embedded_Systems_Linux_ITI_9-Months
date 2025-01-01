#!/bin/bash
if [[ $EUID -ne 0 ]]; then
  echo "This script must be run as root. Use sudo."
  exit 1
fi

#Section 1

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

#Section 2

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