-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Query to discover the crime scene description
SELECT id, description
FROM crime_scene_reports
WHERE month = 7
AND day = 28
AND street = 'Humphrey Street';

-- The witnesses mentioned the Bakery at 10:15am AND something around 10min later (time of the theft)
SELECT *
FROM bakery_security_logs
WHERE month = 7
AND day = 28
AND hour = 10;

-- I'll use the id numbers from the bakery to get the names and passatport numbers from the people how left the bakery right before the theft
SELECT *
FROM people
WHERE license_plate
IN (SELECT license_plate
    FROM bakery_security_logs
    WHERE month = 7
    AND day = 28
    AND hour = 10
    AND minute = 21
    OR minute = 23
    AND activity = 'exit'
    );

--  Used to read the interviews on the theft
SELECT * FROM interviews
WHERE year = 2021
AND month = 7
AND day = 28;

-- I want to know the records on atm transactions before eugene get into the bakery
SELECT * FROM atm_transactions
WHERE year = 2021
AND month = 7
AND day = 28
AND atm_location = 'Leggett Street'
AND transaction_type = 'withdraw';

-- See how took money that day before the theft
SELECT * FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
WHERE bank_accounts.account_number
IN (SELECT account_number FROM atm_transactions
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND atm_location = 'Leggett Street'
    AND transaction_type = 'withdraw'
    );

-- See call history from those people
SELECT caller, receiver, duration FROM phone_calls
WHERE caller
IN (SELECT phone_number FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
WHERE bank_accounts.account_number
IN (SELECT account_number FROM atm_transactions
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND atm_location = 'Leggett Street'
    AND transaction_type = 'withdraw'
    )
    );

-- See who took a flight in the next day
SELECT * FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
JOIN flights ON passengers.flight_id = flights.id
WHERE people.passport_number
IN (SELECT passport_number FROM people
    JOIN bank_accounts ON people.id = bank_accounts.person_id
    WHERE bank_accounts.account_number
    IN (SELECT account_number FROM atm_transactions
        WHERE year = 2021
        AND month = 7
        AND day = 28
        AND atm_location = 'Leggett Street'
        AND transaction_type = 'withdraw'
        )
    )
AND flights.year = 2021
AND flights.month = 7
AND flights.day = 29
AND flights.origin_airport_id = 8;

-- phone calls history from suspects
SELECT * FROM people
JOIN phone_calls ON phone_calls.caller = people.phone_number
WHERE phone_calls.year = 2021
AND phone_calls.month = 7
AND phone_calls.day = 28
AND phone_calls.duration < 60;

-- check the backery again
SELECT *
FROM bakery_security_logs
JOIN people ON bakery_security_logs.license_plate = people.license_plate
WHERE month = 7
AND day = 28
AND hour = 10;

-- all the data colected left me with only two options, Brunce and Diana
-- Brunce went to NYC at 8:20 and Diana to Boston at 16:00
-- The thief took the earliest flight out of fiftyville, so Bruce is the thief