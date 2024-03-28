import pandas as pd
import statsmodels.api as sm

# Read data from Excel file
data = pd.read_excel("data.xlsx")

# Separate independent variables (X) and dependent variable (Y)
X = data[['X1', 'X2']]
Y = data['Y']

# Add constant term for intercept
X = sm.add_constant(X)

# Create and fit the regression model
model = sm.OLS(Y, X).fit()

# Print the model summary
print(model.summary())

# Calculate SST (Total Sum of Squares)
y_mean = Y.mean()
SST = ((Y - y_mean) ** 2).sum()

# Calculate SSR (Regression Sum of Squares)
SSR = ((model.predict(X) - y_mean) ** 2).sum()

# Calculate SSE (Error Sum of Squares)
SSE = ((Y - model.predict(X)) ** 2).sum()

# Calculate R-squared
R_squared = SSR / SST

# Calculate MSR (Mean Regression Sum of Squares)
MSR = SSR / model.df_model

# Calculate MSE (Mean Error Sum of Squares)
MSE = SSE / model.df_resid

# Print calculated values
print("SST:", SST)
print("SSR:", SSR)
print("SSE:", SSE)
print("R^2:", R_squared)
print("MSR:", MSR)
print("MSE:", MSE)

# Print model equation
print("Model Equation:")
print("Y = {:.2f} + {:.2f}*X1 + {:.2f}*X2".format(model.params[0], model.params[1], model.params[2]))
