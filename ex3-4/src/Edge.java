public class Edge<V, L> implements AbstractEdge<V, L> {
    private V start; // vertice iniziale
    private V end;   // vertice finale
    private L label; // etichetta per indicare l'arco

    public Edge(V start, V end, L label) {
        this.start = start;
        this.end = end;
        this.label = label;
    }

    @Override
    public V getStart() {
        return start;
    }
    @Override
    public V getEnd() {
        return end;
    }
    @Override
    public L getLabel() {
        return label;
    }
}
