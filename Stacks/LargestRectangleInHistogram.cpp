class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        // Next Smaller Element (Indices)
        stack<int> st;
        vector<int> nse(n);
        for(int i=n-1;i>=0;i--){
            // pop mark push
            while(st.size()>0 && arr[st.top()] >= arr[i]) st.pop();
            if(st.size() == 0) nse[i] = n; // -1
            else nse[i] = st.top();
            st.push(i);
        }
        // Previous Smaller Element (Indices)
        while(st.size() > 0) st.pop();
        vector<int> pse(n);
        for(int i=0;i<n;i++){
            // pop mark push
            while(st.size()>0 && arr[st.top()] >= arr[i]) st.pop();
            if(st.size() == 0) pse[i] = -1; // -1
            else pse[i] = st.top();
            st.push(i);
        }
        int maxArea = 0;
        for(int i=0;i<n;i++){
            int area = arr[i] * (nse[i] - pse[i] - 1);
            if(area > maxArea) maxArea = area;
        }
        return maxArea;
    }
};
