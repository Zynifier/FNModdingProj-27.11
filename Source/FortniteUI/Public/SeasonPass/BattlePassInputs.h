// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BattlePassInputs.generated.h"

UENUM(BlueprintType)
enum class EBattlePassInputs : uint8
{
	Back = 0,
	ViewItem = 1,
	PreviewAction = 2,
	ReplayTrailer = 3,
	ShowAbout = 4,
	BulkBuyRewards = 5,
	PageComplete = 6,
	ShowAboutCustomization = 7,
	GiftBattlePass = 8,
	SwipeLeft = 9,
	SwipeRight = 10,
	COUNT = 11 UMETA(Hidden),
};

UCLASS(BlueprintType, Blueprintable)
class FORTNITEUI_API UBattlePassInputData : public UObject
{
	GENERATED_BODY()

};

UCLASS(BlueprintType, Blueprintable)
class FORTNITEUI_API UBattlePassBulkBuyInputData : public UBattlePassInputData
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	void GetData(bool& IsPageCompleted, int32& StartingPage, int32& EndingPage, int32& PurchaseCost);

};

UCLASS(BlueprintType, Blueprintable)
class FORTNITEUI_API UBattlePassEnabledInputData : public UBattlePassInputData
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	void GetData(bool& InIsEnabled);

};

