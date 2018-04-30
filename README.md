# Siete-y-Medio

For the first PIC10C assignment, we will be coding the game of Siete-y-medio!


1. 14th April- The initial commit was of course initializing the git repository, together with a readme file and a few gitignore files (to ignore certain C++ files)


2. 14th April- The second commit is where the project was begun and added to the repo. Code was copied straight from the assignment description and the readme was updated. 


3. 14th April- The third commit involved filling out the three classes as much as possible for the time being. No testing has begun as of yet. 

4. 17th April- Finished the game interface for the player's turn. Certain exceptional cases haven't been accounted for (for example, when the player draws after he busts, etc). 

5. 19th April- Finished the game interface for the computer's turn, as well as finishing the end game mechanics and the betting mechanics. Testing has begun. Program works as expected. 


6. 20th April- I made a bunch of commits trying to fix a problem with certain files from the visual studio IDE, that were being modified everytime I opened the project, even though I made no change to the files itself. In the end I could not fix the problem, but I updated the gitignore files to deal with SOME of the problems. The rest don't seem to be fatal and don't affect the major files so I'll let them be. 

7. 21st April- Created a new branch called "newbranch". The newbranch branch will concern itself with cleaning up and formatting the cards.h and cards.cpp files. The master branch will concern itself with the readme.md and the formatting of the output in siete-y-medio.cpp. This way we should be able to resolve most conflicts without too many problems. 

8. 21st April- Now the two branches will be merged. The last change in the master branch, along with this change (also in the master branch) means that the master branch has moved several commits ahead since the original branching. Which means that this merge will be a Non fast forward merge. 

9. 21st April- Resolved a few merge conflicts and checked to make sure the merge went well. Noticed and fixed a formatting error in the Readme file. Still have to check the code for corner cases and enable it to print a log file of games. 

10. 23rd April- Finished up coding the corner cases. There seems to be certain problems where the computers hands aren't being randomized but mine are. 

11. 24th April- Started a new "Experimental" branch to try and fix a few of the last errors of the project. This current edit to the readme is being done on the master branch however. This means that the following merge will be a THREE WAY MERGE (also a non fast forward merge). With this, the gitignore files and the .vs files that I stopped tracking, I should be eligible for the partial credit. 

12. 26th April- Created a new branch "Creating a gamelog". I have not updated the master branch which means the merge can be a fast forward one. However, for the sake of mixing it up, we'll do a non-fast forward branch (which is not three way). Also managed to make the program print out gamelogs in seperate files. The program is fully functional. Finally, I updated gitignore to ignore changes to the game log. 


13. FINAL REMARK: As you might have noticed, certain binary files are still being needlessly tracked and updated at each commit. I did in fact stop tracking many other binary files, but I kept these in the end because a)I wasn't completely able to gitignore them, and b)Upon looking online, several people recomended that these feels are better off not ignored in case of certain emergencies. Thus, I haven't git rm or stopped tracking these particular binary files.  

