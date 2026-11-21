// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/FortGameplayAbility.h"
#include "FortGameplayAbility_Action.generated.h"

UCLASS(MinimalAPI)
class UFortGameplayAbility_Action : public UFortGameplayAbility
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Activation")
	FName ActionName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Activation")
	TArray<FName> ExtraActionNames;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Activation")
	bool bActivateOnInputPress;

};

