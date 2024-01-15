DB_NAME="LibCat.sqlite"

.PHONY: db-init
db-init: db-drop db-create db-fixtures db-move

.PHONY: db-drop
db-drop:
	rm -fv cmake-build-debug/$(DB_NAME)

.PHONY: db-create
db-create:
	./thirdparty/sqlite/sqlite3 $(DB_NAME) ".read ./migrations/001_init_schema.sql"

.PHONY: db-move
db-move:
	mkdir -p cmake-build-debug
	mv $(DB_NAME) cmake-build-debug/

.PHONY: db-fixtures
db-fixtures:
	./thirdparty/sqlite/sqlite3 $(DB_NAME) ".read ./migrations/fixtures/001_authors.sql"
	./thirdparty/sqlite/sqlite3 $(DB_NAME) ".read ./migrations/fixtures/002_publishers.sql"
	./thirdparty/sqlite/sqlite3 $(DB_NAME) ".read ./migrations/fixtures/003_books.sql"
