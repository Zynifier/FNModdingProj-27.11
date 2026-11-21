// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortItem.h"
#include "FortMetadataItem.generated.h"

class UFortMetadataItemDefinition;

UCLASS(NotBlueprintable)
class UFortMetadataItem : public UFortItem
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Category="FortMetadataItem")
	int32 level;

	UPROPERTY(BlueprintReadOnly, Category="FortMetadataItem")
	FString InstanceId;

	UPROPERTY(BlueprintReadOnly, Category="FortMetadataItem")
	FString TemplateId;

	UPROPERTY(BlueprintReadOnly, Category="FortMetadataItem")
	int32 Quantity;

private:
	UPROPERTY()
	TObjectPtr<UFortMetadataItemDefinition> ItemDefinition;

};

