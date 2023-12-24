USE bank_system;

INSERT INTO currency_type (code)
VALUES ('CNY'),
       ('HKD'),
       ('JPY'),
       ('KRW'),
       ('USD'),
       ('EUR');

INSERT INTO terminal (code, password)
VALUES ('T-1', '123456'),
       ('T-2', '654321');

INSERT INTO customer (name, pid, telephone, address)
VALUES ('张三', '123456789012345678', '12345678901', '北京市海淀区'),
       ('李四', '123456789012345679', '12345678902', '北京市海淀区');

INSERT INTO card (id, password, open_money, open_date, is_report_loss, customer_id)
VALUES ('6227 2666 1234 4321', '123456', 1000.00, CURRENT_DATE, 0, 1),
       ('6227 2666 1234 4322', '654321', 1000.00, CURRENT_DATE, 0, 2);

INSERT INTO balance (amount, currency_id, card_id)
VALUES (1000.00, 1, '6227 2666 1234 4321'),
       (1000.00, 1, '6227 2666 1234 4322');

SELECT *
FROM terminal
WHERE code = 'T-1';

SELECT *
FROM customer
WHERE id = 1;

SELECT *
FROM balance
WHERE card_id = '6227 2666 1234 4321';

UPDATE balance
SET amount = 2010.00
WHERE card_id = '6227 2666 1234 4321';