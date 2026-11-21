// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "FortPreferredItemSlotSettings.generated.h"

class UTexture2D;

UENUM(BlueprintType)
enum class EFortPreferredItemSlotItemType : uint8
{
	Unassigned = 0,
	AssaultRifle = 1,
	Shotgun = 2,
	SMG = 3,
	Pistol = 4,
	SniperAndBow = 5,
	Launcher = 6,
	Utility = 7,
	Consumable = 8,
	Num = 9 UMETA(Hidden),
};

USTRUCT(BlueprintType)
struct FPreferredItemSlotSettingData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PreferredItemSlotSettingData")
	FGameplayTag OverrideTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PreferredItemSlotSettingData")
	FGameplayTagContainer GameplayTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PreferredItemSlotSettingData")
	TObjectPtr<UTexture2D> Icon;

};

UCLASS()
class UFortPreferredItemSlotSettings : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortPreferredItemSlotSettings")
	TMap<EFortPreferredItemSlotItemType, FPreferredItemSlotSettingData> SlotItemTypeData;

};

