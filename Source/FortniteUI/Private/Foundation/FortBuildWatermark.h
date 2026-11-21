// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "FortBuildWatermark.generated.h"

class UTextBlock;

UCLASS(Abstract, Config=Game, meta=(DisableNativeTick))
class UFortBuildWatermark : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void UpdateWatermark();

	UPROPERTY(BlueprintReadOnly, Export, Category="FortBuildWatermark", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> Text_BuildWatermark;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortBuildWatermark", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> Text_McpVersion;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortBuildWatermark", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> Text_CalendarOffset;

};

