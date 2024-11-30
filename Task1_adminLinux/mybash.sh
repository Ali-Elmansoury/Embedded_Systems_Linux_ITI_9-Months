#!/bin/bash
cd $HOME
mkdir myDirectory
echo "myDirectory created in home folder"
cd myDirectory
mkdir secondDirectory
echo "secondDirectory created in myDirectory"
cd secondDirectory
touch myNotePaper
echo "myNotePaper created in secondDirectory"
cp myNotePaper ../
echo "myNotePaper copied to myDirectory"
cd ..
mv myNotePaper myOldNotePaper
echo "myNotePaper renamed to myOldNotePaper in myDirectory"
echo "Task completed successfully"