// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "STW/Heroes/FortCharacter.h"
#include "FortDefenderItem.generated.h"

class UFortAlterationItemDefinition;
enum class EFortDefenderSubtype : uint8;

UCLASS(MinimalAPI, BlueprintType)
class UFortDefenderItem : public UFortCharacter
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	EFortDefenderSubtype GetDefenderSubtype() const;

protected:
	UPROPERTY()
	TArray<FString> alterations;

	UPROPERTY()
	TArray<TObjectPtr<UFortAlterationItemDefinition>> AlterationInstances;

};

