// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Customization/CustomCosmeticModifierBase.h"
#include "FortCustomCharmTypeEnum.h"
#include "CustomCosmeticCharmModifier.generated.h"

class AFortPlayerCharm;
class UMeshComponent;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(ChildCanTick))
class ACustomCosmeticCharmModifier : public ACustomCosmeticModifierBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Custom Character")
	void ForceResetParticleSystems();

	UFUNCTION(BlueprintPure, Category="Custom Charm")
	virtual const EFortCustomCharmType::Type GetCharacterCharmType() const;

	UFUNCTION(BlueprintPure, Category="Custom Charm")
	AFortPlayerCharm* GetCharmOwner() const;

	UFUNCTION(BlueprintPure, Category="Custom Charm")
	UMeshComponent* GetSkeletalMeshForAssociatedPlayerPawnCharmType() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnCharmVisibilityChanged(bool bVisible);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void OnPawnAndCharmChanged();

private:
	UPROPERTY(Transient)
	TEnumAsByte<EFortCustomCharmType::Type> CharmType;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerCharm> MyCharmOwner;

};

