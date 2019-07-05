
#define L long long
double findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    if(A.size() > B.size()){
        return findMedianSortedArrays(B,A);
    }
    
    L x=A.size();
    L y=B.size();
    L partition=(x+y+1)/2;
    L low=0,high=x;
    while(low <= high){
        L partition_x=(high+low)/2;
        L partition_y=partition - partition_x;
        

        //if partitionX is 0 it means nothing is there on left side. Use -INF for maxLeftX
        //if partitionX is length of input then there is nothing on right side. Use +INF for minRightX
        int max_left_x=((partition_x==0)?INT_MIN:A[partition_x-1]);
        int min_right_x=((partition_x==x)?INT_MAX:A[partition_x]);
        
        int max_left_y=((partition_y==0)?INT_MIN:B[partition_y-1]);
        int min_right_y=((partition_y==y)?INT_MAX:B[partition_y]);
        
        if(max_left_x <= min_right_y && max_left_y <= min_right_x){
            if(((x+y)%2)==0){
                return (max(max_left_x,max_left_y)+min(min_right_x,min_right_y))/2.0;
            }
            else{
                return max(max_left_x,max_left_y);
            }
        }
        else if(max_left_x > min_right_y){
        	//we are too far on right side for partitionX. Go on left side
            high=partition_x-1;
        }
        else{
        	//we are too far on left side for partitionX. Go on right side
            low=partition_x+1;
        }
    }
}
