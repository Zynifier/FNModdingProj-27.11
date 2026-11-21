// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortCollectionBookCategory.generated.h"

UCLASS(MinimalAPI, BlueprintType)
class UFortCollectionBookCategory : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortCollectionBookCategory")
	bool bIsCategoryUIExpanded;

protected:
	UPROPERTY(Transient)
	FName CategoryDataRowName;

	UPROPERTY(Transient)
	int32 SortPriority;

	UPROPERTY(Transient)
	TArray<FName> ChildrenPageIds;

};

