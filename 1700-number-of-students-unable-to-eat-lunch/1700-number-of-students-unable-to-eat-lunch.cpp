class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int food =0,non = 0;
        int count=students.size();
        for(int i=0;i<students.size();i++){
            if(students[i]==1){
                food++;
            }
            else{
                non++;
            }
        }
        for(int i=0; i<sandwiches.size(); i++){
		if(sandwiches[i] == 0){
			if(non > 0){
				count--;
				non--;
			}
			else{return count;}
		}
		else{
			if(food > 0){
				count--;
				food--;
			}
			else{return count;}
		}
	}
	return count;
    }
};