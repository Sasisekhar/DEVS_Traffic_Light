source $EXPORT_IDF
if [ -d "build" ]; then rm -Rf build; fi
idf.py build
