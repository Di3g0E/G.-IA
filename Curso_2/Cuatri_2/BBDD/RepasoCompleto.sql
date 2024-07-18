use world;

-- HOJA 1 --

-- 1 -- Población total por pais
SELECT Name, country.Population FROM country;

-- 3 -- Densidad de población por continente
SELECT continent, (SUM(population) / SUM(surfaceArea)) desnidad_poblacion FROM country group by continent;

-- 4 --¿Qué regiones se componen por más de 10 paises?
SELECT region, COUNT(Region) FROM country GROUP BY region HAVING COUNT(Region)>10;

-- 5 -- ¿Qué formas de gobierno están contempladas?
SELECT DISTINCT Governmentform FROM country;

-- 6 -- ¿Qué paises tienen como forma de gobierno algún tipo de monarquía? Muéstralos de manera ordenada por continente
     -- y nombre del país
SELECT Name, Continent, GovernmentForm FROM country ORDER BY Continent, Name;

-- 7 -- ¿De qu país no se conoce la esperanza de vida?
SELECT Name, LifeExpectancy FROM country WHERE LifeExpectancy is NULL;

-- 8 -- ¿Qué continentes tienen algún país sin representante político?
SELECT Continent, name, HeadOfState FROM country WHERE HeadOfState IS NULL;

-- 9 -- ¿Qué forma de gobierno tiene Swaziland?
SELECT Name, GovernmentForm FROM country where Name LIKE 'Swaziland';

-- 10 -- ¿Qué paises tienen un nombre local que no coincide con su nombre internacional?
SELECT Name, LocalName From country WHERE Name NOT LIKE LocalName;

-- 11 -- ¿Qué paises se han independizado o su independencia ha sido antes de Cristo?
SELECT Name, CASE
    WHEN IndepYear IS NULL THEN 'n.a.'
    WHEN IndepYear < 0 THEN 'a.c.'
    END AS IndepYear FROM country WHERE (IndepYear<0) OR (IndepYear IS NULL);

-- 12 -- Indica el nombre, año actual, año en el que consiguieron la independencia de los paises con más de 200 años
      -- de independencia
SELECT Name, YEAR(CURRENT_DATE), IndepYear FROM country WHERE IndepYear>200;

-- 13 -- Top 10 de distritos más poblados
SELECT District, Population FROM city ORDER BY Population DESC LIMIT 10;

-- 14 -- Número de ciudades por distrito en 'USA'
SELECT District, COUNT(Name) FROM city WHERE CountryCode LIKE 'USA' GROUP BY District;

-- 15 -- Lenguas oficiales habladas en más de 10 países
SELECT Language, COUNT(CountryCode), IsOfficial FROM countrylanguage WHERE IsOfficial='T' GROUP BY Language HAVING COUNT(CountryCode)>10;

-- 16 -- ¿Cuál es el GNB y el GNP de los paises con una población superior a 50 millones y a qué continente pertenece?
      -- Ordenados de mayor a menorpor su GNP
SELECT Name, GNP, GNP/Population GNP_per_capita, Population, Continent FROM country WHERE Population>50000000;

-- 17 -- ¿Cuáles son los países con mayor esperanza de vida? Indicar el nombre y el continente
      -- (considerar la esperanza de vida superior a 80)
SELECT Name, Continent, LifeExpectancy FROM country WHERE LifeExpectancy>80;

-- 18 -- ¿Cuál es el continente que más países tiene con más de 50 millones de población y un GNP per cápita superior al 0.001?
SELECT Continent, COUNT(*) FROM country WHERE Population>50000000 AND (GNP/Population)>0.001 GROUP BY Continent;


-- HOJA 2 --

-- 1 -- Número total de personas que hablan cada uno de los idiomas oficiales del mundo
SELECT Language, IsOfficial, SUM(Population*Percentage) Num_hablantes FROM countrylanguage, country WHERE IsOfficial='T' GROUP BY Language ORDER BY Num_hablantes DESC;
-- Los cuatro idiomas oficiales más hablados son: Spanish, Arabic, English and German.

-- 2 -- Listado de todas las ciudades, ordenadas alfabéticamente, que pertenecen a paises con una esperanza de vida < 50
SELECT c1.Name, LifeExpectancy FROM country, city c1 WHERE CountryCode=Code AND LifeExpectancy<50 ORDER BY c1.Name;

-- 3 -- Nombre de los paises que tienen más de 50000000 de habitantes
SELECT Name, Population FROM country WHERE Population>50000000 ORDER BY Population DESC;

-- 4 -- Continentes en los que se habla en alguno de sus paises alemán
SELECT DISTINCT Continent FROM country, countrylanguage WHERE Code=CountryCode AND Language='German';

-- 5 -- Nombre de los continentes en los que no se habla chino
(SELECT DISTINCT Continent FROM country)
EXCEPT
(SELECT DISTINCT Continent FROM country, countrylanguage WHERE CountryCode=Code AND Language='Chinese');

-- 6 -- Idiomas por país indicando cuál es el oficial
SELECT Name, Language, IsOfficial FROM countrylanguage, country WHERE Code=CountryCode ORDER BY Name, IsOfficial;

-- 7 -- Nombre de los paises europeos con un único idioma, que además es oficial
SELECT Name, Language, IsOfficial FROM country JOIN countrylanguage on CountryCode=country.Code WHERE IsOfficial='T'
AND Name NOT IN
(SELECT Name FROM country JOIN countrylanguage on Code=CountryCode WHERE IsOfficial='T' GROUP BY Name HAVING COUNT(*)>1);

-- 8 -- Paises que hablen el idioma inglés o francés o ambos, en el resultado de la consulta debe verse qué idioma o idiomas se hablan.
     -- (Utiliza el operador UNION)
(SELECT Name, Language FROM country JOIN countrylanguage ON Code = CountryCode WHERE Language = 'English' OR Language = 'French')
UNION
(SELECT Name, Language FROM country JOIN countrylanguage ON Code = CountryCode WHERE CountryCode IN
                    (SELECT CountryCode FROM countrylanguage WHERE Language = 'English') AND CountryCode IN
                    (SELECT CountryCode FROM countrylanguage WHERE Language = 'French'));

-- 9 -- Ciudades del continente americano (norte y sur) y nombre del país al que pertence
SELECT Continent, country.Name, city.Name FROM country JOIN city ON Code = CountryCode WHERE Continent LIKE '%America';

-- 10 -- Nombre de las capitales de cada país ordenadas por continente
SELECT country.Name, city.Name, country.Continent FROM country JOIN city ON country.Code = city.CountryCode WHERE ID = Capital ORDER BY Continent;

-- 11 -- Paises con su capital y sus idiomas oficiales
SELECT country.Name País, city.Name Capital, countrylanguage.Language, countrylanguage.IsOfficial FROM countrylanguage
    JOIN Country ON countrylanguage.CountryCode = Country.Code JOIN city ON Capital = ID WHERE IsOfficial = 'T' ORDER BY País;

-- 12 -- Paises de Europa que tengan el mismo idioma oficial
SELECT s1.Name, s1.Language, s1.IsOfficial FROM
(SELECT Name, Language, IsOfficial FROM country JOIN countrylanguage ON country.Code = countrylanguage.CountryCode WHERE IsOfficial='T' AND Continent = 'Europe') s1 JOIN
(SELECT Name, Language, IsOfficial FROM country JOIN countrylanguage ON country.Code = countrylanguage.CountryCode WHERE IsOfficial='T' AND Continent = 'Europe') s2 ON
s1.Language = s2.Language AND s1.Name<>s2.Name ORDER BY Language;


-- HOJA 3 --

-- 1 -- Insertar información de un nuevo país en Norteamérica
INSERT INTO country(code, name, continent, region, surfacearea, indepyear, population, lifeexpectancy, gnp, gnpold, localname, governmentform, headofstate, capital, code2) VALUES ('ZYZ', 'Zyxtopia', 'North America', 'Caribbean', 12345, 1900, 5000000, 75.5, 20000, 19000, 'Zyxtopians', 'Constitutuinal Monarchy', 'King Zyxtus I', 1, 'ZY');
UPDATE country SET Code='ZYX' WHERE Code='ZYZ'; -- Actualizar el código, lo había puesto mal
INSERT INTO countrylanguage(countrycode, language, isofficial) VALUES ('ZYX', 'Hindi', 'T'), ('ZYX', 'Zulu', 'F');
INSERT INTO city(name, countrycode, district, population) VALUES ('Zyxville', 'ZYX', 'North Zyxton', 1000000), ('Wubvurg', 'ZYX', 'East Wuvland', 2000000), ('Vut City', 'ZYX', 'South Vutvaria', 3000000);
UPDATE country SET Capital=4080 WHERE Code='ZYX'; -- Actualizar la capital, no existía al crear el país

-- 2 -- Asociar al nuevo país las ciudades de Canadá menos la capital
SELECT * FROM country WHERE Name='Canada'; -- Ver el Code de Canadá
UPDATE city SET CountryCode='ZYX' WHERE CountryCode='CAN' AND ID != (SELECT Capital FROM country WHERE Code='CAN');

-- 3 -- Restaurar la base de datos con los países y ciudades iniciales
DELETE FROM city WHERE ID=4080 OR ID=4081 OR ID=4082; -- Eliminamos las ciudades que hemos creado
UPDATE city SET CountryCode='CAN' WHERE CountryCode='ZYX'; -- Devolvemos las ciudades a Canadá
DELETE FROM countrylanguage WHERE CountryCode='ZYX'; -- Eliminamos los lenguajes
DELETE FROM country WHERE Code='ZYX';

-- 4 -- ¿Qué pasa si borras España?¿Se borran todas sus ciudades?¿Se conserva la integridad referencial?
DELETE FROM country WHERE Code='ESP'; -- No me deja borrarlo porque otras tablas tienen valores ajenos con restricción de borrado

-- 5 -- Comprueba que los datos son consistentes cuando se borra la capital de un país. Por ejemplo, borra Washington y  comprueba
     -- qué pasa en la tabla country
DELETE FROM city WHERE District = 'Washington';
DELETE FROM city WHERE ID IN (SELECT Capital FROM country WHERE Code = 'USA');

-- 6 -- Explica cómo realiza el SGBD la siguiente consulta
EXPLAIN SELECT Language FROM countrylanguage WHERE IsOfficial = 'T' GROUP BY Language HAVING COUNT(*) > 10;
-- Comprueba fila a fila las restricciones.
-- ¿Se podría mejorar la eficiencia de la consulta utilizando un índice? Describe las características de un índice, si es primario
-- o secundario, la clave elegida de indización (atributo/s elegidos para construir el índice) y cómo ha cambiado el plan de ejecución
CREATE INDEX idx_isOfficial_language ON countryLanguage(IsOfficial, Language);
EXPLAIN SELECT Language FROM countrylanguage WHERE IsOfficial = 'T' GROUP BY Language HAVING COUNT(*) > 10;
DROP INDEX idx_isOfficial_language ON countrylanguage;

-- 9 -- Crear tres vistas de la base de datos "world"
CREATE VIEW Country_desc AS
(SELECT country.Name, Continent, IndepYear, GovernmentForm, HeadOfState, c.Name Capital FROM country JOIN city c ON Capital = ID);
CREATE VIEW City_desc AS
(SELECT city.Name Ciudad, country.Name País, Continent FROM country JOIN city ON country.Code = city.CountryCode);
CREATE VIEW Country_OfficialLanguage AS
(SELECT Name, Language FROM country JOIN countrylanguage ON country.Code = countrylanguage.CountryCode WHERE IsOfficial='T' ORDER BY Name);

SELECT * FROM Country_desc;
SELECT * FROM City_desc;
SELECT * FROM Country_OfficialLanguage;

DROP VIEW Country_OfficialLanguage;


-- HOJA 4 --

-- 1 -- Modifica la tabla country para que el atributo GNP sea siempre obligatorio
ALTER TABLE country MODIFY GNP FLOAT NOT NULL;
DESCRIBE country;

-- 2 -- Añadir la restricción de clave ajena al atributo Capital de la tabla país. Las opciones de borrado y
-- modificación deben ser SET NOT NULL y en cascada, respectivamente. ¿Es posible asignar como capital una cuidad que
-- no pertenezca a este país? Si es así, ¿Cómo se podría evitar esta inconsistencia?
ALTER TABLE country ADD CONSTRAINT FK_Capital FOREIGN KEY (Capital) REFERENCES city(ID) ON DELETE SET NULL ON UPDATE CASCADE;

-- PRUEBAS --
EXPLAIN SELECT * FROM country WHERE code = 'AGO';
SELECT * FROM country WHERE code = 'AGO';
SHOW COLUMNS FROM city;
