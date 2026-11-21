// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortTemporaryItemsRow.generated.h"

class UTileView;
enum class EAthenaCustomizationCategory : uint8;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortTemporaryItemsRow : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortTemporaryItemsRow(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintPure)
	FText GetCategoryText(const EAthenaCustomizationCategory InCategory) const;

protected:
	UFUNCTION(BlueprintCallable)
	void SetTileView(UTileView* InTileView);

};

