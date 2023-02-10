
// n = suku ke
// a = awal
// b = beda 

const beda = (n1, n2) => n2-n1;

// n(n+1)/2
// 1+2+3+4+5+6+7 ... 29 = ...
const deret_bilangan = n => (n*(n+1))/2;
console.log(deret_bilangan(29));

// menentukan suku ke n
// Tentukan suku ke 10 dari deret angka 6, 9, 12, 15, 18, ....
const suku_ke_n = (n,a,b)=> a + ((n-1)*b);
console.log(suku_ke_n(10,6,3));

// Hitunglah 10 suku pertama dari deret angka 6, 9, 12, 15, 18, ....
const sn = (n,a,b)=>(n/2)*((2*a) + ((n-1)*b));
console.log(sn(2,6,3));