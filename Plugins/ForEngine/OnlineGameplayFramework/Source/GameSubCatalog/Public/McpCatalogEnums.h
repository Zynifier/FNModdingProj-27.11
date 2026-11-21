// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "McpCatalogEnums.generated.h"

UENUM()
enum class EAppStore : uint8
{
	/** fake store that just short-circuits with success (this is only enabled in dev environments). */
	DebugStore = 0 UMETA(Hidden),
	EpicPurchasingService = 1,
	IOSAppStore = 2,
	WeGameStore = 3,
	GooglePlayAppStore = 4,
	KindleStore = 5,
	PlayStation4Store = 6 UMETA(DisplayName="PlayStation 4 Store"),
	XboxLiveStore = 7,
	NintendoEShop = 8,
	SamsungGalaxyAppStore = 9,
	MicrosoftStore = 10,
	PlayStation5Store = 11 UMETA(DisplayName="PlayStation 5 Store"),
	MAX = 12 UMETA(Hidden),
};

UENUM()
namespace ECatalogSaleType
{
	enum Type
	{
		/** Not on sale */
		NotOnSale = 0 UMETA(Hidden),
		/** Just show new price */
		UndecoratedNewPrice = 1,
		/** Amount off */
		AmountOff = 2,
		/** Percent off */
		PercentOff = 3,
		/** Percent on */
		PercentOn = 4,
		/** Show regular price stricken out*/
		Strikethrough = 5,
		MAX = 6 UMETA(Hidden),
	};
}

UENUM()
namespace EStoreCurrencyType
{
	enum Type
	{
		/** Purchase this with real money. Use CurrencySubType to specify the currency code (e.g. "USD"). */
		RealMoney = 0,
		/** Purchased currency. Divided into 3 types: Earned, PurchaseBonus, and Purchased (transparent to players). */
		MtxCurrency = 1,
		/** Arbitrary item. Use CurrencySubType to specify a templateId to use. */
		GameItem = 2,
		/** Game-specific interpretation. Use CurrencySubType to further qualify. */
		Other = 3,
		MAX = 4 UMETA(Hidden),
	};
}

