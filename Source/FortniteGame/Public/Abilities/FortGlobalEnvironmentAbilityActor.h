// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "Abilities/FortAbilitySystemInterface.h"
#include "FortGlobalEnvironmentAbilityActor.generated.h"

class UFortAbilitySystemComponent;
class UFortDamageSet;

UCLASS(HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortGlobalEnvironmentAbilityActor : public AInfo, public IFortAbilitySystemInterface
{
	GENERATED_BODY()

public:
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortDamageSet> DamageSet;

};

