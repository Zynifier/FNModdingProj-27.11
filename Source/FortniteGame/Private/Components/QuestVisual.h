// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "QuestVisual.generated.h"

class AFortPlayerController;
class UFortLocalPlayer;

UCLASS(Abstract)
class AQuestVisual : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void ObjectiveCompleted(AFortPlayerController* PlayerController);

	UFUNCTION(BlueprintImplementableEvent)
	void QuestCompleted(AFortPlayerController* PlayerController);

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortLocalPlayer> OwningLocalPlayer;

};

