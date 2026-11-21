// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "StyleSheetCollection.generated.h"

class UStyleSheet;

/**
 * This class is used to group style sheets.
 */
UCLASS(BlueprintType)
class UStyleSheetCollection : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Style Sheets")
	TArray<TObjectPtr<UStyleSheet>> StyleSheets;

};

