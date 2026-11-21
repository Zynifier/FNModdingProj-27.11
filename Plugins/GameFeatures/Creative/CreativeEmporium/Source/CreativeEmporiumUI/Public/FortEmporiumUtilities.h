// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FortEmporiumUtilities.generated.h"

class UObject;
enum class EFortEmporiumItemLicense : uint8;

UENUM(BlueprintType)
enum class EFortEmporiumItemFilterMode : uint8
{
	Price = 0,
	License = 1,
};

UENUM(BlueprintType, meta=(Bitflags))
enum class EFortEmporiumItemLicense : uint8
{
	/** Invalid value, used for initialization */
	Invalid = 0,
	CC0 = 1,
	CC_BY = 2,
	CC_BY_SA = 4,
	CC_BY_NC = 8,
	CC_BY_NC_SA = 16,
	CC_BY_ND = 32,
	CC_BY_NC_ND = 64,
	Standard = 128,
	/** Helper value to indicate "any license type" */
	All = 255,
};

UENUM(BlueprintType, meta=(Bitflags))
enum class EFortEmporiumItemPriceFilter : uint8
{
	Invalid = 0,
	Free = 1,
	Premium = 2,
	All = 255,
};

UENUM(BlueprintType)
enum class EFortEmporiumItemSortMode : uint8
{
	/** Do not sort; use original MCP order */
	MCP = 0,
	/** Sort items in alphabetical order */
	AtoZ = 1,
	/** Sort items in reverse alphabetical order */
	ZtoA = 2,
	/** Sort items by lowest price */
	PriceLowToHigh = 3,
	/** Sort items by highest price */
	PriceHighToLow = 4,
	/** Sort items by ascending asset size */
	SizeLowToHigh = 5,
	/** Sort items by descending asset size */
	SizeHighToLow = 6,
};

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnEmporiumJSONReceived, bool, bSuccess, FString, JSONString);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnEmporiumLicenseTextReceived, bool, bSuccess, FString, LicenseText);

USTRUCT(BlueprintType)
struct FFortEmporiumFilterCategory
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortEmporiumFilterCategory")
	FName ID;

	UPROPERTY(EditDefaultsOnly, Category="FortEmporiumFilterCategory")
	FName ParentID;

	UPROPERTY(EditDefaultsOnly, Category="FortEmporiumFilterCategory")
	bool bIsTab;

	UPROPERTY(EditDefaultsOnly, Category="FortEmporiumFilterCategory")
	bool bShowCategoryModal;

	UPROPERTY(EditDefaultsOnly, Category="FortEmporiumFilterCategory")
	TArray<FName> SubcategoryIDList;

};

USTRUCT(BlueprintType)
struct FFortEmporiumFilterEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortEmporiumFilterEntry")
	FName ID;

	UPROPERTY(EditDefaultsOnly, Category="FortEmporiumFilterEntry")
	FText TextRoot;

	UPROPERTY(EditDefaultsOnly, Category="FortEmporiumFilterEntry")
	EFortEmporiumItemFilterMode Mode;

};

USTRUCT(BlueprintType)
struct FFortEmporiumItemLicenseData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortEmporiumItemLicenseData")
	FName ID;

	UPROPERTY(EditDefaultsOnly, Category="FortEmporiumItemLicenseData")
	FString Keyword;

	UPROPERTY(EditDefaultsOnly, Category="FortEmporiumItemLicenseData")
	FText Name;

	UPROPERTY(EditDefaultsOnly, Category="FortEmporiumItemLicenseData")
	EFortEmporiumItemLicense License;

	UPROPERTY(EditDefaultsOnly, Category="FortEmporiumItemLicenseData")
	FString URL;

};

USTRUCT(BlueprintType)
struct FFortEmporiumPriceFilterEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortEmporiumPriceFilterEntry")
	FName ID;

	UPROPERTY(EditDefaultsOnly, Category="FortEmporiumPriceFilterEntry")
	FText Text;

	UPROPERTY(EditDefaultsOnly, Category="FortEmporiumPriceFilterEntry")
	EFortEmporiumItemPriceFilter Filter;

};

USTRUCT(BlueprintType)
struct FFortEmporiumSortEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortEmporiumSortEntry")
	FText Text;

	UPROPERTY(EditDefaultsOnly, Category="FortEmporiumSortEntry")
	EFortEmporiumItemSortMode Mode;

};

UCLASS()
class UFortEmporiumUtilities : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	static const FText& GetCategoryDisplayName(const FName& CategoryID);

	UFUNCTION(BlueprintPure)
	static const FText& GetTextFromEmporiumLicense(const EFortEmporiumItemLicense License);

	UFUNCTION(BlueprintCallable, Category="Emporium", meta=(WorldContext="WorldContextObject"))
	static void RequestJSON(const UObject* WorldContextObject, const FUniqueNetIdRepl& UniqueNetId, const FString& JSONURL, const FOnEmporiumJSONReceived& Callback);

	UFUNCTION(BlueprintCallable, Category="Emporium")
	static void RequestLicenseText(const EFortEmporiumItemLicense License, const FOnEmporiumLicenseTextReceived& Callback);

};

