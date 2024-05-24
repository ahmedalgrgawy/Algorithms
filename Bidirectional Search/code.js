class Graph {
    // Constructor to initialize the graph with V vertices. 
    constructor(V) {
        this.V = V; // Number of vertices 
        // Adjacency list representation 
        this.adj = new Array(V).fill().map(() => []);
    }

    // Function to add an edge between vertices u and v. 
    addEdge(u, v) {
        this.adj[u].push(v);
        this.adj[v].push(u);
    }

    // Breadth-First Search (BFS) starting from a given source node. 
    BFS(queue, visited, parent) {
        const current = queue.shift();
        for (const neighbor of this.adj[current]) {
            if (!visited[neighbor]) {
                parent[neighbor] = current;
                visited[neighbor] = true;
                queue.push(neighbor);
            }
        }
    }

    // Check if there is an intersection between two BFS searches. 
    isIntersecting(s_visited, t_visited) {
        for (let i = 0; i < this.V; i++) {
            if (s_visited[i] && t_visited[i]) {
                return i; // Return the intersecting node 
            }
        }
        return -1; // No intersection found 
    }

    // Print the path from source 's' to target 't' through the intersection node. 
    printPath(s_parent, t_parent, s, t, intersectNode) {
        const path = [];
        path.push(intersectNode);
        let i = intersectNode;
        while (i !== s) {
            path.push(s_parent[i]);
            i = s_parent[i];
        }
        path.reverse();
        i = intersectNode;
        while (i !== t) {
            path.push(t_parent[i]);
            i = t_parent[i];
        }
        console.log("*****Path*****");
        console.log(path.join(' '));
    }

    // Bidirectional search to find the shortest path between 's' and 't'. 
    biDirSearch(s, t) {
        const s_visited = new Array(this.V).fill(false);
        const t_visited = new Array(this.V).fill(false);
        const s_parent = new Array(this.V).fill(-1);
        const t_parent = new Array(this.V).fill(-1);
        const s_queue = [];
        const t_queue = [];
        let intersectNode = -1;

        // Start BFS from the source node 's'. 
        s_queue.push(s);
        s_visited[s] = true;
        s_parent[s] = -1;

        // Start BFS from the target node 't'. 
        t_queue.push(t);
        t_visited[t] = true;
        t_parent[t] = -1;

        // Continue BFS until an intersection is found or both searches are exhausted. 
        while (s_queue.length > 0 && t_queue.length > 0) {
            this.BFS(s_queue, s_visited, s_parent);
            this.BFS(t_queue, t_visited, t_parent);
            intersectNode = this.isIntersecting(s_visited, t_visited);

            if (intersectNode !== -1) {
                console.log(`Path exists between ${s} and ${t}`);
                console.log(`Intersection at: ${intersectNode}`);
                this.printPath(s_parent, t_parent, s, t, intersectNode);
                return;
            }
        }
        console.log(`Path does not exist between ${s} and ${t}`);
    }
}

const n = 15;
const s = 2;
const t = 10;
const graph = new Graph(n);

graph.addEdge(0, 4);
graph.addEdge(1, 4);
graph.addEdge(2, 5);
graph.addEdge(3, 5);
graph.addEdge(4, 6);
graph.addEdge(5, 6);
graph.addEdge(6, 7);
graph.addEdge(7, 8);
graph.addEdge(8, 9);
graph.addEdge(8, 10);
graph.addEdge(9, 11);
graph.addEdge(9, 12);
graph.addEdge(10, 13);
graph.addEdge(10, 14);

g.biDirSearch(s, t); 
