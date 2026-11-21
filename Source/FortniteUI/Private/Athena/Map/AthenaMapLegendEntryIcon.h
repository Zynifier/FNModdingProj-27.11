// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AthenaMapLegendEntryIcon.generated.h"

class UFortLazyImage;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaMapLegendEntryIcon : public UCommonUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> FortLazyImage_LegendIcon;

};

