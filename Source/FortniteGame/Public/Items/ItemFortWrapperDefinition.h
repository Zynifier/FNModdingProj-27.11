// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ItemDefinitionBase.h"
#include "ItemFortWrapperDefinition.generated.h"

class UFortItemDefinition;
class UItemComponentBase;

UCLASS()
class FORTNITEGAME_API UItemFortWrapperDefinition : public UItemDefinitionBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="ItemFortWrapperDefinition")
	TObjectPtr<UFortItemDefinition> FortItemDefinition;

	UPROPERTY(Transient)
	TArray<TSubclassOf<UItemComponentBase>> FortItemComponentList;

};

