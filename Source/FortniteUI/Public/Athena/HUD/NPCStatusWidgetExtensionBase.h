// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "NPCStatusWidgetExtensionBase.generated.h"

class AFortPawn;

UCLASS(Abstract)
class UNPCStatusWidgetExtensionBase : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetFortPawn(AFortPawn* FortPawn);

};

