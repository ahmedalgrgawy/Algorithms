CREATE DATABASE zoo;

CREATE TABLE supplier (
    supplier_id INT NOT NULL IDENTITY PRIMARY KEY,
    name VARCHAR(20) NOT NULL,
    address VARCHAR(50) NOT NULL,
    phone_number VARCHAR(20) NOT NULL,
);
CREATE TABLE person (
    person_id INT NOT NULL IDENTITY PRIMARY KEY,
    name VARCHAR(20) NOT NULL,
    birth_date DATE NOT NULL,
    phone_number VARCHAR(20) NOT NULL,
    job_title VARCHAR(20) NOT NULL,
    address VARCHAR(50) NOT NULL,
    certificate VARCHAR(50) NOT NULL,
);

CREATE TABLE exhibit (
    exhibit_id INT NOT NULL IDENTITY PRIMARY KEY,
    show_time VARCHAR(20) NOT NULL,
    zone VARCHAR(20) NOT NULL,
);

CREATE TABLE animal (
    animal_id INT NOT NULL IDENTITY PRIMARY KEY,
    name VARCHAR(20) NOT NULL,
    date_arrived DATE NOT NULL,
    date_departed DATE,
    date_of_birth DATE NOT NULL,
    date_of_death DATE,
    gender VARCHAR(50) NOT NULL,
    breed VARCHAR(20) NOT NULL,
    origin VARCHAR(20) NOT NULL,
	person_id INT FOREIGN KEY (person_id) REFERENCES person (person_id),
	exhibit_id INT FOREIGN KEY (exhibit_id) REFERENCES exhibit (exhibit_id)
);

CREATE TABLE food (
    food_id INT NOT NULL IDENTITY PRIMARY KEY,
    agenda VARCHAR(20) NOT NULL,
    amount VARCHAR(20),
    type VARCHAR(20),
	supplier_id INT FOREIGN KEY (supplier_id) REFERENCES supplier (supplier_id),
    animal_id INT  FOREIGN KEY (animal_id) REFERENCES animal (animal_id)
	
);


CREATE TABLE checkup (
    checkup_id INT NOT NULL IDENTITY PRIMARY KEY,
    medicine_name VARCHAR(20) NOT NULL,
    schedule VARCHAR(20),
    type VARCHAR(20) NOT NULL,
    amount VARCHAR(20),
    animal_id INT FOREIGN KEY (animal_id) REFERENCES animal (animal_id),
    person_id INT FOREIGN KEY (person_id) REFERENCES person (person_id)
    
);

INSERT INTO animal(name ,date_arrived ,date_departed ,date_of_birth ,date_of_death ,gender ,breed ,origin )
VALUES ('Talat','2010-05-10','','2008-10-10','','Male','lion','South Africa'),
	  ('Naema','2018-05-28','2019-08-12','2016-05-28','','Female','Elephant','Egypt'),
	  ('Saadoun','2018-09-17','','2018-09-17','','Male','Monkey','Egypt'),
	  ('Tote','2016-10-23','','2013-05-21','','Female','Flamingo','Kenya'),
	  ('Soaad','2009-12-08','','2008-03-30','','Female','lion','South Africa'),
	  ('Gafar','2013-05-12','','2010-11-07','','Male','Crocodile','Congo'),
	  ('Zizo','2016-05-10','','2014-10-21','2017-05-13','Male','Giraffe','Somalia'),
	  ('Mymona','2016-06-19','','2015-10-02','','Female','Monkey','Argentina'),
	  ('Ashraf','2017-04-11','','2016-07-15','','Male','Zebra','Mangholia'),
	  ('Damba','2012-03-24','','2010-12-07','','Female','Elephant','India'),
	  ('Coco','2016-05-17','','2012-07-11','','Male','Flamingo','Tanzania'),
	  ('Hady','2015-03-20','','2013-01-10','','Male','Monkey','Burkina Faso');
	   
	   


INSERT INTO person(name ,birth_date ,phone_number ,job_title ,address ,certificate )
VALUES ('abbass saleh','1990-11-27','+201088441523','zoo keeper','10 El Mesaha Sq., DOKKI','degree in zoology'),
       ('khaled moustafa','1987-05-12','+201006214785','manager','27-6th october-cairo','Business Administration'),
       ('adel mahrous','1995-08-22','+201017552210','guard','36-Sayeda Zainab-giza','high school'),
	   ('hassan allam','1988-02-02','+201255008103','zoo keeper','El Remaya Sq. Pyramids Giza','degree in zoology'),
	   ('mouhame khalifa','1976-10-14','+201066060703','vet','4 A El Shark Lel TAameen Bldgs., NASR CITY','Veterinary Medicine'),
	   ('ahmed sabry','1996-06-23','+201554782644','account','1 El-Borsa El-Gedida St., Kasr El-Nil','commerce'),
	   ('sameh hussien','1992-12-05','+201266142583','zoo keeper','12 El-Fardous St., Abbasseya','degree in zoology'),
	   ('hatem nagy','1985-07-11','+201568942377','vet','20 Mourad El-Shereie-Saint Fatima, HELIOPOLIS','Veterinary Medicine'),
	   ('omar kamal','1993-09-29','+201114782561','guard','101 Abdel Moniem Riad St., Agouza','high school'),
	   ('salem mahmoud','1982-04-17','+20118800414','zoo keeper','44 Moez El-Dawla St., 6th District','degree in zoology');

	  


INSERT INTO exhibit ( show_time ,zone )
VALUES('10am : 4pm','A'),
      ('10am : 3pm','C'),
	  ('10am : 5pm','B2'),
	  ('9am : 6pm','D'),
	  ('10am : 4pm','A1'),
      ('10am : 3pm','B');
	    



INSERT INTO checkup (medicine_name,schedule,type,amount)
VALUES('Acepromazine','','dewormer','400 pack'),
      ('altrenogest','','synchronizes estrus','non availiable'),
	  ('amantadine','','chronic pain','600 pack'),
	  ('bupivacaine','27 May ,9am','surgery','1000 pack');
	  



INSERT INTO food(agenda, amount ,type )
VALUES('2pm : 4pm','','flesh '),
      ('1pm : 3pm','','Grains'),
	  ('3pm : 4pm','','Grass');
	     




INSERT INTO  supplier(name ,address ,phone_number)
VALUES('Mars Petcare Inc','El-Obour Bldgs. 4th Bldg., 3rd Floor, Apt. 6','+201000111234'),
      ('Hill Nutrition','Sabaa Emarat Bldgs. 4 El-Shahid Galal El-Din','+201515442173'),
	  ('J.M. Smucker','6 Omar Ibn El Khattab St., Ismaileya Sq','+201165789246');
	  
	  --show all columns for each table

	SELECT*FROM animal;

	SELECT*FROM person;
	  
	SELECT*FROM exhibit;
	  
	SELECT*FROM checkup;
	  
	SELECT*FROM food;
	  
	SELECT*FROM supplier;

	-------------------------------------------------------------------------

	 SELECT*FROM food
	 WHERE agenda>'2PM';

	 ----------------------------------------------------------------------
	 SELECT*FROM animal
	 WHERE gender='male';

	 -------------------------------------------------------------------------
	 SELECT*FROM supplier
	 WHERE name='J.M. Smucker'
	 OR phone_number='+201515442173';

	 -------------------------------------------------------------------------
	 SELECT*FROM animal
	 WHERE animal_id IN (1,7,5);

	 ---------------------------------------------------------------------------
	 SELECT*FROM person
	 ORDER BY job_title DESC, name; 

	 ----------------------------------------------------------------------------
	 SELECT TOP 3*FROM person
	 ORDER BY  name DESC; 

	 ---------------------------------------------------------------------------
	 SELECT agenda , name 
	 FROM food  inner join animal
	 on food.food_id = animal.animal_id;

	 -----------------------------------------------------------------------------
	 SELECT agenda , name 
	 FROM food  right outer join animal
	 on food.food_id = animal.animal_id;

	----------------------------------------------------------------------------
	UPDATE animal
	SET date_arrived = '2014-08-14'
	WHERE animal_id=10;

	SELECT*FROM animal
	WHERE animal_id=10;
 ------------------------------------------------------------------------------------
	ALTER TABLE person
    ADD Email varchar(255);

    update person set Email='Example@gmail.com '
	where name = 'sameh hussien';

    SELECT*FROM person
    WHERE Email='Example@gmail.com';  

	SELECT * FROM person;
 ----------------------------------------------------------------------------------------
	SELECT COUNT(animal_id), gender 
	FROM animal
	GROUP BY gender 
	ORDER BY COUNT(animal_id ) DESC;

--------------------------------------------------------------------------------------------------
	SELECT * FROM person
	WHERE person_id BETWEEN 3 AND 7;
-------------------------------------------------------------------------------------------
	DELETE FROM supplier WHERE name ='Mars Petcare Inc';

	SELECT * FROM supplier;
------------------------------------------------------------------------
   BEGIN TRANSACTION;


   COMMIT;
