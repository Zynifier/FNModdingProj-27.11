// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/FortCosmeticLoadout.h"
#include "Cosmetics/Variants/FortCosmeticVariantTypes.h"
#include "Items/FortProfileItem.h"
#include "FortCosmeticLockerItem.generated.h"

class UWorld;

USTRUCT()
struct FFortCosmeticLockerSlotsActiveVariants
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FMcpVariantReader> Variants;

};

USTRUCT()
struct FFortCosmeticLockerSlots
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FString> Items;

	UPROPERTY()
	TArray<FFortCosmeticLockerSlotsActiveVariants> ActiveVariants;

};

USTRUCT()
struct FFortCosmeticLockerSlotData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TMap<EAthenaCustomizationCategory, FFortCosmeticLockerSlots> Slots;

};

UCLASS(NotBlueprintable)
class UFortCosmeticLockerItem : public UFortProfileItem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static bool IsValidLockerName(UWorld* ContextWorld, const FString& Candidate);

protected:
	UPROPERTY(meta=(DisplayName="LockerName"))
	FString locker_name;

	UPROPERTY()
	FString banner_icon_template;

	UPROPERTY()
	FString banner_color_template;

	UPROPERTY()
	int32 use_count;

	UPROPERTY()
	FFortCosmeticLockerSlotData locker_slots_data;

};

