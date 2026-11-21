// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "AthenaNewsStructs.generated.h"

UENUM(BlueprintType)
enum class EAthenaNewsEntryType : uint8
{
	Text = 0,
	Item = 1,
	Website = 2,
	NavigateToTab = 3,
	Challenge = 4,
	Setting = 5,
	SpatialScreen = 6,
	SmallNews = 7,
	NavigateToBattlePassSubPage = 8,
	Creative = 9,
	NavigateToSubscriptionSubPage = 10,
	ProgressiveItemLearnMore = 11,
	ProgressiveItemReminder = 12,
	ProgressiveItemClaimRewards = 13,
	Event = 14,
	Discovery = 15,
	NavigateToCompetitiveSubPage = 16,
	NavigateToSocialMenu = 17,
	NavigateToSocialTagsSubPage = 18,
	NavigateToRebootRallySubPage = 19,
	NavigateToMapSubPage = 20,
	NavigateToHabaneroSubPage = 21,
	Invalid = 22,
};

UENUM(BlueprintType)
enum class EAthenaNewsStyle : uint8
{
	None = 0,
	SpecialEvent = 1,
	SpecialEvent2 = 2,
};

USTRUCT(BlueprintType)
struct FAthenaEmergencyNotice
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="AthenaEmergencyNotice")
	FString Title;

	UPROPERTY(BlueprintReadOnly, Category="AthenaEmergencyNotice")
	FString Body;

};

USTRUCT(BlueprintType)
struct FImageRef
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="ImageRef")
	int32 Width;

	UPROPERTY(BlueprintReadOnly, Category="ImageRef")
	int32 Height;

	UPROPERTY(BlueprintReadOnly, Category="ImageRef")
	FString Url;

};

USTRUCT(BlueprintType)
struct FAthenaMOTDBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="AthenaMOTDBase")
	EAthenaNewsEntryType EntryType;

	UPROPERTY(BlueprintReadOnly, Category="AthenaMOTDBase")
	FString Title;

	UPROPERTY(BlueprintReadOnly, Category="AthenaMOTDBase")
	FString Body;

	UPROPERTY(BlueprintReadOnly, Category="AthenaMOTDBase")
	TArray<FImageRef> Images;

	UPROPERTY(BlueprintReadOnly, Category="AthenaMOTDBase")
	TArray<FImageRef> TileImages;

	UPROPERTY(BlueprintReadOnly, Category="AthenaMOTDBase")
	FColor CustomDarkColor;

	UPROPERTY(BlueprintReadOnly, Category="AthenaMOTDBase")
	FColor CustomLightColor;

	UPROPERTY(BlueprintReadOnly, Category="AthenaMOTDBase")
	FString AdSpace;

	UPROPERTY(BlueprintReadOnly, Category="AthenaMOTDBase")
	FString TabTitleOverride;

	UPROPERTY(BlueprintReadOnly, Category="AthenaMOTDBase")
	FString ButtonTextOverride;

	UPROPERTY(BlueprintReadOnly, Category="AthenaMOTDBase")
	bool bHasCustomColor;

	UPROPERTY(BlueprintReadOnly, Category="AthenaMOTDBase")
	bool bIsFtueMotd;

};

USTRUCT(BlueprintType)
struct FAthenaMessageEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="AthenaMessageEntry")
	FString Title;

	UPROPERTY(BlueprintReadOnly, Category="AthenaMessageEntry")
	FString Body;

	UPROPERTY(BlueprintReadOnly, Category="AthenaMessageEntry")
	FString Image;

	UPROPERTY(BlueprintReadOnly, Category="AthenaMessageEntry")
	FString Type;

	UPROPERTY(BlueprintReadOnly, Category="AthenaMessageEntry")
	FString AdSpace;

};

USTRUCT(BlueprintType)
struct FChallengeMOTD : public FAthenaMOTDBase
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FCreativeMOTD : public FAthenaMOTDBase
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FDiscoveryMOTD : public FAthenaMOTDBase
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FEventMOTD : public FAthenaMOTDBase
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FItemMOTD : public FAthenaMOTDBase
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FNavigateToBattlePassSubPageMOTD : public FAthenaMOTDBase
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FNavigateToCompetitiveSubPageMOTD : public FAthenaMOTDBase
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FNavigateToHabaneroSubPageMOTD : public FAthenaMOTDBase
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FNavigateToMapSubPageMOTD : public FAthenaMOTDBase
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FNavigateToRebootRallySubPageMOTD : public FAthenaMOTDBase
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FNavigateToSocialMenuMOTD : public FAthenaMOTDBase
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FNavigateToSocialTagsSubPageMOTD : public FAthenaMOTDBase
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FNavigateToSubscriptionSubPageMOTD : public FAthenaMOTDBase
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FNavigateToTabMOTD : public FAthenaMOTDBase
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FSettingsMOTD : public FAthenaMOTDBase
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FSmallNewsMOTD : public FAthenaMOTDBase
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FSpatialScreenMOTD : public FAthenaMOTDBase
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FWebsiteMOTD : public FAthenaMOTDBase
{
	GENERATED_BODY()

};

