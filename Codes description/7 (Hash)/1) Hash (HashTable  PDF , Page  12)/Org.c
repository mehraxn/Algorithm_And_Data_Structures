int hash(float k, int M, float s, float t) {
    return (int)(((k - s) / (t - s)) * M);
}
