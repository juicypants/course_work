
#include "lab7.h"


void printParticipants(const Election &election)
{

   for (int i = 0; i < election.numCandidates + election.numVoters; i++)
   {
      cout << "ID: " << election.participants[i].id << "\tName:" << election.participants[i].name << "\t";
      if (election.participants[i].role == CANDIDATE)
         cout << "Role: Candidate" << endl;
      else
         cout << "Role: Voter" << endl;
   }
}

/* Task 1: 
 * Setup the election
 * - initialize all the member variables of the Election object
 * Parameters:
 *    - election: a Election struct object
 * Note:
 *    - id for voter/candidate are assigned as 1, 2, 3, ...in sequence
 *    - name for voter/candidate are copied from names[][] in sequence
 *    - role: CANDIDATE or VOTER (note candidate can also vote)
 *    - hasVoted = false, voteCount = 0
 */
void setup(Election &election, int numCandidates, int numVoters)
{  
   
   election.numCandidates = numCandidates;
   election.numVoters = numVoters;
   int i = 0;
   while(i < numCandidates){
       strcpy(election.participants[i].name,names[i]);
       election.participants[i].id = i;
       election.participants[i].role = CANDIDATE;
       election.participants[i].hasVoted = false;
       election.participants[i].voteCount = 0;
       i++;
   }
   int j = i;
   while(j<numVoters+i){
       strcpy(election.participants[j].name,names[j]);
       election.participants[j].id = j;
       election.participants[j].role = VOTER;
       election.participants[j].hasVoted = false;
       j++;
   }
  
}



/* Task 2:
 * Casting votes to some candidates by a specific voter given the voter id
 * Parameters:
 *    - election: the Election struct object
 *    - voterId: the voter's id
 * Note:
 *    validates the following 
 *    - voter id has to be valid, note candidate can also vote
 *    - candidate id has to be valid
 *    - voter can only vote once
 */
void voting(Election &election, int voterID)
{
   int voteto;
  
      if(election.participants[voterID].hasVoted == true){
         cout << "The voter has already voted!" << endl;
         }
      
      else{
         cout << "Enter the candidate id you want to vote for: ";
         cin >> voteto;
         
         if (election.participants[voteto].role == CANDIDATE){
            election.participants[voterID].hasVoted = true;
            cout << "You vote for " << voteto << " " << election.participants[voteto].name << endl;
            election.participants[voteto].voteCount ++;
         }
      }

   



}

/* Task 3:
 * Output the number of votes for each candidate
 * and announce the winner by finding who has the maximum number of votes
 * Parameters:
 *    - election: the Election struct object
 * Note: if there is more than 1 candidate has the same number of maximum votes,
 * announce it as a tie election.
 */
void resultTallying(const Election &election)
{
   cout << "Vote counting: " << endl; 
   int i=0;
   int sum = 0;
   int max = 0;
   int max_id = 0;
   int tied = 0;
   while(i<election.numCandidates){
      
      if(election.participants[i].voteCount > max){
         max = election.participants[i].voteCount;
         max_id = i;      
         }
      
      cout << "ID: " << election.participants[i].id << "    Name: " << election.participants[i].name 
      << " Votes: " << election.participants[i].voteCount << endl;
      sum+=election.participants[i].voteCount;
      i++;
   }
   
   i=0;
   while(i<election.numCandidates){
      
      if(election.participants[i].voteCount == max){
         tied++;  
      }
      i++;
   }
   cout << "Total votes received in election : " << sum << endl;

   if(tied > 1){
      cout << "It is a tied election" << endl;
   }
   else{
      cout << "The winner is: " << election.participants[max_id].name << endl;
   }
}
