// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ListViewBase.h"
#include "FortAthenaMOTDTileListView.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaMOTDTileListView : public UListViewBase
{
	GENERATED_BODY()

public:
	UFortAthenaMOTDTileListView(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UPROPERTY(EditAnywhere, Category="FortAthenaMOTDTileListView")
	bool bAllowFocus;

	UPROPERTY(EditAnywhere, Category="FortAthenaMOTDTileListView")
	bool bReturnFocusToSelection;

};

