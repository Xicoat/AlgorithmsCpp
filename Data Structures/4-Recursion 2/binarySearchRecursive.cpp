

include <iostream>
using namespace std;

int calcMid(int start, int end){
    return((end+start)/2);
}

int binSrch(int input[], int element, int start, int end){

    int mid = calcMid(start, end);

    cout << "element = " << element << endl;
    cout << "start value = " << input[start] << " start position =  " << start << endl;
    cout << "mid value= " << input[mid] << " mid position =  " << mid << endl;
    cout << "end value= " << input[end] << " end position =  " << end << endl;


    if (start > end){
        return -1;
    }

    if(input[mid]==element){
       return mid;
    }

    else if(element < input[mid]){
        cout << "lower" << endl;
        end = mid;
        binSrch(input, element, start, end-1);
    }

    else if(element > input[mid]){
        cout << "higher" << endl;
        start = mid;
        binSrch(input, element, start+1, end);
    }
}


// input - input array
// size - length of input array
// element - value to be searched
int binarySearch(int input[], int size, int element) {

    if(size <= 0){
        return 0;
    }
    
    int mid = (size-1)/2;
    int position = binSrch(input, element, 0, size-1);
    
    return position;
}



int main() {
    int input[100000],length = 0,element, ans;

    int elements[] = {6,6,7,10,11,12,13,14,15,18,18,19,22,23,25,26,26,30,35,35,36,39,40,42,46,46,47,48,49,49,51,51,52,54,56,58,58,58,59,61,61,66,66,69,71,72,75,75,76,77,78,81,82,84,85,92,93,95,95,97,98,98,100,105,106,107,108,108,110,115,115,117,118,118,119,119,122,123,124,129,132,133,137,139,143,144,144,145,147,148,149,150,151,156,157,158,158,163,167,167,170,174,174,175,176,176,178,181,181,182,182,184,186,190,194,195,196,198,200,202,203,206,207,207,207,208,209,210,210,211,211,212,213,214,214,217,217,221,224,226,228,229,230,233,234,235,238,238,238,240,242,242,243,243,244,246,247,249,251,254,256,257,257,260,262,264,268,273,273,273,276,277,278,281,281,282,282,282,283,284,284,286,292,293,299,305,306,311,311,312,313,316,320,323,324,325,330,337,337,341,345,350,352,353,355,357,357,358,358,360,365,365,365,367,367,369,370,370,371,372,374,376,378,379,379,382,385,388,388,389,389,394,395,396,396,396,398,399,400,401,402,403,404,405,405,408,415,417,418,418,418,421,424,426,426,428,428,434,437,439,440,441,443,444,445,449,449,451,452,452,454,454,456,458,461,465,466,468,470,472,473,473,475,479,479,480,480,481,483,484,485,488,488,489,489,492,493,493,493,494,496,499};

    for(int i =0;elements[i]!='\0';i++){ 
        length++;
    }

    cout << "length = " << length << endl;

    for(int i =0;i<length;i++){ 
        input[i] = elements[i];
    }

    element = 198;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}
