import numpy as np
from collections import Counter

def knn_predict(X_train, y_train, X_test, k=3):
    predictions = []
    
    for test_point in X_test:
        # 1. Compute distances from test point to all training points
        distances = np.sqrt(np.sum((X_train - test_point) ** 2, axis=1))
        
        # 2. Get indices of k nearest neighbors
        k_indices = np.argsort(distances)[:k]
        
        # 3. Get labels of k nearest neighbors
        k_labels = y_train[k_indices]
        
        # 4. Majority vote (Find the most common class in the k_labels)
        # most_common = Counter(k_labels).most_common(1)[0][0]
        # predictions.append(most_common)
        votes = defaultdict(int)
        for label in k_labels:
            votes[label] += 1
        
        most_common = max(votes, key=lambda label: votes[label])
        predictions.append(most_common)
    
    return np.array(predictions)
