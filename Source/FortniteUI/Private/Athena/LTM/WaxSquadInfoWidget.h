// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/LTMWidgetBase.h"
#include "WaxSquadInfoWidget.generated.h"

UCLASS()
class UWaxSquadInfoWidget : public ULTMWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void SetPlacement(int32 Placement);

	UFUNCTION(BlueprintImplementableEvent)
	void SetScore(int32 Score);

};

