// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UObject/NoExportTypes.h"
#include "Items/FortItemTypeEnum.h"
#include "BaseValidationDataRepository.generated.h"

class UFortBaseValidator;
class UObject;

USTRUCT()
struct FFortValidationData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Validation")
	TArray<TSoftObjectPtr<UObject>> ValidationObjects;

	UPROPERTY(EditDefaultsOnly, Category="Validation")
	TArray<EFortItemType> ValidationObjectTypes;

	UPROPERTY(EditInstanceOnly, Instanced, Category="Validation")
	TArray<TObjectPtr<UFortBaseValidator>> Validators;

};

UCLASS()
class UFortBaseValidationDataRepository : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Validation")
	TArray<FFortValidationData> ValidationData;

};

UCLASS(Abstract, EditInlineNew, NotBlueprintable)
class UFortBaseValidator : public UObject
{
	GENERATED_BODY()

};

