USE books;

 

drop table if exists books
;

 
create table books (
    personID int AUTO_INCREMENT,
    firstName varchar (30) NOT NULL,
    lastName varchar (30) NOT NULL,
    ISBN varchar (30) NOT NULbooksL,
    title varchar (30) NOT NULL,
    copyright varchar (30) NOT NULL,
    comments varchar (30) NOT NULL,
    constraint pk_name primary key (personID)
)
;