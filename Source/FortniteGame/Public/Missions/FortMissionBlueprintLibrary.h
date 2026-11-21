// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/MathFwd.h"
#include "Quests/QuestManagerComponents/FortQuestManagerComponent_Campaign.h"
#include "FortMissionBlueprintLibrary.generated.h"

class AFortPlayerController;
class AFortPlayerPawn;
class UAthenaGliderItemDefinition;
class UFortQuestItemDefinition;

UCLASS(meta=(ScriptName="FortMissionBlueprints"))
class UFortMissionBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Quests")
	static void BindPlayerToObjective(const AFortPlayerController* PlayerController, const UFortQuestItemDefinition* QuestItemDefinition, const FName QuestObjectiveBackendName, FBPOnObjectiveUpdated OnObjectiveUpdatedDelegate);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Quests")
	static void RemovePlayerCallbackFromObjective(const AFortPlayerController* PlayerController, const UFortQuestItemDefinition* QuestItemDefinition, const FName QuestObjectiveBackendName);

	UFUNCTION(BlueprintCallable, Category="Mission|Skydiving")
	static bool Skydive(bool bFromBus, AFortPlayerPawn* InPawn, const UAthenaGliderItemDefinition* GliderOverride);

	UFUNCTION(BlueprintCallable, Category="Mission|Skydiving")
	static void SkydiveFromLocation(bool bFromBus, AFortPlayerPawn* InPawn, const FVector FallLocation, const UAthenaGliderItemDefinition* GliderOverride);

};

