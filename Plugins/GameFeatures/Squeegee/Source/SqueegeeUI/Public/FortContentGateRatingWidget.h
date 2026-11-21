// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Plugin/Squeegee/FortSqueegeeTypes.h"
#include "FortContentGateRatingWidget.generated.h"

UCLASS()
class UFortContentGateRatingWidget : public UFortSqueegeeWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnLabelUpdated(bool bLabelEnabled, const FText& LabelText, const FText& LabelNumber);

	UFUNCTION(BlueprintImplementableEvent)
	void OnStyleUpdated(const FSqueegeeStyleParams& StyleParams);

};

