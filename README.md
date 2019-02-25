# Manto Kraujelio VU Objektinio programavimo:
## Užduotis: Duomenų apdorojimas

**Dabartinės  Version [0.4.2] panaudojimas. Programa seka ir apskaičiuoja moksleivio sugeneruotų pažymių vidurkį ir medianą:**<br/>
- Pradėjus programa sukūriami 5 failai su šabloniniais vardais: `Vardas1 Pavardė1, Vardas2 Pavardė2 ir t.t.` `kursiokai10.txt, kursiokai100.txt, kursiokai1000.txt, kursiokai10000.txt, kursiokai100000.txt`   <br/>
- Programa suskaičiuoja vidurkį ir medianą, ir išveda rezultatus į surūšiuotūs pagal galutinį (vidurkį) failus, pavadintus `neneaudeliai.txt` , kur išvedami visi su galutiniu pažymiu *<5* , likę išvedami į failą `geriukai.txt`
- Programa į ekraną išveda atlikimo laikus su skirtingais duomenų failais
```bash
Generavimo ir skaičiavimo įvykdimas su 10 studentų užtruko: 0.000614084 s
Generavimo ir skaičiavimo įvykdimas su 100 studentų užtruko: 0.00209874 s
Generavimo ir skaičiavimo įvykdimas su 1000 studentų užtruko: 0.0114821 s
Generavimo ir skaičiavimo įvykdimas su 10000 studentų užtruko: 0.0859467 s
Generavimo ir skaičiavimo įvykdimas su 100000 studentų užtruko: 0.831313 s
```


## Programos naudojimas naudojant `g++` kompiliatorių

- `git clone https://github.com/MantasKr3/vuobj`
- `cd vuobj`
- `g++  functions.cpp apdorojimas.cpp  -o open`
- `./open`

## *Detalesni aprašymai bus pridėti prie kiekvieno realeaso*

## [Version 0.4.2](https://github.com/MantasKr3/vuobj/releases/tag/V.0.4.2)
- Added timer to measure execution time of program
```shell
Programos įvykdimas užtruko: 0.897105 s
```
- Deleted unused libs, refactored to another ```.h``` file - ```apdorojimas.h```


## [Version 0.4](https://github.com/MantasKr3/vuobj/releases/tag/V.0.4)
- Added generating of 5 diffrent input (there's is known issue of same name students results being the same) files :
- `kursiokai10.txt, kursiokai100.txt, kursiokai1000.txt, kursiokai10000.txt, kursiokai100000.txt`
- Added output of sorted students by galutinis (vidurkis) to files: `nenaudeliai.txt` and `geriukai.txt`
- Added ```std::chrono::high_resolution_clock::now() ``` to messure time of program execution
- Disabled some functions of previous versions requirements
- Program ouputs times of execution on display :
```bash
Generavimo ir skaičiavimo įvykdimas su 10 studentų užtruko: 0.000614084 s
Generavimo ir skaičiavimo įvykdimas su 100 studentų užtruko: 0.00209874 s
Generavimo ir skaičiavimo įvykdimas su 1000 studentų užtruko: 0.0114821 s
Generavimo ir skaičiavimo įvykdimas su 10000 studentų užtruko: 0.0859467 s
Generavimo ir skaičiavimo įvykdimas su 100000 studentų užtruko: 0.831313 s
```


## [Version 0.3](https://github.com/MantasKr3/vuobj/releases/tag/V.0.3%26V.0.4)
- Fixed Output
- Refactored program to: 
- `functions.cpp`
- `functions.h`
- `apdorojimas.cpp`
- Used exception handling
```c++
try {} 
catch (std::exception& e) {}
 ```

## [Version 0.2.0 - Version 0.2.1](https://github.com/MantasKr3/vuobj/releases/tag/V.0.2.1)
- Added random student generation
- Added input from text file
- Fixed counting

## [Version 0.1.1](https://github.com/MantasKr3/vuobj/releases/tag/V.0.1.1)
- Fixed count function
- Added sorting
- Added structs

## [Version 0.1](https://github.com/MantasKr3/vuobj/releases/tag/V.0.1)
- Initial upload


