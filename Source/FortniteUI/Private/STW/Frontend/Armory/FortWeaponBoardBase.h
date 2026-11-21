// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "FortWeaponBoardBase.generated.h"

class UFortAccountItem;

USTRUCT(BlueprintType)
struct FFortWeaponBoardDisplaySlot
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponBoardDisplaySlot")
	FGameplayTag RequiredTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponBoardDisplaySlot")
	FTransform MeshRelativeTransform;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponBoardDisplaySlot")
	FVector LocalOffsetMultiplier;

};

USTRUCT()
struct FFortWeaponBoardDisplaySlotItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FFortWeaponBoardDisplaySlot DisplaySlot;

};

UCLASS(BlueprintType)
class AFortWeaponBoardBase : public AActor
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnDisplaySlotItemChanged(FFortWeaponBoardDisplaySlot DisplaySlot, UFortAccountItem* Item);

	UFUNCTION(BlueprintCallable)
	void PopulateDisplaySlotsWithBestWeapons();

	UFUNCTION(BlueprintCallable)
	void PopulateDisplaySlotsWithRandomWeapons();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponBoardBase")
	TArray<FFortWeaponBoardDisplaySlot> RangedWeaponDisplaySlots;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponBoardBase")
	TArray<FFortWeaponBoardDisplaySlot> MeleeWeaponDisplaySlots;

private:
	UFUNCTION()
	void HandleAsyncLoadComplete();

	UPROPERTY()
	TArray<FFortWeaponBoardDisplaySlotItem> DisplaySlotItemList;

};

