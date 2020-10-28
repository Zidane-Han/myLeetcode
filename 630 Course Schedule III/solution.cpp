class Solution {
public:
    static bool Compare(vector<int>& courseA, vector<int>& courseB) {
        return (courseA[1] < courseB[1]);
    }

    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<int> pq; // from largest duration to smallest
        // sort courses by end time, from early to late
        sort(courses.begin(), courses.end(), Compare);
        // lambda expression 
        // sort(courses.begin(), courses.end(), [](vector<int>& A, vector<int>& B){return A[1] < B[1];});
        
        int currt = 0;
        for (auto course : courses) {
            currt += course[0];
            pq.push(course[0]);
            while (currt > course[1]) {
                currt -= pq.top();
                pq.pop();
            }
        }

        return pq.size();
    }
};
