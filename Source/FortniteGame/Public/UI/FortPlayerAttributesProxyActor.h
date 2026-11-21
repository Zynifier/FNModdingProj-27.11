// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Abilities/FortAbilitySystemInterface.h"
#include "Player/FortPlayerState.h"
#include "FortPlayerAttributesProxyActor.generated.h"

class UFortAbilitySystemComponent;

UCLASS()
class AFortPlayerAttributesProxyActor : public AActor, public IFortAbilitySystemInterface
{
	GENERATED_BODY()

public:
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

private:
	UPROPERTY()
	FFortPlayerAttributeSets AttributeSets;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortAbilitySystemComponent> AbilitySystemComponent;

};

