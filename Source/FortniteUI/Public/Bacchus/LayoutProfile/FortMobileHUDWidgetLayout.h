// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/CanvasPanelSlot.h"
#include "FortMobileHUDWidgetLayout.generated.h"

USTRUCT()
struct FFortMobileHUDWidgetLayout
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	FAnchorData LayoutData;

	UPROPERTY(Transient)
	int32 ZOrder;

};

