USE bpla;

CREATE TABLE commands (
	type TINYINT UNSIGNED,
	num SMALLINT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
	userid INT UNSIGNED COMMENT 'identifier of user which order the command',
	sent BIT(1),
	confirmed BIT(1),
	report BIT(1)
) ENGINE INNODB;

CREATE TABLE route (
       route_num TINYINT UNSIGNED COMMENT 'counter of route_clean commands ', 
	num SMALLINT UNSIGNED NOT NULL COMMENT 'checkpoint ordinal number in route',
	position_longitude FLOAT(10,7),
	position_latitude FLOAT(9,7),
	emergency_longitude FLOAT(10,7), 
	emergency_latitude FLOAT(9,7),
	altitude SMALLINT UNSIGNED NOT NULL COMMENT 'in decs of cm',
	speed SMALLINT UNSIGNED NOT NULL COMMENT 'in mps',
PRIMARY KEY (route_num, num)
) ENGINE INNODB;

CREATE TABLE msg_heartbeat (
	num SMALLINT UNSIGNED PRIMARY KEY,
	longitude FLOAT(10,7),
	latitude FLOAT(9,7),
	heading FLOAT(10,7),
	baroaltabs SMALLINT UNSIGNED,
	baroaltrel SMALLINT UNSIGNED,
	gpsalt SMALLINT UNSIGNED,
	temperature SMALLINT UNSIGNED,
	voltage SMALLINT UNSIGNED,
	current SMALLINT UNSIGNED,
	boardtime TIME,
	gsmlevel TINYINT UNSIGNED,
	last_msgnum SMALLINT UNSIGNED,
	denial TINYINT UNSIGNED,
	servoch1 SMALLINT UNSIGNED,
	servoch2 SMALLINT UNSIGNED,
	servoch3 SMALLINT UNSIGNED,
	servoch4 SMALLINT UNSIGNED,
	servoch5 SMALLINT UNSIGNED,
	servoch6 SMALLINT UNSIGNED,
	speed SMALLINT UNSIGNED,
	status TINYINT UNSIGNED
) ENGINE INNODB;

CREATE TABLE msg_zerobaroalt (
	num SMALLINT UNSIGNED PRIMARY KEY,
	zerobaroalt SMALLINT UNSIGNED
) ENGINE INNODB;

CREATE TABLE msg_updcpt (
	num SMALLINT UNSIGNED PRIMARY KEY,
	routenum SMALLINT UNSIGNED,
	position_longitude FLOAT(10,7),
	position_latitude FLOAT(9,7),
	emergency_longitude FLOAT(10,7), 
	emergency_latitude FLOAT(9,7),
	altitude SMALLINT UNSIGNED NOT NULL,
	speed SMALLINT UNSIGNED NOT NULL
) ENGINE INNODB COMMENT 'log command to update checkpoint';