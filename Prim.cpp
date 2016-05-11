
struct edge
{

    edge(int f, int t, int w)
    {
        from = f ;
        to =t ;
        weight = w ;
    }
    int from ,to,weight;
    bool operator< (const edge & e) const
    {
        return weight > e.weight;
    }
};

pair <int , vector<edge> > PRIM (vector <vector<edge>> adjList) // O (E logV)
{
    int N = adjList.size() , cost = 0;
    vector<int> visited (N , 0) ;
    vector<int> visited2 (N , 0) ;
    vector<edge> Graph ;

    priority_queue <edge> queueEdges ; // 1) priority_queue to sort edges
    // queueEdges.push(edge(-1,0,0)); //add base edge
    for(int j = 0 ; j<adjList.size() ; ++j)
    {
        for(int i = j+1 ; i<adjList[j].size() ; ++i)    //3) Iterate on adjacent edges & add new edges, using e.to as src
        {
            edge conectedEdge = adjList[j][i];
            // cout<< conectedEdge.weight<<" ";
            queueEdges.push(conectedEdge);
        }
        // cout<<endl;
    }

    cout<<"queueEdgesSize: "<< queueEdges.size()<<endl;
    while(!queueEdges.empty())
    {

        edge newEdge = queueEdges.top();
        queueEdges.pop();

        if ( visited2[newEdge.from] > 1 || visited2[newEdge.to] > 1 ) continue ;
        visited2[newEdge.from] ++ ;
        visited2[newEdge.to] ++ ;

        cost+= newEdge.weight;
        Graph.push_back(newEdge);
        if(Graph.size()==N-1) break ;
    }

    return make_pair(cost, Graph );
}
