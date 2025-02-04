source $EXPORT_IDF
rm *.csv
if [ -d "build" ]; then rm -Rf build; fi
idf.py build
