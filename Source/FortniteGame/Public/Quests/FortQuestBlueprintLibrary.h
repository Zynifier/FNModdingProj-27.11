// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FortQuestBlueprintLibrary.generated.h"

class AActor;
class UFortPlayerStateComponent_Quests;
class UFortQuestItem;
class UFortQuestItemDefinition;
class UObject;

UCLASS()
class UFortQuestBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Quest")
	static UFortPlayerStateComponent_Quests* GetQuestComponentForPlayerObject(const UObject* InObject);

	UFUNCTION(BlueprintCallable, Category="Quest")
	static UFortQuestItem* GetQuestFromDefinition(const AActor* QuestOwner, const UFortQuestItemDefinition* QuestDefinition);

};

