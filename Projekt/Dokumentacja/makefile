

# tutaj trzeba podac sciezke do katalogu z plikami naglowkowymi
zrodla=kod


.PHONY: clean
 

__ : dokumentacja.pdf
	echo "gotowe"

# polaczenie sprawozdania z dokumentacja z doxygena
dokumentacja.pdf : sprawozdanie.pdf refman.pdf
	pdftk sprawozdanie.pdf ./latex/refman.pdf cat output dokumentacja.pdf

# kompilacja sprawozdania:
sprawozdanie.pdf : sprawozdanie.tex
	pdflatex sprawozdanie
	bibtex   sprawozdanie
	pdflatex sprawozdanie
	pdflatex sprawozdanie

# kompilacja dokumentacji
refman.pdf : $(zrodla)/Bilet.hpp $(zrodla)/Data.hpp $(zrodla)/Plik.hpp $(zrodla)/Rezerwacja.hpp $(zrodla)/Rezerwacje.hpp $(zrodla)/Sala.hpp $(zrodla)/Status.h Doxyfile
	doxygen 
	$(MAKE) -C latex
	cp ./latex/refman.pdf .
	
# wygenerowanie pliku konfiguracyjnego dla doxygena	
Doxyfile : 
	doxygen -g 	
	mv Doxyfile doxy
	cat doxy | LC_ALL=C gsed -e 's/INPUT[ \t]\+=/INPUT = $(zrodla)/g' | LC_ALL=C gsed -e 's/UML_LOOK[ \t]\+=[ \t]\+NO/UML_LOOK = YES/g' | LC_ALL=C gsed -e 's/OUTPUT_LANGUAGE[ \t]\+=[ \t]\+English/OUTPUT_LANGUAGE = Polish/g' | LC_ALL=C gsed -e 's/PROJECT_NAME[ \t]\+=[ \t]\+"My Project"/PROJECT_NAME = "Projekt zaliczeniowy z PK3-SSI"/g' | LC_ALL=C gsed -s 's/GENERATE_HTML[ \t]\+=[ \t]\+YES/GENERATE_HTML = NO/g' | LC_ALL=C gsed -s 's/EXTRACT_ALL[ \t]\+=[ \t]\+NO/EXTRACT_ALL = YES/g'| LC_ALL=C gsed -s 's/HAVE_DOT[ \t]\+=[ \t]\+NO/HAVE_DOT = YES/g' | LC_ALL=C gsed -s 's/COLLABORATION_GRAPH[ \t]\+=[ \t]\+NO/COLLABORATION_GRAPH = YES/g' > Doxyfile 
	
# usuniecie zbednych plikow	
clean : 	
	for f in `ls doxy Doxyfile *.aux *.log *.out *.gz *.bib *.blg *.bbl *.o *~ refman.pdf sprawozdanie.pdf` ; do  if [ -f $$f ] ; then rm $$f  ; fi;   done;
	if [ -d latex ] ; then rm -r latex ; fi ;
	if [ -d html ]  ; then rm -r html  ; fi ;
	
		
	
	

