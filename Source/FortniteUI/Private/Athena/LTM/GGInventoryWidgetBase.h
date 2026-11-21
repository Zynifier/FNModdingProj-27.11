// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/GGWidgetBase.h"
#include "GGInventoryWidgetBase.generated.h"

class UFortWeaponItemDefinition;
class UTexture2D;
enum class EFortRarity : uint8;

UCLASS()
class UGGInventoryWidgetBase : public UGGWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void LastWeaponReached();

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateWidgetForNewWeapon(UTexture2D* Texture, EFortRarity Rarity);

	UPROPERTY(BlueprintReadOnly, Category="GGInventoryWidgetBase")
	TObjectPtr<UFortWeaponItemDefinition> NextItemToDisplay;

private:
	UFUNCTION()
	void OnLocalPlayerNewWeapon(UFortWeaponItemDefinition* NewWeapon);

};

