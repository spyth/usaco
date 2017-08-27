-- 175
SELECT Person.FirstName, Person.LastName, Address.City, Address.State FROM Person
LEFT JOIN Address ON Person.PersonId = Address.PersonId

-- 176
-- select the second highest vale from the table. should return null if not exist.
SELECT MAX(Salary) AS SecondHighestSalary FROM Employee
WHERE Salary<(SELECT MAX(Salary) FROM Employee)

