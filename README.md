# Hash generatoriaus kūrimas
## Maišos funkcijos idėja Pseudo-kodo stiliumi

<img width="500" alt="Drawing 1" src="https://github.com/user-attachments/assets/d4802077-dbc0-40d2-806e-14f51df31e41">

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

### Patikrinti ar funkcijai atitinka reikalavimai

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

