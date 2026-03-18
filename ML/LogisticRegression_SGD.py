import numpy as np

def sigmoid(z):
    return 1 / (1 + np.exp(-z))

def logistic_regression_sgd(X, y, lr=0.01, epochs=100, batch_size=32):
    n_samples, n_features = X.shape

    W = np.zeros(n_features)
    b = 0.0

    epoch_losses = []

    for epoch in range(epochs):
        indices = np.random.permutation(n_samples)
        X_shuffled = X[indices]
        y_shuffled = y[indices]

        batch_losses = []

        for start in range(0, n_samples, batch_size):
            X_batch = X_shuffled[start : start + batch_size]
            y_batch = y_shuffled[start : start + batch_size]

            # 1. Forward pass: sigmoid instead of identity
            logits = X_batch @ W + b
            y_pred = sigmoid(logits)             # (batch,) in (0, 1)

            # 2. Binary cross-entropy loss
            batch_loss = -np.mean(
                y_batch * np.log(y_pred + 1e-9) +
                (1 - y_batch) * np.log(1 - y_pred + 1e-9)
            )
            batch_losses.append(batch_loss)

            # 3. Gradients (same form as linear regression)
            residuals = y_pred - y_batch         # (batch,)
            dW = (X_batch.T @ residuals) / len(X_batch)
            db = residuals.mean()

            W -= lr * dW
            b -= lr * db

        epoch_loss = np.mean(batch_losses)
        epoch_losses.append(epoch_loss)

        if (epoch + 1) % 10 == 0:
            print(f"Epoch {epoch+1}/{epochs}  BCE: {epoch_loss:.4f}")

    return W, b, epoch_losses


def predict(X, W, b, threshold=0.5):
    return (sigmoid(X @ W + b) >= threshold).astype(int)
