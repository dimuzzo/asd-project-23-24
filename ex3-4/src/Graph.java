import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.LinkedList;
import java.util.Collection;

public class Graph<V, L> implements AbstractGraph<V, L> {
    private boolean directed;
    private boolean labelled;
    private HashMap<V, LinkedList<Edge<V, L>>> adjacentArch;

    public Graph(boolean directed, boolean labelled) {
        this.directed = directed;
        this.labelled = labelled;
        this.adjacentArch = new HashMap<>();
    }

    @Override
    public boolean isDirected() {
        return directed;
    }

    @Override
    public boolean isLabelled() {
        return labelled;
    }

    @Override
    public boolean addNode(V a) {
        if (containsNode(a)) {
            return false;
        }
        adjacentArch.put(a, new LinkedList<>());
        return true;
    }

    @Override
    public boolean addEdge(V a, V b, L l){
        if(containsEdge(a, b)){
            return false;
        }
        if(!labelled){
            l = null;
        }
        adjacentArch.get(a).add(new Edge<>(a, b, l));
        if(!directed){
            adjacentArch.get(b).add(new Edge<>(b, a, l));
        }
        return true;
    }

    @Override
    public boolean containsNode(V a){
        return adjacentArch.containsKey(a);
    }

    @Override
    public boolean containsEdge(V a, V b){
        return findEdge(a, b) != null;
    }

    @Override
    public boolean removeNode(V a){
        if(!containsNode(a)){
            return false;
        }
        for(V node : getNodes()){
            removeEdge(node, a);
        }
        adjacentArch.remove(a);
        return true;
    }

    @Override
    public boolean removeEdge(V a, V b){
        if(!containsEdge(a, b)){
            return false;
        }
        else{
            Edge<V, L> edge = findEdge(a, b);
            adjacentArch.get(a).remove(edge);
            if(!directed){
                Edge<V, L> revEdge = findEdge(b, a);
                adjacentArch.get(b).remove(revEdge);
            }
            return true;
        }
    }

    @Override
    public int numNodes(){
        return adjacentArch.size();
    }

    @Override
    public int numEdges(){
        int edgeCount = 0;
        for(V neighbourNode : adjacentArch.keySet()){
            edgeCount += getNeighbours(neighbourNode).size();
        }
        return directed ? edgeCount : (edgeCount / 2);
    }

    @Override
    public Collection<V> getNodes(){
        return new HashSet<>(adjacentArch.keySet());
    }

    @Override
    public HashSet<Edge<V, L>> getEdges(){
        HashSet<Edge<V, L>> edges = new HashSet<>();
        for(List<Edge<V, L>> edgeList : adjacentArch.values()){
            edges.addAll(edgeList);
        }
        return edges;
    }

    @Override
    public Collection<V> getNeighbours(V a){
        LinkedList<V> neighbours = new LinkedList<>();
        if(containsNode(a)){
            for(Edge<V, L> edge : adjacentArch.get(a)){
                neighbours.add(edge.getEnd());
            }
        }
        return neighbours;
    }

    @Override
    public L getLabel(V a, V b){
        Edge<V, L> edge = findEdge(a, b);
        return (edge != null) ? edge.getLabel() : null;
    }

    private Edge<V, L> findEdge(V a, V b){
        if(containsNode(a)){
            for(Edge<V, L> edge : adjacentArch.get(a)){
                if(edge.getEnd().equals(b)){
                    return edge;
                }
            }
        }
        return null;
    }
}