// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/LTMWidgetBase.h"
#include "TagTeamCountWidget.generated.h"

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UTagTeamCountWidget : public ULTMWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void SetBlueTeamSize(int32 TeamSize, int32 TotalSize);

	UFUNCTION(BlueprintImplementableEvent)
	void SetCurrentTeam(uint8 CurrentTeam);

	UFUNCTION(BlueprintImplementableEvent)
	void SetRedTeamSize(int32 TeamSize, int32 TotalSize);

};

