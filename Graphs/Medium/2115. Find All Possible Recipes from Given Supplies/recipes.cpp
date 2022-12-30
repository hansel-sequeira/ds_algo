vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        //Kahn's algorithm
        int n = recipes.size();
        unordered_map<string, vector<string>> umap;
        unordered_map<string, int> indegree;
        for(int i=0;i<n;i++){
            string recipe = recipes[i];
            for(string ingredient: ingredients[i]){
                umap[ingredient].push_back(recipe);
                indegree[recipe]++;
            }
        }
        vector<string> result;
        queue<string> q;
        for(string str: supplies)   
            q.push(str);
        //indegree of the supplies is 0
        while(!q.empty()){
            string ingredient = q.front();
            q.pop();
            for(string str: umap[ingredient]){
                if(--indegree[str] == 0){
                    result.push_back(str);
                    q.push(str);
                }
            }
        }
        return result;
    }
