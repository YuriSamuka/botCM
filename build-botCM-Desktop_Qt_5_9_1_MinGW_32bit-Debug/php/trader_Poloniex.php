<?php
/**
 * Created by PhpStorm.
 * User: Yuri
 * Date: 27/02/2018
 * Time: 19:42
 */
require_once "Poloniex.php";
require_once "funcoes.php";

define('TIME_FRAME', 300);
define('MEDIA_RAPIDA', 9);
define('MEDIA_LENTA', 40);

$trader = new Poloniex('EPET7WRX-F8D7ZJJ3-DTHE75JB-SHF65WA9', '8978ac924a9726dae3bc0db7787d02f0eac0f17cd5cbdf731992b9c6c9a8e4be965388de5d6772ec63ea0cf77ce5bea46d4de20cdbdedb3c30816af1779a64ad');

$candles = [];
$instante = time();
$balances = $trader->get_balances();
$tickers = $trader->get_ticker('USDT_BTC');

		/*$amount = $balances['USDT'] / $tickers['last'];
		$price = $tickers['last'];
		var_dump('Compra: ' . $amount . ' por: ' . $price . ' Paga ' . $balances['USDT']);
		$ordem = $trader->buy('USDT_BTC', $price, $amount);
		var_dump($ordem);
		die();*/


$range = ComparaMA(MA('USDT_BTC', TIME_FRAME, MEDIA_RAPIDA), MA('USDT_BTC', TIME_FRAME, MEDIA_LENTA));
if($range > 1.5){
	if($balances['USDT'] > 1){
		$amount = $balances['USDT'] / $tickers['last'];
		$price = $tickers['last'];
		var_dump('Compra: ' . $amount . ' por: ' . $price . ' Paga ' . $balances['USDT']);
		$ordem = $trader->buy('USDT_BTC', $price, $amount, 1);
		if(!isset($ordem['error'])){
			$aDados = [
				'tipo_operacao' => 'B',
				'preco' => $price,
				'montante' => $amount,
				'total' => $balances['USDT'],
				'rangec' => $range,
				'mar' => MA('USDT_BTC', TIME_FRAME, MEDIA_RAPIDA),
				'mal' => MA('USDT_BTC', TIME_FRAME, MEDIA_LENTA)
				];
			insert_db($aDados, 'btc_usdt');	
		}
	}
} else if($range < 0.5){
	if($balances['BTC'] > 0.001){
		$amount = $balances['BTC'];
		$price = $tickers['last'];
		var_dump('venda: ' . $amount . ' por: ' . $price . ' recebe ' . $balances['USDT']);
		$ordem = $trader->sell('USDT_BTC', $price, $amount, 1);
		var_dump($ordem);
		if(!isset($ordem['error'])){
			$aDados = [
						'tipo_operacao' => 'S',
						'preco' => $price,
						'montante' => $amount,
						'total' => $balances['USDT'],
						'rangec' => $range,
						'mar' => MA('USDT_BTC', TIME_FRAME, MEDIA_RAPIDA),
						'mal' => MA('USDT_BTC', TIME_FRAME, MEDIA_LENTA)
						];
			insert_db($aDados, 'btc_usdt');	
		}
	}
}