public class Edge<V, L> implements AbstractEdge<V, L> {
    private V start; // Starting node
    private V end;   // Ending node
    private L label; // Label for the edge between the two nodes

    public Edge(V start, V end, L label) {
        this.start = start;
        this.end = end;
        this.label = label;
    }

    @Override
    public V getStart() {
        return this.start;
    }
    @Override
    public V getEnd() {
        return this.end;
    }
    @Override
    public L getLabel() {
        return this.label;
    }
}