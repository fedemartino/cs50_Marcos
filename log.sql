-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT * FROM crime_scene_reports;

--Crime report
SELECT description
FROM crime_scene_reports
WHERE day = 28 AND year = 2020 AND month = 7 AND street = 'Chamberlin Street';

--Witness interviews
SELECT transcript
FROM interviews
WHERE day = 28 AND year = 2020 AND month = 7;

--Thief license plate
SELECT license_plate
FROM courthouse_security_logs
WHERE day = 28 AND hour = 10 AND minute > 15 AND minute < 26 AND activity = 'exit';

--ATM withdrawal account
SELECT id
FROM atm_transactions
WHERE year = 2020 AND month = 7 AND day = 28 AND atm_location = 'Fifer Street' AND transaction_type = 'withdraw';

--Person_id from Bank Account
SELECT person_id
FROM bank_accounts JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE id IN (
SELECT id
FROM atm_transactions
WHERE year = 2020 AND month = 7 AND day = 28 AND atm_location = 'Fifer Street' AND transaction_type = 'withdraw');

--Destination city
SELECT city FROM airports JOIN flights ON airports.id = flights.destination_airport_id
WHERE origin_airport_id IN (
SELECT origin_airport_id
FROM flights JOIN airports ON flights.origin_airport_id = airports.id
WHERE city = 'Fiftyville') AND year = 2020 AND month = 7 AND day = 29
ORDER BY hour
LIMIT 1;

--flight id
SELECT id FROM flights
WHERE origin_airport_id IN (
SELECT origin_airport_id
FROM flights JOIN airports ON flights.origin_airport_id = airports.id
WHERE city = 'Fiftyville') AND year = 2020 AND month = 7 AND day = 29
ORDER BY hour
LIMIT 1;

--passenger list -- passport number
SELECT passport_number FROM passengers JOIN flights ON passengers.flight_id = flights.id
WHERE id = (SELECT id FROM flights
WHERE origin_airport_id IN (
SELECT origin_airport_id
FROM flights JOIN airports ON flights.origin_airport_id = airports.id
WHERE city = 'Fiftyville') AND year = 2020 AND month = 7 AND day = 29
ORDER BY hour
LIMIT 1);

--Thiefs phone number
SELECT caller
FROM phone_calls
WHERE month = 7 AND year = 2020 AND day = 28 AND duration < 60;

--Thiefs name
SELECT name FROM people
WHERE passport_number IN (
SELECT passport_number FROM passengers JOIN flights ON passengers.flight_id = flights.id
WHERE id = (SELECT id FROM flights
WHERE origin_airport_id IN (
SELECT origin_airport_id
FROM flights JOIN airports ON flights.origin_airport_id = airports.id
WHERE city = 'Fiftyville') AND year = 2020 AND month = 7 AND day = 29
ORDER BY hour
LIMIT 1))
AND
phone_number IN (
SELECT caller
FROM phone_calls
WHERE month = 7 AND year = 2020 AND day = 28 AND duration < 60)
AND
license_plate IN (
SELECT license_plate
FROM courthouse_security_logs
WHERE day = 28 AND hour = 10 AND minute > 15 AND minute < 26 AND activity = 'exit')
AND
id IN (
SELECT person_id
FROM bank_accounts JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE id IN (
SELECT id
FROM atm_transactions
WHERE year = 2020 AND month = 7 AND day = 28 AND atm_location = 'Fifer Street' AND transaction_type = 'withdraw')
);

--Thief number
SELECT phone_number FROM people
WHERE name = 'Ernest';

--Accomplice phone number
SELECT receiver FROM phone_calls
WHERE month = 7 AND year = 2020 AND day = 28 AND duration < 60 AND caller IN (
SELECT phone_number
FROM people
WHERE name = 'Ernest'
);

--Accomplice name
SELECT name FROM people
WHERE phone_number IN (
SELECT receiver
FROM phone_calls
WHERE month = 7 AND year = 2020 AND day = 28 AND duration < 60 AND caller IN (SELECT phone_number
FROM people
WHERE name = 'Ernest')
);