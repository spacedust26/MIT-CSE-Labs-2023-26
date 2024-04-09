--DBS lab endsem question pyq

--Create the following Vehicle Service database which store the different parts details and parts used in the service of different customer vehicles: 
--Schema:
--Part(PartNo, PartName, VehicleType, Unit Price, SalesPrice) 
--Service(ServiceNo, PartNo, ServiceDate, CustomerNo, Qty) 
--Constraints: 
--i. Vehicle Type should be 'V1', 'V2', 'V3', 'V4', or 'V5' 
--ii. UnitPrice and SalesPrice should be greater than zero 
--iii. PartNo, FK in Service refers to PartNo, PK in Part

create table part(
  PartNo int primary key,
  PartName char(2),
  VehicleType char(2),
  UnitPrice number,
  SalesPrice number,
  check(VehicleType in ('V1', 'V2', 'V3', 'V4', 'V5')),
  check(UnitPrice > 0 and SalesPrice > 0)
);

create table service(
  ServiceNo int,
  PartNo int references part,
  ServiceDate date,
  CustomerNo char(2),
  Qty int,
  primary key(ServiceNo, PartNo)
);

insert into part values(1, 'P1', 'V1', 10, 12);
insert into part values(2, 'P2', 'V2', 100, 110);
insert into part values(3, 'P3', 'V3', 150, 175);
insert into part values(4, 'P4', 'V4', 200, 250);
insert into part values(5, 'P5', 'V5', 75, 90);

insert into service values(1, 1, '01-Jan-17', 'C1', 5);
insert into service values(1, 3, '01-Jan-17', 'C1', 4);
insert into service values(2, 3, '05-Feb-18', 'C2', 10);
insert into service values(3, 1, '15-May-18', 'C3', 9);
insert into service values(4, 1, '03-Jun-19', 'C1', 5);

-- A. Write the following queries in SQL:
-- i.List the Part Names which are not used to service the vehicle of any customer.
select PartName from part where PartNo not in (select distinct PartNo from service);

-- ii.List the customer number who has got his vehicle serviced maximum number of times.
create view max_time(CustomerNo, cn) as select CustomerNo , count(CustomerNo) cn from service group by CustomerNo;

select CustomerNo, cn from max_time where cn >= all(select cn from max_time);

-- iii.List the customer number whose vehicle service used all the parts of vehicle type V1.
select distinct CustomerNo from service s join part p on s.PartNo = p.PartNo and VehicleType = 'V1';

-- B. Write a PL/SQL program to find the total profit done in the sales of a given part number in the service of different customer vehicles. Raise an exception for invalid part number.
declare
  pno part.PartNo%type;
  invalid_part_number exception;
  up part.UnitPrice%type;
  sp part.SalesPrice%type;
  profit part.SalesPrice%type;
begin
  pno := '&Part_Number';
  select UnitPrice into up from part where PartNo = pno;
  select SalesPrice into sp from part where PartNo = pno;
  if sql%notfound then raise invalid_part_number;
  end if;
  profit := sp - up;
  dbms_output.put_line('Profit: ' || profit);
  exception
    when invalid_part_number then 
      dbms_output.put_line('Invalid part number');
end;
/