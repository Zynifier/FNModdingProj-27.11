// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortScriptedAction.h"
#include "CheckTutorialAndLeavePartyActionBase.generated.h"

class AFortPlayerController;

UCLASS(Abstract, BlueprintType, Blueprintable, HideCategories=("Actor", "Navigation", "Replication", "Actor", "Navigation", "Replication"))
class ACheckTutorialAndLeavePartyActionBase : public AFortScriptedAction
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerController> PlayerController;

};

