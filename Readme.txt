			Tema3 - Procedural City
			Lidia Istrate 335CC


	Pentru genera o structura random a orasului , voi genera pozitii random pentru intersectiile dintre strazi.
	Orasul este cuprins intre limitele -24.5f si 24.5f atat pe ox cat si pe oz , astfel generez 2 vectori cu valori 
de x si z intre aceste limite .
	Apoi asamblez matricea de intersectii folosind vectorul de x si z , intersectiile vor fi astfel incepand din capatul 
(-24.5f, -24.5f) pana la (24.5f , 24.5f).
	
	Pun textura de iarba pe toata suprafata orasului , iar intre intersectii folosesc functia 

	void drawStreetBetween(Intersection p1, Intersection p2) :

		Daca intersectiile au acelasi x , desenez un dreptunghi scalat cu glm::vec3(1.0f, 1.0f, abs(p1.z - p2.z) - 1 ).
		Daca intersectiile au acelasi z , desenez un dreptunghi scalat cu  glm::vec3(abs(p1.x - p2.x) - 1, 1.0f, 1.0f).

		Pun in stanga si dreapta strazilor si trotuare.


	Prin variabila generatedBuildings retin daca am generat deja valorile cladirilor . 
	Folosesc clasa Building in care voi retine daca desenez un paralelipiped sau un cilindru , cate componente va avea si
cu cat vor fi scalate fiecare.

	Functia : void computeBuildingScale(Building *b);

 genereaza valorile cu care vor fi scalate componentele cladirilor.


	Functia : void generateBuilding(Building b); genereaza tipul de cladire .

	Fragment Shader : 
		- se aplica textura data
		- daca este cladire va avea mai multe lumini spot pe care le aplic
		- daca nu este cladire aplic o lumina directionala 







