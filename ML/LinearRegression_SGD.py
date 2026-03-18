import numpy as np

def linear_regression_sgd(X, y, lr=0.01, epochs=100, batch_size=32):
    n_samples, n_features = X.shape
    
    W = np.zeros(n_features)
    b = 0.0
    
    epoch_losses = []

    for epoch in range(epochs):
        indices = np.random.permutation(n_samples)
        X_shuffled = X[indices]
        y_shuffled = y[indices]

        batch_losses = []  # collect loss for each mini-batch

        for start in range(0, n_samples, batch_size):
            X_batch = X_shuffled[start : start + batch_size]
            y_batch = y_shuffled[start : start + batch_size]

            y_pred = X_batch @ W + b

            residuals = y_pred - y_batch
            batch_loss = np.mean(residuals ** 2)  # MSE for this mini-batch
            batch_losses.append(batch_loss)

            dW = (X_batch.T @ residuals) / len(X_batch)
            db = residuals.mean()

            W -= lr * dW
            b -= lr * db

        # Epoch loss = mean of all mini-batch losses
        epoch_loss = np.mean(batch_losses)
        epoch_losses.append(epoch_loss)

        if (epoch + 1) % 10 == 0:
            print(f"Epoch {epoch+1}/{epochs}  MSE: {epoch_loss:.4f}")

    return W, b, epoch_losses




# Closed Form Solution 
# theta = (X  T X)^-1 X.T y
import numpy as np
def linear_regression_normal_equation(X: list[list[float]], y: list[float]) -> list[float]:
    # Your code here, make sure to round
    X = np.asarray(X)
    y = np.asarray(y)

    invX = np.linalg.inv(np.dot(X.T, X))
    forward = np.dot(X.T, y)
    
    theta = np.round(np.dot(invX, forward), 4)
