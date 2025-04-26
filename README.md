# OOP-CPP
Repository for øvinger og lingnende i TDT4102.

Kommer til å legge ut alle øvingene i dette repoet i hver sin mappe, men koden vil ikke være særlig brukbar utenfor et environment med TDT4102 extensionen installert.

## Eksamensrelaterte notater:
Dette blir en slags huskeliste over grunnleggende informasjon i C++.

### Typekonvertering:
| Fra type:  | Til type: | Funksjon: | Forklaring/kommentar | 
| ------------- | ------------- | -------------| -------------|
| String (char*)  | int  | atoi(variabel) | ASCII To Integer |
| int  | String (char*)  | itoa(variabel)  | Integer To ASCII |
| ASCII  | Float  | atof(variabel)  | ASCII To Float |
| int, float, double etc.  | String (char*)  | std::tostring(variabel)  | Fra std namespace |
| ASCII  | Float  | atof(variabel)  | ASCII To Float |
| enum  | int  | static_cast<int>(c)  | enum til int, når det gjelder static_cast bør det bare brukes dersom du vet at objektet faktisk kan endres|
| void* | int, float, double etc. | static_cast<int>(ptr) | Setter void-peker til spesifikk type, ettersom void-pekere ikke har en type |






### Stack vs. heap minne:

| Stack  | Heap |
| ------------- | ------------- |
| Stack allokeres under kjøretid, men størrelsen til hver stack "frame" er bestemt under kompilering | Heap allokeres dynamisk under kjøretid |
| Minne er kun tilgjengelig mens funksjonen kjører, minnet deallokeres automatisk (når en funksjon er ferdig) | Heap minnet eksisterer så lenge programmet kjører, minnet må frigjøres manuelt |
| Ved overflyt: gir feilmelding "segmentation fault"  | Kan gi mange forskjellige feilmeldinger ved overflyt (eller ingen i det hele tatt), ettersom C++ ikke har en garbage collector er dette vanskelig å oppdage, vanligste feilen er minnelekkasje og dette kan være vanskelig å oppdage |
|Raskt, på grunn av automatisk minnehåndtering | Tregere, hovedsaklig på grunn av manuell deallokering |
| Tryggere en heap, pga. data er kun tilgjengelig for eieren av tråden | Mindre trygt når det kommer til tråder |




