# Kelompok:
# 1. Isep lutpi nur (2113191079)
# 2. Farhan azis (2113191097)
# 3. M. Taufiq hidayatuloh (2113191036)
# 4. Dara atria ferliandini (2113191098)
# Repository Project: https://github.com/iseplutpinur/tugas_besar_big_data_semester7

# clear console
cat("\014")

# Eksplorasi Data ==============================================================
titanic = read.csv('D:\\Kampus\\Tugas Besar Big Data Semester 7\\big data titanic\\titanic.csv')
dim(titanic) # Dimensi data
head(titanic) # data paling atas
tail(titanic) # data paling bawah
str(titanic) # strukutr data
summary(titanic) # ringkasan data

# mengubah label klasifikasi
titanic$Survived = factor(titanic$Survived, labels=c("died", "survived"))

# Visualisasi Data =============================================================
# Distribusi class mengunakan pie chart
survivedTable = table(titanic$Survived)
survivedTable
par(mar = c(0, 0, 0, 0), oma = c(0, 0, 0, 0))
pie(survivedTable,labels=c("Died","Survived"))


# Perbandingan korban berdasarkan jenis kelamin menggunakan pie chart
male = titanic[titanic$Sex=="male",]

female = titanic[titanic$Sex=="female",]

par(mfrow = c(1, 2), mar = c(0, 0, 2, 0), oma = c(0, 1, 0, 1))
pie(table(male$Survived),labels=c("Dead","Survived"),  main="Perbandingan Korban Penumpang Pria")
pie(table(female$Survived),labels=c("Dead","Survived"), main="Perbandingan Korban Penumpang Wanita")




