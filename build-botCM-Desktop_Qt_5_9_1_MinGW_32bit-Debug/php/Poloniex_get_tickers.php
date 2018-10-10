<?php
/**
 * Created by PhpStorm.
 * User: Yuri
 * Date: 27/02/2018
 * Time: 19:42
 */
require_once "Poloniex.php";
require_once "funcoes.php";

$trader = new Poloniex('EPET7WRX-F8D7ZJJ3-DTHE75JB-SHF65WA9', '8978ac924a9726dae3bc0db7787d02f0eac0f17cd5cbdf731992b9c6c9a8e4be965388de5d6772ec63ea0cf77ce5bea46d4de20cdbdedb3c30816af1779a64ad');

$candles = [];
$instante = time();
$balances = $trader->get_balances();
$tickers = $trader->get_ticker('USDT_BTC');

if(ComparaMA(MA('USDT_BTC', 900, 9), MA('USDT_BTC', 900, 40)) > 1.7){
	if($balances['USDT'] > 1){
		$amount = $balances['USDT'] / $tickers['lowestAsk'];
		$price = $tickers['lowestAsk'];
		var_dump('Compra: ' . $amount . ' por: ' . $price . ' Paga ' . $balances['USDT']);
		$trader->buy('USDT_BTC', $price, $amount);
	}
} else if(ComparaMA(MA('USDT_BTC', 900, 9), MA('USDT_BTC', 900, 40)) < -1.7){
	if($balances['BTC'] > 0.001){
		$amount = $balances['BTC'];
		$price = $tickers['lowestAsk'];
		var_dump('venda: ' . $amount . ' por: ' . $price . ' recebe ' . $balances['USDT']);
		var_dump($trader->sell('USDT_BTC', $price, $amount));	
	}
}