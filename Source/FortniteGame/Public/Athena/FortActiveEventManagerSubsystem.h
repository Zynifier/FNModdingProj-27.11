// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "FortActiveEventManagerSubsystem.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnActiveEventHotfixesApplied);

UCLASS(meta=(DisplayName="Fort Active Events Manager"))
class UFortActiveEventManagerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintAssignable)
	FOnActiveEventHotfixesApplied OnActiveEventHotfixesApplied;

};

