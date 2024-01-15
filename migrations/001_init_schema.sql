CREATE TABLE IF NOT EXISTS authors(
    id integer primary key autoincrement,
    name varchar(25) not null
);

CREATE TABLE IF NOT EXISTS books(
    id integer primary key autoincrement,
    title varchar(25) not null,
    author_id integer not null,
    publisher_id integer not null,
    published_in integer not null,
    foreign key (author_id) references authors(id),
    foreign key (publisher_id) references publishers(id)
);

CREATE TABLE IF NOT EXISTS publishers(
    id integer primary key autoincrement,
    name varchar(25) not null
);
