# Nume proiect: Fast Food Smart

Scurtă descriere: 🍔 Fast Food Smart este un proiect C++ conceput pentru a simula un sistem modern de comandă într-un restaurant de tip fast-food, dar cu un accent puternic pe sănătate și personalizare.
🔑 Funcționalități principale
- Autentificare utilizatori
Clienții își pot crea conturi și se pot loga pentru a accesa meniul personalizat.
- Comandă inteligentă
Sistemul permite selectarea produselor dorite, dar le adaptează automat în funcție de preferințele și nevoile fiecărui client (ex. reducerea grăsimilor, opțiuni fără zahăr, porții echilibrate).
- Procesare sănătoasă a alimentelor
Algoritmul din spate ajustează rețetele pentru a menține gustul, dar să fie mai nutritive și mai potrivite pentru un stil de viață sănătos.
- Interfață modulară
Codul este organizat pe clase (produse, utilizatori, comenzi), ceea ce permite extinderea ușoară cu noi tipuri de mâncare sau funcționalități.
- Experiență personalizată
Fiecare client primește recomandări bazate pe istoricul comenzilor și preferințele salvate.
🎯 Obiectiv
Proiectul îmbină rapiditatea și comoditatea fast-food-ului cu principiile alimentației sănătoase, oferind o experiență digitală prietenoasă și adaptată fiecărui utilizator

## Instrucțiuni de compilare
- Configurare:
  - Linux/macOS/MSVC: `cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug`
  - Windows GCC + Ninja: `cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug -G Ninja`
- Build: `cmake --build build --config Debug --parallel 6`
- Install (opțional): `cmake --install build --config Debug --prefix install_dir`
- Rulează: `./build/oop` sau `./install_dir/bin/oop`

## Cerințe și conformitate
- C++ (fără variabile globale, membri private/protected)
- Meniu interactiv în `main.cpp`
- Separare .hpp/.cpp
- GitHub Actions: build & run (fără erori)
- Operatorii: `<<`, `>>`, `=`, alți operatori membru + non-membru
- Ierarhii: min. 2-3, cu upcast/downcast și destructor virtual
- Excepții: bază std::exception, propagare și upcasting în catch
- Template: 1 clasă, 2 instanțieri
- STL: 2 containere + 1 algoritm cu lambda
- Design Patterns: 2 (ex. Factory + Strategy)

## Date de intrare
- Interactiv: `tastatura.txt` (exemple)
- Fișiere externe: `data/*.txt` (unde e cazul)

## Resurse
- Linkuri și note despre materialele folosite.

* În general, acestea sunt prezente în [CppCoreGuideline](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md), dar nu e nevoie să parcurgeți documentul, doar să scrieți codul suficient de organizat

* folderele `build/` și `install_dir/` sunt adăugate în fișierul `.gitignore` deoarece
conțin fișiere generate și nu ne ajută să le versionăm.
