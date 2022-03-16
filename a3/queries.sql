# We use SELECT * to list all MenuItems and prices
SELECT * FROM `restaurantMenu`;

# We use LIKE to lists all menu items ordered by a single customer
SELECT * FROM `ORDERS` WHERE CID LIKE '2';

# We use the INNER JOIN to returns all items ordered by which customers
SELECT ORDERS.MenuItem, CUSTOMERS.CID
FROM `ORDERS`
INNER JOIN `CUSTOMERS` ON ORDERS.CID = CUSTOMERS.CID;

# We use LEFT JOIN on ORDERS to lists all customer info even if they
# did not make an order as they might still choose to. If CID is null,
# it means the customer has not ordered anything yet.
SELECT DISTINCT CUSTOMERS.NAME, CUSTOMERS.PAYMENT, ORDERS.CID FROM `CUSTOMERS`
LEFT OUTER JOIN `ORDERS` ON ORDERS.CID = CUSTOMERS.CID;

# We use RIGHT JOIN to return CUSTOMERS where we print all orders for all customers,
# even those who have not ordered anything yet. It helps us see our orders for all customers by name and CID.
SELECT ORDERS.OrderNumber, ORDERS.MenuItem, ORDERS.TotalPrice, CUSTOMERS.CID FROM `ORDERS`
RIGHT OUTER JOIN `CUSTOMERS` ON ORDERS.CID = CUSTOMERS.CID;

# We use the UNION keyword to find a list of all customers regardless of whether they
# have ordered anything yet, they may still choose to order something.
SELECT `CID` FROM `CUSTOMERS`
UNION
SELECT `CID` FROM `ORDERS`;

# We use the GROUP BY keyword to return the Count of each menu item for the kitchen.
SELECT COUNT(`MenuItem`), `MenuItem` FROM `ORDERS`
GROUP BY `MenuItem`;

# We used the Offset 4 skip any earlier orders to and we used TotalPrice ASC 
# to try to get the final order totals.
SELECT `CID`, `TotalPrice` FROM `ORDERS`
ORDER BY `TotalPrice` ASC
LIMIT 3
OFFSET 4;