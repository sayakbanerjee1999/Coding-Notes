import numpy as np

def kmeans_plus_plus(X, k, max_iters=100, tol=1e-4):
    # 1. K-Means++ initialization
    centroids = [X[np.random.randint(0, X.shape[0])]]

    for _ in range(k - 1):
        distances = np.array([
            min(np.linalg.norm(x - c) ** 2 for c in centroids)
            for x in X
        ])
        probs = distances / distances.sum()
        centroids.append(X[np.random.choice(X.shape[0], p=probs)])

    centroids = np.array(centroids)


    # 2. Random Initialization (Take k indices from X points)
    indices = np.random.choice(X.shape[0], k, replace=False)
    centroids = X[indices]

    for _ in range(max_iters):
        # 2. Assign clusters
        distances = np.zeros((X.shape[0], k))
        for j in range(k):
            distances[:, j] = np.linalg.norm(X - centroids[j], axis=1)
        labels = np.argmin(distances, axis=1)

        # 3. Recompute centroids
        new_centroids = np.zeros((k, X.shape[1]))      # k centroids with dimension(k, m) where X dimension - (n, m)
        for j in range(k):
            # Collect all points which belong to a particular label
            members = X[labels == j]
            if len(members) > 0:
                new_centroids[j] = members.mean(axis=0)

        # 4. Convergence check
        if np.linalg.norm(new_centroids - centroids) < tol:
            break

        centroids = new_centroids

    return labels, centroids
