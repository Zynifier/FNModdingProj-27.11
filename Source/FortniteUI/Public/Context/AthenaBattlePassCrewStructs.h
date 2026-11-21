// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/DateTime.h"
#include "Athena/ItemShop/AthenaItemShopEnums.h"
#include "McpCatalogEnums.h"
#include "Online/FortMcpProfileCommonCore.h"
#include "AthenaBattlePassCrewStructs.generated.h"

UENUM()
enum class ECrewDetailsTag : uint8
{
	SeasonLaunchBenefit = 0,
	MonthlyBenefit = 1,
	CrewMonthBenefit = 2,
	AvailableUntilBenefit = 3,
	MonthlySubscription = 4,
	None = 5,
};

UENUM()
enum class ECrewItemShopTileType : uint8
{
	None = 0,
	Subscription = 1,
	ProgressiveCosmetic = 2,
};

UENUM()
enum class ECrewTileType : uint8
{
	None = 0,
	Basic = 1,
	BattlePass = 2,
	CrewPack = 3,
	ProgressiveCosmetic = 4,
	TemporaryItems = 5,
};

USTRUCT()
struct FAthenaSubscriptionProgressiveInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FText> InfoModalEntries;

	UPROPERTY()
	FText NewStagesUnlockFinePrint;

};

USTRUCT()
struct FAthenaSubscriptionTemporaryItemsInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FText> InfoModalEntries;

};

USTRUCT()
struct FCrewTileImages
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString TileImageURL;

	UPROPERTY()
	FString NextTileImageURL;

};

USTRUCT()
struct FBattlePassPurchaseData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString BattlePassPurchaseBackgroundURL;

	UPROPERTY()
	FText BattlePassPurchaseDisclaimer;

	UPROPERTY()
	FText BattlePassScreenDisclaimer;

	UPROPERTY()
	FText BattlePassPurchaseLevelDisclaimer;

	UPROPERTY()
	FText BattlePassPurchaseDescription;

	UPROPERTY()
	FString BattlePassPurchaseConfirmBackgroundURL;

	UPROPERTY()
	FCrewTileImages BattlePassTileImages;

};

USTRUCT()
struct FCrewBenefits
{
	GENERATED_BODY()

};

USTRUCT()
struct FCrewDefaultData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FText Title;

	UPROPERTY()
	FText Description;

	UPROPERTY()
	FString BackgroundURL;

};

USTRUCT()
struct FCrewItemShopTileData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FText ViolatorText;

	UPROPERTY()
	EViolatorIntensity ViolatorIntensity;

	UPROPERTY()
	FText NextViolatorText;

	UPROPERTY()
	EViolatorIntensity NextViolatorIntensity;

	UPROPERTY()
	FCrewTileImages ItemShopTileImages;

};

USTRUCT()
struct FCrewItemShopTileEntry
{
	GENERATED_BODY()

public:
	UPROPERTY()
	ECrewItemShopTileType TileType;

	UPROPERTY()
	FCrewItemShopTileData TileData;

};

USTRUCT()
struct FCrewItemShopData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FCrewItemShopTileEntry> TileEntries;

};

USTRUCT()
struct FCrewPlatformAndCountriesPair
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EAppStore SubscriptionPlatform;

	UPROPERTY()
	FString CountryCodes;

};

USTRUCT(BlueprintType)
struct FCrewTableRow
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="CrewTableRow")
	TArray<FText> RowData;

	UPROPERTY(BlueprintReadOnly, Category="CrewTableRow")
	bool bIsHeaderRow;

};

USTRUCT()
struct FCrewPlatformTable
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EAppStore SubscriptionPlatform;

	UPROPERTY()
	TArray<FCrewTableRow> TableRows;

};

USTRUCT()
struct FORTNITEUI_API FCrewPlatformAndCountriesNotificationModal
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString NotificationId;

	UPROPERTY()
	TArray<FCrewPlatformAndCountriesPair> ValidPlatformAndCountriesPairs;

	UPROPERTY()
	FText Title;

	UPROPERTY()
	FText DefaultBodyText;

	UPROPERTY()
	FText BodyTextIfSubscriptionCanceled;

	UPROPERTY()
	FText BodyTextIfNoBodyTable;

	UPROPERTY()
	FText BodyTextIfNoBodyTableAndSubscriptionCanceled;

	UPROPERTY()
	FDateTime EffectiveDate;

	UPROPERTY()
	TArray<FCrewPlatformTable> PlatformSpecificBodyTables;

	UPROPERTY()
	FText CheckboxText;

	UPROPERTY()
	FText DefaultConfirmButtonText;

	UPROPERTY()
	FText ConfirmButtonTextIfSubscriptionCanceled;

	UPROPERTY()
	FText CancelSubscriptionButtonText;

	UPROPERTY()
	FText MoreInfoText;

	UPROPERTY()
	FText MoreInfoUrl;

	UPROPERTY()
	FDateTime NotificationStartDate;

	UPROPERTY()
	FDateTime NotificationEndDate;

};

USTRUCT()
struct FCrewSubscriptionStateModal
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EMcpSubscriptionState SubscriptionState;

	UPROPERTY()
	TArray<FText> BulletPoints;

};

USTRUCT()
struct FCrewModals
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FCrewSubscriptionStateModal> CancellationInfoErrorStateModals;

	UPROPERTY()
	TArray<FCrewPlatformAndCountriesNotificationModal> PlatformAndCountriesNotificationModals;

};

USTRUCT()
struct FSubscriptionModalInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ModalId;

	UPROPERTY()
	EAppStore PlatformId;

	UPROPERTY()
	TArray<FText> Entries;

	UPROPERTY()
	FString QrCodeImage;

};

USTRUCT()
struct FSubscriptionModals
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FSubscriptionModalInfo> Modals;

};

USTRUCT()
struct FCrewScreenData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FText CrewDisclaimer;

	UPROPERTY()
	FCrewDefaultData DefaultData;

	UPROPERTY()
	FCrewBenefits Benefits;

	UPROPERTY()
	FCrewModals CrewModals;

	UPROPERTY()
	FCrewItemShopData ItemShopData;

	UPROPERTY()
	FCrewItemShopTileData ItemShopTileData;

	UPROPERTY()
	FAthenaSubscriptionProgressiveInfo ProgressiveInfo;

	UPROPERTY()
	FAthenaSubscriptionTemporaryItemsInfo TemporaryItemsInfo;

	UPROPERTY()
	FSubscriptionModals SubModals;

};

USTRUCT()
struct FCrewTileDetailsData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString TileImageURL;

	UPROPERTY()
	FText Title;

	UPROPERTY()
	FText Description;

	UPROPERTY()
	ECrewDetailsTag Tag;

	UPROPERTY()
	FString BackgroundImageURL;

};

USTRUCT()
struct FCrewTileDataBasic
{
	GENERATED_BODY()

public:
	UPROPERTY()
	ECrewTileType TileType;

	UPROPERTY()
	FText TileLabel;

	UPROPERTY()
	FCrewTileDetailsData Details;

};

USTRUCT()
struct FCrewTileDataBattlePass : public FCrewTileDataBasic
{
	GENERATED_BODY()

};

USTRUCT()
struct FCrewTileDataCrewPack : public FCrewTileDataBasic
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FString> CrewPackItems;

	UPROPERTY()
	bool bHasNextCrewPackDetails;

	UPROPERTY()
	FCrewTileDetailsData NextDetails;

	UPROPERTY()
	TArray<FString> NextCrewPackItems;

};

USTRUCT()
struct FCrewTileDataProgressiveCosmetic : public FCrewTileDataBasic
{
	GENERATED_BODY()

};

USTRUCT()
struct FCrewTileDataTemporaryItems : public FCrewTileDataBasic
{
	GENERATED_BODY()

};

