#DROP TABLE IF EXISTS `restaurantMenu`;
-- This creates the restaurant menu
CREATE TABLE IF NOT EXISTS `restaurantMenu` (
  `MenuItem` varchar(50) NOT NULL,
  `Price` int(5) NOT NULL,
  PRIMARY KEY (`menuitem`)
);
#DROP TABLE IF EXISTS `CUSTOMERS`;
-- This creates the Customers table
CREATE TABLE IF NOT EXISTS `CUSTOMERS` (
  `CID` int(2) NOT NULL,
  `NAME` varchar(50) NOT NULL,
  `PAYMENT` varchar(50) NOT NULL,
  PRIMARY KEY (`CID`)
);
#DROP TABLE IF EXISTS `ORDERS`;
-- This creates the Orders table
CREATE TABLE IF NOT EXISTS `ORDERS` (
  `CID` int(2) NOT NULL,
  `MenuItem` varchar(50) NOT NULL,
  `TotalPrice` int(10) NOT NULL,
  `OrderNumber` int(10) NOT NULL
);

-- Inserts the restaurant menu options
INSERT INTO `restaurantMenu` (`MenuItem`, `Price`) VALUES
  ('Penne alla Vodka', '20'),
  ('Carbonara Pasta', '20'),
  ('Burger and Fries', '15'),
  ('Side of Fries', '5'),
  ('Side Salad', '5'),
  ('Garlic Knots', '8'),
  ('Coca Cola', '2'),
  ('Meatball Spaghetti', '10');

-- Inserts all customers and their payment method
INSERT INTO `CUSTOMERS` (`CID`, `NAME`, `PAYMENT`) VALUES
  ('0', 'Tom Brady', 'CREDITCARD'),
  ('1', 'Kevin Dennis', 'CASH'),
  ('2', 'Jared Ligatti', 'CASH'),
  ('3', 'Elon Musk', 'ElonBucks');

-- Inserts all orders and includes the totalPrice as well as the CID
INSERT INTO `ORDERS` (`OrderNumber`, `CID`, `MenuItem`, `TotalPrice`) VALUES
  ('0', '0', 'Burger and Fries', '15'),
  ('1', '0', 'Side Salad', '20'),
  ('2', '0', 'Coca Cola', '22'),
  ('3', '1', 'Burger and Fries', '15'),
  ('4', '1', 'Garlic Knots', '23'),
  ('5', '2', 'Penne alla Vodka', '20'),
  ('6', '2', 'Garlic Knots', '30');