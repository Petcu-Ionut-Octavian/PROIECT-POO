# Nume proiect: Sistem de gestiune roboți modulari

Scurtă descriere: Aplicație C++ cu ierarhii de clase pentru roboți terestri/aerieni, senzori și misiuni. Demonstrează compunere, moștenire, upcasting/downcasting, excepții, template-uri, STL, și 2 design patterns.

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
