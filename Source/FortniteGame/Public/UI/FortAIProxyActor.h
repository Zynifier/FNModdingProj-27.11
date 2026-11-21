// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Chaos/ChaosEngineInterface.h"
#include "GameFramework/Actor.h"
#include "Abilities/FortAbilitySystemInterface.h"
#include "FortCombatTypes.h"
#include "FortDamageableActorInterface.h"
#include "FortAIProxyActor.generated.h"

class UFortAbilitySystemComponent;
class UFortDamageSet;
class UFortHealthSet;
class UFortMovementSet;

UCLASS()
class AFortAIProxyActor : public AActor, public IFortAbilitySystemInterface, public IFortDamageableActorInterface
{
	GENERATED_BODY()

public:
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	UPROPERTY()
	TEnumAsByte<EPhysicalSurface> PrimaryPhysicalSurface;

private:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortHealthSet> HealthSet;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortDamageSet> DamageSet;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortMovementSet> MovementSet;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TEnumAsByte<EFortBaseWeaponDamage::Type> BaseWeaponDamageResponseType;

};

