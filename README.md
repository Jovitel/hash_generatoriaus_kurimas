# Hash generatoriaus kūrimas V0.1
## Maišos funkcijos idėja Pseudo-kodo stiliumi

<img width="501" alt="Drawing 1 (1)" src="https://github.com/user-attachments/assets/4e07d654-c502-460b-bd08-c96a846aae6b">

## Programos veikimas:

Galimi pasirinkimai:

1 - įvesti simbolius

2 - atidaryti failus, sudarytus tik iš vieno, bet skirtingo simbolio.

3 - atidaryti failus, sudarytus iš daug (> 1000) atsitiktinai sugeneruotų simbolių.

4 - atidaryti failus, sudarytus iš daug (> 1000) simbolių, bet besiskiriančių vienas nuo kito tik vienu simboliu.

5 - atidaryti tuščią failą.

6 - BAIGTI DARBĄ.

## Ekspermentinis tyrimas ir rezultatų analizė

### Sukurti reikiamus failus

Bent du failai būtų sudaryti tik iš vieno, tačiau skirtingo, simbolio. **vienas_a.txt ir vienas_b.txt**

Bent du failai būtų sudaryti iš daug (> 1000) atsitiktinai sugeneruotų simbolių. **random_input_1.txt ir random_input_2.txt**

Bent du failai būtų sudaryti iš daug (> 1000) simbolių,
bet skirtųsi vienas nuo kito tik vienu (pvz. vidurinėje pozicijoje esančiu) simboliu. **1_random_input_symbol.txt ir 2_random_input_symbol.txt**

Tuščio failo. **tuscias.txt**

### 1. Patikrinti ar funkcijai atitinka reikalavimai

1. Maišos funkcijos įėjimas (angl. input) gali būti bet kokio dydžio simbolių eilutė (angl.string).
   
2. Maišos funkcijos išėjimas (angl. output) visuomet yra to paties, fiksuoto, dydžio rezultatas
(pageidautina 256 bit'ų ilgio, t.y., 64 simbolių hex'as).

*Palyginsiu failų, kuriuos sudaro skirtingas kiekis simbolių (vienas_a.txt ir random_input_1.txt) rezultatus*

*vienas_a.txt output*

```
Original string (vienas_a.txt): aaaaaaaa
Hash: 6161616161616161626364656667686962636465666768696263646566676869
```

*random_input_1.txt output*

```
Hash: 7f7b85bb9681a5a19da89a98a49ca18c81b1a89e92c98caaa4a39aa4a793836b
```

**Rezultatas**

Nesvarbu, kokio dydžio inputas, outputas visada 64 simbolių dydžio.

3. Maišos funkcija yra deterministinė, t. y., tam pačiam įvedimui (input'ui) išvedimas (output'as) visuomet yra tas pats.

*Pati du kartus įrašysiu žodį "Lietuva"*

*Pirmas kartas*

```
Original string: Lietuva
Hash: 4c6965747576614d6b68787a62684d6b68787a62684d6b68787a62684d6b6878
```

*Antras kartas*

```
Original string: Lietuva
Hash: 4c6965747576614d6b68787a62684d6b68787a62684d6b68787a62684d6b6878
```

**Rezultatas**

Funkcija yra deterministinė

### 2. Hash apskaičiavimo laikas

*Naudojau konstitucija.txt (PATAISIAU)*

| Simbolių skaičius | 1000   | 2000   | 3000   | 4000  |
|-------------------|--------|--------|--------|-------|
| Laikas (ms)       | 3.0767 | 4.1196 | 2.2999 | 4.452 |


**Rezultatas**

Naudojant didesni kiekį simbolių, laikas irgi didėja. Bandysiu patobulinti efektyvumą.

### 3.  Iš hash funkcijos rezultato (output'o) praktiškai neįmanoma atgaminti pradinio įvedimo (input'o).

**Rezultatas**

Iš anksčiau matytų output'ų ir input'ų galima teigti, jog jie nėra susiję, tačiau reikia didinti Lavinos efektą.

### 4. Lavinos efektas (angl. Avalanche effect)

```
Original string: lietuva
Hash: 6c6965747576616d6b68787a62686d6b68787a62686d6b68787a62686d6b6878
```

```
Original string: Lietuva
Hash: 4c6965747576614d6b68787a62684d6b68787a62684d6b68787a62684d6b6878
```

```
Original string: Lietuva!
Hash: 4c696574757661214d6b68787a6268214d6b68787a6268214d6b68787a626821
```

**Rezultatas**

Hash kodai turi tam tikrų panašumų, tačiau nėra visiškai vienodi. Reikės patobulinti kodo išsiskyrimą.

# Hash generatoriaus kūrimas V0.2

## Maišos funkcijos idėja Pseudo-kodo stiliumi

<img width="500" alt="Drawing 1 (2)" src="https://github.com/user-attachments/assets/db7f9e75-2401-4132-b152-547b13738b33">

Pakeistas kodas į racionalesnį, nėra toks painus.

## Programos veikimas:

Galimi pasirinkimai:

1 - įvesti simbolius

2 - atidaryti failus, sudarytus tik iš vieno, bet skirtingo simbolio.

3 - atidaryti failus, sudarytus iš daug (> 1000) atsitiktinai sugeneruotų simbolių.

4 - atidaryti failus, sudarytus iš daug (> 1000) simbolių, bet besiskiriančių vienas nuo kito tik vienu simboliu.

5 - atidaryti tuščią failą.

6 - BAIGTI DARBĄ.

## Ekspermentinis tyrimas ir rezultatų analizė

### Sukurti reikiamus failus

Bent du failai būtų sudaryti tik iš vieno, tačiau skirtingo, simbolio. **vienas_a.txt ir vienas_b.txt**

Bent du failai būtų sudaryti iš daug (> 1000) atsitiktinai sugeneruotų simbolių. **random_input_1.txt ir random_input_2.txt**

Bent du failai būtų sudaryti iš daug (> 1000) simbolių,
bet skirtųsi vienas nuo kito tik vienu (pvz. vidurinėje pozicijoje esančiu) simboliu. **1_random_input_symbol.txt ir 2_random_input_symbol.txt**

Tuščio failo. **tuscias.txt**

### 1. Patikrinti ar funkcijai atitinka reikalavimai

1. Maišos funkcijos įėjimas (angl. input) gali būti bet kokio dydžio simbolių eilutė (angl.string).
   
2. Maišos funkcijos išėjimas (angl. output) visuomet yra to paties, fiksuoto, dydžio rezultatas
(pageidautina 256 bit'ų ilgio, t.y., 64 simbolių hex'as).

*Palyginsiu failų, kuriuos sudaro skirtingas kiekis simbolių (vienas_a.txt ir random_input_1.txt) rezultatus*

*vienas_a.txt output*

```
Original string (vienas_a.txt): aaaaaaaa
Hash: W1616W6161W1616W6263W4656W6768W9626W6465W6676W6962W3646W6667W869
```

*random_input_1.txt output*

```
Hash: 7f7b85bb9681a5a19da89a98a49ca18c81b1a89e92c98caaa4a39aa4a793836b
```

**Rezultatas**

Nesvarbu, kokio dydžio inputas, outputas visada 64 simbolių dydžio.

3. Maišos funkcija yra deterministinė, t. y., tam pačiam įvedimui (input'ui) išvedimas (output'as) visuomet yra tas pats.

*Pati du kartus įrašysiu žodį "Lietuva"*

*Pirmas kartas*

```
Original string: Lietuva
Hash: 4c6965747576614d6b68787a62684d6b68787a62684d6b68787a62684d6b6878
```

*Antras kartas*

```
Original string: Lietuva
Hash: 4c6965747576614d6b68787a62684d6b68787a62684d6b68787a62684d6b6878
```

**Rezultatas**

Funkcija yra deterministinė

### 2. Hash apskaičiavimo laikas

(V0.1 versijos testavime, panaudojau ne konstitucija.txt failą, 
todėl sulyginau naudotų simbolių skaičių su eilučių skaičiumi, jog būtų galima palyginti ir
V0.2 atlikau tinkamai)

*Naudojau failą konstitucija.txt *
| Simbolių skaičius ~         |         |        |  1000  |  2000  | 3000  |       | 4000  |       |
|-----------------------------|---------|--------|--------|--------|-------|-------|-------|-------|
| Eilučių skaičius            | 1       |    8   |   16   |   32   |   53  |   64  |   76  |  128  |
|-----------------------------|---------|--------|--------|--------|-------|-------|-------|-------|
| Vidutinis laikas (ms)       |1.21928  |2.93526 |2.13968 |4.06148 |1.33172|3.08026|3.40688|27.8968|

![Ekrano kopija (421)](https://github.com/user-attachments/assets/eadd5f32-77e6-4864-8859-26f3f6fd9ceb)


**Rezultatas**

Naudojant didesni kiekį simbolių, laikas irgi didėja, bet palyginus su V0.1 laikas geresnis V0.2.

### 3.  Iš hash funkcijos rezultato (output'o) praktiškai neįmanoma atgaminti pradinio įvedimo (input'o). Kolizija.

*Sukūriau funkcijas, kurios sukuria atsitiktinių simbolių eilučių failus ir patikrina, ar yra kolizija*

*25 000 porų, po 10 simbolių*

```
Iveskite norimu poru skaiciu: 25000
Iveskite simboliu ilgi: 10
Hash sukurimo laikas: 0.0508 ms
Hash sukurimo laikas: 0.16 ms
Hash sukurimo laikas: 0.0684 ms
Nera hash koliziju.
```

*25 000 porų, po 100 simbolių*


```
Iveskite norimu poru skaiciu: 25000
Iveskite simboliu ilgi: 100
Hash sukurimo laikas: 0.0661 ms
Hash sukurimo laikas: 0.0534 ms
Hash sukurimo laikas: 0.1095 ms
Nera hash koliziju.
```

*25 000 porų, po 500 simbolių*

```
Iveskite norimu poru skaiciu: 25000
Iveskite simboliu ilgi: 500
Hash sukurimo laikas: 0.049 ms
Hash sukurimo laikas: 0.0398 ms
Hash sukurimo laikas: 0.0288 ms
Nera hash koliziju.
```

*25 000 porų, po 1000 simbolių*

```
Iveskite norimu poru skaiciu: 25000
Iveskite simboliu ilgi: 1000
Hash sukurimo laikas: 0.0465 ms
Hash sukurimo laikas: 0.0257 ms
Hash sukurimo laikas: 0.0446 ms
Nera hash koliziju.
```

**Rezultatas**

Galima teigti, jog kolizijos nėra.

### 4. Lavinos efektas (angl. Avalanche effect)

```
Original string: lietuva
Hash: 6c6965747576616d6b68787a62686d6b68787a62686d6b68787a62686d6b6878
```

```
Original string: Lietuva
Hash: 4c6965747576614d6b68787a62684d6b68787a62684d6b68787a62684d6b6878
```

```
Original string: Lietuva!
Hash: 4c696574757661214d6b68787a6268214d6b68787a6268214d6b68787a626821
```

**Rezultatas**

Hash kodai turi tam tikrų panašumų, tačiau nėra visiškai vienodi. Reikės patobulinti kodo išsiskyrimą.
