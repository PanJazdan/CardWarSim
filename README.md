Projekt terminalowej symulacji karcianej gry w wojne.

<h2>Zasady</h2>
Jest dwóch graczy, każdy początkowo ma taką samą ilość kart, ale wartości są dobierane pseudolosowo.
Zbiór wartości jest od 2 do 14.
Wojna jest podzielona na bitwy. 
Jedna bitwa to pojedynczy ruch gracza.

Ruch polega na wyłożeniu karty z wierzchu swojej talii i porównaniu jej z wyłożoną, w tym samym czasie, kartą przeciwnika. 

Ta która ma większą wartość wygrywa i jej właściciel zabiera obie wyłożone na spód swojej talii.

Jeśli jest remis gracze wykładają dwie kolejne i dopiero porównywana jest trzecia z nich(bo na stole każdego graczy leżą po trzy karty). W przypadku dalszego remisu trzeciej karty, sprawdzana jest druga wyłożona. Gdy druga remisuje, cały proces remisu powtarzany jest aż do roztrzygnięcia bitwy i wszystkie karty, które brały udział w bitwie lądują na spodzie talii zwycięzcy.

Gdy, któryś z graczy straci wszystkie karty, gra się kończy i wygrywa gracz, która ma wszystkie karty.

<h1>Dokumentacja</h1>
    <h2>Klasy i obiekty</h2>

<h3>Card</h3>

Klasa Card jest implementacją karty.
Card posiada wartość i zna kartę następującą i poprzedzającą za pomocą wskaźników.

Można ustawić i pobrać jej wartość i sąsiadów.

<h3>Player</h3>

Klasa Player to implementacja gracza.
Player zna ilość kart w ręce i wie jaka jest pierwsza i ostatnia karta.

Player posiada opcję wypisania swojej talii za pomocą *print_player()*.
Przełożenia danej karty na spód talii - *move_card_at_end(Card\*card)*.
I zmiany pierwszej karty w ręce - *first_change()*. 

<h3>Main</h3>

Plik Main zawiera przebieg gry. Zaimplementowany jest system walki *bool walcz(Player &gracz1,Player &gracz2,int level)*. Walka trwa dopóki zwraca wartość *true*.

Przed rozpoczęciem wojny talia jest tasowana i rozdawana równo po połowie graczom.

<h2>Uwagi</h2>
Aktualnie wysłana wersja posiada zakomentowane wypisywanie talii graczy i symuluje 200 gier w celu zwizualizowania statystyk. Statystyki są zapisywane w pliku **dane.txt**. 
Mozna tam zobaczyć dla każdej rozgrywki ile trwała rund(bitew) jaka była średnia wartość kart obu graczy i który z graczy wygrał. Na końcu pliku jest zapisana średnia ilość rund 200 rozgrywkach ile średnio każdy z graczy wygrał i jaka była średnia średnich wartości początkowych każdego z graczy.

