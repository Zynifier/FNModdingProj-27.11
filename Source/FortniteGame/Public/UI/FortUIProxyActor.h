// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Abilities/FortAbilitySystemInterface.h"
#include "Attributes/FortAttributeInitializationKey.h"
#include "FortDamageSourceInterface.h"
#include "FortUIProxyActor.generated.h"

class UAttributeSet;
class UFortAbilitySystemComponent;
class UFortItemDefinition;

UCLASS(MinimalAPI)
class AFortUIProxyActor : public AActor, public IFortAbilitySystemInterface, public IFortDamageSourceInterface
{
	GENERATED_BODY()

public:
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Attributes", meta=(EditInline="true"))
	TArray<TObjectPtr<UAttributeSet>> AttributeSets;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UFortItemDefinition> ItemDef;

	UPROPERTY()
	FFortAttributeInitializationKey InitializerKey;

};

