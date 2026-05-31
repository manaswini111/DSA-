class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        
        sort(asteroids.begin(),asteroids.end());
        long long curmass=mass;
        for(int i=0;i<asteroids.size();i++)
        {
            if(curmass>=asteroids[i])
             {
                
                curmass +=asteroids[i];
             }
             else return false;
        }
        return true;
    }
};