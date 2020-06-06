class Edge {
public:
	Edge(int v1, int v2, bool directed, bool weighted, double weight = -1);

	int getV1() const;
	int getV2() const;
private:
	int v1;
	int v2;

	double weight;

	bool directed;
	bool weighted;
};
