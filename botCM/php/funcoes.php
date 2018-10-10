<?php
function MA($par, $periodo, $comprimento){
	global $candles, $instante;
	$trader = new Poloniex('EPET7WRX-F8D7ZJJ3-DTHE75JB-SHF65WA9', '8978ac924a9726dae3bc0db7787d02f0eac0f17cd5cbdf731992b9c6c9a8e4be965388de5d6772ec63ea0cf77ce5bea46d4de20cdbdedb3c30816af1779a64ad');
	$start = $instante - $periodo * 50;
	if(empty($candles)){
		$candles = $trader->get_chart($par, $start, $instante, $periodo);		
	}
	$pricesClose = array_column($candles, 'close');
	$slice = 49 - $comprimento;
	$pricesClose = array_slice($pricesClose, $slice, 49, true);
	$sumCloseCandle = array_sum($pricesClose);
	$trader = null;
	return $sumCloseCandle/count($pricesClose);
}

function EMACalculator($limit,$array)
{
    $EMA_previous_day = $array[0];
    //print_r($array);
    $multiplier1 = (2/$limit+1);
    $EMA[]=array();
    $EMA = $array[0];
    $Close= $array[1];
    
    while($limit)
{    
    //echo"EMA is $EMA\n";
    $EMA = ($Close - $EMA_previous_day) * $multiplier1 + $EMA_previous_day;
    $EMA_previous_day= $EMA;
    
    $limit--;
}
return $EMA;
}

function ComparaMA($MA1, $MA2){
	global $candles;
	return (($MA1 - $MA2)*1000)/$candles[49]['close'];
}