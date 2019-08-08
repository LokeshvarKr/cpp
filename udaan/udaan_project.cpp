#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class ObjectiveQuestion{
	string question;
	int answer;
	vector<string>options;

public:
	ObjectiveQuestion(){}
	~ ObjectiveQuestion(){}

	void set_question(string question){
		this->question=question;
	}
	void set_options(string option1,string option2,string option3,string option4){
		this->options.push_back(option1);
		this->options.push_back(option2);
		this->options.push_back(option3);
		this->options.push_back(option4);		
	}
	void set_answer(int answer){
		this->answer;
	}
	void print_question(){
		cout<<"Problem"<<endl;
		cout<<question<<endl;
		cout<<"options :"<<endl;
		for(int i=0;i<options.size();i++){
			cout<<('a'+i)<<". "<<options[i]<<endl;
		}
	}
	int get_currect_option(){
		return answer;
	}
};

class User{
public:
	string uid;
	string uname;
	double score;
	 User(string uid,string uname):uid(uid),uname(uname),score(0){}
	~ User(){}
	void set_score(double score){
		this->score=score;
	}
};

class Quiz{
public:
	string quiz_details;
	int num;
	Quiz(){
		quiz_details="Read carefully. best of luck !";
		num=10;
	}
	Quiz(string quiz_details,int num){
		this->num=num;
		this->quiz_details=quiz_details;
	}
	void print_quiz_details(){
		cout<<"Quiz Details : "<<endl;
		cout<<"Number of questions "<<num<<endl;
		cout<<quiz_details<<endl;
	}
	void get_quiz_questions(vector<ObjectiveQuestion*> &questions,vector<ObjectiveQuestion*> &quiz_question){
		int n=questions.size();
		vector<ObjectiveQuestion*> quiz_questions;
		if(n < num){
			cout<<num<<" question is not present in system"<<endl;
			return;
		}
		bool *a=new bool[n];
		for(int i=0;i<n;i++){
			a[i]=false;
		}

		while(num){
			int x=rand()%n;
			if(a[x]==false){
				a[x]=true;
				num--;
				quiz_questions.push_back(questions[x]);
			}
		}
		delete [] a;
		return;
	}
};
int main(){
	User *user;
	ObjectiveQuestion *q;
	unordered_map<string,User*> users;
	Quiz *quiz=new Quiz();
	vector<ObjectiveQuestion*> objective_questions;
	vector<ObjectiveQuestion*> quiz_questions;
	bool *user_ans;

	int x=0;
	int p;
	string name;
	string uid;
	
	int num_options;
	string option;
	string question;
	int answer;
	string option1,option2,option3,option4;

	int correct_option;
	int entered_ans;
	double score;
	bool flag=true;
	while(flag){
		cout<<"Enter 1 to add question"<<endl;
		cout<<"Enter 2 to add user"<<endl;
		cout<<"Enter 3 to conduct quiz"<<endl;
		cout<<"Enter 0 to Exit"<<endl;
		cin>>x;

		switch(x){
			case 1:
					q=new ObjectiveQuestion();
					cout<<"Enter question in details"<<endl;
					cin>>ws;
					getline(cin,question);
					q->set_question(question);
					
					cout<<"enter 4 options (use Enter key to separate each options)"<<endl;
					cin>>ws;
					getline(cin,option1);
					cin>>ws;
					getline(cin,option2);
					cin>>ws;
					getline(cin,option3);
					cin>>ws;
					getline(cin,option4);
					cin>>ws;
					q->set_options(option1,option2,option3,option4);
					cout<<"Enter Answer(currect option)"<<endl;
					cin>>answer;
					q->set_answer(answer);
					objective_questions.push_back(q);
					break;

			case 2:
					cin>>ws;
					cout<<"Enter user name"<<endl;
					cin>>uid;

					cin>>ws;
					cout<<"Enter user id"<<endl;
					cin>>name;

					user=new User(uid,name);
					users[uid]=user;
					break;
			case 3:
					cin>>ws;
					cout<<"Exicited For Quiz!"<<endl;
					cout<<"Enter user id"<<endl;
					cin>>uid;
					if(users.find(uid)==users.end()){
						users[uid]=new User(uid,"nothing");
					}
					cout<<"details obout quiz"<<endl;
					cout<<quiz->quiz_details<<endl;
					cout<<"Quiz Started"<<endl;
					quiz_questions.clear();
					quiz->get_quiz_questions(objective_questions,quiz_questions);
					cin>>ws;
					user_ans=new bool[quiz_questions.size()];
					for(int i=0;i<quiz_questions.size();i++){
						quiz_questions[i]->print_question();
						cout<<endl;
						cout<<"Enter your ans"<<endl;
						cin>>entered_ans;
						correct_option=quiz_questions[i]->get_currect_option();
						if(correct_option==entered_ans){
							user_ans[i]=true;
						}
						else{
							user_ans[i]=false;
						}
					}
					score=0;
					for(int i=0;i<quiz_questions.size();i++){
						if(user_ans[i]==true)
							score+=1;
					}
					delete [] user_ans;
					users[uid]->set_score(score);
					cout<<"Your Score is : "<<score<<endl;
					break;
			case 0: flag=false;
					break;
			default : flag=false;
					break;
		}
	}
}