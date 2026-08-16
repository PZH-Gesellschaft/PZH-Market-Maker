# PZH Market Maker

*PZH Market Maker (PZHMM) is a HFT bot with the strategy of market maker*
*This bot create consideration FINMA Regulation* 

## List Supporterd Exchanges

These are the exchanges that the bot officially supports

1. Binance
2. Kraken

## Dependencies

1. yyjson
2. libcrypto
3. openssl
4. libwebsockets

# Formats

The file used to define what is to be bought or sold is `setting.json`
which must be placed in the same folder as the one where you run the bot

## Setting Format

```json
{	
	"exchange": [ // List of the exchanges to operate
		"binance",
		"kraken"
	],

	"threads": 2 // The number of threads indicates the number of exchanges on which trading will take place
}
```

## Exchange Format

```json
{	
	"symbol": "", // Symbol to operate

	"bid":   10,  // Limit of orders on bid
	"ask":   10,  // Limit of orders on ask
	"size":  10,  // Size of the orders
	"limit": 700, // Inventory limit
	
	"gamma": 0.1, // Risk Aversion
	
	"apikey":    "", // Public Apikey
	"apisecret": "", // Secret Apikey

	"exit": false,       // If true, exit of the program
	"keep_orders": false // If this is true, it does not cancel the orders if the symbol is changed
}
```