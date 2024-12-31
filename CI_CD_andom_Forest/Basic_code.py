import pandas as pd
from sklearn.preprocessing import OneHotEncoder
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error

data = pd.read_csv("Housing_Data.csv")

encoder = OneHotEncoder(sparse_output=False)

encoded_column = encoder.fit_transform(data[['column_name']])

encoded_df = pd.DataFrame(encoded_column, columns=encoder.categories_[0])

data = data.drop('column_name', axis=1)
data = pd.concat([data, encoded_df], axis=1)

# Chia dữ liệu thành training và testing set
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Tạo mô hình Linear Regression và huấn luyện
model = LinearRegression()
model.fit(X_train, y_train)

# Dự đoán và đánh giá mô hình
y_pred = model.predict(X_test)
mse = mean_squared_error(y_test, y_pred)

# In kết quả
print("Mean Squared Error:", mse)

