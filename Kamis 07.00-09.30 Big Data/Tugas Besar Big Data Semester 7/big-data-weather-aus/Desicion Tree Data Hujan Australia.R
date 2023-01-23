# clear console
cat("\014")
#D:\\Kampus\\big-data-weather-aus\\weatherAUS.csv

dataset_path = "D:\\Kampus\\big-data-weather-aus\\weatherAUS.csv"
data = read.csv(dataset_path)


# Melihat data
# View(data)

# mengatsi missing value dengan replace by mean value
rawdata=data
for(i in 1:col(rawdata)){
  rawdata[is.na(rawdata[,i]),i] <- mean(rawdata[,i], na.rm=TRUE)
}
# View(data)

# mengatasi missing value dengan menghapus NA
rawdata3=rawdata
rawdata3 <- na.omit(rawdata)
# View(rawdata3)


#Desicion Trees with package rpart
library(dplyr)
rawdata3 <- rawdata3 %>%
  mutate(across(where(is.character), as.factor))



# partition and create training set and testing set
set.seed(1234)
dibagi <- sample(2, nrow(rawdata3), replace=TRUE, prob=c(0.8,0.2))

trainData <- rawdata3[dibagi==1,]
testData <- rawdata3[dibagi==2,]


library(party)
#creating the model
predictor <- RainTomorrow ~ Location + MinTemp + MaxTemp + Rainfall + Evaporation + Sunshine + WindGustDir + WindGustSpeed + WindDir9am + WindDir3pm + WindSpeed9am + WindSpeed3pm + Humidity9am + Humidity3pm + Pressure9am + Pressure3pm + Cloud9am + Cloud3pm + Temp9am + Temp3pm + RainToday

tree <- ctree(predictor, data=trainData)
tree
plot(tree)

# check the prediction
table(predict(tree), trainData$RainTomorrow)

# predict on test data
tree <- ctree(predictor, data=testData)
testPred <- predict(tree, newData=testData)
table(testPred, testData$RainTomorrow)




