// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SolUserWidget.generated.h"

/**
 * UMG VPL wrapper widget. Sub-class this in Blueprints to create/host a VPL widget.
 * Makes/Generates a VPL from the provided "data source" (model).
 */
UCLASS(Abstract)
class SOLARISUI_API USolUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	USolUserWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};

