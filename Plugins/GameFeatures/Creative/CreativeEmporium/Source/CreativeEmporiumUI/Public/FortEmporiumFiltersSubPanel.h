// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortEmporiumFiltersSubPanel.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortEmporiumFiltersSubPanel : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortEmporiumFiltersSubPanel(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};

