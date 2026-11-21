// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Collections/FortCollectionData.h"
#include "FortCollectionData_PlayerAugment.generated.h"

class UFortPlayerAugmentItemDefinition;

UCLASS(MinimalAPI)
class UFortCollectionDataEntryPlayerAugment : public UFortCollectionDataEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortCollectionDataEntryPlayerAugment")
	TObjectPtr<UFortPlayerAugmentItemDefinition> PlayerAugmentItemDefinition;

	UPROPERTY(EditDefaultsOnly, Category="FortCollectionDataEntryPlayerAugment")
	FText AdditionalDescription;

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleDefaultsOnly, Transient, Category="FortCollectionDataEntryPlayerAugment")
	FText EntryName;
#endif

};

UCLASS(MinimalAPI)
class UFortCollectionDataPlayerAugment : public UFortCollectionData
{
	GENERATED_BODY()

};

