--2020 lab endsem paper

-- 1. Write the create statement for the below mentioned tables with all attributes and constraints:
-- Match(MatchID(pk), TeamName1, Team Name2, Ground, Match Date)
-- Player (PlayerID(pk), LastName, FirstName, Country, YearBorn, Birth Place) 
-- Batting(MatchID(pk), PlayerID(pk), BattingOrder, RunsScored) 
-- NOTE: MatchID in Batting table refers to MatchID of Match Table
-- PlayerID in Batting table refers to PlayerID of Player Table 
create table match(
  MatchID int primary key,
  TeamName1 varchar(20),
  TeamName2 varchar(20),
  Ground varchar(20),
  MatchDate date
);

create table player(
  PlayerID int primary key,
  LastName varchar(20),
  FirstName varchar(20),
  Country varchar(20),
  YearBorn int,
  BirthPlace varchar(20)
);

create table batting(
  MatchID int references match,
  PlayerID int references player,
  RunsScored int,
  BattingOrder int,
  primary key(MatchID, PlayerID)
);

--2. Write the insert statement for 1 row for each of the created table.
insert into match values(2675, 'Australia', 'India', 'Melbourne', '10-Feb-2008');
insert into match values(2688, 'Australia', 'India', 'Sydney', '2-Mar-2008');
insert into match values(2689, 'Australia', 'India', 'Brisbane', '4-Mar-2008');
insert into match values(2755, 'India', 'West Indies', 'Brisbane', '7-Jul-2010');
insert into match values(2750, 'Sri Lanka', 'India', 'Brisbane', '7-Apr-2010');

insert into player values(89001, 'Tendulkar', 'Sachin', 'India', 1973, 'Mumbai');
insert into player values(27002, 'Sharma', 'Ishant', 'India', 1988, 'Delhi');
insert into player values(99001, 'Lee', 'Brett', 'Australia', 1976, 'Wollongong');
insert into player values(98002, 'Lara', 'Brian', 'West Indies', 1969, 'Santa Cruz');
insert into player values(91001, 'Jayasurya', 'Sanath', 'Sri Lanka', 1969, 'Matara');

insert into batting values(2689, 89001, 71, 1);
insert into batting values(2688, 98002, 42, 2);
insert into batting values(2675, 27002, 0, 2);
insert into batting values(2689, 99001, 9, 2);
insert into batting values(2755, 89001, 44, 1);
insert into batting values(2750, 89001, 40, 4);
insert into batting values(2755, 27002, 29, 3);

-- 3. Write SQL queries for the following using the above database
-- a. Find all the information about players from India who were born after 1975
select * from player where YearBorn > 1975 and Country = 'India';

-- b. List matches played in which TeamName1 is India or Australia. 
(select MatchID from match where TeamName1 = 'India') union (select MatchID from match where TeamName1 = 'Australia');

-- c. Find the names of all players that have batted in all the ODI matches in Melbourne ground.
select FirstName, LastName from player p join batting b on p.PlayerID = b.PlayerID join match m on m.MatchID = b.MatchID and m.ground = 'Melbourne'; 

-- d. Find the youngest player.
select FirstName, LastName from player where YearBorn >= all(select YearBorn from player);

-- 4. Create a PLSQL block to read a player id and display his total number of runs in words. (i.e. if the total runs is 10 then display "ONE" "ZERO").
create or replace function letter_score(num int) return match.TeamName1%type as
  message match.TeamName1%type;
begin
  if num = 0 then
    message := 'ZERO';
  elsif num = 1 then
    message := 'ONE';
  elsif num = 2 then
    message := 'TWO';
  elsif num = 3 then
    message := 'THREE';
  elsif num = 4 then
    message := 'FOUR';
  elsif num = 5 then
    message := 'FIVE';
  elsif num = 6 then
    message := 'SIX';
  elsif num = 7 then
    message := 'SEVEN';
  elsif num = 8 then
    message := 'EIGHT';
  elsif num = 9 then
    message := 'NINE';
  end if;
  return message;
end;
/

declare 
  pid batting.PlayerID%type;
  cursor c is select * from batting where PlayerID = pid;
  runs batting.RunsScored%type := 0;
  fn int := 0;
  ln int := 0;
  fm match.TeamName1%type;
  lm match.TeamName1%type;
begin
  pid := '&Player_ID';
  for temp in c loop
    runs := runs + temp.RunsScored;
  end loop;
  dbms_output.put_line(runs);
  fn := trunc(runs / 10);
  ln := runs mod 10;
  fm := letter_score(fn);
  lm := letter_score(ln);
  dbms_output.put_line(fm ||' ' ||lm);
end;
/