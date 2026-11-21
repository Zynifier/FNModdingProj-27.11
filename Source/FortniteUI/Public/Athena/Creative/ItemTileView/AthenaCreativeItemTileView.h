// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonTileView.h"
#include "AthenaCreativeItemTileView.generated.h"

class UFortItem;
class UFortOptionsTab;

UCLASS(BlueprintType)
class UAthenaCreativeItemTileView : public UCommonTileView
{
	GENERATED_BODY()

public:
	UAthenaCreativeItemTileView(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UPROPERTY(BlueprintReadWrite, Export, Category="Hierarchy", meta=(EditInline="true"))
	TObjectPtr<UFortOptionsTab> ParentTab;

	UPROPERTY(BlueprintReadWrite, Category="Loading Data")
	TObjectPtr<UFortItem> CurrentlyFocusedItem;

};

