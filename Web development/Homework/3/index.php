<?php

/**
 * This is the main file which receives and analyzes data, 
 * generates response data and finally calls the template.
 */

// show all warnings and errors on the screen
error_reporting(E_ALL);
ini_set('display_errors', 1);

$currencies = array ("USD"=>"US dollar",
"JPY"=>"Japanese yen",
"BGN"=>"Bulgarian lev",
"CZK"=>"Czech koruna",
"DKK"=>"Danish krone",
"GBP"=>"Pound sterling",
"HUF"=>"Hungarian forint",
"PLN"=>"Polish zloty",
"RON"=>"Romanian leu",
"SEK"=>"Swedish krona",
"CHF"=>"Swiss franc",
"ISK"=>"Icelandic krona",
"NOK"=>"Norwegian krone",
"HRK"=>"Croatian kuna",
"RUB"=>"Russian rouble",
"TRY"=>"Turkish lira",
"AUD"=>"Australian dollar",
"BRL"=>"Brazilian real",
"CAD"=>"Canadian dollar",
"CNY"=>"Chinese yuan renminbi",
"HKD"=>"Hong Kong dollar",
"IDR"=>"Indonesian rupiah",
"ILS"=>"Israeli shekel",
"INR"=>"Indian rupee",
"KRW"=>"South Korean won",
"MXN"=>"Mexican peso",
"MYR"=>"Malaysian ringgit",
"NZD"=>"New Zealand dollar",
"PHP"=>"Philippine peso",
"SGD"=>"Singapore dollar",
"THB"=>"Thai baht",
"ZAR"=>"South African rand");

// DO NOT EDIT BEFORE THIS LINE

/* Functions and classes You might want to use (you have to study function descriptions and examples)
 * Note: You can easily solve this task without using any regular expressions
file_get_contents() http://lv1.php.net/file_get_contents
file_put_contents() http://lv1.php.net/file_put_contents
file_exists() http://lv1.php.net/file_exists
round() http://lv1.php.net/round
SimpleXMLElement http://php.net/manual/en/simplexml.examples-basic.php http://php.net/manual/en/class.simplexmlelement.php 
date() http://lv1.php.net/manual/en/function.date.php or Date http://lv1.php.net/manual/en/class.datetime.php
Multiple string functions (choose by studying descriptions) http://lv1.php.net/manual/en/ref.strings.php
Multiple variable handling functions (choose by studying descriptions) http://lv1.php.net/manual/en/ref.var.php
Optionally you can use some array functions (with $_GET, $target_currencies) http://lv1.php.net/manual/en/ref.array.php
*/

// Your code goes here

$result = ""; //valid values: empty string, "OK", "ERROR"
$result_message = "";
$date = "";

function validateDate (&$date) 
{
    $newDate = DateTime::createFromFormat('m-d-Y', $date);
    $currentDay = intval($newDate->format('w')); 

    if ($currentDay === 0 || $currentDay === 6)
    {
        $newDate->modify("last Friday");
        $date = $newDate->format('m-d-Y');
    }
}

function validateInput (&$result, &$result_message, &$date) 
{
    if (empty($_GET['date']))
    {
        $result = "ERROR";
        $result_message = "Please enter a date!";
        
        return false;
    }

    $startDate = DateTime::createFromFormat("Y-m-d", "1999-01-04");
    $endDate = new DateTime();
    $currDate = DateTime::createFromFormat("Y-m-d", $_GET['date']);

    if (!($currDate > $startDate && $currDate <= $endDate))
    {
        $result = "ERROR";
        $result_message = "This date " .  $currDate->format('m-d-Y') . " is not between
        the " . $startDate->format('m-d-Y') . " and the " . $endDate->format('m-d-Y');

        return false;
    }

    $num = $_GET['amount'];

    if (!is_numeric($num) || intval($num) <= 0)
    {
        $result = "ERROR";
        $result_message = "Please enter a valid amount!";
        
        return false;
    }

    global $currencies;
    
    if (!array_key_exists($_GET['currency'], $currencies))
    {
        $result = "ERROR";
        $result_message = "Please enter a valid currency!";
        
        return false;
    }

    $result = "OK";
    $date = $currDate->format('m-d-Y');
    return true;
}

function validateXML($currency, &$result, &$result_message)
{
    set_error_handler(function() { }); 
    // Surpress warnings, if we can't get content

    $url = 'https://www.ecb.europa.eu/stats/policy_and_exchange_rates/euro_reference_exchange_rates/html/' . $currency . '.xml';
    $content = file_get_contents($url);

    if ($content === false) 
    // Warnings were outputted, so we deal with them
    {
        $result = "ERROR";
        $result_message = "The service is currenty unavailable!";
        restore_error_handler();

        return false;
    }

    file_put_contents("xml/" . $currency . ".xml", $content);

    restore_error_handler();
    // Warnings are visible again

    return true;
}

function GetConversionRate($currency, &$result, &$result_message, $date) 
{
    $dir = "xml/" . $currency . ".xml";
    $fileCreated = false;

    if (!file_exists($dir))
    {
        if (!validateXML($currency, $result, $result_message))
        {
            return 0;
        }

        $fileCreated = true;
    }

    $xml = simplexml_load_file($dir);

    if ($xml === false) 
    { 
        $result = "ERROR";
        $result_message = "Sorry, could not load the document!";
    }else
    {
        $items = $xml->DataSet->Series->Obs;
        $item = $items[sizeof($items) - 1];

        $lastXMLDate = DateTime::createFromFormat("Y-m-d", $item["TIME_PERIOD"]);
        $dateObject = DateTime::createFromFormat("m-d-Y", $date);

        if ($lastXMLDate < $dateObject && !$fileCreated)
        // If we don't check for fileCreated, then the program will execute
        // the same code twice, when there is no file in the xml directory,
        // which is resource inefficient, so we prevent this by checking if
        // the file was created in this execution, if it is, we don't execute
        // the code below
        {
            if (!validateXML($currency, $result, $result_message))
            {
                return 0;
            }

            $xml = simplexml_load_file($dir);

            $items = $xml->DataSet->Series->Obs;
        }

        $dateObject = $dateObject->format("Y-m-d");

        foreach ($items as $i)
        {
            if (strval($i["TIME_PERIOD"]) === $dateObject)
            {
                return $i["OBS_VALUE"];
            }
        }

        $dateObject = DateTime::createFromFormat("Y-m-d", $dateObject);

        $result = "ERROR";
        $result_message = "EU still hasn't added this date " . $dateObject->format("m-d-Y") . " to their statistics, try again later!";

        return 0;
    }
}

if (validateInput($result, $result_message, $date)) 
{
    $currency = strtolower($_GET['currency']);
    $amount = $_GET['amount'];

    validateDate($date);

    $rate = GetConversionRate($currency, $result, $result_message, $date);

    if ($rate != 0) 
    // The rate will never be zero from the EU stats, if rate is 0
    // that means that something went wrong and I assigned it
    {
        $result = "OK";
        $value = round($amount / $rate, 2);
        $result_message = "$value";
    }
}

// DO NOT EDIT AFTER THIS LINE

require("view.php");