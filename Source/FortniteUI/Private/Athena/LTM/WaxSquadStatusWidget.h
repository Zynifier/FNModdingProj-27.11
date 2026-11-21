// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AthenaPlayerInfoBaseWidgetInterface.h"
#include "Athena/LTM/LTMWidgetBase.h"
#include "WaxSquadStatusWidget.generated.h"

enum class EWaxState : uint8;

UCLASS()
class UWaxSquadStatusWidget : public ULTMWidgetBase, public IAthenaPlayerInfoBaseWidgetInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateLives(int32 NewScore);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateScore(int32 NewScore);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateThreatValue(EWaxState NewWaxState);

};

