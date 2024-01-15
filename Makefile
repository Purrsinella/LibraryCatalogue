.PHONY: db-init
db-init:
	./thirdparty/sqlite/sqlite3 LibCat.sqlite ".read ./migrations/001_init_schema.sql"
	mkdir -p cmake-build-debug
	mv LibCat.sqlite cmake-build-debug

.PHONY: db-drop
db-drop:
	rm cmake-build-debug/LibCat.sqlite