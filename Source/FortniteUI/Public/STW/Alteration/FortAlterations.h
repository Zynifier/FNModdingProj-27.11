// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortAlterations.generated.h"

class UFortAlterationItemDefinition;
class UFortItem;
enum class EFortRarity : uint8;

UENUM(BlueprintType)
enum class EFortAlterationWidgetState : uint8
{
	Normal = 0,
	Upgrade = 1,
	Evolution = 2,
};

UCLASS(BlueprintType)
class UFortAlterationInfo : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="FortAlteration")
	UFortAlterationItemDefinition* GetAlterationDefintion() const;

	UFUNCTION(BlueprintPure, Category="FortAlteration")
	UFortItem* GetCorrespondingItem() const;

	UFUNCTION(BlueprintPure, Category="FortAlteration")
	float GetCurrentPipCount(float MaxPips) const;

	UFUNCTION(BlueprintPure, Category="FortAlteration")
	EFortRarity GetRarity() const;

	UFUNCTION(BlueprintPure, Category="FortAlteration")
	int32 GetRequiredLevel() const;

	UFUNCTION(BlueprintPure, Category="FortAlteration")
	int32 GetSlotIndex() const;

	UFUNCTION(BlueprintPure, Category="FortAlteration")
	bool IsAlterationHighlighted() const;

	UFUNCTION(BlueprintPure, Category="FortAlteration")
	bool IsAlterationUnlocked() const;

	UFUNCTION(BlueprintPure, Category="FortAlteration")
	bool IsFreeAlterationChoice() const;

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortItem> CorrespondingItem;

	UPROPERTY(Transient)
	int32 SlotIndex;

	UPROPERTY(Transient)
	TObjectPtr<UFortAlterationItemDefinition> AlterationDef;

	UPROPERTY(Transient)
	int32 RequiredMinLevel;

	UPROPERTY(Transient)
	bool bIsUpgrade;

	UPROPERTY(Transient)
	int32 CurrentItemLevel;

	UPROPERTY(Transient)
	bool bFreeAlterationSlot;

	UPROPERTY(Transient)
	bool bUnlockedByEvolution;

	UPROPERTY(Transient)
	int32 UpgradeLevelDelta;

};

