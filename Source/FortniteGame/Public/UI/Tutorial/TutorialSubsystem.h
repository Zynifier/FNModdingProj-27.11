// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TutorialSubsystem.generated.h"

class AFortAthenaTutorialManager;

UCLASS(MinimalAPI)
class UTutorialSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Tutorial Subsystem")
	bool IsInTutorial() const;

private:
	UPROPERTY(Transient)
	TWeakObjectPtr<AFortAthenaTutorialManager> TutorialManager;

};

