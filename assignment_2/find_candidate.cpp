#include<iostream>
#include"pntvec.h"
#include<fstream>
#include<vector>
#include<cmath>

double get_score(pntvec& candidate, std::vector<pntvec>& cloud );
std::vector<pntvec> get_candidates_from_file();
std::vector<pntvec> get_cloud_from_file();
//Finds the best candidate to approximate a point cloud from given point cloud and candidate files, then prints the candidate point's coordinates and score to standard out
int main(){
    std::vector<pntvec> candidates = get_candidates_from_file();//puts candidate points from file into vector
    std::vector<pntvec> cloud = get_cloud_from_file();//puts point cloud points from file into vector
    double min_score=9999999999999;
    int best_point=0;
    for(int i=0;i<candidates.size();i++){//computes score for each candidate to find the minimum
        double score = get_score(candidates[i], cloud);
        if(score<min_score){
            best_point=i;
            min_score=score;
        }
    }
    std::cout<<candidates[best_point].x<<" "<<candidates[best_point].y<<" "<<candidates[best_point].z<<" "<<std::endl;
    std::cout<<min_score<<std::endl;
    return 0;
}
//returns a vector of candidate points from candidates.txt in the working directory
std::vector<pntvec> get_candidates_from_file(){
    double x, y, z;
    std::vector<pntvec> to_return;
    std::ifstream candidate_file("candidates.txt");
    pntvec p;
    while(candidate_file >>p.x&&candidate_file>>p.y&&candidate_file >>p.z){       
        to_return.push_back(p);
    }
    return to_return;
}
//returns a vector of cloud points from point_cloud.txt in the working directory
std::vector<pntvec> get_cloud_from_file(){
    double x, y, z;
    std::vector<pntvec> to_return;
    std::ifstream candidate_file("point_cloud.txt");
    while(candidate_file >> x >> y >> z){
        pntvec p;
        p.x=x;
        p.y=y;
        p.z=z;
        to_return.push_back(p);
    }
    return to_return;
}
//calculates the score of a candidate point given the point and a vector of the point cloud points and returns it as a double
double get_score(pntvec& candidate, std::vector<pntvec>& cloud ){
    double distance = 0;
    double x,y,z;
    for(int i=0;i<cloud.size();i++){
        x=cloud[i].x;
        y=cloud[i].y;
        z=cloud[i].z;
        distance+=std::sqrt(std::pow(candidate.x-x,2)+std::pow(candidate.y-y,2)+std::pow(candidate.z-z,2)); 
    }
    
    return distance;
}
