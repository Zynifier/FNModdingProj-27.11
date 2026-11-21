// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortItem.h"
#include "FortPersistableItem.generated.h"

class UFortPersistableItemDefinition;

UCLASS(MinimalAPI, NotBlueprintable)
class UFortPersistableItem : public UFortItem
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TObjectPtr<UFortPersistableItemDefinition> ItemDefinition;

	UPROPERTY(BlueprintReadOnly, Category="FortPersistableItem")
	FString InstanceId;

	UPROPERTY(BlueprintReadOnly, Category="FortPersistableItem")
	FString TemplateId;

	UPROPERTY(BlueprintReadOnly, Category="FortPersistableItem")
	int32 Quantity;

	UPROPERTY()
	bool bIsLocalOnlyItem;

};

