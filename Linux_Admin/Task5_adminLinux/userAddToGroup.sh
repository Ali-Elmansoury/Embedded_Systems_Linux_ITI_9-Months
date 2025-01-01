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