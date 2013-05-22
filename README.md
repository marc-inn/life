# eLife
Let's play game for life!

# Sposób działania

## Klient

x Na początku przesyła dane do serwera o
	
	x liczbie początkowej populacji i wysyła indentyfikatory początkowej populacji
	x szybkości przesyłania elementów?
	
x wyświetla na bieżąco wyniki które dostał od serwera

	x ja
	
## Serwer



## Strategia:

x Co może być tu abstrakcyjnego?

	x abstrakcja strategii, która będzie służyła obiektom do przetrwania
	x abstrakcja obiektu-zwierzaka, z jego podstawowymi cechami i funkcjami
	x abstrakcja planszy, którą łatwo można przeprogramować na inne systemy i biblioteki
	
x Propozycje funkcji życiowych:

	x podstawowe potrzeby życiowe wg. Maslowa, piramida potrzeb	
	x sex, potrzeba utrzymania gatunku
	x jedzenie
	x picie
	x spanie

x Jak kształcić cechy u nowych osobnikóœ?

	x kod DNA
	x dziedziczenie różnych recesywnych i dominujących cech

x Jak działają funkcje życiowe

	x gdy niski poziom wody w obiekcie
		x uruchamiamy szukajWodę()?
			x potem rozpaczliwieSzukajWodę()?

x Jak świat wpływa na obiekty?
	
	x różne środowisko = różne wychowanie
	x odległość od wody = mniejsza szansa na przetrwanie?

x Rodzaje środowisk

	x mapa różnych środowisk
	x pustynia
	x dżungla
	x knieje
	x góry
	x step
	x mazury
	x coś tam innego

x Jak pogrupować obiekty?

	x roślinożercy i mięsożercy
 	x ułożyć specjalną hierarchię członków gatunku
	x lista klanów? 
		x na jej czele głowy klanów
		x najstarsi, członkowie klanu
		x poniżej członkowie rodu niżsi i w jakichś sposób pogrupowani
		
x Rozdzielanie strategii:

	x gra podzielona na kilka trybów generujących różne zachowania populacji
		x teoria Darwina
		x teoria Mendela
		x chromosomy
		x kod DNA
		

x Mutacje?
	
	x blisko spokrewnione klany mogą generować zmodyfikowane dziecka
	x kopulacja dwóch różnych gatunków powoduje stworzenie muła?

## Klasy
### Związane z obsługą interfejsu na różnych systemach

* `Okno`
* `Wzorzec`
	* Most?
	
### Związane z tworzeniem mapy

* `Mapa`
	* 
* `Wzorzec`
	* Budowniczy?
	
### Związane z tworzeniem obiektów na mapie

* `Zwierzak`
	* klasa abstrakcyjna, interfejs
* `ZwierzakRoslinozerca : Zwierzak`
	* na jej podstawie tworzone będą nowe klony roślinożernych zwierzątek
* `Wzorzec:` 
	* Prototyp
		* Służy do tworzenia nowych obiektów w czasie rzeczywistym
